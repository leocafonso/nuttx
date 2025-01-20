/****************************************************************************
 * boards/arm/sam34/arduino-due/include/board.h
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

#ifndef __BOARDS_ARM_RA_ARDUINO_UNO_R4_INCLUDE_BOARD_H
#define __BOARDS_ARM_RA_ARDUINO_UNO_R4_INCLUDE_BOARD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Clocking *****************************************************************/

/* 
 * This is the canonical configuration:
 *   System Clock source      : HOCO 
 *   ICLK(Hz)                 : 32000000   
 *   PCLKA(Hz)                : 32000000    
 *   PCLKB(Hz)                : 32000000            
 *   PCLKC(Hz)                : 32000000            
 *   PCLKD(Hz)                : 32000000  
 *   FCLK(Hz)                 : 32000000 
 *   USBCLK(Hz)               : 0 
 */

/* HOCO - 24 MHz RC factory-trimmed
 * LOCO - 32 KHz RC
 */

#define RA_HOCO_FREQUENCY     32000000ul
#define RA_LOCO_FREQUENCY     32768ul
#define RA_MOCO_FREQUENCY     8000000ul

#define RA_HOCOEN     1

/* Clocks divisor are  1/2^n where n can go from 0 to 6*/

#define RA_FCK_DIV       0
#define RA_ICK_DIV       0
#define RA_PCKA_DIV      0
#define RA_PCKB_DIV      0
#define RA_PCKC_DIV      0
#define RA_PCKD_DIV      0

#endif /* __BOARDS_ARM_RA_ARDUINO_UNO_R4_INCLUDE_BOARD_H */
