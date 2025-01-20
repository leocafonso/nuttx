/****************************************************************************
 * arch/arm/src/sam34/sam_lowputc.c
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

#include <stdint.h>

#include <nuttx/irq.h>
#include <nuttx/arch.h>

#include "arm_internal.h"
#include "ra_lowputc.h"
#include "hardware/ra_sci.h"
#include "hardware/ra_mstp.h"
#include "hardware/ra_system.h"
#include "hardware/ra_gpio.h"

/* The board.h file may redefine pin configurations defined in sam_pinmap.h */
#include <arch/board/board.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
#define HAVE_CONSOLE 1
/* Configuration ************************************************************/
#define BSP_PRV_PRCR_KEY                        (0xA500U)

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: arm_lowputc
 *
 * Description:
 *   Output one byte on the serial console
 *
 ****************************************************************************/

void arm_lowputc(char ch)
{
#ifdef HAVE_CONSOLE
  irqstate_t flags;
  for (; ; )
    {

      while ((getreg8(R_SCI2_SSR) & R_SCI2_SSR_TEND) == 0);

      // /* Disable interrupts so that the test and the transmission are
      //  * atomic.
      //  */
      flags = spin_lock_irqsave(NULL);
      if ((getreg8(R_SCI2_SSR) & R_SCI2_SSR_TEND)  == R_SCI2_SSR_TEND)
        {
          /* Send the character */

          putreg8((uint32_t)ch, R_SCI2_TDR);

          spin_unlock_irqrestore(NULL, flags);
          return;
        }

      spin_unlock_irqrestore(NULL, flags);
    }
#endif
}

/****************************************************************************
 * Name: up_putc
 *
 * Description:
 *   Provide priority, low-level access to support OS debug writes
 *
 ****************************************************************************/

int up_putc(int ch)
{
#ifdef HAVE_CONSOLE
  /* Check for LF */

  if (ch == '\n')
    {
      /* Add CR */

      arm_lowputc('\r');
    }

  arm_lowputc(ch);
#endif
  return ch;
}

/****************************************************************************
 * Name: ra_lowsetup
 *
 * Description:
 *   This performs basic initialization of the USART used for the serial
 *   console.  Its purpose is to get the console output available as soon
 *   as possible.
 *
 ****************************************************************************/

void ra_lowsetup(void)
{
  uint32_t regval;
  regval = R_PMISC_PWPR_PFSWE;
  putreg8(0, R_PMISC_PWPR);
  putreg8(regval, R_PMISC_PWPR);
  regval = (0x4 & R_PFS_PSEL_MASK) << R_PFS_PSEL_SHIFT | R_PFS_PMR;
  modifyreg32(R_PFS(3,2),0 , regval);
  modifyreg32(R_PFS(3,1),0 , regval);
  regval = R_PMISC_PWPR_B0WI;
  putreg8(0, R_PMISC_PWPR);
  putreg8(regval, R_PMISC_PWPR);

  putreg16((BSP_PRV_PRCR_KEY | R_SYSTEM_PRCR_PRC1), R_SYSTEM_PRCR);
  modifyreg32(R_MSTP_MSTPCRB, R_MSTP_MSTPCRB_MSTPB29, 0);
  putreg16(BSP_PRV_PRCR_KEY, R_SYSTEM_PRCR);
  regval = 0;
  putreg8(regval, R_SCI2_SCR);

  regval  = 8;
  putreg8(regval, R_SCI2_BRR);


  regval = (R_SCI2_SCR_TE | R_SCI2_SCR_RE);
  putreg8(regval, R_SCI2_SCR);
}
