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
#  include <termios.h>
#endif

#include <nuttx/irq.h>
#include <nuttx/arch.h>
#include <nuttx/fs/ioctl.h>
#include <nuttx/serial/serial.h>

#include <arch/board/board.h>

#include "arm_internal.h"
#include "chip.h"

#include "hardware/ra4m1_sci.h"
#include "hardware/ra4m1_mstp.h"
#include "hardware/ra4m1_system.h"
#include "ra4m1_lowputc.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
#define BSP_PRV_PRCR_KEY                        (0xA500U)

#    define CONSOLE_DEV         g_uart0port  /* UART0 is console */
#    define TTYS0_DEV           g_uart0port  /* UART0 is ttyS0 */
#    define UART0_ASSIGNED      1
/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/
static int  up_setup(struct uart_dev_s *dev);
static void up_shutdown(struct uart_dev_s *dev);
static int  up_attach(struct uart_dev_s *dev);
static void up_detach(struct uart_dev_s *dev);
static int up_rxinterrupt(int irq, void *context, void *arg);
static int up_txinterrupt(int irq, void *context, void *arg);
static int up_teinterrupt(int irq, void *context, void *arg);
static int up_erinterrupt(int irq, void *context, void *arg);
static int  up_ioctl(struct file *filep, int cmd, unsigned long arg);
static int  up_receive(struct uart_dev_s *dev, unsigned int *status);
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
  const uint32_t usartbase;     /* Base address of USART registers */
  uint32_t baud;                /* Configured baud */
  uint32_t sr;                  /* Saved status bits */
  uint8_t  rxirq;                 /* IRQ associated with this USART */
  uint8_t  txirq;                 /* IRQ associated with this USART */
  uint8_t  teirq;                 /* IRQ associated with this USART */
  uint8_t  erirq;                 /* IRQ associated with this USART */
  uint8_t  parity;              /* 0=none, 1=odd, 2=even */
  uint8_t  bits;                /* Number of bits (5-9) */
  bool     stopbits2;           /* true: Configure with 2 stop bits instead of 1 */
};

static struct up_dev_s g_uart0priv =
{
  .usartbase      = R_SCI2_BASE,
  .baud           = 115200,
  .rxirq          = SCI2_RXI,
  .txirq          = SCI2_TXI,
  .teirq          = SCI2_TEI,
  .erirq          = SCI2_ERI,
  .parity         = 0,
  .bits           = 0,
  .stopbits2      = 0,
};

static const struct uart_ops_s g_uart_ops =
{
  .setup          = up_setup,
  .shutdown       = up_shutdown,
  .attach         = up_attach,
  .detach         = up_detach,
  .ioctl          = up_ioctl,
  .receive        = up_receive,
  .rxint          = up_rxint,
  .rxavailable    = up_rxavailable,
  .send           = up_send,
  .txint          = up_txint,
  .txready        = up_txready,
  .txempty        = up_txempty,
};

/* I/O buffers */

static char g_uart0rxbuffer[CONFIG_UART0_RXBUFSIZE];
static char g_uart0txbuffer[CONFIG_UART0_TXBUFSIZE];


