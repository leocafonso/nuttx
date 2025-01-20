/****************************************************************************
 * arch/arm/src/ra4m1/ra4m1_clockconfig.c
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

#define HOCO_FREQ RA4M1_HOCO_FREQUENCY

#if HOCO_FREQ == 24000000ul
#define OFS1_HOCO_FREQ 0
#elif HOCO_FREQ == 32000000ul
#define OFS1_HOCO_FREQ 2
#elif HOCO_FREQ == 48000000ul
#define OFS1_HOCO_FREQ 4
#elif HOCO_FREQ == 64000000ul
#define OFS1_HOCO_FREQ 5
#else
#error "Unsupported HOCO frequency"
#endif

struct ofs0_reg
{
    uint32_t RSVD1 : 1;
    uint32_t IWDTSTRT : 1;
    uint32_t IWDTTOPS : 2;
    uint32_t IWDTCKS : 4;
    uint32_t IWDTRPES : 2;
    uint32_t IWDTRPSS : 2;
    uint32_t IWDTRSTIRQS : 1;
    uint32_t RSVD2 : 1;
    uint32_t IWDTSTPCTL : 1;
    uint32_t RSVD3 : 2;
    uint32_t WDTSTRT : 1;
    uint32_t WDTTOPS : 2;
    uint32_t WDTCKS : 4;
    uint32_t WDTRPES : 2;
    uint32_t WDTRPSS : 2;
    uint32_t WDTRSTIRQS : 1;
    uint32_t RSVD4 : 1;
    uint32_t WDTSTPCTL : 1;
    uint32_t RSVD5 : 1;
};

struct ofs1_reg
{
    uint32_t RSVD1 : 2;
    uint32_t LVDAS : 1;
    uint32_t VDSEL1 : 3;
    uint32_t RSVD2 : 2;
    uint32_t HOCOEN : 1;
    uint32_t RSVD3 : 3;
    uint32_t HOCOFRQ1 : 3;
    uint32_t RSVD4 : 17;
};

struct mpu_regs
{
    uint32_t SECMPUPCSO;
    uint32_t SECMPUPCEO;
    uint32_t SECMPUPCS1;
    uint32_t SECMPUPCE1;
    uint32_t SECMPUS0;
    uint32_t SECMPUE0;
    uint32_t SECMPUS1;
    uint32_t SECMPUE1;
    uint32_t SECMPUS2;
    uint32_t SECMPUE2;
    uint32_t SECMPUS3;
    uint32_t SECMPUE3;
    uint32_t SECMPUAC;
};

struct opt_set_mem
{
    struct ofs0_reg ofs0;
    struct ofs1_reg ofs1;
    struct mpu_regs mpu;
};

const struct opt_set_mem ops __attribute__((section(".rom_registers"))) __attribute__((__used__)) = {
    .ofs0 = {
        /*
         * Initial settings for watchdog timers. Set all fields to 1,
         * disabling watchdog functionality as config options have not
         * yet been implemented.
         */
        .RSVD1 = 0x1,
        .IWDTSTRT = 0x1, /* Disable independent watchdog timer
                          */
        .IWDTTOPS = 0x3,
        .IWDTCKS = 0xf,
        .IWDTRPES = 0x3,
        .IWDTRPSS = 0x3,
        .IWDTRSTIRQS = 0x1,
        .RSVD2 = 0x1,
        .IWDTSTPCTL = 0x1,
        .RSVD3 = 0x3,
        .WDTSTRT = 0x1, /* Stop watchdog timer following reset */
        .WDTTOPS = 0x3,
        .WDTCKS = 0xf,
        .WDTRPES = 0x3,
        .WDTRPSS = 0x3,
        .WDTRSTIRQS = 0x1,
        .RSVD4 = 0x1,
        .WDTSTPCTL = 0x1,
        .RSVD5 = 0x1,
    },
    .ofs1 = {
        .RSVD1 = 0x3,
        .LVDAS = 0x1, /* Disable voltage monitor 0 following reset */
        .VDSEL1 = 0x3,
        .RSVD2 = 0x3,
        .HOCOEN = !RA4M1_HOCOEN,
        .RSVD3 = 0x7,
        .HOCOFRQ1 = OFS1_HOCO_FREQ,
        .RSVD4 = 0x1ffff,
    },
    .mpu = {
        /*
         * Initial settings for MPU. Set all areas to maximum values
         * essentially disabling MPU functionality as config options
         * have not yet been implemented.
         */
        .SECMPUPCSO = 0x00fffffc,
        .SECMPUPCEO = 0x00ffffff,
        .SECMPUPCS1 = 0x00fffffc,
        .SECMPUPCE1 = 0x00ffffff,
        .SECMPUS0 = 0x00fffffc,
        .SECMPUE0 = 0x00ffffff,
        .SECMPUS1 = 0x200ffffc,
        .SECMPUE1 = 0x200fffff,
        .SECMPUS2 = 0x407ffffc,
        .SECMPUE2 = 0x407fffff,
        .SECMPUS3 = 0x40dffffc,
        .SECMPUE3 = 0x40dfffff,
        .SECMPUAC = 0xffffffff,
    }};

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* Key code for writing PRCR register. */
#define BSP_PRV_PRCR_KEY (0xA500U)
#define BSP_PRV_PRCR_PRC1_UNLOCK ((BSP_PRV_PRCR_KEY) | 0x2U)
#define BSP_PRV_PRCR_UNLOCK ((BSP_PRV_PRCR_KEY) | 0x3U)
#define BSP_PRV_PRCR_LOCK ((BSP_PRV_PRCR_KEY) | 0x0U)

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
 * Name: ra4m1_clockconfig
 *
 * Description:
 *   Called to initialize the RA4M1.  This does whatever setup is needed to
 *   put the SoC in a usable state.  This includes the initialization of
 *   clocking using the settings in board.h.
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
    modifyreg32(R_SYSTEM_SCKDIVCR,
                (R_SYSTEM_SCKDIVCR_FCK_MASK << R_SYSTEM_SCKDIVCR_FCK_SHIFT |
                 R_SYSTEM_SCKDIVCR_ICK_MASK << R_SYSTEM_SCKDIVCR_ICK_SHIFT |
                 R_SYSTEM_SCKDIVCR_PCKA_MASK << R_SYSTEM_SCKDIVCR_PCKA_SHIFT |
                 R_SYSTEM_SCKDIVCR_PCKB_MASK << R_SYSTEM_SCKDIVCR_PCKB_SHIFT |
                 R_SYSTEM_SCKDIVCR_PCKC_MASK << R_SYSTEM_SCKDIVCR_PCKC_SHIFT |
                 R_SYSTEM_SCKDIVCR_PCKD_MASK << R_SYSTEM_SCKDIVCR_PCKD_SHIFT),
                (RA4M1_FCK_DIV << R_SYSTEM_SCKDIVCR_FCK_SHIFT |
                 RA4M1_ICK_DIV << R_SYSTEM_SCKDIVCR_ICK_SHIFT |
                 RA4M1_PCKA_DIV << R_SYSTEM_SCKDIVCR_PCKA_SHIFT |
                 RA4M1_PCKB_DIV << R_SYSTEM_SCKDIVCR_PCKB_SHIFT |
                 RA4M1_PCKC_DIV << R_SYSTEM_SCKDIVCR_PCKC_SHIFT |
                 RA4M1_PCKD_DIV << R_SYSTEM_SCKDIVCR_PCKD_SHIFT));
                 
}
