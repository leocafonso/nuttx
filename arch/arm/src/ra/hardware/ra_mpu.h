/****************************************************************************
 * arch/arm/src/ra/hardware/ra_mpu.h
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

#ifndef __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4M1_MPU_H
#define __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4M1_MPU_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <arch/ra4m1/chip.h>
#include "ra4m1_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* MMPU - Bus Master MPU */
#define R_MMPU_MMPUCTLA_OFFSET            0x0000
#define R_MMPU_MMPUCTLA                   (R_MMPU_BASE + R_MMPU_MMPUCTLA_OFFSET)
#define R_MMPU_MMPUCTLA_KEY               (8 <<  8) /* 100: Key Code These bits are used to enable or disable writing of the OAD and ENABLE bit. */
#define R_MMPU_MMPUCTLA_KEY_MASK               (0xff)
#define R_MMPU_MMPUCTLA_OAD               (1 <<  1) /* 02: Operation after detection */
#define R_MMPU_MMPUCTLA_ENABLE            (1 <<  0) /* 01: Master Group enable */
#define R_MMPU_MMPUACA_SIZE               16
#define R_MMPU_MMPUACA_OFFSET             0x0200
#define R_MMPU_MMPUACA(p)                 (R_MMPU_BASE + R_MMPU_MMPUACA_OFFSET + (p)*0x0010)
#define R_MMPU_MMPUACA_WP                 (1 <<  2) /* 04: Write protection */
#define R_MMPU_MMPUACA_RP                 (1 <<  1) /* 02: Read protection */
#define R_MMPU_MMPUACA_ENABLE             (1 <<  0) /* 01: Region enable */
#define R_MMPU_MMPUSA_SIZE                16
#define R_MMPU_MMPUSA_OFFSET              0x0204
#define R_MMPU_MMPUSA(p)                  (R_MMPU_BASE + R_MMPU_MMPUSA_OFFSET + (p)*0x0010)
#define R_MMPU_MMPUSA_MMPUSA              (32 <<  0) /* 01: Address where the region starts, for use in region determination. NOTE: The low-order 2 bits are fixed to 0. */
#define R_MMPU_MMPUSA_MMPUSA_MASK              (0xffffffff)
#define R_MMPU_MMPUEA_SIZE                16
#define R_MMPU_MMPUEA_OFFSET              0x0208
#define R_MMPU_MMPUEA(p)                  (R_MMPU_BASE + R_MMPU_MMPUEA_OFFSET + (p)*0x0010)
#define R_MMPU_MMPUEA_MMPUEA              (32 <<  0) /* 01: Region end address register Address where the region end, for use in region determination. NOTE: The low-order 2 bits are fixed to 1. */
#define R_MMPU_MMPUEA_MMPUEA_MASK              (0xffffffff)
#define R_MMPU_MMPUPTA_OFFSET             0x0102
#define R_MMPU_MMPUPTA                    (R_MMPU_BASE + R_MMPU_MMPUPTA_OFFSET)
#define R_MMPU_MMPUPTA_KEY                (8 <<  8) /* 100: Write Keyword The data written to these bits are not stored. */
#define R_MMPU_MMPUPTA_KEY_MASK                (0xff)
#define R_MMPU_MMPUPTA_PROTECT            (1 <<  0) /* 01: Protection of register (MMPUSAn, MMPUEAn and MMPUACAn) */

