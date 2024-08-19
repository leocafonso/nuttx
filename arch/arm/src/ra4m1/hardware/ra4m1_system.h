/****************************************************************************
 * arch/arm/src/ra4m1/hardware/ra4m1_system.h
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

#ifndef __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4M1_SYSTEM_H
#define __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4M1_SYSTEM_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <arch/ra4m1/chip.h>
#include "ra4m1_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* SYSTEM register offsets ****************************************************/

#define RA4M1_PRCR_OFFSET       0x03FE /* Protect Register*/


/* Register Addresses *******************************************************/

#define RA4M1_PRCR_REG              (R_SYSTEM_BASE+RA4M1_PRCR_OFFSET)

/* SYSTEM register bit definitions ********************************************/

/* Protect Register (16-bit value) */
#define RA4M1_PRC0        (1 << 0)  /* Bit 0: Protect Bit 0 */
#define RA4M1_PRC1        (1 << 1)  /* Bit 1: Protect Bit 1 */
#define RA4M1_PRC3        (1 << 3)  /* Bit 3: Protect Bit 3 */
#define RA4M1_PRC3        (1 << 3)  /* Bit 3: Protect Bit 3 */
#define RA4M1_PRKEY_SHIFT (8)       /* Bit 8-15:  PRKEY*/


#endif /* __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4M1_SYSTEM_H */