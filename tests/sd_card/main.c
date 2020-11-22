#include <stdint.h>
#include "../common.h"

// links
//    http://elm-chan.org/docs/mmc/mmc_e.html#spiinit
//    https://openlabpro.com/guide/interfacing-microcontrollers-with-sd-card/

enum {
  clk_speed = 25000000,
  spi_rate = clk_speed / 200000, // 200khz
};

enum {
  sd_cmd0 = 0x40,
};

int main() {
  *hw_leds = 0xcc;
  spi_set_clock_div(spi_rate);

  // card init
  spi_set_cs(1);      // cs high
  for (int i=0; i<10; ++i) {
    spi_send(0xff);
  }

  for (;;) {
    spi_send(0xff);     // drive `do` pin high
    spi_set_cs(0);      // cs low

    spi_send(0xff);     // dummy
    spi_send(0xff);     // dummy
    spi_send(0x40);     // command
    spi_send(0x00);     // arg 0
    spi_send(0x00);     // arg 1
    spi_send(0x00);     // arg 2
    spi_send(0x00);     // arg 3
    spi_send(0x95);     // crc

    uint8_t res = 0x80;
    do {
      uint8_t res = spi_send(0xff);
    } while (res & 0x80);
    *hw_leds = res;

    spi_set_cs(1);      // cs high
    delay(200);
  }
}
