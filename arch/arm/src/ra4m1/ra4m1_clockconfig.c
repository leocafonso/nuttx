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

/****************************************************************************
 * Pre-processor Definitions
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
 
}
