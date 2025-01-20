/****************************************************************************
 * arch/arm/src/sam34/hardware/sam_uart.h
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

#ifndef __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4_GPIO_H
#define __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4_GPIO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "chip.h"
#include "hardware/ra4m1_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define R_PORT_PCNTR1_OFFSET             0x0000
#define R_PCNTR1_PORT(p)                 (R_PORT0_BASE + (p)*0x20 + R_PORT_PCNTR1_OFFSET)
#define R_PORT_PCNTR1_PODR               (16 << 16) /* 10000: Pmn Output Data */
#define R_PORT_PCNTR1_PODR_MASK          (0xffff)
#define R_PORT_PCNTR1_PDR                (16 <<  0) /* 01: Pmn Direction */
#define R_PORT_PCNTR1_PDR_MASK           (0xffff)

#define R_PORT_PCNTR2_OFFSET             0x0004
#define R_PCNTR2_PORT(p)                 (R_PORT0_BASE + (p)*0x20 + R_PORT_PCNTR2_OFFSET)
#define R_PORT_PCNTR2_EIDR               (16 << 16) /* 10000: Pmn Event Input Data */
#define R_PORT_PCNTR2_EIDR_MASK          (0xffff)
#define R_PORT_PCNTR2_PIDR               (16 <<  0) /* 01: Pmn Input Data */
#define R_PORT_PCNTR2_PIDR_MASK          (0xffff)

#define R_PORT_PCNTR3_OFFSET             0x0008
#define R_PCNTR3_PORT(p)                 (R_PORT0_BASE + (p)*0x20 + R_PORT_PCNTR3_OFFSET)
#define R_PORT0_PCNTR3_PORR              (16 << 16) /* 10000: Pmn Output Reset */
#define R_PORT0_PCNTR3_PORR_MASK         (0xffff)
#define R_PORT0_PCNTR3_POSR              (16 <<  0) /* 01: Pmn Output Set */
#define R_PORT0_PCNTR3_POSR_MASK         (0xffff)

#define R_PORT_PCNTR4_OFFSET             0x000c
#define R_PCNTR4_PORT(p)                 (R_PORT0_BASE + (p)*0x20 + R_PORT_PCNTR4_OFFSET)
#define R_PORT_PCNTR4_EORR               (16 << 16) /* 10000: Pmn Event Output Reset */
#define R_PORT_PCNTR4_EORR_MASK          (0xffff)
#define R_PORT_PCNTR4_EOSR               (16 <<  0) /* 01: Pmn Event Output Set */
#define R_PORT_PCNTR4_EOSR_MASK          (0xffff)

/* PFS - Pmn Pin Function Control Register */
#define R_PFS(port,pin)           (R_PFS_BASE + (port)*0x40 + (pin)*0x04)
#define R_PFS_PSEL_SHIFT          (24) /* 1000000: Port Function Select These bits select the peripheral function. For individual pin functions, see the MPC table */
#define R_PFS_PSEL_MASK           (0x1f)
#define R_PFS_PMR                 (1 << 16) /* 10000: Port Mode Control */
#define R_PFS_ASEL                (1 << 15) /* 8000: Analog Input enable */
#define R_PFS_ISEL                (1 << 14) /* 4000: IRQ input enable */
#define R_PFS_DSCR                (1 << 10) /* 400: Port Drive Capability */
#define R_PFS_NCODR               (1 <<  6) /* 40: N-Channel Open Drain Control */
#define R_PFS_PCR                 (1 <<  4) /* 10: Pull-up Control */
#define R_PFS_PDR                 (1 <<  2) /* 04: Port Direction */
#define R_PFS_PIDR                (1 <<  1) /* 02: Port Input Data */
#define R_PFS_PODR                (1 <<  0) /* 01: Port Output Data */

/* PMISC - Miscellaneous Port Control Register */
#define R_PMISC_PWPR_OFFSET               0x0003
#define R_PMISC_PWPR                      (R_PMISC_BASE + R_PMISC_PWPR_OFFSET)
#define R_PMISC_PWPR_B0WI                 (1 <<  7) /* 80: PFSWE Bit Write Disable */
#define R_PMISC_PWPR_PFSWE                (1 <<  6) /* 40: PFS Register Write Enable */


/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Public Functions Prototypes
 ****************************************************************************/

#endif /* __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4_GPIO_H */
