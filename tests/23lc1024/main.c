#include <stdint.h>
#include "../common.h"

// 23lc1024 pin mapping
//
// 1  CS
// 2  MISO
// 3  (tie gnd)
// 4  GND
// 5  MOSI
// 6  SCK
// 7  (tie vcc)
// 8  VCC

enum {
  clk_speed = 12000000,
  delay_time = (clk_speed / (12 * 10)),
  spi_rate = clk_speed / 100000,
};

static inline void write(uint32_t addr, uint8_t data) {
  spi_set_cs(0);
  // write command
  spi_send(0x02);
  // address
  spi_send((addr >> 16) & 0xff);
  spi_send((addr >> 8 ) & 0xff);
  spi_send((addr      ) & 0xff);
  // data
  spi_send(data);
  spi_set_cs(1);
}

static inline uint8_t read(uint32_t addr) {
  spi_set_cs(0);
  uint8_t out = 0;
  // read command
  spi_send(0x03);
  // address
  spi_send((addr >> 16) & 0xff);
  spi_send((addr >> 8 ) & 0xff);
  spi_send((addr      ) & 0xff);
  // data
  out = spi_send(0x00);
  spi_set_cs(1);
  return out;
}

int main() {
  *hw_leds = 0;
  spi_set_clock_div(spi_rate);
  for (int i=0;;++i) {
    write(i, i);
    *hw_leds = read(i);
    delay(delay_time);
  }
}
