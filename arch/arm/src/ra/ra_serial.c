/****************************************************************************
 * arch/arm/src/sam34/sam_serial.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#ifdef CONFIG_SERIAL_TERMIOS
#include <termios.h>
#endif

#include <nuttx/irq.h>
#include <nuttx/arch.h>
#include <nuttx/fs/ioctl.h>
#include <nuttx/serial/serial.h>

#include <arch/board/board.h>

#include "arm_internal.h"
#include "chip.h"

#include "hardware/ra_sci.h"
#include "hardware/ra_mstp.h"
#include "hardware/ra_system.h"
#include "ra_lowputc.h"
#include "ra_icu.h"
#include "ra_gpio.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
#define BSP_PRV_PRCR_KEY (0xA500U)

/* Is there a serial console?  It could be on UART0-1 or USART0-3 */

#if defined(CONFIG_UART0_SERIAL_CONSOLE) && defined(CONFIG_RA_SCI0_UART)
#undef CONFIG_UART1_SERIAL_CONSOLE
#undef CONFIG_UART2_SERIAL_CONSOLE
#undef CONFIG_UART9_SERIAL_CONSOLE
#define HAVE_CONSOLE 1
#elif defined(CONFIG_UART1_SERIAL_CONSOLE) && defined(CONFIG_RA_SCI1_UART)
#undef CONFIG_UART0_SERIAL_CONSOLE
#undef CONFIG_UART2_SERIAL_CONSOLE
#undef CONFIG_UART9_SERIAL_CONSOLE
#define HAVE_CONSOLE 1
#elif defined(CONFIG_UART2_SERIAL_CONSOLE) && defined(CONFIG_RA_SCI2_UART)
#undef CONFIG_UART0_SERIAL_CONSOLE
#undef CONFIG_UART1_SERIAL_CONSOLE
#undef CONFIG_UART9_SERIAL_CONSOLE
#define HAVE_CONSOLE 1
#elif defined(CONFIG_UART9_SERIAL_CONSOLE) && defined(CONFIG_RA_SCI9_UART)
#undef CONFIG_UART0_SERIAL_CONSOLE
#undef CONFIG_UART1_SERIAL_CONSOLE
#undef CONFIG_UART2_SERIAL_CONSOLE
#define HAVE_CONSOLE 1
#else
#ifndef CONFIG_NO_SERIAL_CONSOLE
#warning "No valid CONFIG_USARTn_SERIAL_CONSOLE Setting"
#endif

#undef CONFIG_UART0_SERIAL_CONSOLE
#undef CONFIG_UART1_SERIAL_CONSOLE
#undef CONFIG_UART2_SERIAL_CONSOLE
#undef CONFIG_UART9_SERIAL_CONSOLE
#undef HAVE_CONSOLE
#endif

/* First pick the console and ttys0. */

#if defined(CONFIG_UART0_SERIAL_CONSOLE)
#define CONSOLE_DEV g_uart0port /* UART0 is console */
#define TTYS0_DEV g_uart0port   /* UART0 is ttyS0 */
#define UART0_ASSIGNED 1
#elif defined(CONFIG_UART1_SERIAL_CONSOLE)
#define CONSOLE_DEV g_uart1port /* UART1 is console */
#define TTYS0_DEV g_uart1port   /* UART1 is ttyS0 */
#define UART1_ASSIGNED 1
#elif defined(CONFIG_UART2_SERIAL_CONSOLE)
#define CONSOLE_DEV g_uart2port /* UART2 is console */
#define TTYS0_DEV g_uart2port   /* UART2 is ttyS0 */
#define UART2_ASSIGNED 1
#elif defined(CONFIG_UART9_SERIAL_CONSOLE)
#define CONSOLE_DEV g_uart9port /* UART9 is console */
#define TTYS0_DEV g_uart9port   /* UART9 is ttyS0 */
#define UART9_ASSIGNED 1
#else
#undef CONSOLE_DEV /* No console */
#if defined(CONFIG_RA_SCI0_UART)
#define TTYS0_DEV g_uart0port /* UART0 is ttyS0 */
#define UART0_ASSIGNED 1
#elif defined(CONFIG_RA_SCI1_UART)
#define TTYS0_DEV g_uart1port /* UART1 is ttyS0 */
#define UART1_ASSIGNED 1
#elif defined(CONFIG_RA_SCI2_UART)
#define TTYS0_DEV g_uart2port /* UART2 is ttyS0 */
#define UART2_ASSIGNED 1
#elif defined(CONFIG_RA_SCI9_UART)
#define TTYS0_DEV g_uart9port /* UART9 is ttyS0 */
#define UART9_ASSIGNED 1
#endif
#endif

