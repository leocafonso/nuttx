/****************************************************************************
 * arch/arm/src/ra4m1/hardware/ra4m1_flash.h
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

#ifndef __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4M1_FLASH_H
#define __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4M1_FLASH_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <arch/ra4m1/chip.h>
#include "ra4m1_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* FCACHE register offsets ****************************************************/

                                          /* 0x0000-0x0100 Reserved */
#define RA4M1_FCACHEE_OFFSET       0x0100 /* Flash Cache Enable Register */
#define RA4M1_FCACHEIV_OFFSET      0x0104 /* Flash Cache Invalidate Register */

/* Register Addresses *******************************************************/

#define RA4M1_FCACHEE_REG              (R_FCACHE_BASE+RA4M1_FCACHEE_OFFSET)
#define RA4M1_FCACHEIV_REG             (R_FCACHE_BASE+RA4M1_FCACHEIV_OFFSET)

/* FCACHE register bit definitions ********************************************/

/* Flash Cache Enable Register (16-bit value) */
#define RA4M1_FCACHEEN         (1 << 0)  /* Bit 0: FCACHE Enable */

/* Flash Cache Enable Register (16-bit value) */
#define RA4M1_FCACHEIV         (1 << 0)  /* Bit 0: Flash Cache Invalidate */


#endif /* __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4M1_FLASH_H */