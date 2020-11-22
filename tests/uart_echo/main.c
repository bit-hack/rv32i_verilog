#include <stdint.h>
#include "../common.h"

enum {
  clk_speed = 25000000,
  uart_rate = clk_speed / 9600,
};

int main() {
  *hw_leds = 0;
  uart_set_clock_div(uart_rate);
  for (;;) {
    if (uart_recv_pending()) {
      uint8_t r = uart_recv_byte();
      uart_send_byte(r);
      *hw_leds = r;
    }
  }
}
