#include <stdint.h>

#include "../common.h"

int main() {
  *hw_leds = 0xcc;
  for (;;) {
    (*hw_leds)++;
  }
}
