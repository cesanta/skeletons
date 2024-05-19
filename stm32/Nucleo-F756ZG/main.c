// SPDX-FileCopyrightText: 2024 Cesanta Software Limited
// SPDX-License-Identifier: AGPL-3.0 or commercial

#include "hal.h"

int main(void) {
  hal_init();  // Cross-platform hardware init

  // Blink an LED
  uint64_t timer = 0;
  for (;;) {
    uint64_t ticks = clock_get_ticks();
    if (timer < ticks) {
      gpio_toggle(LED1);
      printf("CPU %lu MHz, ticks: %lu\r\n", SystemCoreClock / 1000000,
             (unsigned long) ticks);
      timer += 500;
    }
  }

  return 0;
}