/* Pick ttys1. */

#if defined(CONFIG_RA_SCI0_UART) && !defined(UART0_ASSIGNED)
#define TTYS1_DEV g_uart0port /* UART0 is ttyS1 */
#define UART0_ASSIGNED 1
#elif defined(CONFIG_RA_SCI1_UART) && !defined(UART1_ASSIGNED)
#define TTYS1_DEV g_uart1port /* UART1 is ttyS1 */
#define UART1_ASSIGNED 1
#elif defined(CONFIG_RA_SCI2_UART) && !defined(UART2_ASSIGNED)
#define TTYS1_DEV g_usart0port /* UART2 is ttyS1 */
#define UART2_ASSIGNED 1
#elif defined(CONFIG_RA_SCI9_UART) && !defined(UART9_ASSIGNED)
#define TTYS1_DEV g_usart1port /* UART9 is ttyS1 */
#define UART9_ASSIGNED 1
#endif
/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/
static int up_setup(struct uart_dev_s *dev);
static void up_shutdown(struct uart_dev_s *dev);
static int up_attach(struct uart_dev_s *dev);
static void up_detach(struct uart_dev_s *dev);
static int up_rxinterrupt(int irq, void *context, void *arg);
static int up_txinterrupt(int irq, void *context, void *arg);
static int up_teinterrupt(int irq, void *context, void *arg);
static int up_erinterrupt(int irq, void *context, void *arg);
static int up_ioctl(struct file *filep, int cmd, unsigned long arg);
static int up_receive(struct uart_dev_s *dev, unsigned int *status);
static void up_rxint(struct uart_dev_s *dev, bool enable);
static bool up_rxavailable(struct uart_dev_s *dev);
static void up_send(struct uart_dev_s *dev, int ch);
static void up_txint(struct uart_dev_s *dev, bool enable);
static bool up_txready(struct uart_dev_s *dev);
static bool up_txempty(struct uart_dev_s *dev);

/****************************************************************************
 * Private Data
 ****************************************************************************/

struct up_dev_s
{
  const uint32_t usartbase; /* Base address of USART registers */
  uint32_t baud;            /* Configured baud */
  uint32_t sr;              /* Saved status bits */
  uint8_t rxirq;            /* IRQ associated with this USART */
  uint8_t txirq;            /* IRQ associated with this USART */
  uint8_t teirq;            /* IRQ associated with this USART */
  uint8_t erirq;            /* IRQ associated with this USART */
  uint8_t parity;           /* 0=none, 1=odd, 2=even */
  uint8_t bits;             /* Number of bits (5-9) */
  bool stopbits2;           /* true: Configure with 2 stop bits instead of 1 */
};

static const struct uart_ops_s g_uart_ops =
    {
        .setup = up_setup,
        .shutdown = up_shutdown,
        .attach = up_attach,
        .detach = up_detach,
        .ioctl = up_ioctl,
        .receive = up_receive,
        .rxint = up_rxint,
        .rxavailable = up_rxavailable,
        .send = up_send,
        .txint = up_txint,
        .txready = up_txready,
        .txempty = up_txempty,
};


