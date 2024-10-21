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

#ifndef __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4_SCI_H
#define __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4_SCI_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "chip.h"
#include "hardware/ra4m1_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* SCI0 - Serial Communication Interface 0 */
#define R_SCI0_SMR_OFFSET                 0x0000
#define R_SCI0_SMR                        (R_SCI0_BASE + R_SCI0_SMR_OFFSET)
#define R_SCI0_SMR_CM                     (1 <<  7) /* 80: Communication Mode */
#define R_SCI0_SMR_CHR                    (1 <<  6) /* 40: Character Length (Valid only in asynchronous mode) */
#define R_SCI0_SMR_PE                     (1 <<  5) /* 20: Parity Enable (Valid only in asynchronous mode) */
#define R_SCI0_SMR_PM                     (1 <<  4) /* 10: Parity Mode (Valid only when the PE bit is 1) */
#define R_SCI0_SMR_STOP                   (1 <<  3) /* 08: Stop Bit Length (Valid only in asynchronous mode) */
#define R_SCI0_SMR_MP                     (1 <<  2) /* 04: Multi-Processor Mode (Valid only in asynchronous mode) */
#define R_SCI0_SMR_CKS                    (2 <<  0) /* 01: Clock Select */
#define R_SCI0_SMR_CKS_MASK                    (0x03)
#define R_SCI0_SMR_SMCI_OFFSET            0x0000
#define R_SCI0_SMR_SMCI                   (R_SCI0_BASE + R_SCI0_SMR_SMCI_OFFSET)
#define R_SCI0_SMR_SMCI_GM                (1 <<  7) /* 80: GSM Mode */
#define R_SCI0_SMR_SMCI_BLK               (1 <<  6) /* 40: Block Transfer Mode */
#define R_SCI0_SMR_SMCI_PE                (1 <<  5) /* 20: Parity Enable (Valid only in asynchronous mode) */
#define R_SCI0_SMR_SMCI_PM                (1 <<  4) /* 10: Parity Mode (Valid only when the PE bit is 1) */
#define R_SCI0_SMR_SMCI_BCP               (2 <<  2) /* 04: Base Clock Pulse (Valid only in asynchronous mode) */
#define R_SCI0_SMR_SMCI_BCP_MASK               (0x03)
#define R_SCI0_SMR_SMCI_CKS               (2 <<  0) /* 01: Clock Select */
#define R_SCI0_SMR_SMCI_CKS_MASK               (0x03)
#define R_SCI0_BRR_OFFSET                 0x0001
#define R_SCI0_BRR                        (R_SCI0_BASE + R_SCI0_BRR_OFFSET)
#define R_SCI0_BRR_BRR                    (8 <<  0) /* 01: BRR is an 8-bit register that adjusts the bit rate. */
#define R_SCI0_BRR_BRR_MASK                    (0xff)
#define R_SCI0_SCR_OFFSET                 0x0002
#define R_SCI0_SCR                        (R_SCI0_BASE + R_SCI0_SCR_OFFSET)
#define R_SCI0_SCR_TIE                    (1 <<  7) /* 80: Transmit Interrupt Enable */
#define R_SCI0_SCR_RIE                    (1 <<  6) /* 40: Receive Interrupt Enable */
#define R_SCI0_SCR_TE                     (1 <<  5) /* 20: Transmit Enable */
#define R_SCI0_SCR_RE                     (1 <<  4) /* 10: Receive Enable */
#define R_SCI0_SCR_MPIE                   (1 <<  3) /* 08: Multi-Processor Interrupt Enable (Valid in asynchronous mode when SMR.MP = 1) */
#define R_SCI0_SCR_TEIE                   (1 <<  2) /* 04: Transmit End Interrupt Enable */
#define R_SCI0_SCR_CKE                    (2 <<  0) /* 01: Clock Enable */
#define R_SCI0_SCR_CKE_MASK                    (0x03)
#define R_SCI0_SCR_SMCI_OFFSET            0x0002
#define R_SCI0_SCR_SMCI                   (R_SCI0_BASE + R_SCI0_SCR_SMCI_OFFSET)
#define R_SCI0_SCR_SMCI_TIE               (1 <<  7) /* 80: Transmit Interrupt Enable */
#define R_SCI0_SCR_SMCI_RIE               (1 <<  6) /* 40: Receive Interrupt Enable */
#define R_SCI0_SCR_SMCI_TE                (1 <<  5) /* 20: Transmit Enable */
#define R_SCI0_SCR_SMCI_RE                (1 <<  4) /* 10: Receive Enable */
#define R_SCI0_SCR_SMCI_MPIE              (1 <<  3) /* 08: Multi-Processor Interrupt Enable */
#define R_SCI0_SCR_SMCI_TEIE              (1 <<  2) /* 04: Transmit End Interrupt Enable */
#define R_SCI0_SCR_SMCI_CKE               (2 <<  0) /* 01: Clock Enable */
#define R_SCI0_SCR_SMCI_CKE_MASK               (0x03)
#define R_SCI0_TDR_OFFSET                 0x0003
#define R_SCI0_TDR                        (R_SCI0_BASE + R_SCI0_TDR_OFFSET)
#define R_SCI0_TDR_TDR                    (8 <<  0) /* 01: TDR is an 8-bit register that stores transmit data. */
#define R_SCI0_TDR_TDR_MASK                    (0xff)
#define R_SCI0_SSR_OFFSET                 0x0004
#define R_SCI0_SSR                        (R_SCI0_BASE + R_SCI0_SSR_OFFSET)
#define R_SCI0_SSR_TDRE                   (1 <<  7) /* 80: Transmit Data Empty Flag */
#define R_SCI0_SSR_RDRF                   (1 <<  6) /* 40: Receive Data Full Flag */
#define R_SCI0_SSR_ORER                   (1 <<  5) /* 20: Overrun Error Flag */
#define R_SCI0_SSR_FER                    (1 <<  4) /* 10: Framing Error Flag */
#define R_SCI0_SSR_PER                    (1 <<  3) /* 08: Parity Error Flag */
#define R_SCI0_SSR_TEND                   (1 <<  2) /* 04: Transmit End Flag */
#define R_SCI0_SSR_MPB                    (1 <<  1) /* 02: Multi-Processor */
#define R_SCI0_SSR_MPBT                   (1 <<  0) /* 01: Multi-Processor Bit Transfer */
#define R_SCI0_SSR_FIFO_OFFSET            0x0004
#define R_SCI0_SSR_FIFO                   (R_SCI0_BASE + R_SCI0_SSR_FIFO_OFFSET)
#define R_SCI0_SSR_FIFO_TDFE              (1 <<  7) /* 80: Transmit FIFO data empty flag */
#define R_SCI0_SSR_FIFO_RDF               (1 <<  6) /* 40: Receive FIFO data full flag */
#define R_SCI0_SSR_FIFO_ORER              (1 <<  5) /* 20: Overrun Error Flag */
#define R_SCI0_SSR_FIFO_FER               (1 <<  4) /* 10: Framing Error Flag */
#define R_SCI0_SSR_FIFO_PER               (1 <<  3) /* 08: Parity Error Flag */
#define R_SCI0_SSR_FIFO_TEND              (1 <<  2) /* 04: Transmit End Flag */
#define R_SCI0_SSR_FIFO_DR                (1 <<  0) /* 01: Receive Data Ready flag (Valid only in asynchronous mode(including multi-processor) and FIFO selected) */
#define R_SCI0_SSR_SMCI_OFFSET            0x0004
#define R_SCI0_SSR_SMCI                   (R_SCI0_BASE + R_SCI0_SSR_SMCI_OFFSET)
#define R_SCI0_SSR_SMCI_TDRE              (1 <<  7) /* 80: Transmit Data Empty Flag */
#define R_SCI0_SSR_SMCI_RDRF              (1 <<  6) /* 40: Receive Data Full Flag */
#define R_SCI0_SSR_SMCI_ORER              (1 <<  5) /* 20: Overrun Error Flag */
#define R_SCI0_SSR_SMCI_ERS               (1 <<  4) /* 10: Error Signal Status Flag */
#define R_SCI0_SSR_SMCI_PER               (1 <<  3) /* 08: Parity Error Flag */
#define R_SCI0_SSR_SMCI_TEND              (1 <<  2) /* 04: Transmit End Flag */
#define R_SCI0_SSR_SMCI_MPB               (1 <<  1) /* 02: Multi-Processor This bit should be 0 in smart card interface mode. */
#define R_SCI0_SSR_SMCI_MPBT              (1 <<  0) /* 01: Multi-Processor Bit Transfer This bit should be 0 in smart card interface mode. */
#define R_SCI0_RDR_OFFSET                 0x0005
#define R_SCI0_RDR                        (R_SCI0_BASE + R_SCI0_RDR_OFFSET)
#define R_SCI0_RDR_RDR                    (8 <<  0) /* 01: RDR is an 8-bit register that stores receive data. */
#define R_SCI0_RDR_RDR_MASK                    (0xff)
#define R_SCI0_SCMR_OFFSET                0x0006
#define R_SCI0_SCMR                       (R_SCI0_BASE + R_SCI0_SCMR_OFFSET)
#define R_SCI0_SCMR_BCP2                  (1 <<  7) /* 80: Base Clock Pulse 2 Selects the number of base clock cycles in combination with the SMR.BCP[1:0] bits */
#define R_SCI0_SCMR_CHR1                  (1 <<  4) /* 10: Character Length 1 (Only valid in asynchronous mode) */
#define R_SCI0_SCMR_SDIR                  (1 <<  3) /* 08: Transmitted/Received Data Transfer Direction NOTE: The setting is invalid and a fixed data length of 8 bits is used in modes other than asynchronous mode. Set this bit to 1 if operation is to be in simple I2C mode. */
#define R_SCI0_SCMR_SINV                  (1 <<  2) /* 04: Transmitted/Received Data Invert Set this bit to 0 if operation is to be in simple I2C mode. */
#define R_SCI0_SCMR_SMIF                  (1 <<  0) /* 01: Smart Card Interface Mode Select */
#define R_SCI0_SEMR_OFFSET                0x0007
#define R_SCI0_SEMR                       (R_SCI0_BASE + R_SCI0_SEMR_OFFSET)
#define R_SCI0_SEMR_RXDESEL               (1 <<  7) /* 80: Asynchronous Start Bit Edge Detection Select (Valid only in asynchronous mode) */
#define R_SCI0_SEMR_BGDM                  (1 <<  6) /* 40: Baud Rate Generator Double-Speed Mode Select (Only valid the CKE[1] bit in SCR is 0 in asynchronous mode). */
#define R_SCI0_SEMR_NFEN                  (1 <<  5) /* 20: Digital Noise Filter Function Enable (The NFEN bit should be 0 without simple I2C mode and asynchronous mode.) In asynchronous mode, for RXDn input only. In simple I2C mode, for RXDn/TxDn input. */
#define R_SCI0_SEMR_ABCS                  (1 <<  4) /* 10: Asynchronous Mode Base Clock Select (Valid only in asynchronous mode) */
#define R_SCI0_SEMR_ABCSE                 (1 <<  3) /* 08: Asynchronous Mode Extended Base Clock Select 1 (Valid only in asynchronous mode and SCR.CKE[1]=0) */
#define R_SCI0_SEMR_BRME                  (1 <<  2) /* 04: Bit Rate Modulation Enable */
#define R_SCI0_SNFR_OFFSET                0x0008
#define R_SCI0_SNFR                       (R_SCI0_BASE + R_SCI0_SNFR_OFFSET)
#define R_SCI0_SNFR_NFCS                  (3 <<  0) /* 01: Noise Filter Clock Select */
#define R_SCI0_SNFR_NFCS_MASK                  (0x07)
#define R_SCI0_SIMR1_OFFSET               0x0009
#define R_SCI0_SIMR1                      (R_SCI0_BASE + R_SCI0_SIMR1_OFFSET)
#define R_SCI0_SIMR1_IICDL                (5 <<  3) /* 08: SDA Delay Output Select Cycles below are of the clock signal from the on-chip baud rate generator. */
#define R_SCI0_SIMR1_IICDL_MASK                (0x1f)
#define R_SCI0_SIMR1_IICM                 (1 <<  0) /* 01: Simple I2C Mode Select */
#define R_SCI0_SIMR2_OFFSET               0x000a
#define R_SCI0_SIMR2                      (R_SCI0_BASE + R_SCI0_SIMR2_OFFSET)
#define R_SCI0_SIMR2_IICACKT              (1 <<  5) /* 20: ACK Transmission Data */
#define R_SCI0_SIMR2_IICCSC               (1 <<  1) /* 02: Clock Synchronization */
#define R_SCI0_SIMR2_IICINTM              (1 <<  0) /* 01: I2C Interrupt Mode Select */
#define R_SCI0_SIMR3_OFFSET               0x000b
#define R_SCI0_SIMR3                      (R_SCI0_BASE + R_SCI0_SIMR3_OFFSET)
#define R_SCI0_SIMR3_IICSCLS              (2 <<  6) /* 40: SCL Output Select */
#define R_SCI0_SIMR3_IICSCLS_MASK              (0x03)
#define R_SCI0_SIMR3_IICSDAS              (2 <<  4) /* 10: SDA Output Select */
#define R_SCI0_SIMR3_IICSDAS_MASK              (0x03)
#define R_SCI0_SIMR3_IICSTIF              (1 <<  3) /* 08: Issuing of Start, Restart, or Stop Condition Completed Flag (When 0 is written to IICSTIF, it is cleared to 0.) */
#define R_SCI0_SIMR3_IICSTPREQ            (1 <<  2) /* 04: Stop Condition Generation */
#define R_SCI0_SIMR3_IICRSTAREQ           (1 <<  1) /* 02: Restart Condition Generation */
#define R_SCI0_SIMR3_IICSTAREQ            (1 <<  0) /* 01: Start Condition Generation */
#define R_SCI0_SISR_OFFSET                0x000c
#define R_SCI0_SISR                       (R_SCI0_BASE + R_SCI0_SISR_OFFSET)
#define R_SCI0_SISR_IICACKR               (1 <<  0) /* 01: ACK Reception Data Flag */
#define R_SCI0_SPMR_OFFSET                0x000d
#define R_SCI0_SPMR                       (R_SCI0_BASE + R_SCI0_SPMR_OFFSET)
#define R_SCI0_SPMR_CKPH                  (1 <<  7) /* 80: Clock Phase Select */
#define R_SCI0_SPMR_CKPOL                 (1 <<  6) /* 40: Clock Polarity Select */
#define R_SCI0_SPMR_MFF                   (1 <<  4) /* 10: Mode Fault Flag */
#define R_SCI0_SPMR_MSS                   (1 <<  2) /* 04: Master Slave Select */
#define R_SCI0_SPMR_CTSE                  (1 <<  1) /* 02: CTS Enable */
#define R_SCI0_SPMR_SSE                   (1 <<  0) /* 01: SSn Pin Function Enable */
#define R_SCI0_TDRHL_OFFSET               0x000e
#define R_SCI0_TDRHL                      (R_SCI0_BASE + R_SCI0_TDRHL_OFFSET)
#define R_SCI0_TDRHL_TDRHL                (16 <<  0) /* 01: TDRHL is a 16-bit register that stores transmit data. */
#define R_SCI0_TDRHL_TDRHL_MASK                (0xffff)
#define R_SCI0_FTDRHL_OFFSET              0x000e
#define R_SCI0_FTDRHL                     (R_SCI0_BASE + R_SCI0_FTDRHL_OFFSET)
#define R_SCI0_FTDRHL_MPBT                (1 <<  9) /* 200: Multi-processor transfer bit flag (Valid only in asynchronous mode and SMR.MP=1 and FIFO selected) */
#define R_SCI0_FTDRHL_TDAT                (9 <<  0) /* 01: Serial transmit data (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode, and FIFO selected) */
#define R_SCI0_FTDRHL_TDAT_MASK                (0x1ff)
#define R_SCI0_FTDRH_OFFSET               0x000e
#define R_SCI0_FTDRH                      (R_SCI0_BASE + R_SCI0_FTDRH_OFFSET)
#define R_SCI0_FTDRH_MPBT                 (1 <<  1) /* 02: Multi-processor transfer bit flag (Valid only in asynchronous mode and SMR.MP=1 and FIFO selected) */
#define R_SCI0_FTDRH_TDATH                (1 <<  0) /* 01: Serial transmit data (b8) (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode, and FIFO selected) */
#define R_SCI0_FTDRL_OFFSET               0x000f
#define R_SCI0_FTDRL                      (R_SCI0_BASE + R_SCI0_FTDRL_OFFSET)
#define R_SCI0_FTDRL_TDATL                (8 <<  0) /* 01: Serial transmit data(b7-b0) (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode, and FIFO selected) */
#define R_SCI0_FTDRL_TDATL_MASK                (0xff)
#define R_SCI0_RDRHL_OFFSET               0x0010
#define R_SCI0_RDRHL                      (R_SCI0_BASE + R_SCI0_RDRHL_OFFSET)
#define R_SCI0_RDRHL_RDRHL                (16 <<  0) /* 01: RDRHL is an 16-bit register that stores receive data. */
#define R_SCI0_RDRHL_RDRHL_MASK                (0xffff)
#define R_SCI0_FRDRHL_OFFSET              0x0010
#define R_SCI0_FRDRHL                     (R_SCI0_BASE + R_SCI0_FRDRHL_OFFSET)
#define R_SCI0_FRDRHL_RDF                 (1 << 14) /* 4000: Receive FIFO data full flag (It is same as SSR.RDF) */
#define R_SCI0_FRDRHL_ORER                (1 << 13) /* 2000: Overrun error flag (It is same as SSR.ORER) */
#define R_SCI0_FRDRHL_FER                 (1 << 12) /* 1000: Framing error flag */
#define R_SCI0_FRDRHL_PER                 (1 << 11) /* 800: Parity error flag */
#define R_SCI0_FRDRHL_DR                  (1 << 10) /* 400: Receive data ready flag (It is same as SSR.DR) */
#define R_SCI0_FRDRHL_MPB                 (1 <<  9) /* 200: Multi-processor bit flag (Valid only in asynchronous mode with SMR.MP=1 and FIFO selected) It can read multi-processor bit corresponded to serial receive data(RDATA[8:0]) */
#define R_SCI0_FRDRHL_RDAT                (9 <<  0) /* 01: Serial receive data (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode, and FIFO selected) */
#define R_SCI0_FRDRHL_RDAT_MASK                (0x1ff)
#define R_SCI0_FRDRH_OFFSET               0x0010
#define R_SCI0_FRDRH                      (R_SCI0_BASE + R_SCI0_FRDRH_OFFSET)
#define R_SCI0_FRDRH_RDF                  (1 <<  6) /* 40: Receive FIFO data full flag (It is same as SSR.RDF) */
#define R_SCI0_FRDRH_ORER                 (1 <<  5) /* 20: Overrun error flag (It is same as SSR.ORER) */
#define R_SCI0_FRDRH_FER                  (1 <<  4) /* 10: Framing error flag */
#define R_SCI0_FRDRH_PER                  (1 <<  3) /* 08: Parity error flag */
#define R_SCI0_FRDRH_DR                   (1 <<  2) /* 04: Receive data ready flag (It is same as SSR.DR) */
#define R_SCI0_FRDRH_MPB                  (1 <<  1) /* 02: Multi-processor bit flag (Valid only in asynchronous mode with SMR.MP=1 and FIFO selected) It can read multi-processor bit corresponded to serial receive data(RDATA[8:0]) */
#define R_SCI0_FRDRH_RDATH                (1 <<  0) /* 01: Serial receive data(b8) (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode, and FIFO selected) */
#define R_SCI0_FRDRL_OFFSET               0x0011
#define R_SCI0_FRDRL                      (R_SCI0_BASE + R_SCI0_FRDRL_OFFSET)
#define R_SCI0_FRDRL_RDATL                (8 <<  0) /* 01: Serial receive data (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode, and FIFO selected) NOTE: When reading both of FRDRH register and FRDRL register, please read by an order of the FRDRH register and the FRDRL register. */
#define R_SCI0_FRDRL_RDATL_MASK                (0xff)
#define R_SCI0_MDDR_OFFSET                0x0012
#define R_SCI0_MDDR                       (R_SCI0_BASE + R_SCI0_MDDR_OFFSET)
#define R_SCI0_MDDR_MDDR                  (8 <<  0) /* 01: MDDR corrects the bit rate adjusted by the BRR register. */
#define R_SCI0_MDDR_MDDR_MASK                  (0xff)
#define R_SCI0_DCCR_OFFSET                0x0013
#define R_SCI0_DCCR                       (R_SCI0_BASE + R_SCI0_DCCR_OFFSET)
#define R_SCI0_DCCR_DCME                  (1 <<  7) /* 80: Data Compare Match Enable (Valid only in asynchronous mode(including multi-processor) */
#define R_SCI0_DCCR_IDSEL                 (1 <<  6) /* 40: ID frame select (Valid only in asynchronous mode(including multi-processor) */
#define R_SCI0_DCCR_DFER                  (1 <<  4) /* 10: Data Compare Match Framing Error Flag */
#define R_SCI0_DCCR_DPER                  (1 <<  3) /* 08: Data Compare Match Parity Error Flag */
#define R_SCI0_DCCR_DCMF                  (1 <<  0) /* 01: Data Compare Match Flag */
#define R_SCI0_FCR_OFFSET                 0x0014
#define R_SCI0_FCR                        (R_SCI0_BASE + R_SCI0_FCR_OFFSET)
#define R_SCI0_FCR_RSTRG                  (4 << 12) /* 1000: RTS Output Active Trigger Number Select (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode) */
#define R_SCI0_FCR_RSTRG_MASK                  (0x0f)
#define R_SCI0_FCR_RTRG                   (4 <<  8) /* 100: Receive FIFO data trigger number (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode) */
#define R_SCI0_FCR_RTRG_MASK                   (0x0f)
#define R_SCI0_FCR_TTRG                   (4 <<  4) /* 10: Transmit FIFO data trigger number (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode) */
#define R_SCI0_FCR_TTRG_MASK                   (0x0f)
#define R_SCI0_FCR_DRES                   (1 <<  3) /* 08: Receive data ready error select bit (When detecting a reception data ready, the interrupt request is selected.) */
#define R_SCI0_FCR_TFRST                  (1 <<  2) /* 04: Transmit FIFO Data Register Reset (Valid only in FCR.FM=1) */
#define R_SCI0_FCR_RFRST                  (1 <<  1) /* 02: Receive FIFO Data Register Reset (Valid only in FCR.FM=1) */
#define R_SCI0_FCR_FM                     (1 <<  0) /* 01: FIFO Mode Select (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode) */
#define R_SCI0_FDR_OFFSET                 0x0016
#define R_SCI0_FDR                        (R_SCI0_BASE + R_SCI0_FDR_OFFSET)
#define R_SCI0_FDR_T                      (5 <<  8) /* 100: Transmit FIFO Data Count Indicate the quantity of non-transmit data stored in FTDRH and FTDRL (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode, while FCR.FM=1) */
#define R_SCI0_FDR_T_MASK                      (0x1f)
#define R_SCI0_FDR_R                      (5 <<  0) /* 01: Receive FIFO Data Count Indicate the quantity of receive data stored in FRDRH and FRDRL (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode, while FCR.FM=1) */
#define R_SCI0_FDR_R_MASK                      (0x1f)
#define R_SCI0_LSR_OFFSET                 0x0018
#define R_SCI0_LSR                        (R_SCI0_BASE + R_SCI0_LSR_OFFSET)
#define R_SCI0_LSR_PNUM                   (5 <<  8) /* 100: Parity Error Count Indicates the quantity of data with a parity error among the receive data stored in the receive FIFO data register (FRDRH and FRDRL). */
#define R_SCI0_LSR_PNUM_MASK                   (0x1f)
#define R_SCI0_LSR_FNUM                   (5 <<  2) /* 04: Framing Error Count Indicates the quantity of data with a framing error among the receive data stored in the receive FIFO data register (FRDRH and FRDRL). */
#define R_SCI0_LSR_FNUM_MASK                   (0x1f)
#define R_SCI0_LSR_ORER                   (1 <<  0) /* 01: Overrun Error Flag (Valid only in asynchronous mode(including multi-processor) or clock synchronous mode, and FIFO selected) */
#define R_SCI0_CDR_OFFSET                 0x001a
#define R_SCI0_CDR                        (R_SCI0_BASE + R_SCI0_CDR_OFFSET)
#define R_SCI0_CDR_CMPD                   (9 <<  0) /* 01: Compare Match Data Compare data pattern for address match wake-up function */
#define R_SCI0_CDR_CMPD_MASK                   (0x1ff)
#define R_SCI0_SPTR_OFFSET                0x001c
#define R_SCI0_SPTR                       (R_SCI0_BASE + R_SCI0_SPTR_OFFSET)
#define R_SCI0_SPTR_SPB2IO                (1 <<  2) /* 04: Serial port break I/O bit (It's selected whether the value of SPB2DT is output to TxD terminal.) */
#define R_SCI0_SPTR_SPB2DT                (1 <<  1) /* 02: Serial port break data select bit (The output level of TxD terminal is selected when SCR.TE = 0.) */
#define R_SCI0_SPTR_RXDMON                (1 <<  0) /* 01: Serial input data monitor bit (The state of the RXD terminal is shown.) */

