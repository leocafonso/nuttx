/****************************************************************************
 * arch/renesas/src/common/renesas_doirq.c
 *
 * SPDX-License-Identifier: Apache-2.0
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
#include <assert.h>

#include <nuttx/irq.h>
#include <nuttx/arch.h>
#include <nuttx/board.h>
#include <arch/board/board.h>
#include <sched/sched.h>

#include "renesas_internal.h"
#include "group/group.h"

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

uint32_t *renesas_doirq(int irq, uint32_t * regs)
{
  struct tcb_s **running_task = &g_running_tasks[this_cpu()];

  if (*running_task != NULL)
    {
      renesas_copystate((*running_task)->xcp.regs, regs);
    }

  board_autoled_on(LED_INIRQ);
#ifdef CONFIG_SUPPRESS_INTERRUPTS
  PANIC();
#else
  if ((unsigned)irq < NR_IRQS)
    {
      /* Current regs non-zero indicates that we are processing
       * an interrupt; g_current_regs is also used to manage
       * interrupt level context switches.
       *
       * Nested interrupts are not supported.
       */

      DEBUGASSERT(up_current_regs() == NULL);
      up_set_current_regs(regs);

      /* Deliver the IRQ */

      irq_dispatch(irq, regs);

      /* Check for a context switch.  If a context switch occurred, then
       * g_current_regs will have a different value than it did on entry.
       * If an interrupt level context switch has occurred, then restore the
       * floating point state and the establish the correct address
       * environment before returning from the interrupt.
       */

      if (regs != up_current_regs())
        {
#ifdef CONFIG_ARCH_FPU
          /* Restore floating point registers */

          up_restorefpu(up_current_regs());
#endif

#ifdef CONFIG_ARCH_ADDRENV
          /* Make sure that the address environment for the previously
           * running task is closed down gracefully (data caches dump,
           * MMU flushed) and set up the address environment for the new
           * thread at the head of the ready-to-run list.
           */

          addrenv_switch(NULL);
#endif

          /* Record the new "running" task when context switch occurred.
           * g_running_tasks[] is only used by assertion logic for reporting
           * crashes.
           */

          g_running_tasks[this_cpu()] = this_task();
        }

      /* Get the current value of regs... it may have changed because
       * of a context switch performed during interrupt processing.
       */

      regs = up_current_regs();

      /* Set g_current_regs to NULL to indicate that we are no longer in an
       * interrupt handler.
       */

      up_set_current_regs(NULL);
    }

  board_autoled_off(LED_INIRQ);
#endif
  return regs;
}
