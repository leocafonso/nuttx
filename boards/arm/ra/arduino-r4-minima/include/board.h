/****************************************************************************
 * boards/arm/rA/arduino-r4-minima/include/board.h
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

/* HOCO - 32 MHz RC factory-trimmed
 */



/* Clock selection HOCO, MOCO, LOCO, PLL*/

#define RA_CKSEL  R_SYSTEM_SCKSCR_CKSEL_HOCO

#define RA_HOCOEN     !R_OFS1_HOCOEN /* Inverted logic to enable */
#define RA_HOCO_FREQUENCY  R_OFS1_HOCOFRQ1_32MHZ



#define RA_ICK_DIV       R_SYSTEM_SCKDIVCR_ICK_DIV_1
#define RA_ICLK_FREQUENCY  32000000
#define RA_FCK_DIV       R_SYSTEM_SCKDIVCR_FCK_DIV_1
#define RA_FCK_FREQUENCY  32000000
#define RA_PCKA_DIV      R_SYSTEM_SCKDIVCR_PCKA_DIV_1
#define RA_PCKA_FREQUENCY  32000000
#define RA_PCKB_DIV      R_SYSTEM_SCKDIVCR_PCKB_DIV_1
#define RA_PCKB_FREQUENCY  32000000
#define RA_PCKC_DIV      R_SYSTEM_SCKDIVCR_PCKC_DIV_1
#define RA_PCKC_FREQUENCY  32000000
#define RA_PCKD_DIV      R_SYSTEM_SCKDIVCR_PCKD_DIV_1
#define RA_PCKD_FREQUENCY  32000000



/* Alternate function pin selections ****************************************/

#define GPIO_SCI2_RX   GPIO_RXD2_MISO2_SCL2_1  /* P301 */
#define GPIO_SCI2_TX   GPIO_TXD2_MOSI2_SDA2_1  /* P302 */

#define GPIO_SCI1_RX   GPIO_RXD1_MISO1_SCL1_3  /* P502 */
#define GPIO_SCI1_TX   GPIO_TXD1_MOSI1_SDA1_3  /* P501 */

#define GPIO_SCI9_RX   GPIO_RXD9_MISO9_SCL9_1  /* P110 */
#define GPIO_SCI9_TX   GPIO_TXD9_MOSI9_SDA9_1  /* P109 */

/* ID_CODE ****************************************/

#define IDCODE1   0xFFFFFFFF  
#define IDCODE2   0xFFFFFFFF  
#define IDCODE3   0xFFFFFFFF  
#define IDCODE4   0xFFFFFFFF  


#endif /* __BOARDS_ARM_RA_ARDUINO_UNO_R4_INCLUDE_BOARD_H */
