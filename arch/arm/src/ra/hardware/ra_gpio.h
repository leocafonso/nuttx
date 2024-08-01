/****************************************************************************
 * arch/arm/src/ra/hardware/ra_gpio.h
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

#ifndef __ARCH_ARM_SRC_RA_HARDWARE_RA_GPIO_H
#define __ARCH_ARM_SRC_RA_HARDWARE_RA_GPIO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "chip.h"
#include "hardware/ra_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Register Offsets *********************************************************/

#define R_PORT_PCNTR1_OFFSET            0x0000  /* Port Control Register 1 (32-bits) */
#define R_PORT_PODR_OFFSET              0x0000  /* Pmn Output Data (16-bits) */
#define R_PORT_PDR_OFFSET               0x0002  /* Pmn Direction (16-bits) */
#define R_PORT_PCNTR2_OFFSET            0x0004  /* Port Control Register 2 (32-bits) */
#define R_PORT_EIDR_OFFSET              0x0004  /* Port Event Input Data (16-bits) */
#define R_PORT_PIDR_OFFSET              0x0006  /* Pmn State (16-bits) */
#define R_PORT_PCNTR3_OFFSET            0x0008  /* Port Control Register 3 (32-bits) */
#define R_PORT_PORR_OFFSET              0x0008  /* Pmn Output Reset (16-bits) */
#define R_PORT_POSR_OFFSET              0x000a  /* Pmn Output Set (16-bits) */
#define R_PORT_PCNTR4_OFFSET            0x000c  /* Port Control Register 3 (32-bits) */
#define R_PORT_EORR_OFFSET              0x000c  /* Pmn Event Output Set (16-bits) */
#define R_PORT_EOSR_OFFSET              0x000e  /* Pmn Output Reset (16-bits) */

/* Register Addresses *******************************************************/

/* PORT0 Registers */
#  define R_PORT0_PCNTR1          (R_PORT0_BASE + R_PORT_PCNTR1_OFFSET)
#  define R_PORT0_PODR            (R_PORT0_BASE + R_PORT_PODR_OFFSET)
#  define R_PORT0_PDR             (R_PORT0_BASE + R_PORT_PDR_OFFSET)
#  define R_PORT0_PCNTR2          (R_PORT0_BASE + R_PORT_PCNTR2_OFFSET)
#  define R_PORT0_EIDR            (R_PORT0_BASE + R_PORT_EIDR_OFFSET)
#  define R_PORT0_PIDR            (R_PORT0_BASE + R_PORT_PIDR_OFFSET)
#  define R_PORT0_PCNTR3          (R_PORT0_BASE + R_PORT_PCNTR3_OFFSET)
#  define R_PORT0_PORR            (R_PORT0_BASE + R_PORT_PORR_OFFSET)
#  define R_PORT0_POSR            (R_PORT0_BASE + R_PORT_POSR_OFFSET)
#  define R_PORT0_PCNTR4          (R_PORT0_BASE + R_PORT_PCNTR4_OFFSET)
#  define R_PORT0_EORR            (R_PORT0_BASE + R_PORT_EORR_OFFSET)
#  define R_PORT0_EOSR            (R_PORT0_BASE + R_PORT_EOSR_OFFSET)

/* PORT1 Registers */
#  define R_PORT1_PCNTR1          (R_PORT1_BASE + R_PORT_PCNTR1_OFFSET)
#  define R_PORT1_PODR            (R_PORT1_BASE + R_PORT_PODR_OFFSET)
#  define R_PORT1_PDR             (R_PORT1_BASE + R_PORT_PDR_OFFSET)
#  define R_PORT1_PCNTR2          (R_PORT1_BASE + R_PORT_PCNTR2_OFFSET)
#  define R_PORT1_EIDR            (R_PORT1_BASE + R_PORT_EIDR_OFFSET)
#  define R_PORT1_PIDR            (R_PORT1_BASE + R_PORT_PIDR_OFFSET)
#  define R_PORT1_PCNTR3          (R_PORT1_BASE + R_PORT_PCNTR3_OFFSET)
#  define R_PORT1_PORR            (R_PORT1_BASE + R_PORT_PORR_OFFSET)
#  define R_PORT1_POSR            (R_PORT1_BASE + R_PORT_POSR_OFFSET)
#  define R_PORT1_PCNTR4          (R_PORT1_BASE + R_PORT_PCNTR4_OFFSET)
#  define R_PORT1_EORR            (R_PORT1_BASE + R_PORT_EORR_OFFSET)
#  define R_PORT1_EOSR            (R_PORT1_BASE + R_PORT_EOSR_OFFSET)