/* I/O buffers */
#if defined(CONFIG_RA_SCI0_UART)
static char g_uart0rxbuffer[CONFIG_UART0_RXBUFSIZE];
static char g_uart0txbuffer[CONFIG_UART0_TXBUFSIZE];
#elif defined(CONFIG_RA_SCI1_UART)
static char g_uart1rxbuffer[CONFIG_UART1_RXBUFSIZE];
static char g_uart1txbuffer[CONFIG_UART1_TXBUFSIZE];
#elif defined(CONFIG_RA_SCI2_UART)
static char g_uart2rxbuffer[CONFIG_UART2_RXBUFSIZE];
static char g_uart2txbuffer[CONFIG_UART2_TXBUFSIZE];
#elif defined(CONFIG_RA_SCI9_UART)
static char g_uart9rxbuffer[CONFIG_UART9_RXBUFSIZE];
static char g_uart9txbuffer[CONFIG_UART9_TXBUFSIZE];
#endif

#if defined(CONFIG_RA_SCI0_UART)
static struct up_dev_s g_uart0priv =
    {
        .usartbase = R_SCI0_BASE,
        .rxirq = SCI0_RXI,
        .txirq = SCI0_TXI,
        .teirq = SCI0_TEI,
        .erirq = SCI0_ERI,
        .baud = CONFIG_UART0_BAUD,
        .parity = CONFIG_UART0_PARITY,
        .bits = CONFIG_UART0_BITS,
        .stopbits2 = CONFIG_UART0_2STOP,
};

static uart_dev_t g_uart0port =
    {
        .recv =
            {
                .size = CONFIG_UART0_RXBUFSIZE,
                .buffer = g_uart0rxbuffer,
            },
        .xmit =
            {
                .size = CONFIG_UART0_TXBUFSIZE,
                .buffer = g_uart0txbuffer,
            },
        .ops = &g_uart_ops,
        .priv = &g_uart0priv,
};
#elif defined(CONFIG_RA_SCI1_UART)
static struct up_dev_s g_uart1priv =
    {
        .usartbase = R_SCI1_BASE,
        .rxirq = SCI1_RXI,
        .txirq = SCI1_TXI,
        .teirq = SCI1_TEI,
        .erirq = SCI1_ERI,
        .baud = CONFIG_UART1_BAUD,
        .parity = CONFIG_UART1_PARITY,
        .bits = CONFIG_UART1_BITS,
        .stopbits2 = CONFIG_UART1_2STOP,
};

static uart_dev_t g_uart1port =
    {
        .recv =
            {
                .size = CONFIG_UART1_RXBUFSIZE,
                .buffer = g_uart1rxbuffer,
            },
        .xmit =
            {
                .size = CONFIG_UART1_TXBUFSIZE,
                .buffer = g_uart1txbuffer,
            },
        .ops = &g_uart_ops,
        .priv = &g_uart1priv,
};
#elif defined(CONFIG_RA_SCI2_UART)
static struct up_dev_s g_uart2priv =
    {
        .usartbase = R_SCI2_BASE,
        .rxirq = SCI2_RXI,
        .txirq = SCI2_TXI,
        .teirq = SCI2_TEI,
        .erirq = SCI2_ERI,
        .baud = CONFIG_UART2_BAUD,
        .parity = CONFIG_UART2_PARITY,
        .bits = CONFIG_UART2_BITS,
        .stopbits2 = CONFIG_UART2_2STOP,
};

static uart_dev_t g_uart2port =
    {
        .recv =
            {
                .size = CONFIG_UART2_RXBUFSIZE,
                .buffer = g_uart2rxbuffer,
            },
        .xmit =
            {
                .size = CONFIG_UART2_TXBUFSIZE,
                .buffer = g_uart2txbuffer,
            },
        .ops = &g_uart_ops,
        .priv = &g_uart2priv,
};
#elif defined(CONFIG_RA_SCI9_UART)
static struct up_dev_s g_uart9priv =
    {
        .usartbase = R_SCI9_BASE,
        .rxirq = SCI9_RXI,
        .txirq = SCI9_TXI,
        .teirq = SCI9_TEI,
        .erirq = SCI9_ERI,
        .baud = CONFIG_UART9_BAUD,
        .parity = CONFIG_UART9_PARITY,
        .bits = CONFIG_UART9_BITS,
        .stopbits2 = CONFIG_UART9_2STOP,
};

