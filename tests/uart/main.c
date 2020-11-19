#include <stdint.h>
#include "../common.h"

const char *message = "Hello World\r\n";

enum {
  clk_speed = 25000000,
  uart_rate = clk_speed / 9600,
};

int main() {
  *hw_leds = 0;
  uart_set_clock_div(uart_rate);
  for (;;) {
    uart_send_string(message);
    delay(1000000);
    ++(*hw_leds);
  }
}
