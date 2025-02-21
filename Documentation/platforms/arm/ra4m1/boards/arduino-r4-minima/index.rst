================
Arduino R4 Minima
================

That board features the R7FA4M1ABxCFM MCU with 256KiB of FLASH
and 32KiB of SRAM running at 64MHz (internal clock - HOCO).

Buttons and LEDs
================

  Buttons
  -------
  There are no buttons on the Arduino Due board.

  LEDs
  ----
  There are three user-controllable LEDs on board the Arduino Due board:

      LED              GPIO
      ---------------- -----
      L   Amber LED    P111
      TX  Yellow LED   P012
      RX  Yellow LED   P013

  LED L is connected to ground and can be illuminated by driving the P111
  output high. The TX and RX LEDs are pulled high and can be illuminated by
  driving the corresponding
  GPIO output to low.

  These LEDs are not used by the board port unless CONFIG_ARCH_LEDS is
  defined.  In that case, the usage by the board port is defined in
  include/board.h and src/sam_leds.c. The LEDs are used to encode OS-related
  events as follows:

    SYMBOL                MEANING                         LED STATE
                                                    L         TX       RX
    -------------------  -----------------------  -------- -------- --------
    LED_STARTED          NuttX has been started     OFF      OFF      OFF
    LED_HEAPALLOCATE     Heap has been allocated    OFF      OFF      OFF
    LED_IRQSENABLED      Interrupts enabled         OFF      OFF      OFF
    LED_STACKCREATED     Idle stack created         ON       OFF      OFF
    LED_INIRQ            In an interrupt            N/C      GLOW     OFF
    LED_SIGNAL           In a signal handler        N/C      GLOW     OFF
    LED_ASSERTION        An assertion failed        N/C      GLOW     OFF
    LED_PANIC            The system has crashed     N/C      N/C      Blinking
    LED_IDLE             MCU is is sleep mode       ------ Not used --------

  Thus if LED L is statically on, NuttX has successfully booted and is,
  apparently, running normally.  If LED RX is glowing, then NuttX is
  handling interrupts (and also signals and assertions).  If TX is flashing
  at approximately 2Hz, then a fatal error has been detected and the system
  has halted.

Serial Consoles
===============

  The R7FA4M1ABxCFM has a UART and 4 SCI.

  Any of SCI may be used as a serial console.  By default,
  the SCI2 is used as the serial console in all configurations.  But that is
  easily changed by modifying the configuration.

Loading Code
============

It is possible to use Jlink on the SWD connector or use the USB Boot avaliable throught the USB-C connector.

RA USB Boot:
-----------

Reboot the board with BOOT shorted to GND and press the reset button twice (double click). The board will enumerate as Renesas RA USB Boot.

Then flash the Nuttx.hex* with rfp-cli (https://www.renesas.com/en/software-tool/renesas-flash-programmer-programming-gui)

e.g:
rfp-cli -device ra -port /dev/ttyACM0 -p ./build/nuttx.hex

* Programming using the binary format will fail because, by default, the RA4M1 NuttX port writes to the .idcode section, which is located beyond the end of the flash area. This causes the RFP to attempt writing to protected regions, leading to failures.