static uart_dev_t g_uart9port =
    {
        .recv =
            {
                .size = CONFIG_UART9_RXBUFSIZE,
                .buffer = g_uart9rxbuffer,
            },
        .xmit =
            {
                .size = CONFIG_UART9_TXBUFSIZE,
                .buffer = g_uart9txbuffer,
            },
        .ops = &g_uart_ops,
        .priv = &g_uart9priv,
};
#endif
/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_serialin
 ****************************************************************************/

static inline uint8_t up_serialin_u8(struct up_dev_s *priv, int offset)
{
  return getreg8(priv->usartbase + offset);
}

static inline uint32_t up_serialin_u32(struct up_dev_s *priv, int offset)
{
  return getreg32(priv->usartbase + offset);
}

/****************************************************************************
 * Name: up_serialout
 ****************************************************************************/

static inline void up_serialout_u32(struct up_dev_s *priv, int offset,
                                uint32_t value)
{
    putreg32(value, priv->usartbase + offset);
}

static inline void up_serialout_u8(struct up_dev_s *priv, int offset,
                                uint8_t value)
{
    putreg8(value, priv->usartbase + offset);
}

static int up_setup(struct uart_dev_s *dev)
{
  struct up_dev_s *priv = (struct up_dev_s *)dev->priv;
  uint8_t regval;

#if defined(CONFIG_RA_SCI0_UART)
  ra_configgpio(GPIO_SCI0_RX);
  ra_configgpio(GPIO_SCI0_TX);
#elif defined(CONFIG_RA_SCI1_UART)
  ra_configgpio(GPIO_SCI1_RX);
  ra_configgpio(GPIO_SCI1_TX);
#elif defined(CONFIG_RA_SCI2_UART)
  ra_configgpio(GPIO_SCI2_RX);
  ra_configgpio(GPIO_SCI2_TX);
#elif defined(CONFIG_RA_SCI9_UART)
  ra_configgpio(GPIO_SCI9_RX);
  ra_configgpio(GPIO_SCI9_TX);
#endif

  // up_disableallints(priv, &imr);
  up_shutdown(dev);

  putreg16((BSP_PRV_PRCR_KEY | R_SYSTEM_PRCR_PRC1), R_SYSTEM_PRCR);
  modifyreg32(R_MSTP_MSTPCRB, R_MSTP_MSTPCRB_MSTPB29, 0);
  putreg16(BSP_PRV_PRCR_KEY, R_SYSTEM_PRCR);

  regval = 0;
  up_serialout_u8(priv, R_SCI_SCR_OFFSET, regval);

/*
  UART character length requires change in two registers - SCMR and SMR
  SCMR.CHR1 SMR.CHR
  0 0: Transmit/receive in 9-bit data length
  0 1: Transmit/receive in 9-bit data length
  1 0: Transmit/receive in 8-bit data length (initial value)
  1 1: Transmit/receive in 7-bit data length.
*/

  regval = up_serialin_u8(priv, R_SCI_SCMR_OFFSET);

  if (priv->bits == 9)
  {
    regval &= ~R_SCI_SCMR_CHR1; 
  }

  up_serialout_u8(priv, R_SCI_SCMR_OFFSET, regval);

  regval = 0;
  if (priv->parity > 0)
  {
    regval |= R_SCI_SMR_PE;
    if (priv->parity == 1)
    {
      regval |= R_SCI_SMR_PM;
    }
  }

  if (priv->stopbits2 == 1)
  {
    regval |= R_SCI_SMR_STOP;
  }

  if (priv->bits == 7 || priv->bits == 9)
  {
    regval |= R_SCI_SMR_CHR;
  }

  up_serialout_u8(priv, R_SCI_SMR_OFFSET, regval);


  regval = 8;
  up_serialout_u8(priv, R_SCI_BRR_OFFSET, regval);

  regval = (R_SCI_SCR_TIE | R_SCI_SCR_RIE | R_SCI_SCR_TE | R_SCI_SCR_RE);
  up_serialout_u8(priv, R_SCI_SCR_OFFSET, regval);

  return OK;
}
static void up_shutdown(struct uart_dev_s *dev)
{
}
static int up_attach(struct uart_dev_s *dev)
{
  struct up_dev_s *priv = (struct up_dev_s *)dev->priv;
  int ret;

  /* Attach and enable the IRQ */
  ret = irq_attach(priv->rxirq, up_rxinterrupt, dev);
  if (ret < 0)
  {
    return ret;
  }

  ret = irq_attach(priv->txirq, up_txinterrupt, dev);
  if (ret < 0)
  {
    irq_detach(priv->rxirq);
    return ret;
  }
  ret = irq_attach(priv->teirq, up_teinterrupt, dev);
  if (ret < 0)
  {
    irq_detach(priv->txirq);
    irq_detach(priv->rxirq);
    return ret;
  }

  ret = irq_attach(priv->erirq, up_erinterrupt, dev);
  if (ret < 0)
  {
    irq_detach(priv->erirq);
    irq_detach(priv->txirq);
    irq_detach(priv->rxirq);
    return ret;
  }

  up_enable_irq(priv->rxirq);
  up_enable_irq(priv->txirq);
  up_enable_irq(priv->teirq);
  up_enable_irq(priv->erirq);

  return ret;
}
static void up_detach(struct uart_dev_s *dev)
{
  struct up_dev_s *priv = (struct up_dev_s *)dev->priv;

  up_disable_irq(priv->rxirq);
  up_disable_irq(priv->txirq);
  up_disable_irq(priv->teirq);
  up_disable_irq(priv->erirq);
  irq_detach(priv->rxirq);
  irq_detach(priv->txirq);
  irq_detach(priv->teirq);
  irq_detach(priv->erirq);
}