/* PORT2 Registers */
#  define R_PORT2_PCNTR1          (R_PORT2_BASE + R_PORT_PCNTR1_OFFSET)
#  define R_PORT2_PODR            (R_PORT2_BASE + R_PORT_PODR_OFFSET)
#  define R_PORT2_PDR             (R_PORT2_BASE + R_PORT_PDR_OFFSET)
#  define R_PORT2_PCNTR2          (R_PORT2_BASE + R_PORT_PCNTR2_OFFSET)
#  define R_PORT2_EIDR            (R_PORT2_BASE + R_PORT_EIDR_OFFSET)
#  define R_PORT2_PIDR            (R_PORT2_BASE + R_PORT_PIDR_OFFSET)
#  define R_PORT2_PCNTR3          (R_PORT2_BASE + R_PORT_PCNTR3_OFFSET)
#  define R_PORT2_PORR            (R_PORT2_BASE + R_PORT_PORR_OFFSET)
#  define R_PORT2_POSR            (R_PORT2_BASE + R_PORT_POSR_OFFSET)
#  define R_PORT2_PCNTR4          (R_PORT2_BASE + R_PORT_PCNTR4_OFFSET)
#  define R_PORT2_EORR            (R_PORT2_BASE + R_PORT_EORR_OFFSET)
#  define R_PORT2_EOSR            (R_PORT2_BASE + R_PORT_EOSR_OFFSET)

/* PORT3 Registers */
#  define R_PORT3_PCNTR1          (R_PORT3_BASE + R_PORT_PCNTR1_OFFSET)
#  define R_PORT3_PODR            (R_PORT3_BASE + R_PORT_PODR_OFFSET)
#  define R_PORT3_PDR             (R_PORT3_BASE + R_PORT_PDR_OFFSET)
#  define R_PORT3_PCNTR2          (R_PORT3_BASE + R_PORT_PCNTR2_OFFSET)
#  define R_PORT3_EIDR            (R_PORT3_BASE + R_PORT_EIDR_OFFSET)
#  define R_PORT3_PIDR            (R_PORT3_BASE + R_PORT_PIDR_OFFSET)
#  define R_PORT3_PCNTR3          (R_PORT3_BASE + R_PORT_PCNTR3_OFFSET)
#  define R_PORT3_PORR            (R_PORT3_BASE + R_PORT_PORR_OFFSET)
#  define R_PORT3_POSR            (R_PORT3_BASE + R_PORT_POSR_OFFSET)
#  define R_PORT3_PCNTR4          (R_PORT3_BASE + R_PORT_PCNTR4_OFFSET)
#  define R_PORT3_EORR            (R_PORT3_BASE + R_PORT_EORR_OFFSET)
#  define R_PORT3_EOSR            (R_PORT3_BASE + R_PORT_EOSR_OFFSET)