/* No registers defined for peripheral SCI1. Using those of SCI0. */
#define R_SCI1_SMR_OFFSET                 R_SCI0_SMR_OFFSET
#define R_SCI1_SMR                        R_SCI0_SMR
#define R_SCI1_SMR_CM                     R_SCI0_SMR_CM
#define R_SCI1_SMR_CHR                    R_SCI0_SMR_CHR
#define R_SCI1_SMR_PE                     R_SCI0_SMR_PE
#define R_SCI1_SMR_PM                     R_SCI0_SMR_PM
#define R_SCI1_SMR_STOP                   R_SCI0_SMR_STOP
#define R_SCI1_SMR_MP                     R_SCI0_SMR_MP
#define R_SCI1_SMR_CKS                    R_SCI0_SMR_CKS
#define R_SCI1_SMR_CKS_MASK               R_SCI0_SMR_CKS_MASK
#define R_SCI1_SMR_SMCI_OFFSET            R_SCI0_SMR_SMCI_OFFSET
#define R_SCI1_SMR_SMCI                   R_SCI0_SMR_SMCI
#define R_SCI1_SMR_SMCI_GM                R_SCI0_SMR_SMCI_GM
#define R_SCI1_SMR_SMCI_BLK               R_SCI0_SMR_SMCI_BLK
#define R_SCI1_SMR_SMCI_PE                R_SCI0_SMR_SMCI_PE
#define R_SCI1_SMR_SMCI_PM                R_SCI0_SMR_SMCI_PM
#define R_SCI1_SMR_SMCI_BCP               R_SCI0_SMR_SMCI_BCP
#define R_SCI1_SMR_SMCI_BCP_MASK          R_SCI0_SMR_SMCI_BCP_MASK
#define R_SCI1_SMR_SMCI_CKS               R_SCI0_SMR_SMCI_CKS
#define R_SCI1_SMR_SMCI_CKS_MASK          R_SCI0_SMR_SMCI_CKS_MASK
#define R_SCI1_BRR_OFFSET                 R_SCI0_BRR_OFFSET
#define R_SCI1_BRR                        R_SCI0_BRR
#define R_SCI1_BRR_BRR                    R_SCI0_BRR_BRR
#define R_SCI1_BRR_BRR_MASK               R_SCI0_BRR_BRR_MASK
#define R_SCI1_SCR_OFFSET                 R_SCI0_SCR_OFFSET
#define R_SCI1_SCR                        R_SCI0_SCR
#define R_SCI1_SCR_TIE                    R_SCI0_SCR_TIE
#define R_SCI1_SCR_RIE                    R_SCI0_SCR_RIE
#define R_SCI1_SCR_TE                     R_SCI0_SCR_TE
#define R_SCI1_SCR_RE                     R_SCI0_SCR_RE
#define R_SCI1_SCR_MPIE                   R_SCI0_SCR_MPIE
#define R_SCI1_SCR_TEIE                   R_SCI0_SCR_TEIE
#define R_SCI1_SCR_CKE                    R_SCI0_SCR_CKE
#define R_SCI1_SCR_CKE_MASK               R_SCI0_SCR_CKE_MASK
#define R_SCI1_SCR_SMCI_OFFSET            R_SCI0_SCR_SMCI_OFFSET
#define R_SCI1_SCR_SMCI                   R_SCI0_SCR_SMCI
#define R_SCI1_SCR_SMCI_TIE               R_SCI0_SCR_SMCI_TIE
#define R_SCI1_SCR_SMCI_RIE               R_SCI0_SCR_SMCI_RIE
#define R_SCI1_SCR_SMCI_TE                R_SCI0_SCR_SMCI_TE
#define R_SCI1_SCR_SMCI_RE                R_SCI0_SCR_SMCI_RE
#define R_SCI1_SCR_SMCI_MPIE              R_SCI0_SCR_SMCI_MPIE
#define R_SCI1_SCR_SMCI_TEIE              R_SCI0_SCR_SMCI_TEIE
#define R_SCI1_SCR_SMCI_CKE               R_SCI0_SCR_SMCI_CKE
#define R_SCI1_SCR_SMCI_CKE_MASK          R_SCI0_SCR_SMCI_CKE_MASK
#define R_SCI1_TDR_OFFSET                 R_SCI0_TDR_OFFSET
#define R_SCI1_TDR                        R_SCI0_TDR
#define R_SCI1_TDR_TDR                    R_SCI0_TDR_TDR
#define R_SCI1_TDR_TDR_MASK               R_SCI0_TDR_TDR_MASK
#define R_SCI1_SSR_OFFSET                 R_SCI0_SSR_OFFSET
#define R_SCI1_SSR                        R_SCI0_SSR
#define R_SCI1_SSR_TDRE                   R_SCI0_SSR_TDRE
#define R_SCI1_SSR_RDRF                   R_SCI0_SSR_RDRF
#define R_SCI1_SSR_ORER                   R_SCI0_SSR_ORER
#define R_SCI1_SSR_FER                    R_SCI0_SSR_FER
#define R_SCI1_SSR_PER                    R_SCI0_SSR_PER
#define R_SCI1_SSR_TEND                   R_SCI0_SSR_TEND
#define R_SCI1_SSR_MPB                    R_SCI0_SSR_MPB
#define R_SCI1_SSR_MPBT                   R_SCI0_SSR_MPBT
#define R_SCI1_SSR_FIFO_OFFSET            R_SCI0_SSR_FIFO_OFFSET
#define R_SCI1_SSR_FIFO                   R_SCI0_SSR_FIFO
#define R_SCI1_SSR_FIFO_TDFE              R_SCI0_SSR_FIFO_TDFE
#define R_SCI1_SSR_FIFO_RDF               R_SCI0_SSR_FIFO_RDF
#define R_SCI1_SSR_FIFO_ORER              R_SCI0_SSR_FIFO_ORER
#define R_SCI1_SSR_FIFO_FER               R_SCI0_SSR_FIFO_FER
#define R_SCI1_SSR_FIFO_PER               R_SCI0_SSR_FIFO_PER
#define R_SCI1_SSR_FIFO_TEND              R_SCI0_SSR_FIFO_TEND
#define R_SCI1_SSR_FIFO_DR                R_SCI0_SSR_FIFO_DR
#define R_SCI1_SSR_SMCI_OFFSET            R_SCI0_SSR_SMCI_OFFSET
#define R_SCI1_SSR_SMCI                   R_SCI0_SSR_SMCI
#define R_SCI1_SSR_SMCI_TDRE              R_SCI0_SSR_SMCI_TDRE
#define R_SCI1_SSR_SMCI_RDRF              R_SCI0_SSR_SMCI_RDRF
#define R_SCI1_SSR_SMCI_ORER              R_SCI0_SSR_SMCI_ORER
#define R_SCI1_SSR_SMCI_ERS               R_SCI0_SSR_SMCI_ERS
#define R_SCI1_SSR_SMCI_PER               R_SCI0_SSR_SMCI_PER
#define R_SCI1_SSR_SMCI_TEND              R_SCI0_SSR_SMCI_TEND
#define R_SCI1_SSR_SMCI_MPB               R_SCI0_SSR_SMCI_MPB
#define R_SCI1_SSR_SMCI_MPBT              R_SCI0_SSR_SMCI_MPBT
#define R_SCI1_RDR_OFFSET                 R_SCI0_RDR_OFFSET
#define R_SCI1_RDR                        R_SCI0_RDR
#define R_SCI1_RDR_RDR                    R_SCI0_RDR_RDR
#define R_SCI1_RDR_RDR_MASK               R_SCI0_RDR_RDR_MASK
#define R_SCI1_SCMR_OFFSET                R_SCI0_SCMR_OFFSET
#define R_SCI1_SCMR                       R_SCI0_SCMR
#define R_SCI1_SCMR_BCP2                  R_SCI0_SCMR_BCP2
#define R_SCI1_SCMR_CHR1                  R_SCI0_SCMR_CHR1
#define R_SCI1_SCMR_SDIR                  R_SCI0_SCMR_SDIR
#define R_SCI1_SCMR_SINV                  R_SCI0_SCMR_SINV
#define R_SCI1_SCMR_SMIF                  R_SCI0_SCMR_SMIF
#define R_SCI1_SEMR_OFFSET                R_SCI0_SEMR_OFFSET
#define R_SCI1_SEMR                       R_SCI0_SEMR
#define R_SCI1_SEMR_RXDESEL               R_SCI0_SEMR_RXDESEL
#define R_SCI1_SEMR_BGDM                  R_SCI0_SEMR_BGDM
#define R_SCI1_SEMR_NFEN                  R_SCI0_SEMR_NFEN
#define R_SCI1_SEMR_ABCS                  R_SCI0_SEMR_ABCS
#define R_SCI1_SEMR_ABCSE                 R_SCI0_SEMR_ABCSE
#define R_SCI1_SEMR_BRME                  R_SCI0_SEMR_BRME
#define R_SCI1_SNFR_OFFSET                R_SCI0_SNFR_OFFSET
#define R_SCI1_SNFR                       R_SCI0_SNFR
#define R_SCI1_SNFR_NFCS                  R_SCI0_SNFR_NFCS
#define R_SCI1_SNFR_NFCS_MASK             R_SCI0_SNFR_NFCS_MASK
#define R_SCI1_SIMR1_OFFSET               R_SCI0_SIMR1_OFFSET
#define R_SCI1_SIMR1                      R_SCI0_SIMR1
#define R_SCI1_SIMR1_IICDL                R_SCI0_SIMR1_IICDL
#define R_SCI1_SIMR1_IICDL_MASK           R_SCI0_SIMR1_IICDL_MASK
#define R_SCI1_SIMR1_IICM                 R_SCI0_SIMR1_IICM
#define R_SCI1_SIMR2_OFFSET               R_SCI0_SIMR2_OFFSET
#define R_SCI1_SIMR2                      R_SCI0_SIMR2
#define R_SCI1_SIMR2_IICACKT              R_SCI0_SIMR2_IICACKT
#define R_SCI1_SIMR2_IICCSC               R_SCI0_SIMR2_IICCSC
#define R_SCI1_SIMR2_IICINTM              R_SCI0_SIMR2_IICINTM
#define R_SCI1_SIMR3_OFFSET               R_SCI0_SIMR3_OFFSET
#define R_SCI1_SIMR3                      R_SCI0_SIMR3
#define R_SCI1_SIMR3_IICSCLS              R_SCI0_SIMR3_IICSCLS
#define R_SCI1_SIMR3_IICSCLS_MASK         R_SCI0_SIMR3_IICSCLS_MASK
#define R_SCI1_SIMR3_IICSDAS              R_SCI0_SIMR3_IICSDAS
#define R_SCI1_SIMR3_IICSDAS_MASK         R_SCI0_SIMR3_IICSDAS_MASK
#define R_SCI1_SIMR3_IICSTIF              R_SCI0_SIMR3_IICSTIF
#define R_SCI1_SIMR3_IICSTPREQ            R_SCI0_SIMR3_IICSTPREQ
#define R_SCI1_SIMR3_IICRSTAREQ           R_SCI0_SIMR3_IICRSTAREQ
#define R_SCI1_SIMR3_IICSTAREQ            R_SCI0_SIMR3_IICSTAREQ
#define R_SCI1_SISR_OFFSET                R_SCI0_SISR_OFFSET
#define R_SCI1_SISR                       R_SCI0_SISR
#define R_SCI1_SISR_IICACKR               R_SCI0_SISR_IICACKR
#define R_SCI1_SPMR_OFFSET                R_SCI0_SPMR_OFFSET
#define R_SCI1_SPMR                       R_SCI0_SPMR
#define R_SCI1_SPMR_CKPH                  R_SCI0_SPMR_CKPH
#define R_SCI1_SPMR_CKPOL                 R_SCI0_SPMR_CKPOL
#define R_SCI1_SPMR_MFF                   R_SCI0_SPMR_MFF
#define R_SCI1_SPMR_MSS                   R_SCI0_SPMR_MSS
#define R_SCI1_SPMR_CTSE                  R_SCI0_SPMR_CTSE
#define R_SCI1_SPMR_SSE                   R_SCI0_SPMR_SSE
#define R_SCI1_TDRHL_OFFSET               R_SCI0_TDRHL_OFFSET
#define R_SCI1_TDRHL                      R_SCI0_TDRHL
#define R_SCI1_TDRHL_TDRHL                R_SCI0_TDRHL_TDRHL
#define R_SCI1_TDRHL_TDRHL_MASK           R_SCI0_TDRHL_TDRHL_MASK
#define R_SCI1_FTDRHL_OFFSET              R_SCI0_FTDRHL_OFFSET
#define R_SCI1_FTDRHL                     R_SCI0_FTDRHL
#define R_SCI1_FTDRHL_MPBT                R_SCI0_FTDRHL_MPBT
#define R_SCI1_FTDRHL_TDAT                R_SCI0_FTDRHL_TDAT
#define R_SCI1_FTDRHL_TDAT_MASK           R_SCI0_FTDRHL_TDAT_MASK
#define R_SCI1_FTDRH_OFFSET               R_SCI0_FTDRH_OFFSET
#define R_SCI1_FTDRH                      R_SCI0_FTDRH
#define R_SCI1_FTDRH_MPBT                 R_SCI0_FTDRH_MPBT
#define R_SCI1_FTDRH_TDATH                R_SCI0_FTDRH_TDATH
#define R_SCI1_FTDRL_OFFSET               R_SCI0_FTDRL_OFFSET
#define R_SCI1_FTDRL                      R_SCI0_FTDRL
#define R_SCI1_FTDRL_TDATL                R_SCI0_FTDRL_TDATL
#define R_SCI1_FTDRL_TDATL_MASK           R_SCI0_FTDRL_TDATL_MASK
#define R_SCI1_RDRHL_OFFSET               R_SCI0_RDRHL_OFFSET
#define R_SCI1_RDRHL                      R_SCI0_RDRHL
#define R_SCI1_RDRHL_RDRHL                R_SCI0_RDRHL_RDRHL
#define R_SCI1_RDRHL_RDRHL_MASK           R_SCI0_RDRHL_RDRHL_MASK
#define R_SCI1_FRDRHL_OFFSET              R_SCI0_FRDRHL_OFFSET
#define R_SCI1_FRDRHL                     R_SCI0_FRDRHL
#define R_SCI1_FRDRHL_RDF                 R_SCI0_FRDRHL_RDF
#define R_SCI1_FRDRHL_ORER                R_SCI0_FRDRHL_ORER
#define R_SCI1_FRDRHL_FER                 R_SCI0_FRDRHL_FER
#define R_SCI1_FRDRHL_PER                 R_SCI0_FRDRHL_PER
#define R_SCI1_FRDRHL_DR                  R_SCI0_FRDRHL_DR
#define R_SCI1_FRDRHL_MPB                 R_SCI0_FRDRHL_MPB
#define R_SCI1_FRDRHL_RDAT                R_SCI0_FRDRHL_RDAT
#define R_SCI1_FRDRHL_RDAT_MASK           R_SCI0_FRDRHL_RDAT_MASK
#define R_SCI1_FRDRH_OFFSET               R_SCI0_FRDRH_OFFSET
#define R_SCI1_FRDRH                      R_SCI0_FRDRH
#define R_SCI1_FRDRH_RDF                  R_SCI0_FRDRH_RDF
#define R_SCI1_FRDRH_ORER                 R_SCI0_FRDRH_ORER
#define R_SCI1_FRDRH_FER                  R_SCI0_FRDRH_FER
#define R_SCI1_FRDRH_PER                  R_SCI0_FRDRH_PER
#define R_SCI1_FRDRH_DR                   R_SCI0_FRDRH_DR
#define R_SCI1_FRDRH_MPB                  R_SCI0_FRDRH_MPB
#define R_SCI1_FRDRH_RDATH                R_SCI0_FRDRH_RDATH
#define R_SCI1_FRDRL_OFFSET               R_SCI0_FRDRL_OFFSET
#define R_SCI1_FRDRL                      R_SCI0_FRDRL
#define R_SCI1_FRDRL_RDATL                R_SCI0_FRDRL_RDATL
#define R_SCI1_FRDRL_RDATL_MASK           R_SCI0_FRDRL_RDATL_MASK
#define R_SCI1_MDDR_OFFSET                R_SCI0_MDDR_OFFSET
#define R_SCI1_MDDR                       R_SCI0_MDDR
#define R_SCI1_MDDR_MDDR                  R_SCI0_MDDR_MDDR
#define R_SCI1_MDDR_MDDR_MASK             R_SCI0_MDDR_MDDR_MASK
#define R_SCI1_DCCR_OFFSET                R_SCI0_DCCR_OFFSET
#define R_SCI1_DCCR                       R_SCI0_DCCR
#define R_SCI1_DCCR_DCME                  R_SCI0_DCCR_DCME
#define R_SCI1_DCCR_IDSEL                 R_SCI0_DCCR_IDSEL
#define R_SCI1_DCCR_DFER                  R_SCI0_DCCR_DFER
#define R_SCI1_DCCR_DPER                  R_SCI0_DCCR_DPER
#define R_SCI1_DCCR_DCMF                  R_SCI0_DCCR_DCMF
#define R_SCI1_FCR_OFFSET                 R_SCI0_FCR_OFFSET
#define R_SCI1_FCR                        R_SCI0_FCR
#define R_SCI1_FCR_RSTRG                  R_SCI0_FCR_RSTRG
#define R_SCI1_FCR_RSTRG_MASK             R_SCI0_FCR_RSTRG_MASK
#define R_SCI1_FCR_RTRG                   R_SCI0_FCR_RTRG
#define R_SCI1_FCR_RTRG_MASK              R_SCI0_FCR_RTRG_MASK
#define R_SCI1_FCR_TTRG                   R_SCI0_FCR_TTRG
#define R_SCI1_FCR_TTRG_MASK              R_SCI0_FCR_TTRG_MASK
#define R_SCI1_FCR_DRES                   R_SCI0_FCR_DRES
#define R_SCI1_FCR_TFRST                  R_SCI0_FCR_TFRST
#define R_SCI1_FCR_RFRST                  R_SCI0_FCR_RFRST
#define R_SCI1_FCR_FM                     R_SCI0_FCR_FM
#define R_SCI1_FDR_OFFSET                 R_SCI0_FDR_OFFSET
#define R_SCI1_FDR                        R_SCI0_FDR
#define R_SCI1_FDR_T                      R_SCI0_FDR_T
#define R_SCI1_FDR_T_MASK                 R_SCI0_FDR_T_MASK
#define R_SCI1_FDR_R                      R_SCI0_FDR_R
#define R_SCI1_FDR_R_MASK                 R_SCI0_FDR_R_MASK
#define R_SCI1_LSR_OFFSET                 R_SCI0_LSR_OFFSET
#define R_SCI1_LSR                        R_SCI0_LSR
#define R_SCI1_LSR_PNUM                   R_SCI0_LSR_PNUM
#define R_SCI1_LSR_PNUM_MASK              R_SCI0_LSR_PNUM_MASK
#define R_SCI1_LSR_FNUM                   R_SCI0_LSR_FNUM
#define R_SCI1_LSR_FNUM_MASK              R_SCI0_LSR_FNUM_MASK
#define R_SCI1_LSR_ORER                   R_SCI0_LSR_ORER
#define R_SCI1_CDR_OFFSET                 R_SCI0_CDR_OFFSET
#define R_SCI1_CDR                        R_SCI0_CDR
#define R_SCI1_CDR_CMPD                   R_SCI0_CDR_CMPD
#define R_SCI1_CDR_CMPD_MASK              R_SCI0_CDR_CMPD_MASK
#define R_SCI1_SPTR_OFFSET                R_SCI0_SPTR_OFFSET
#define R_SCI1_SPTR                       R_SCI0_SPTR
#define R_SCI1_SPTR_SPB2IO                R_SCI0_SPTR_SPB2IO
#define R_SCI1_SPTR_SPB2DT                R_SCI0_SPTR_SPB2DT
#define R_SCI1_SPTR_RXDMON                R_SCI0_SPTR_RXDMON