/****************************************************************************
 * Name: up_rxinterrupt
 *
 * Description:
 *   This is the common UART RX interrupt handler.
 *
 ****************************************************************************/

static int up_rxinterrupt(int irq, void *context, void *arg)
{
  struct uart_dev_s *dev = (struct uart_dev_s *)arg;
  ra_clear_ir(irq);
  uart_recvchars(dev);
  return OK;
}

/****************************************************************************
 * Name: up_txinterrupt
 *
 * Description:
 *   This is the common UART TX interrupt handler.
 *
 ****************************************************************************/

static int up_txinterrupt(int irq, void *context, void *arg)
{
  struct uart_dev_s *dev = (struct uart_dev_s *)arg;
  ra_clear_ir(irq);
  uart_xmitchars(dev);

  return OK;
}

static int up_teinterrupt(int irq, void *context, void *arg)
{
  return OK;
}

static int up_erinterrupt(int irq, void *context, void *arg)
{
  return OK;
}

static int up_ioctl(struct file *filep, int cmd, unsigned long arg)
{
#if defined(CONFIG_SERIAL_TERMIOS) || defined(CONFIG_SERIAL_TIOCSERGSTRUCT)
  struct inode *inode = filep->f_inode;
  struct uart_dev_s *dev = inode->i_private;
#endif
  int ret = OK;

  switch (cmd)
  {
#ifdef CONFIG_SERIAL_TIOCSERGSTRUCT
  case TIOCSERGSTRUCT:
  {
    struct up_dev_s *user = (struct up_dev_s *)arg;
    if (!user)
    {
      ret = -EINVAL;
    }
    else
    {
      memcpy(user, dev, sizeof(struct up_dev_s));
    }
  }
  break;
#endif

#ifdef CONFIG_SERIAL_TERMIOS
  case TCGETS:
  {
    struct termios *termiosp = (struct termios *)arg;
    struct up_dev_s *priv = (struct up_dev_s *)dev->priv;

    if (!termiosp)
    {
      ret = -EINVAL;
      break;
    }

    /* Return parity */

    termiosp->c_cflag = ((priv->parity != 0) ? PARENB : 0) |
                        ((priv->parity == 1) ? PARODD : 0);

    /* Return stop bits */

    termiosp->c_cflag |= (priv->stopbits2) ? CSTOPB : 0;

    /* Return flow control */

#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
    termiosp->c_cflag |= (priv->flowc) ? (CCTS_OFLOW | CRTS_IFLOW) : 0;
#endif
    /* Return baud */

    cfsetispeed(termiosp, priv->baud);

    /* Return number of bits */

    switch (priv->bits)
    {
    case 5:
      termiosp->c_cflag |= CS5;
      break;

    case 6:
      termiosp->c_cflag |= CS6;
      break;

    case 7:
      termiosp->c_cflag |= CS7;
      break;

    default:
    case 8:
      termiosp->c_cflag |= CS8;
      break;

    case 9:
      termiosp->c_cflag |= CS8 /* CS9 */;
      break;
    }
  }
  break;

  case TCSETS:
  {
    struct termios *termiosp = (struct termios *)arg;
    struct up_dev_s *priv = (struct up_dev_s *)dev->priv;
    uint32_t baud;
    uint32_t imr;
    uint8_t parity;
    uint8_t nbits;
    bool stop2;
#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
    bool flowc;
#endif

    if (!termiosp)
    {
      ret = -EINVAL;
      break;
    }

    /* Decode baud. */

    ret = OK;
    baud = cfgetispeed(termiosp);

    /* Decode number of bits */

    switch (termiosp->c_cflag & CSIZE)
    {
    case CS5:
      nbits = 5;
      break;

    case CS6:
      nbits = 6;
      break;

    case CS7:
      nbits = 7;
      break;

    case CS8:
      nbits = 8;
      break;
#if 0
          case CS9:
            nbits = 9;
            break;
#endif
    default:
      ret = -EINVAL;
      break;
    }

    /* Decode parity */

    if ((termiosp->c_cflag & PARENB) != 0)
    {
      parity = (termiosp->c_cflag & PARODD) ? 1 : 2;
    }
    else
    {
      parity = 0;
    }

    /* Decode stop bits */

    stop2 = (termiosp->c_cflag & CSTOPB) != 0;

    /* Decode flow control */

#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
    flowc = (termiosp->c_cflag & (CCTS_OFLOW | CRTS_IFLOW)) != 0;
#endif
    /* Verify that all settings are valid before committing */

    if (ret == OK)
    {
      /* Commit */

      priv->baud = baud;
      priv->parity = parity;
      priv->bits = nbits;
      priv->stopbits2 = stop2;
#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
      priv->flowc = flowc;
#endif
      /* effect the changes immediately - note that we do not
       * implement TCSADRAIN / TCSAFLUSH
       */

      up_disableallints(priv, &imr);
      ret = up_setup(dev);

      /* Restore the interrupt state */

      up_restoreusartint(priv, imr);
    }
  }
  break;
#endif /* CONFIG_SERIAL_TERMIOS */

  default:
    ret = -ENOTTY;
    break;
  }

  return ret;
}
static int up_receive(struct uart_dev_s *dev, unsigned int *status)
{
  struct up_dev_s *priv = (struct up_dev_s *)dev->priv;

  /* Return the error information in the saved status */

  *status = priv->sr;
  priv->sr = 0;
  /* Then return the actual received byte */
  return (int)(up_serialin_u8(priv, R_SCI_RDR_OFFSET) & 0xff);
}