/* PORT4 Registers */
#  define R_PORT4_PCNTR1          (R_PORT4_BASE + R_PORT_PCNTR1_OFFSET)
#  define R_PORT4_PODR            (R_PORT4_BASE + R_PORT_PODR_OFFSET)
#  define R_PORT4_PDR             (R_PORT4_BASE + R_PORT_PDR_OFFSET)
#  define R_PORT4_PCNTR2          (R_PORT4_BASE + R_PORT_PCNTR2_OFFSET)
#  define R_PORT4_EIDR            (R_PORT4_BASE + R_PORT_EIDR_OFFSET)
#  define R_PORT4_PIDR            (R_PORT4_BASE + R_PORT_PIDR_OFFSET)
#  define R_PORT4_PCNTR3          (R_PORT4_BASE + R_PORT_PCNTR3_OFFSET)
#  define R_PORT4_PORR            (R_PORT4_BASE + R_PORT_PORR_OFFSET)
#  define R_PORT4_POSR            (R_PORT4_BASE + R_PORT_POSR_OFFSET)
#  define R_PORT4_PCNTR4          (R_PORT4_BASE + R_PORT_PCNTR4_OFFSET)
#  define R_PORT4_EORR            (R_PORT4_BASE + R_PORT_EORR_OFFSET)
#  define R_PORT4_EOSR            (R_PORT4_BASE + R_PORT_EOSR_OFFSET)

/* PORT5 Registers */
#  define R_PORT5_PCNTR1          (R_PORT5_BASE + R_PORT_PCNTR1_OFFSET)
#  define R_PORT5_PODR            (R_PORT5_BASE + R_PORT_PODR_OFFSET)
#  define R_PORT5_PDR             (R_PORT5_BASE + R_PORT_PDR_OFFSET)
#  define R_PORT5_PCNTR2          (R_PORT5_BASE + R_PORT_PCNTR2_OFFSET)
#  define R_PORT5_EIDR            (R_PORT5_BASE + R_PORT_EIDR_OFFSET)
#  define R_PORT5_PIDR            (R_PORT5_BASE + R_PORT_PIDR_OFFSET)
#  define R_PORT5_PCNTR3          (R_PORT5_BASE + R_PORT_PCNTR3_OFFSET)
#  define R_PORT5_PORR            (R_PORT5_BASE + R_PORT_PORR_OFFSET)
#  define R_PORT5_POSR            (R_PORT5_BASE + R_PORT_POSR_OFFSET)
#  define R_PORT5_PCNTR4          (R_PORT5_BASE + R_PORT_PCNTR4_OFFSET)
#  define R_PORT5_EORR            (R_PORT5_BASE + R_PORT_EORR_OFFSET)
#  define R_PORT5_EOSR            (R_PORT5_BASE + R_PORT_EOSR_OFFSET)

/* PORT6 Registers */
#  define R_PORT6_PCNTR1          (R_PORT6_BASE + R_PORT_PCNTR1_OFFSET)
#  define R_PORT6_PODR            (R_PORT6_BASE + R_PORT_PODR_OFFSET)
#  define R_PORT6_PDR             (R_PORT6_BASE + R_PORT_PDR_OFFSET)
#  define R_PORT6_PCNTR2          (R_PORT6_BASE + R_PORT_PCNTR2_OFFSET)
#  define R_PORT6_EIDR            (R_PORT6_BASE + R_PORT_EIDR_OFFSET)
#  define R_PORT6_PIDR            (R_PORT6_BASE + R_PORT_PIDR_OFFSET)
#  define R_PORT6_PCNTR3          (R_PORT6_BASE + R_PORT_PCNTR3_OFFSET)
#  define R_PORT6_PORR            (R_PORT6_BASE + R_PORT_PORR_OFFSET)
#  define R_PORT6_POSR            (R_PORT6_BASE + R_PORT_POSR_OFFSET)
#  define R_PORT6_PCNTR4          (R_PORT6_BASE + R_PORT_PCNTR4_OFFSET)
#  define R_PORT6_EORR            (R_PORT6_BASE + R_PORT_EORR_OFFSET)
#  define R_PORT6_EOSR            (R_PORT6_BASE + R_PORT_EOSR_OFFSET)

