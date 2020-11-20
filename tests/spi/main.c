#include <stdint.h>
#include "../common.h"

enum {
  clk_speed = 25000000,
  spi_rate = 2,
};

int main() {
  spi_set_clock_div(spi_rate);
  for (;;) {
    *hw_spi_cs = 0;
    spi_send(0x01);
    spi_send(0x80);
    spi_send(0xFF);
    spi_send(0x00);
    *hw_spi_cs = 1;
    delay(20);
  }
}