/* SCI2 - Serial Communication Interface 2 */
#define R_SCI2_SMR_OFFSET                 0x0000
#define R_SCI2_SMR                        (R_SCI2_BASE + R_SCI2_SMR_OFFSET)
#define R_SCI2_SMR_CM                     (1 <<  7) /* 80: Communication Mode */
#define R_SCI2_SMR_CHR                    (1 <<  6) /* 40: Character Length (Valid only in asynchronous mode) */
#define R_SCI2_SMR_PE                     (1 <<  5) /* 20: Parity Enable (Valid only in asynchronous mode) */
#define R_SCI2_SMR_PM                     (1 <<  4) /* 10: Parity Mode (Valid only when the PE bit is 1) */
#define R_SCI2_SMR_STOP                   (1 <<  3) /* 08: Stop Bit Length (Valid only in asynchronous mode) */
#define R_SCI2_SMR_MP                     (1 <<  2) /* 04: Multi-Processor Mode (Valid only in asynchronous mode) */
#define R_SCI2_SMR_CKS                    (2 <<  0) /* 01: Clock Select */
#define R_SCI2_SMR_CKS_MASK                    (0x03)
#define R_SCI2_SMR_SMCI_OFFSET            0x0000
#define R_SCI2_SMR_SMCI                   (R_SCI2_BASE + R_SCI2_SMR_SMCI_OFFSET)
#define R_SCI2_SMR_SMCI_GM                (1 <<  7) /* 80: GSM Mode */
#define R_SCI2_SMR_SMCI_BLK               (1 <<  6) /* 40: Block Transfer Mode */
#define R_SCI2_SMR_SMCI_PE                (1 <<  5) /* 20: Parity Enable (Valid only in asynchronous mode) */
#define R_SCI2_SMR_SMCI_PM                (1 <<  4) /* 10: Parity Mode (Valid only when the PE bit is 1) */
#define R_SCI2_SMR_SMCI_BCP               (2 <<  2) /* 04: Base Clock Pulse (Valid only in asynchronous mode) */
#define R_SCI2_SMR_SMCI_BCP_MASK               (0x03)
#define R_SCI2_SMR_SMCI_CKS               (2 <<  0) /* 01: Clock Select */
#define R_SCI2_SMR_SMCI_CKS_MASK               (0x03)
#define R_SCI2_BRR_OFFSET                 0x0001
#define R_SCI2_BRR                        (R_SCI2_BASE + R_SCI2_BRR_OFFSET)
#define R_SCI2_BRR_BRR                    (8 <<  0) /* 01: BRR is an 8-bit register that adjusts the bit rate. */
#define R_SCI2_BRR_BRR_MASK                    (0xff)
#define R_SCI2_SCR_OFFSET                 0x0002
#define R_SCI2_SCR                        (R_SCI2_BASE + R_SCI2_SCR_OFFSET)
#define R_SCI2_SCR_TIE                    (1 <<  7) /* 80: Transmit Interrupt Enable */
#define R_SCI2_SCR_RIE                    (1 <<  6) /* 40: Receive Interrupt Enable */
#define R_SCI2_SCR_TE                     (1 <<  5) /* 20: Transmit Enable */
#define R_SCI2_SCR_RE                     (1 <<  4) /* 10: Receive Enable */
#define R_SCI2_SCR_MPIE                   (1 <<  3) /* 08: Multi-Processor Interrupt Enable (Valid in asynchronous mode when SMR.MP = 1) */
#define R_SCI2_SCR_TEIE                   (1 <<  2) /* 04: Transmit End Interrupt Enable */
#define R_SCI2_SCR_CKE                    (2 <<  0) /* 01: Clock Enable */
#define R_SCI2_SCR_CKE_MASK                    (0x03)
#define R_SCI2_SCR_SMCI_OFFSET            0x0002
#define R_SCI2_SCR_SMCI                   (R_SCI2_BASE + R_SCI2_SCR_SMCI_OFFSET)
#define R_SCI2_SCR_SMCI_TIE               (1 <<  7) /* 80: Transmit Interrupt Enable */
#define R_SCI2_SCR_SMCI_RIE               (1 <<  6) /* 40: Receive Interrupt Enable */
#define R_SCI2_SCR_SMCI_TE                (1 <<  5) /* 20: Transmit Enable */
#define R_SCI2_SCR_SMCI_RE                (1 <<  4) /* 10: Receive Enable */
#define R_SCI2_SCR_SMCI_MPIE              (1 <<  3) /* 08: Multi-Processor Interrupt Enable */
#define R_SCI2_SCR_SMCI_TEIE              (1 <<  2) /* 04: Transmit End Interrupt Enable */
#define R_SCI2_SCR_SMCI_CKE               (2 <<  0) /* 01: Clock Enable */
#define R_SCI2_SCR_SMCI_CKE_MASK               (0x03)
#define R_SCI2_TDR_OFFSET                 0x0003
#define R_SCI2_TDR                        (R_SCI2_BASE + R_SCI2_TDR_OFFSET)
#define R_SCI2_TDR_TDR                    (8 <<  0) /* 01: TDR is an 8-bit register that stores transmit data. */
#define R_SCI2_TDR_TDR_MASK                    (0xff)
#define R_SCI2_SSR_OFFSET                 0x0004
#define R_SCI2_SSR                        (R_SCI2_BASE + R_SCI2_SSR_OFFSET)
#define R_SCI2_SSR_TDRE                   (1 <<  7) /* 80: Transmit Data Empty Flag */
#define R_SCI2_SSR_RDRF                   (1 <<  6) /* 40: Receive Data Full Flag */
#define R_SCI2_SSR_ORER                   (1 <<  5) /* 20: Overrun Error Flag */
#define R_SCI2_SSR_FER                    (1 <<  4) /* 10: Framing Error Flag */
#define R_SCI2_SSR_PER                    (1 <<  3) /* 08: Parity Error Flag */
#define R_SCI2_SSR_TEND                   (1 <<  2) /* 04: Transmit End Flag */
#define R_SCI2_SSR_MPB                    (1 <<  1) /* 02: Multi-Processor */
#define R_SCI2_SSR_MPBT                   (1 <<  0) /* 01: Multi-Processor Bit Transfer */
#define R_SCI2_SSR_SMCI_OFFSET            0x0004
#define R_SCI2_SSR_SMCI                   (R_SCI2_BASE + R_SCI2_SSR_SMCI_OFFSET)
#define R_SCI2_SSR_SMCI_TDRE              (1 <<  7) /* 80: Transmit Data Empty Flag */
#define R_SCI2_SSR_SMCI_RDRF              (1 <<  6) /* 40: Receive Data Full Flag */
#define R_SCI2_SSR_SMCI_ORER              (1 <<  5) /* 20: Overrun Error Flag */
#define R_SCI2_SSR_SMCI_ERS               (1 <<  4) /* 10: Error Signal Status Flag */
#define R_SCI2_SSR_SMCI_PER               (1 <<  3) /* 08: Parity Error Flag */
#define R_SCI2_SSR_SMCI_TEND              (1 <<  2) /* 04: Transmit End Flag */
#define R_SCI2_SSR_SMCI_MPB               (1 <<  1) /* 02: Multi-Processor This bit should be 0 in smart card interface mode. */
#define R_SCI2_SSR_SMCI_MPBT              (1 <<  0) /* 01: Multi-Processor Bit Transfer This bit should be 0 in smart card interface mode. */
#define R_SCI2_RDR_OFFSET                 0x0005
#define R_SCI2_RDR                        (R_SCI2_BASE + R_SCI2_RDR_OFFSET)
#define R_SCI2_RDR_RDR                    (8 <<  0) /* 01: RDR is an 8-bit register that stores receive data. */
#define R_SCI2_RDR_RDR_MASK                    (0xff)
#define R_SCI2_SCMR_OFFSET                0x0006
#define R_SCI2_SCMR                       (R_SCI2_BASE + R_SCI2_SCMR_OFFSET)
#define R_SCI2_SCMR_BCP2                  (1 <<  7) /* 80: Base Clock Pulse 2 Selects the number of base clock cycles in combination with the SMR.BCP[1:0] bits */
#define R_SCI2_SCMR_CHR1                  (1 <<  4) /* 10: Character Length 1 (Only valid in asynchronous mode) */
#define R_SCI2_SCMR_SDIR                  (1 <<  3) /* 08: Transmitted/Received Data Transfer Direction NOTE: The setting is invalid and a fixed data length of 8 bits is used in modes other than asynchronous mode. Set this bit to 1 if operation is to be in simple I2C mode. */
#define R_SCI2_SCMR_SINV                  (1 <<  2) /* 04: Transmitted/Received Data Invert Set this bit to 0 if operation is to be in simple I2C mode. */
#define R_SCI2_SCMR_SMIF                  (1 <<  0) /* 01: Smart Card Interface Mode Select */
#define R_SCI2_SEMR_OFFSET                0x0007
#define R_SCI2_SEMR                       (R_SCI2_BASE + R_SCI2_SEMR_OFFSET)
#define R_SCI2_SEMR_RXDESEL               (1 <<  7) /* 80: Asynchronous Start Bit Edge Detection Select (Valid only in asynchronous mode) */
#define R_SCI2_SEMR_BGDM                  (1 <<  6) /* 40: Baud Rate Generator Double-Speed Mode Select (Only valid the CKE[1] bit in SCR is 0 in asynchronous mode). */
#define R_SCI2_SEMR_NFEN                  (1 <<  5) /* 20: Digital Noise Filter Function Enable (The NFEN bit should be 0 without simple I2C mode and asynchronous mode.) In asynchronous mode, for RXDn input only. In simple I2C mode, for RXDn/TxDn input. */
#define R_SCI2_SEMR_ABCS                  (1 <<  4) /* 10: Asynchronous Mode Base Clock Select (Valid only in asynchronous mode) */
#define R_SCI2_SEMR_ABCSE                 (1 <<  3) /* 08: Asynchronous Mode Extended Base Clock Select 1 (Valid only in asynchronous mode and SCR.CKE[1]=0) */
#define R_SCI2_SEMR_BRME                  (1 <<  2) /* 04: Bit Rate Modulation Enable */
#define R_SCI2_SNFR_OFFSET                0x0008
#define R_SCI2_SNFR                       (R_SCI2_BASE + R_SCI2_SNFR_OFFSET)
#define R_SCI2_SNFR_NFCS                  (3 <<  0) /* 01: Noise Filter Clock Select */
#define R_SCI2_SNFR_NFCS_MASK                  (0x07)
#define R_SCI2_SIMR1_OFFSET               0x0009
#define R_SCI2_SIMR1                      (R_SCI2_BASE + R_SCI2_SIMR1_OFFSET)
#define R_SCI2_SIMR1_IICDL                (5 <<  3) /* 08: SDA Delay Output Select Cycles below are of the clock signal from the on-chip baud rate generator. */
#define R_SCI2_SIMR1_IICDL_MASK                (0x1f)
#define R_SCI2_SIMR1_IICM                 (1 <<  0) /* 01: Simple I2C Mode Select */
#define R_SCI2_SIMR2_OFFSET               0x000a
#define R_SCI2_SIMR2                      (R_SCI2_BASE + R_SCI2_SIMR2_OFFSET)
#define R_SCI2_SIMR2_IICACKT              (1 <<  5) /* 20: ACK Transmission Data */
#define R_SCI2_SIMR2_IICCSC               (1 <<  1) /* 02: Clock Synchronization */
#define R_SCI2_SIMR2_IICINTM              (1 <<  0) /* 01: I2C Interrupt Mode Select */
#define R_SCI2_SIMR3_OFFSET               0x000b
#define R_SCI2_SIMR3                      (R_SCI2_BASE + R_SCI2_SIMR3_OFFSET)
#define R_SCI2_SIMR3_IICSCLS              (2 <<  6) /* 40: SCL Output Select */
#define R_SCI2_SIMR3_IICSCLS_MASK              (0x03)
#define R_SCI2_SIMR3_IICSDAS              (2 <<  4) /* 10: SDA Output Select */
#define R_SCI2_SIMR3_IICSDAS_MASK              (0x03)
#define R_SCI2_SIMR3_IICSTIF              (1 <<  3) /* 08: Issuing of Start, Restart, or Stop Condition Completed Flag (When 0 is written to IICSTIF, it is cleared to 0.) */
#define R_SCI2_SIMR3_IICSTPREQ            (1 <<  2) /* 04: Stop Condition Generation */
#define R_SCI2_SIMR3_IICRSTAREQ           (1 <<  1) /* 02: Restart Condition Generation */
#define R_SCI2_SIMR3_IICSTAREQ            (1 <<  0) /* 01: Start Condition Generation */
#define R_SCI2_SISR_OFFSET                0x000c
#define R_SCI2_SISR                       (R_SCI2_BASE + R_SCI2_SISR_OFFSET)
#define R_SCI2_SISR_IICACKR               (1 <<  0) /* 01: ACK Reception Data Flag */
#define R_SCI2_SPMR_OFFSET                0x000d
#define R_SCI2_SPMR                       (R_SCI2_BASE + R_SCI2_SPMR_OFFSET)
#define R_SCI2_SPMR_CKPH                  (1 <<  7) /* 80: Clock Phase Select */
#define R_SCI2_SPMR_CKPOL                 (1 <<  6) /* 40: Clock Polarity Select */
#define R_SCI2_SPMR_MFF                   (1 <<  4) /* 10: Mode Fault Flag */
#define R_SCI2_SPMR_MSS                   (1 <<  2) /* 04: Master Slave Select */
#define R_SCI2_SPMR_CTSE                  (1 <<  1) /* 02: CTS Enable */
#define R_SCI2_SPMR_SSE                   (1 <<  0) /* 01: SSn Pin Function Enable */
#define R_SCI2_TDRHL_OFFSET               0x000e
#define R_SCI2_TDRHL                      (R_SCI2_BASE + R_SCI2_TDRHL_OFFSET)
#define R_SCI2_TDRHL_TDRHL                (16 <<  0) /* 01: TDRHL is a 16-bit register that stores transmit data. */
#define R_SCI2_TDRHL_TDRHL_MASK                (0xffff)
#define R_SCI2_RDRHL_OFFSET               0x0010
#define R_SCI2_RDRHL                      (R_SCI2_BASE + R_SCI2_RDRHL_OFFSET)
#define R_SCI2_RDRHL_RDRHL                (16 <<  0) /* 01: RDRHL is an 16-bit register that stores receive data. */
#define R_SCI2_RDRHL_RDRHL_MASK                (0xffff)
#define R_SCI2_MDDR_OFFSET                0x0012
#define R_SCI2_MDDR                       (R_SCI2_BASE + R_SCI2_MDDR_OFFSET)
#define R_SCI2_MDDR_MDDR                  (8 <<  0) /* 01: MDDR corrects the bit rate adjusted by the BRR register. */
#define R_SCI2_MDDR_MDDR_MASK                  (0xff)
#define R_SCI2_DCCR_OFFSET                0x0013
#define R_SCI2_DCCR                       (R_SCI2_BASE + R_SCI2_DCCR_OFFSET)
#define R_SCI2_DCCR_DCME                  (1 <<  7) /* 80: Data Compare Match Enable (Valid only in asynchronous mode(including multi-processor) */
#define R_SCI2_DCCR_IDSEL                 (1 <<  6) /* 40: ID frame select (Valid only in asynchronous mode(including multi-processor) */
#define R_SCI2_DCCR_DFER                  (1 <<  4) /* 10: Data Compare Match Framing Error Flag */
#define R_SCI2_DCCR_DPER                  (1 <<  3) /* 08: Data Compare Match Parity Error Flag */
#define R_SCI2_DCCR_DCMF                  (1 <<  0) /* 01: Data Compare Match Flag */
#define R_SCI2_CDR_OFFSET                 0x001a
#define R_SCI2_CDR                        (R_SCI2_BASE + R_SCI2_CDR_OFFSET)
#define R_SCI2_CDR_CMPD                   (9 <<  0) /* 01: Compare Match Data Compare data pattern for address match wake-up function */
#define R_SCI2_CDR_CMPD_MASK                   (0x1ff)
#define R_SCI2_SPTR_OFFSET                0x001c
#define R_SCI2_SPTR                       (R_SCI2_BASE + R_SCI2_SPTR_OFFSET)
#define R_SCI2_SPTR_SPB2IO                (1 <<  2) /* 04: Serial port break I/O bit (It's selected whether the value of SPB2DT is output to TxD terminal.) */
#define R_SCI2_SPTR_SPB2DT                (1 <<  1) /* 02: Serial port break data select bit (The output level of TxD terminal is selected when SCR.TE = 0.) */
#define R_SCI2_SPTR_RXDMON                (1 <<  0) /* 01: Serial input data monitor bit (The state of the RXD terminal is shown.) */