/* PORT7 Registers */
#  define R_PORT7_PCNTR1          (R_PORT7_BASE + R_PORT_PCNTR1_OFFSET)
#  define R_PORT7_PODR            (R_PORT7_BASE + R_PORT_PODR_OFFSET)
#  define R_PORT7_PDR             (R_PORT7_BASE + R_PORT_PDR_OFFSET)
#  define R_PORT7_PCNTR2          (R_PORT7_BASE + R_PORT_PCNTR2_OFFSET)
#  define R_PORT7_EIDR            (R_PORT7_BASE + R_PORT_EIDR_OFFSET)
#  define R_PORT7_PIDR            (R_PORT7_BASE + R_PORT_PIDR_OFFSET)
#  define R_PORT7_PCNTR3          (R_PORT7_BASE + R_PORT_PCNTR3_OFFSET)
#  define R_PORT7_PORR            (R_PORT7_BASE + R_PORT_PORR_OFFSET)
#  define R_PORT7_POSR            (R_PORT7_BASE + R_PORT_POSR_OFFSET)
#  define R_PORT7_PCNTR4          (R_PORT7_BASE + R_PORT_PCNTR4_OFFSET)
#  define R_PORT7_EORR            (R_PORT7_BASE + R_PORT_EORR_OFFSET)
#  define R_PORT7_EOSR            (R_PORT7_BASE + R_PORT_EOSR_OFFSET)

/* PORT8 Registers */
#  define R_PORT8_PCNTR1          (R_PORT8_BASE + R_PORT_PCNTR1_OFFSET)
#  define R_PORT8_PODR            (R_PORT8_BASE + R_PORT_PODR_OFFSET)
#  define R_PORT8_PDR             (R_PORT8_BASE + R_PORT_PDR_OFFSET)
#  define R_PORT8_PCNTR2          (R_PORT8_BASE + R_PORT_PCNTR2_OFFSET)
#  define R_PORT8_EIDR            (R_PORT8_BASE + R_PORT_EIDR_OFFSET)
#  define R_PORT8_PIDR            (R_PORT8_BASE + R_PORT_PIDR_OFFSET)
#  define R_PORT8_PCNTR3          (R_PORT8_BASE + R_PORT_PCNTR3_OFFSET)
#  define R_PORT8_PORR            (R_PORT8_BASE + R_PORT_PORR_OFFSET)
#  define R_PORT8_POSR            (R_PORT8_BASE + R_PORT_POSR_OFFSET)
#  define R_PORT8_PCNTR4          (R_PORT8_BASE + R_PORT_PCNTR4_OFFSET)
#  define R_PORT8_EORR            (R_PORT8_BASE + R_PORT_EORR_OFFSET)
#  define R_PORT8_EOSR            (R_PORT8_BASE + R_PORT_EOSR_OFFSET)

/* PORT9 Registers */
#  define R_PORT9_PCNTR1          (R_PORT9_BASE + R_PORT_PCNTR1_OFFSET)
#  define R_PORT9_PODR            (R_PORT9_BASE + R_PORT_PODR_OFFSET)
#  define R_PORT9_PDR             (R_PORT9_BASE + R_PORT_PDR_OFFSET)
#  define R_PORT9_PCNTR2          (R_PORT9_BASE + R_PORT_PCNTR2_OFFSET)
#  define R_PORT9_EIDR            (R_PORT9_BASE + R_PORT_EIDR_OFFSET)
#  define R_PORT9_PIDR            (R_PORT9_BASE + R_PORT_PIDR_OFFSET)
#  define R_PORT9_PCNTR3          (R_PORT9_BASE + R_PORT_PCNTR3_OFFSET)
#  define R_PORT9_PORR            (R_PORT9_BASE + R_PORT_PORR_OFFSET)
#  define R_PORT9_POSR            (R_PORT9_BASE + R_PORT_POSR_OFFSET)
#  define R_PORT9_PCNTR4          (R_PORT9_BASE + R_PORT_PCNTR4_OFFSET)
#  define R_PORT9_EORR            (R_PORT9_BASE + R_PORT_EORR_OFFSET)
#  define R_PORT9_EOSR            (R_PORT9_BASE + R_PORT_EOSR_OFFSET)