static uart_dev_t g_uart0port =
{
  .recv     =
  {
    .size   = CONFIG_UART0_RXBUFSIZE,
    .buffer = g_uart0rxbuffer,
  },
  .xmit     =
  {
    .size   = CONFIG_UART0_TXBUFSIZE,
    .buffer = g_uart0txbuffer,
  },
  .ops      = &g_uart_ops,
  .priv     = &g_uart0priv,
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static int  up_setup(struct uart_dev_s *dev)
{
  //struct up_dev_s *priv = (struct up_dev_s *)dev->priv;
  uint32_t regval;

  /* Note: The logic here depends on the fact that that the USART module
   * was enabled and the pins were configured in sam_lowsetup().
   */

  /* The shutdown method will put the UART in a known, disabled state */

  // up_disableallints(priv, &imr);
  up_shutdown(dev);
  putreg16((BSP_PRV_PRCR_KEY | R_SYSTEM_PRCR_PRC1), R_SYSTEM_PRCR);
  modifyreg32(R_MSTP_MSTPCRB, R_MSTP_MSTPCRB_MSTPB29, 0);
  putreg16(BSP_PRV_PRCR_KEY, R_SYSTEM_PRCR);
  regval = 0;
  putreg8(regval, R_SCI2_SCR);

  regval  = 8;
  putreg8(regval, R_SCI2_BRR);


  regval = (R_SCI2_SCR_TIE | R_SCI2_SCR_RIE | R_SCI2_SCR_TE | R_SCI2_SCR_RE);
  putreg8(regval, R_SCI2_SCR);

  return OK;
}
static void up_shutdown(struct uart_dev_s *dev)
{

}
static int  up_attach(struct uart_dev_s *dev)
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
  ret = irq_attach(priv->teirq, up_rxinterrupt, dev);
  if (ret < 0)
  {
    irq_detach(priv->txirq);
    irq_detach(priv->rxirq);
    return ret;
  }

  ret = irq_attach(priv->erirq, up_txinterrupt, dev);
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
//   struct uart_dev_s *dev = (struct uart_dev_s *)arg;
//   struct efm32_usart_s *priv;
//   uint32_t intflags;

//   DEBUGASSERT(dev != NULL && dev->priv != NULL);
//   priv = (struct efm32_usart_s *)dev->priv;

//   /* Read the interrupt flags register */

//   intflags = efm32_serialin(priv, EFM32_USART_IF_OFFSET);

//   /* Clear pending interrupts by writing to the interrupt flag clear
//    * register.
//    */

//   efm32_serialout(priv, EFM32_USART_IFC_OFFSET, intflags & EFM32_RX_INTS);

//   /* Check if the receive data is available is full (RXDATAV). */

//   if ((intflags & USART_IEN_RXDATAV) != 0)
//     {
//       /* Process incoming bytes */

//       uart_recvchars(dev);
//     }

// #ifdef CONFIG_DEBUG_FEATURES
//   /* Check for receive errors */

//   if ((intflags & EFM32_RXERR_INTS) != 0)
//     {
//       /* RXOF - RX Overflow Interrupt Enable
//        * RXUF - RX Underflow Interrupt Enable
//        * TXUF - TX Underflow Interrupt Enable
//        * PERR - Parity Error Interrupt Enable
//        * FERR - Framing Error Interrupt Enable
//        */

//       _err("RX ERROR: %08x\n", intflags);
//     }
// #endif

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
//   struct uart_dev_s *dev = (struct uart_dev_s *)arg;
//   struct efm32_usart_s *priv;
//   uint32_t intflags;

//   DEBUGASSERT(dev != NULL && dev->priv != NULL);
//   priv = (struct efm32_usart_s *)dev->priv;

//   /* Read the interrupt flags register */

//   intflags = efm32_serialin(priv, EFM32_USART_IF_OFFSET);

//   /* Clear pending interrupts by writing to the interrupt flag clear
//    * register.  We won't clear RX errors until they have been reported.
//    */

//   efm32_serialout(priv, EFM32_USART_IFC_OFFSET, intflags & EFM32_TX_INTS);

//   /* Check if the transmit data buffer became half full */

//   if ((intflags & USART_IEN_TXBL) != 0)
//     {
//       /* Process outgoing bytes */

//       uart_xmitchars(dev);
//     }

// #ifdef CONFIG_DEBUG_FEATURES
//   /* Check for transmit errors */

//   if ((intflags & EFM32_TXERR_INTS) != 0)
//     {
//       /* TXOF - TX Overflow Interrupt Enable */

//       _err("RX ERROR: %08x\n", intflags);
//     }
// #endif

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

static int  up_ioctl(struct file *filep, int cmd, unsigned long arg)
{
    return OK;
}
static int  up_receive(struct uart_dev_s *dev, unsigned int *status)
{
    return OK;
}
static void up_rxint(struct uart_dev_s *dev, bool enable)
{

}
static bool up_rxavailable(struct uart_dev_s *dev)
{
    return true;
}
static void up_send(struct uart_dev_s *dev, int ch)
{

}
static void up_txint(struct uart_dev_s *dev, bool enable)
{
    return OK;
}
static bool up_txready(struct uart_dev_s *dev)
{
    return true;
}
static bool up_txempty(struct uart_dev_s *dev)
{
    return true;
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
  /* NOTE:  All GPIO configuration for the USARTs was performed in
   * sam_lowsetup
   */

  /* Disable all USARTS */

 // up_disableallints(TTYS0_DEV.priv, NULL);
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

  uart_register("/dev/ttyS0", &TTYS0_DEV);
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
