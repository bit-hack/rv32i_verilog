#include <stdint.h>

#include "../common.h"

int main() {
  uint32_t x = 12345;
  *hw_leds = x;
  for (;;) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *hw_leds = x;
  }
}
