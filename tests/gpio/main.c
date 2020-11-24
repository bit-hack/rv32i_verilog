#include <stdint.h>

#include "../common.h"

int main() {
  set_gpio_oe(1);
  for (int i=0;;++i) {
    set_gpio_pin(i & 1);
    set_leds(i & 1);
    delay(12000000 / 12);
  }
}