static void up_rxint(struct uart_dev_s *dev, bool enable)
{
}

static bool up_rxavailable(struct uart_dev_s *dev)
{
  struct up_dev_s *priv = (struct up_dev_s *)dev->priv;
  return ((up_serialin_u8(priv, R_SCI_SSR_OFFSET) & R_SCI_SSR_RDRF) == R_SCI_SSR_RDRF);
}
static void up_send(struct uart_dev_s *dev, int ch)
{
  struct up_dev_s *priv = (struct up_dev_s *)dev->priv;
  up_serialout_u8(priv, R_SCI_TDR_OFFSET, (uint8_t)ch);
}
static void up_txint(struct uart_dev_s *dev, bool enable)
{
  // struct up_dev_s *priv = (struct up_dev_s *)dev->priv;
  irqstate_t flags;

  flags = enter_critical_section();
  if (enable)
  {
    /* Set to receive an interrupt when the TX holding register register
     * is empty
     */

#ifndef CONFIG_SUPPRESS_SERIAL_INTS
    // regval = (R_SCI2_SCR_TIE | R_SCI2_SCR_RIE | R_SCI2_SCR_TE | R_SCI2_SCR_RE);
    // putreg8(regval, R_SCI2_SCR);
    // up_serialout(priv, SAM_UART_IER_OFFSET, UART_INT_TXRDY);

    /* Fake a TX interrupt here by just calling uart_xmitchars() with
     * interrupts disabled (note this may recurse).
     */

    uart_xmitchars(dev);

#endif
  }
  else
  {
    /* Disable the TX interrupt */

    // up_serialout(priv, SAM_UART_IDR_OFFSET, UART_INT_TXRDY);
  }

  leave_critical_section(flags);
}
static bool up_txready(struct uart_dev_s *dev)
{
  struct up_dev_s *priv = (struct up_dev_s *)dev->priv;
  bool ret = ((up_serialin_u8(priv, R_SCI_SSR_OFFSET) & R_SCI_SSR_TDRE) == R_SCI_SSR_TDRE);
  return ret;
}
static bool up_txempty(struct uart_dev_s *dev)
{
  struct up_dev_s *priv = (struct up_dev_s *)dev->priv;
  bool ret = ((up_serialin_u8(priv, R_SCI_SSR_OFFSET) & R_SCI_SSR_TDRE) == R_SCI_SSR_TDRE);
  return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: arm_earlyserialinit
 *
 * Description:
 *   Performs the low level USART initialization early in debug so that the
 *   serial console will be available during bootup.  This must be called
 *   before arm_serialinit.
 *
 ****************************************************************************/

void arm_earlyserialinit(void)
{
  /* Disable all USARTS */

#ifdef TTYS0_DEV
  // up_disableallints(TTYS0_DEV.priv, NULL);
#endif
#ifdef TTYS1_DEV
  up_disableallints(TTYS1_DEV.priv, NULL);
#endif
#ifdef TTYS2_DEV
  up_disableallints(TTYS2_DEV.priv, NULL);
#endif
#ifdef TTYS3_DEV
  up_disableallints(TTYS3_DEV.priv, NULL);
#endif
#ifdef TTYS4_DEV
  up_disableallints(TTYS4_DEV.priv, NULL);
#endif
#ifdef TTYS5_DEV
  up_disableallints(TTYS5_DEV.priv, NULL);
#endif

  /* Configuration whichever one is the console */
  CONSOLE_DEV.isconsole = true;

  up_setup(&CONSOLE_DEV);
}

/****************************************************************************
 * Name: arm_serialinit
 *
 * Description:
 *   Register serial console and serial ports.  This assumes
 *   that arm_earlyserialinit was called previously.
 *
 ****************************************************************************/

void arm_serialinit(void)
{
  /* Register the console */

#ifdef HAVE_CONSOLE
  uart_register("/dev/console", &CONSOLE_DEV);
#endif

  /* Register all USARTs */
#ifdef TTYS0_DEV
  uart_register("/dev/ttyS0", &TTYS0_DEV);
#endif
#ifdef TTYS1_DEV
  uart_register("/dev/ttyS1", &TTYS1_DEV);
#endif
#ifdef TTYS2_DEV
  uart_register("/dev/ttyS2", &TTYS2_DEV);
#endif
#ifdef TTYS3_DEV
  uart_register("/dev/ttyS3", &TTYS3_DEV);
#endif
#ifdef TTYS4_DEV
  uart_register("/dev/ttyS4", &TTYS4_DEV);
#endif
#ifdef TTYS5_DEV
  uart_register("/dev/ttyS5", &TTYS5_DEV);
#endif
}
