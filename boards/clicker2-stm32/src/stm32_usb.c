/************************************************************************************
 * boards/clicker2-stm32/src/stm32_usb.c
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************/

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>
#include <debug.h>

#include "stm32_otgfs.h"
#include "clicker2-stm32.h"

#ifdef CONFIG_STM32_OTGFS

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

#ifdef CONFIG_USBDEV
#  define HAVE_USB 1
#else
#  warning "CONFIG_STM32_OTGFS is enabled but CONFIG_USBDEV is not"
#  undef HAVE_USB
#endif

/************************************************************************************
 * Public Functions
 ************************************************************************************/

/************************************************************************************
 * Name: stm32_usb_configure
 *
 * Description:
 *   Called from stm32_boardinitialize very early in inialization to setup USB-related
 *   GPIO pins for the Olimex STM32 P407 board.
 *
 ************************************************************************************/

void stm32_usb_configure(void)
{
#ifdef CONFIG_STM32_OTGFS
  /* The OTG FS has an internal soft pull-up.  No GPIO configuration is required */

  /* Configure the OTG FS VBUS sensing GPIO */

  stm32_configgpio(GPIO_OTGFS_VBUS);
#endif
}

/************************************************************************************
 * Name:  stm32_usbsuspend
 *
 * Description:
 *   Board logic must provide the stm32_usbsuspend logic if the USBDEV driver is
 *   used.  This function is called whenever the USB enters or leaves suspend mode.
 *   This is an opportunity for the board logic to shutdown clocks, power, etc.
 *   while the USB is suspended.
 *
 ************************************************************************************/

#ifdef CONFIG_USBDEV
void stm32_usbsuspend(FAR struct usbdev_s *dev, bool resume)
{
  uinfo("resume: %d\n", resume);
}
#endif

#endif /* CONFIG_STM32_OTGFS */
