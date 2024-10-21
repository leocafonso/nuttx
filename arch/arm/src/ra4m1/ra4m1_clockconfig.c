/****************************************************************************
 * arch/arm/src/sam34/sam_clockconfig.c
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
#include <debug.h>

#include <nuttx/arch.h>
#include <arch/board/board.h>

#include "arm_internal.h"
#include "ra4m1_clockconfig.h"
#include "hardware/ra4m1_flash.h"
#include "hardware/ra4m1_system.h"


/** ROM registers defined here. Some have masks to make sure reserved bits are set appropriately. */
static const uint32_t g_bsp_rom_registers[]  __attribute__((section(".rom_registers"))) __attribute__((__used__)) =
{
    (uint32_t) 0xFFFFFFFF,
    (uint32_t) 0xFFFFAEC3, /* HOCO = 32 MHz. Voltage Detection 0 = 3.84 V */
    (uint32_t) 0x00FFFFFC,
    (uint32_t) 0x00FFFFFF,
    (uint32_t) 0x00FFFFFC,
    (uint32_t) 0x00FFFFFF,
    (uint32_t) 0x00FFFFFC,
    (uint32_t) 0x00FFFFFF,
    (uint32_t) 0x200FFFFC,
    (uint32_t) 0x200FFFFF,
    (uint32_t) 0x407FFFFC,
    (uint32_t) 0x407FFFFF,
    (uint32_t) 0x400DFFFC,
    (uint32_t) 0x400DFFFF,
    (uint32_t) 0xffffffff
};

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* Key code for writing PRCR register. */
#define BSP_PRV_PRCR_KEY                        (0xA500U)
#define BSP_PRV_PRCR_PRC1_UNLOCK                ((BSP_PRV_PRCR_KEY) | 0x2U)
#define BSP_PRV_PRCR_UNLOCK                     ((BSP_PRV_PRCR_KEY) | 0x3U)
#define BSP_PRV_PRCR_LOCK                       ((BSP_PRV_PRCR_KEY) | 0x0U)

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
 * Name: sam_clockconfig
 *
 * Description:
 *   Called to initialize the SAM3/4.  This does whatever setup is needed to
 *   put the SoC in a usable state.  This includes the initialization of
 *   clocking using the settings in board.h.  (After power-on reset, the
 *   SAM3/4 is initially running on a 4MHz internal RC clock).  This
 *   function also performs other low-level chip initialization of the chip
 *   including EFC, master clock, IRQ & watchdog configuration.
 *
 ****************************************************************************/

void ra4m1_clockconfig(void)
{
    /* Unlock VBTCR1 register. */
    putreg16((BSP_PRV_PRCR_KEY | R_SYSTEM_PRCR_PRC0 | R_SYSTEM_PRCR_PRC1), R_SYSTEM_PRCR);

    /* The VBTCR1.BPWSWSTP must be set after reset on MCUs that have VBTCR1.BPWSWSTP. Reference section 11.2.1
     * "VBATT Control Register 1 (VBTCR1)" and Figure 11.2 "Setting flow of the VBTCR1.BPWSWSTP bit" in the RA4M1 manual
     * R01UM0007EU0110. This must be done before bsp_clock_init because LOCOCR, LOCOUTCR, SOSCCR, and SOMCR cannot
     * be accessed until VBTSR.VBTRVLD is set. */
    modifyreg8(R_SYSTEM_VBTCR1, 0, R_SYSTEM_VBTCR1_BPWSWSTP);
    while ((getreg8(R_SYSTEM_VBTSR) & R_SYSTEM_VBTSR_VBTRVLD) == 0)
    {
    }

    /* Disable FCache. */
    modifyreg16(R_FCACHE_FCACHEE, R_FCACHE_FCACHEE_FCACHEEN, 0);

    modifyreg8(R_SYSTEM_SCKSCR, R_SYSTEM_SCKSCR_CKSEL_MASK, 0);

    /* lock VBTCR1 register. */
    putreg16(0, R_SYSTEM_PRCR);

    /* PCLKA = 32Mhz */
    putreg32(0, R_SYSTEM_SCKDIVCR);
} 