/* No registers defined for peripheral SCI9. Using those of SCI2. */
#define R_SCI9_SMR_OFFSET                 R_SCI2_SMR_OFFSET
#define R_SCI9_SMR                        R_SCI2_SMR
#define R_SCI9_SMR_CM                     R_SCI2_SMR_CM
#define R_SCI9_SMR_CHR                    R_SCI2_SMR_CHR
#define R_SCI9_SMR_PE                     R_SCI2_SMR_PE
#define R_SCI9_SMR_PM                     R_SCI2_SMR_PM
#define R_SCI9_SMR_STOP                   R_SCI2_SMR_STOP
#define R_SCI9_SMR_MP                     R_SCI2_SMR_MP
#define R_SCI9_SMR_CKS                    R_SCI2_SMR_CKS
#define R_SCI9_SMR_CKS_MASK               R_SCI2_SMR_CKS_MASK
#define R_SCI9_SMR_SMCI_OFFSET            R_SCI2_SMR_SMCI_OFFSET
#define R_SCI9_SMR_SMCI                   R_SCI2_SMR_SMCI
#define R_SCI9_SMR_SMCI_GM                R_SCI2_SMR_SMCI_GM
#define R_SCI9_SMR_SMCI_BLK               R_SCI2_SMR_SMCI_BLK
#define R_SCI9_SMR_SMCI_PE                R_SCI2_SMR_SMCI_PE
#define R_SCI9_SMR_SMCI_PM                R_SCI2_SMR_SMCI_PM
#define R_SCI9_SMR_SMCI_BCP               R_SCI2_SMR_SMCI_BCP
#define R_SCI9_SMR_SMCI_BCP_MASK          R_SCI2_SMR_SMCI_BCP_MASK
#define R_SCI9_SMR_SMCI_CKS               R_SCI2_SMR_SMCI_CKS
#define R_SCI9_SMR_SMCI_CKS_MASK          R_SCI2_SMR_SMCI_CKS_MASK
#define R_SCI9_BRR_OFFSET                 R_SCI2_BRR_OFFSET
#define R_SCI9_BRR                        R_SCI2_BRR
#define R_SCI9_BRR_BRR                    R_SCI2_BRR_BRR
#define R_SCI9_BRR_BRR_MASK               R_SCI2_BRR_BRR_MASK
#define R_SCI9_SCR_OFFSET                 R_SCI2_SCR_OFFSET
#define R_SCI9_SCR                        R_SCI2_SCR
#define R_SCI9_SCR_TIE                    R_SCI2_SCR_TIE
#define R_SCI9_SCR_RIE                    R_SCI2_SCR_RIE
#define R_SCI9_SCR_TE                     R_SCI2_SCR_TE
#define R_SCI9_SCR_RE                     R_SCI2_SCR_RE
#define R_SCI9_SCR_MPIE                   R_SCI2_SCR_MPIE
#define R_SCI9_SCR_TEIE                   R_SCI2_SCR_TEIE
#define R_SCI9_SCR_CKE                    R_SCI2_SCR_CKE
#define R_SCI9_SCR_CKE_MASK               R_SCI2_SCR_CKE_MASK
#define R_SCI9_SCR_SMCI_OFFSET            R_SCI2_SCR_SMCI_OFFSET
#define R_SCI9_SCR_SMCI                   R_SCI2_SCR_SMCI
#define R_SCI9_SCR_SMCI_TIE               R_SCI2_SCR_SMCI_TIE
#define R_SCI9_SCR_SMCI_RIE               R_SCI2_SCR_SMCI_RIE
#define R_SCI9_SCR_SMCI_TE                R_SCI2_SCR_SMCI_TE
#define R_SCI9_SCR_SMCI_RE                R_SCI2_SCR_SMCI_RE
#define R_SCI9_SCR_SMCI_MPIE              R_SCI2_SCR_SMCI_MPIE
#define R_SCI9_SCR_SMCI_TEIE              R_SCI2_SCR_SMCI_TEIE
#define R_SCI9_SCR_SMCI_CKE               R_SCI2_SCR_SMCI_CKE
#define R_SCI9_SCR_SMCI_CKE_MASK          R_SCI2_SCR_SMCI_CKE_MASK
#define R_SCI9_TDR_OFFSET                 R_SCI2_TDR_OFFSET
#define R_SCI9_TDR                        R_SCI2_TDR
#define R_SCI9_TDR_TDR                    R_SCI2_TDR_TDR
#define R_SCI9_TDR_TDR_MASK               R_SCI2_TDR_TDR_MASK
#define R_SCI9_SSR_OFFSET                 R_SCI2_SSR_OFFSET
#define R_SCI9_SSR                        R_SCI2_SSR
#define R_SCI9_SSR_TDRE                   R_SCI2_SSR_TDRE
#define R_SCI9_SSR_RDRF                   R_SCI2_SSR_RDRF
#define R_SCI9_SSR_ORER                   R_SCI2_SSR_ORER
#define R_SCI9_SSR_FER                    R_SCI2_SSR_FER
#define R_SCI9_SSR_PER                    R_SCI2_SSR_PER
#define R_SCI9_SSR_TEND                   R_SCI2_SSR_TEND
#define R_SCI9_SSR_MPB                    R_SCI2_SSR_MPB
#define R_SCI9_SSR_MPBT                   R_SCI2_SSR_MPBT
#define R_SCI9_SSR_SMCI_OFFSET            R_SCI2_SSR_SMCI_OFFSET
#define R_SCI9_SSR_SMCI                   R_SCI2_SSR_SMCI
#define R_SCI9_SSR_SMCI_TDRE              R_SCI2_SSR_SMCI_TDRE
#define R_SCI9_SSR_SMCI_RDRF              R_SCI2_SSR_SMCI_RDRF
#define R_SCI9_SSR_SMCI_ORER              R_SCI2_SSR_SMCI_ORER
#define R_SCI9_SSR_SMCI_ERS               R_SCI2_SSR_SMCI_ERS
#define R_SCI9_SSR_SMCI_PER               R_SCI2_SSR_SMCI_PER
#define R_SCI9_SSR_SMCI_TEND              R_SCI2_SSR_SMCI_TEND
#define R_SCI9_SSR_SMCI_MPB               R_SCI2_SSR_SMCI_MPB
#define R_SCI9_SSR_SMCI_MPBT              R_SCI2_SSR_SMCI_MPBT
#define R_SCI9_RDR_OFFSET                 R_SCI2_RDR_OFFSET
#define R_SCI9_RDR                        R_SCI2_RDR
#define R_SCI9_RDR_RDR                    R_SCI2_RDR_RDR
#define R_SCI9_RDR_RDR_MASK               R_SCI2_RDR_RDR_MASK
#define R_SCI9_SCMR_OFFSET                R_SCI2_SCMR_OFFSET
#define R_SCI9_SCMR                       R_SCI2_SCMR
#define R_SCI9_SCMR_BCP2                  R_SCI2_SCMR_BCP2
#define R_SCI9_SCMR_CHR1                  R_SCI2_SCMR_CHR1
#define R_SCI9_SCMR_SDIR                  R_SCI2_SCMR_SDIR
#define R_SCI9_SCMR_SINV                  R_SCI2_SCMR_SINV
#define R_SCI9_SCMR_SMIF                  R_SCI2_SCMR_SMIF
#define R_SCI9_SEMR_OFFSET                R_SCI2_SEMR_OFFSET
#define R_SCI9_SEMR                       R_SCI2_SEMR
#define R_SCI9_SEMR_RXDESEL               R_SCI2_SEMR_RXDESEL
#define R_SCI9_SEMR_BGDM                  R_SCI2_SEMR_BGDM
#define R_SCI9_SEMR_NFEN                  R_SCI2_SEMR_NFEN
#define R_SCI9_SEMR_ABCS                  R_SCI2_SEMR_ABCS
#define R_SCI9_SEMR_ABCSE                 R_SCI2_SEMR_ABCSE
#define R_SCI9_SEMR_BRME                  R_SCI2_SEMR_BRME
#define R_SCI9_SNFR_OFFSET                R_SCI2_SNFR_OFFSET
#define R_SCI9_SNFR                       R_SCI2_SNFR
#define R_SCI9_SNFR_NFCS                  R_SCI2_SNFR_NFCS
#define R_SCI9_SNFR_NFCS_MASK             R_SCI2_SNFR_NFCS_MASK
#define R_SCI9_SIMR1_OFFSET               R_SCI2_SIMR1_OFFSET
#define R_SCI9_SIMR1                      R_SCI2_SIMR1
#define R_SCI9_SIMR1_IICDL                R_SCI2_SIMR1_IICDL
#define R_SCI9_SIMR1_IICDL_MASK           R_SCI2_SIMR1_IICDL_MASK
#define R_SCI9_SIMR1_IICM                 R_SCI2_SIMR1_IICM
#define R_SCI9_SIMR2_OFFSET               R_SCI2_SIMR2_OFFSET
#define R_SCI9_SIMR2                      R_SCI2_SIMR2
#define R_SCI9_SIMR2_IICACKT              R_SCI2_SIMR2_IICACKT
#define R_SCI9_SIMR2_IICCSC               R_SCI2_SIMR2_IICCSC
#define R_SCI9_SIMR2_IICINTM              R_SCI2_SIMR2_IICINTM
#define R_SCI9_SIMR3_OFFSET               R_SCI2_SIMR3_OFFSET
#define R_SCI9_SIMR3                      R_SCI2_SIMR3
#define R_SCI9_SIMR3_IICSCLS              R_SCI2_SIMR3_IICSCLS
#define R_SCI9_SIMR3_IICSCLS_MASK         R_SCI2_SIMR3_IICSCLS_MASK
#define R_SCI9_SIMR3_IICSDAS              R_SCI2_SIMR3_IICSDAS
#define R_SCI9_SIMR3_IICSDAS_MASK         R_SCI2_SIMR3_IICSDAS_MASK
#define R_SCI9_SIMR3_IICSTIF              R_SCI2_SIMR3_IICSTIF
#define R_SCI9_SIMR3_IICSTPREQ            R_SCI2_SIMR3_IICSTPREQ
#define R_SCI9_SIMR3_IICRSTAREQ           R_SCI2_SIMR3_IICRSTAREQ
#define R_SCI9_SIMR3_IICSTAREQ            R_SCI2_SIMR3_IICSTAREQ
#define R_SCI9_SISR_OFFSET                R_SCI2_SISR_OFFSET
#define R_SCI9_SISR                       R_SCI2_SISR
#define R_SCI9_SISR_IICACKR               R_SCI2_SISR_IICACKR
#define R_SCI9_SPMR_OFFSET                R_SCI2_SPMR_OFFSET
#define R_SCI9_SPMR                       R_SCI2_SPMR
#define R_SCI9_SPMR_CKPH                  R_SCI2_SPMR_CKPH
#define R_SCI9_SPMR_CKPOL                 R_SCI2_SPMR_CKPOL
#define R_SCI9_SPMR_MFF                   R_SCI2_SPMR_MFF
#define R_SCI9_SPMR_MSS                   R_SCI2_SPMR_MSS
#define R_SCI9_SPMR_CTSE                  R_SCI2_SPMR_CTSE
#define R_SCI9_SPMR_SSE                   R_SCI2_SPMR_SSE
#define R_SCI9_TDRHL_OFFSET               R_SCI2_TDRHL_OFFSET
#define R_SCI9_TDRHL                      R_SCI2_TDRHL
#define R_SCI9_TDRHL_TDRHL                R_SCI2_TDRHL_TDRHL
#define R_SCI9_TDRHL_TDRHL_MASK           R_SCI2_TDRHL_TDRHL_MASK
#define R_SCI9_RDRHL_OFFSET               R_SCI2_RDRHL_OFFSET
#define R_SCI9_RDRHL                      R_SCI2_RDRHL
#define R_SCI9_RDRHL_RDRHL                R_SCI2_RDRHL_RDRHL
#define R_SCI9_RDRHL_RDRHL_MASK           R_SCI2_RDRHL_RDRHL_MASK
#define R_SCI9_MDDR_OFFSET                R_SCI2_MDDR_OFFSET
#define R_SCI9_MDDR                       R_SCI2_MDDR
#define R_SCI9_MDDR_MDDR                  R_SCI2_MDDR_MDDR
#define R_SCI9_MDDR_MDDR_MASK             R_SCI2_MDDR_MDDR_MASK
#define R_SCI9_DCCR_OFFSET                R_SCI2_DCCR_OFFSET
#define R_SCI9_DCCR                       R_SCI2_DCCR
#define R_SCI9_DCCR_DCME                  R_SCI2_DCCR_DCME
#define R_SCI9_DCCR_IDSEL                 R_SCI2_DCCR_IDSEL
#define R_SCI9_DCCR_DFER                  R_SCI2_DCCR_DFER
#define R_SCI9_DCCR_DPER                  R_SCI2_DCCR_DPER
#define R_SCI9_DCCR_DCMF                  R_SCI2_DCCR_DCMF
#define R_SCI9_CDR_OFFSET                 R_SCI2_CDR_OFFSET
#define R_SCI9_CDR                        R_SCI2_CDR
#define R_SCI9_CDR_CMPD                   R_SCI2_CDR_CMPD
#define R_SCI9_CDR_CMPD_MASK              R_SCI2_CDR_CMPD_MASK
#define R_SCI9_SPTR_OFFSET                R_SCI2_SPTR_OFFSET
#define R_SCI9_SPTR                       R_SCI2_SPTR
#define R_SCI9_SPTR_SPB2IO                R_SCI2_SPTR_SPB2IO
#define R_SCI9_SPTR_SPB2DT                R_SCI2_SPTR_SPB2DT
#define R_SCI9_SPTR_RXDMON                R_SCI2_SPTR_RXDMON

/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Public Functions Prototypes
 ****************************************************************************/

#endif /* __ARCH_ARM_SRC_RA4M1_HARDWARE_RA4_SCI_H */