/* SMPU - Bus Slave MPU */
#define R_SMPU_SMPUCTL_OFFSET             0x0000
#define R_SMPU_SMPUCTL                    (R_SMPU_BASE + R_SMPU_SMPUCTL_OFFSET)
#define R_SMPU_SMPUCTL_KEY                (8 <<  8) /* 100: Key Code This bit is used to enable or disable rewriting of the PROTECT and OAD bit. */
#define R_SMPU_SMPUCTL_KEY_MASK                (0xff)
#define R_SMPU_SMPUCTL_PROTECT            (1 <<  1) /* 02: Protection of register */
#define R_SMPU_SMPUCTL_OAD                (1 <<  0) /* 01: Master Group enable */
#define R_SMPU_SMPUMBIU_OFFSET            0x0010
#define R_SMPU_SMPUMBIU                   (R_SMPU_BASE + R_SMPU_SMPUMBIU_OFFSET)
#define R_SMPU_SMPUMBIU_WPGRPA            (1 <<  3) /* 08: Master Group A Write protection */
#define R_SMPU_SMPUMBIU_RPGRPA            (1 <<  2) /* 04: Master Group A Read protection */
#define R_SMPU_SMPUFBIU_OFFSET            0x0014
#define R_SMPU_SMPUFBIU                   (R_SMPU_BASE + R_SMPU_SMPUFBIU_OFFSET)
#define R_SMPU_SMPUFBIU_WPGRPA            (1 <<  3) /* 08: Master Group A Write protection */
#define R_SMPU_SMPUFBIU_RPGRPA            (1 <<  2) /* 04: Master Group A Read protection */
#define R_SMPU_SMPUFBIU_WPCPU             (1 <<  1) /* 02: CPU Write protection */
#define R_SMPU_SMPUFBIU_RPCPU             (1 <<  0) /* 01: CPU Read protection */
#define R_SMPU_SMPUSRAM0_OFFSET           0x0018
#define R_SMPU_SMPUSRAM0                  (R_SMPU_BASE + R_SMPU_SMPUSRAM0_OFFSET)
#define R_SMPU_SMPUSRAM0_WPGRPA           (1 <<  3) /* 08: Master Group A Write protection */
#define R_SMPU_SMPUSRAM0_RPGRPA           (1 <<  2) /* 04: Master Group A Read protection */
#define R_SMPU_SMPUSRAM0_WPCPU            (1 <<  1) /* 02: CPU Write protection */
#define R_SMPU_SMPUSRAM0_RPCPU            (1 <<  0) /* 01: CPU Read protection */
#define R_SMPU_SMPUPBIU_SIZE              3
#define R_SMPU_SMPUPBIU_OFFSET            0x0020
#define R_SMPU_SMPUPBIU(p)                (R_SMPU_BASE + R_SMPU_SMPUPBIU_OFFSET + (p)*0x0004)
#define R_SMPU_SMPUPBIU_WPGRPA            (1 <<  3) /* 08: Master Group A Write protection */
#define R_SMPU_SMPUPBIU_RPGRPA            (1 <<  2) /* 04: Master Group A Read protection */
#define R_SMPU_SMPUPBIU_WPCPU             (1 <<  1) /* 02: CPU Write protection */
#define R_SMPU_SMPUPBIU_RPCPU             (1 <<  0) /* 01: CPU Read protection */