/* Register Bitfield Definitions ********************************************/

/* Port Control Register 1 (32-bits) */

#define R_PORT1_PCNTR1_PODR_SHIFT               (16) /* 10000: Pmn Output Data */
#define R_PORT1_PCNTR1_PODR_MASK               (0xffff)
#define R_PORT1_PCNTR1_PDR_SHIFT                (0) /* 01: Pmn Direction */
#define R_PORT1_PCNTR1_PDR_MASK                (0xffff)

/* Pmn Output Data (16-bits) */

#define R_PORT1_PODR_PODR_SHIFT                 (0) /* 01: Pmn Output Data */
#define R_PORT1_PODR_PODR_MASK                 (0xffff)

/* Pmn Direction (16-bits) */

#define R_PORT1_PDR_PDR_SHIFT                   (0) /* 01: Pmn Direction */
#define R_PORT1_PDR_PDR_MASK                   (0xffff)

/* Port Control Register 2 (32-bits) */

#define R_PORT1_PCNTR2_EIDR_SHIFT               (16) /* 10000: Pmn Event Input Data */
#define R_PORT1_PCNTR2_EIDR_MASK               (0xffff)
#define R_PORT1_PCNTR2_PIDR_SHIFT               (0) /* 01: Pmn Input Data */
#define R_PORT1_PCNTR2_PIDR_MASK               (0xffff)

/* Port Event Input Data (16-bits) */

#define R_PORT1_EIDR_EIDR_SHIFT                 (0) /* 01: Pmn Event Input Data */
#define R_PORT1_EIDR_EIDR_MASK                 (0xffff)

/* Pmn State (16-bits) */

#define R_PORT1_PIDR_PIDR_SHIFT                 (0) /* 01: Pmn Input Data */
#define R_PORT1_PIDR_PIDR_MASK                 (0xffff)

/* Port Control Register 3 (32-bits) */

#define R_PORT1_PCNTR3_PORR_SHIFT               (16) /* 10000: Pmn Output Reset */
#define R_PORT1_PCNTR3_PORR_MASK               (0xffff)
#define R_PORT1_PCNTR3_POSR_SHIFT               (0) /* 01: Pmn Output Set */
#define R_PORT1_PCNTR3_POSR_MASK               (0xffff)

/* Pmn Output Reset (16-bits) */

#define R_PORT1_PORR_PORR_SHIFT                 (0) /* 01: Pmn Output Reset */
#define R_PORT1_PORR_PORR_MASK                 (0xffff)

/* Pmn Output Set (16-bits) */

#define R_PORT1_POSR_POSR_SHIFT                 (0) /* 01: Pmn Output Set */
#define R_PORT1_POSR_POSR_MASK                 (0xffff)

/* Port Control Register 3 (32-bits) */

#define R_PORT1_PCNTR4_EORR_SHIFT               (16) /* 10000: Pmn Event Output Reset */
#define R_PORT1_PCNTR4_EORR_MASK               (0xffff)
#define R_PORT1_PCNTR4_EOSR_SHIFT               (0) /* 01: Pmn Event Output Set */
#define R_PORT1_PCNTR4_EOSR_MASK               (0xffff)

/* Pmn Event Output Set (16-bits) */

#define R_PORT1_EORR_EORR_SHIFT                 (0) /* 01: Pmn Event Output Reset */
#define R_PORT1_EORR_EORR_MASK                 (0xffff)

/* Pmn Output Reset (16-bits) */

#define R_PORT1_EOSR_EOSR_SHIFT                 (0) /* 01: Pmn Event Output Set */
#define R_PORT1_EOSR_EOSR_MASK                 (0xffff)


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

#endif /* __ARCH_ARM_SRC_RA_HARDWARE_RA_GPIO_H */
