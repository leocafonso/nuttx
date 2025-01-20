/****************************************************************************
 * arch/arm/src/ra4m1/hardware/ra4m1_mstp.h
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

#ifndef __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4_MSTP_H
#define __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4_MSTP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "chip.h"
#include "hardware/ra4m1_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/


/* MSTP - Module Stop Control B,C,D */
#define R_MSTP_MSTPCRB_OFFSET             0x0000
#define R_MSTP_MSTPCRB                    (R_MSTP_BASE + R_MSTP_MSTPCRB_OFFSET)
#define R_MSTP_MSTPCRB_MSTPB31            (1 << 31) /* 80000000: Serial Communication Interface 0 Module Stop */
#define R_MSTP_MSTPCRB_MSTPB30            (1 << 30) /* 40000000: Serial Communication Interface 1 Module Stop */
#define R_MSTP_MSTPCRB_MSTPB29            (1 << 29) /* 20000000: Serial Communication Interface 2 Module Stop */
#define R_MSTP_MSTPCRB_MSTPB22            (1 << 22) /* 400000: Serial Communication Interface 9 Module Stop */
#define R_MSTP_MSTPCRB_MSTPB19            (1 << 19) /* 80000: Serial Peripheral Interface 0 Module Stop */
#define R_MSTP_MSTPCRB_MSTPB18            (1 << 18) /* 40000: Serial Peripheral Interface 1 Module Stop */
#define R_MSTP_MSTPCRB_MSTPB11            (1 << 11) /* 800: Universal Serial Bus 2.0 FS Interface Module Stop */
#define R_MSTP_MSTPCRB_MSTPB9             (1 <<  9) /* 200: I2C Bus Interface 0 Module Stop */
#define R_MSTP_MSTPCRB_MSTPB8             (1 <<  8) /* 100: I2C Bus Interface 1 Module Stop */
#define R_MSTP_MSTPCRB_MSTPB2             (1 <<  2) /* 04: Controller Area Network Module Stop */
#define R_MSTP_MSTPCRC_OFFSET             0x0004
#define R_MSTP_MSTPCRC                    (R_MSTP_BASE + R_MSTP_MSTPCRC_OFFSET)
#define R_MSTP_MSTPCRC_MSTPC31            (1 << 31) /* 80000000: SCE5 Module Stop */
#define R_MSTP_MSTPCRC_MSTPC14            (1 << 14) /* 4000: Event Link Controller Module Stop */
#define R_MSTP_MSTPCRC_MSTPC13            (1 << 13) /* 2000: Data Operation Circuit Module Stop */
#define R_MSTP_MSTPCRC_MSTPC8             (1 <<  8) /* 100: Synchronous Serial Interface 0 Module Stop */
#define R_MSTP_MSTPCRC_MSTPC4             (1 <<  4) /* 10: Segment LCD Controller Module Stop */
#define R_MSTP_MSTPCRC_MSTPC3             (1 <<  3) /* 08: Capacitive Touch Sensing Unit Module Stop */
#define R_MSTP_MSTPCRC_MSTPC1             (1 <<  1) /* 02: Cyclic Redundancy Check Calculator Module Stop */
#define R_MSTP_MSTPCRC_MSTPC0             (1 <<  0) /* 01: Clock Frequency Accuracy Measurement Circuit Module Stop */
#define R_MSTP_MSTPCRD_OFFSET             0x0008
#define R_MSTP_MSTPCRD                    (R_MSTP_BASE + R_MSTP_MSTPCRD_OFFSET)
#define R_MSTP_MSTPCRD_MSTPD31            (1 << 31) /* 80000000: Operational Amplifier Module Stop */
#define R_MSTP_MSTPCRD_MSTPD29            (1 << 29) /* 20000000: Low-Power Analog Comparator Module Stop */
#define R_MSTP_MSTPCRD_MSTPD20            (1 << 20) /* 100000: 12-Bit D/A Converter Module Stop */
#define R_MSTP_MSTPCRD_MSTPD19            (1 << 19) /* 80000: 8-bit D/A Converter Module Stop */
#define R_MSTP_MSTPCRD_MSTPD16            (1 << 16) /* 10000: 14-Bit A/D Converter Module Stop */
#define R_MSTP_MSTPCRD_MSTPD14            (1 << 14) /* 4000: Port Output Enable for GPT Module Stop */
#define R_MSTP_MSTPCRD_MSTPD6             (1 <<  6) /* 40: General PWM Timer 169 to 164 Module Stop */
#define R_MSTP_MSTPCRD_MSTPD5             (1 <<  5) /* 20: General PWM Timer 323 to 320 Module Stop */
#define R_MSTP_MSTPCRD_MSTPD3             (1 <<  3) /* 08: Asynchronous General Purpose Timer 0 Module Stop */
#define R_MSTP_MSTPCRD_MSTPD2             (1 <<  2) /* 04: Asynchronous General Purpose Timer 1 Module Stop */

/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Public Functions Prototypes
 ****************************************************************************/

#endif /* __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4_MSTP_H */