/* SPMON - CPU Stack Pointer Monitor */
#define R_SPMON_MSPMPUOAD_OFFSET          0x0000
#define R_SPMON_MSPMPUOAD                 (R_SPMON_BASE + R_SPMON_MSPMPUOAD_OFFSET)
#define R_SPMON_MSPMPUOAD_KEY             (8 <<  8) /* 100: Write Keyword The data written to these bits are not stored. */
#define R_SPMON_MSPMPUOAD_KEY_MASK             (0xff)
#define R_SPMON_MSPMPUOAD_OAD             (1 <<  0) /* 01: Operation after detection */
#define R_SPMON_MSPMPUCTL_OFFSET          0x0004
#define R_SPMON_MSPMPUCTL                 (R_SPMON_BASE + R_SPMON_MSPMPUCTL_OFFSET)
#define R_SPMON_MSPMPUCTL_ERROR           (1 <<  8) /* 100: Stack Pointer Monitor Error Flag */
#define R_SPMON_MSPMPUCTL_ENABLE          (1 <<  0) /* 01: Stack Pointer Monitor Enable */
#define R_SPMON_MSPMPUPT_OFFSET           0x0006
#define R_SPMON_MSPMPUPT                  (R_SPMON_BASE + R_SPMON_MSPMPUPT_OFFSET)
#define R_SPMON_MSPMPUPT_KEY              (8 <<  8) /* 100: Write Keyword The data written to these bits are not stored. */
#define R_SPMON_MSPMPUPT_KEY_MASK              (0xff)
#define R_SPMON_MSPMPUPT_PROTECT          (1 <<  0) /* 01: Protection of register (MSPMPUAC, MSPMPUSA and MSPMPUSE) */
#define R_SPMON_MSPMPUSA_OFFSET           0x0008
#define R_SPMON_MSPMPUSA                  (R_SPMON_BASE + R_SPMON_MSPMPUSA_OFFSET)
#define R_SPMON_MSPMPUSA_MSPMPUSA         (32 <<  0) /* 01: Region start address register Address where the region starts, for use in region determination. NOTE: Range: 0x1FF00000-0x200FFFFC The low-order 2 bits are fixed to 0. */
#define R_SPMON_MSPMPUSA_MSPMPUSA_MASK         (0xffffffff)
#define R_SPMON_MSPMPUEA_OFFSET           0x000c
#define R_SPMON_MSPMPUEA                  (R_SPMON_BASE + R_SPMON_MSPMPUEA_OFFSET)
#define R_SPMON_MSPMPUEA_MSPMPUEA         (32 <<  0) /* 01: Region end address register Address where the region starts, for use in region determination. NOTE: Range: 0x1FF00003-0x200FFFFF The low-order 2 bits are fixed to 1. */
#define R_SPMON_MSPMPUEA_MSPMPUEA_MASK         (0xffffffff)
#define R_SPMON_PSPMPUOAD_OFFSET          0x0010
#define R_SPMON_PSPMPUOAD                 (R_SPMON_BASE + R_SPMON_PSPMPUOAD_OFFSET)
#define R_SPMON_PSPMPUOAD_KEY             (8 <<  8) /* 100: Key Code The data written to these bits are not stored. */
#define R_SPMON_PSPMPUOAD_KEY_MASK             (0xff)
#define R_SPMON_PSPMPUOAD_OAD             (1 <<  0) /* 01: Operation after detection */
#define R_SPMON_PSPMPUCTL_OFFSET          0x0014
#define R_SPMON_PSPMPUCTL                 (R_SPMON_BASE + R_SPMON_PSPMPUCTL_OFFSET)
#define R_SPMON_PSPMPUCTL_ERROR           (1 <<  8) /* 100: Stack Pointer Monitor Error Flag */
#define R_SPMON_PSPMPUCTL_ENABLE          (1 <<  0) /* 01: Stack Pointer Monitor Enable */
#define R_SPMON_PSPMPUPT_OFFSET           0x0016
#define R_SPMON_PSPMPUPT                  (R_SPMON_BASE + R_SPMON_PSPMPUPT_OFFSET)
#define R_SPMON_PSPMPUPT_KEY              (8 <<  8) /* 100: Key Code The data written to these bits are not stored. */
#define R_SPMON_PSPMPUPT_KEY_MASK              (0xff)
#define R_SPMON_PSPMPUPT_PROTECT          (1 <<  0) /* 01: Protection register (PSPMPUAC, PSPMPUSA and PSPMPUSE) */
#define R_SPMON_PSPMPUSA_OFFSET           0x0018
#define R_SPMON_PSPMPUSA                  (R_SPMON_BASE + R_SPMON_PSPMPUSA_OFFSET)
#define R_SPMON_PSPMPUSA_PSPMPUSA         (32 <<  0) /* 01: Region start address register Address where the region starts, for use in region determination. NOTE: Range: 0x1FF00000-0x200FFFFC The low-order 2 bits are fixed to 0. */
#define R_SPMON_PSPMPUSA_PSPMPUSA_MASK         (0xffffffff)
#define R_SPMON_PSPMPUEA_OFFSET           0x001c
#define R_SPMON_PSPMPUEA                  (R_SPMON_BASE + R_SPMON_PSPMPUEA_OFFSET)
#define R_SPMON_PSPMPUEA_PSPMPUEA         (32 <<  0) /* 01: Region end address register Address where the region starts, for use in region determination. NOTE: Range: 0x1FF00003-0x200FFFFF The low-order 2 bits are fixed to 1. */
#define R_SPMON_PSPMPUEA_PSPMPUEA_MASK         (0xffffffff)

#endif /* __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4M1_FLASH_H */
