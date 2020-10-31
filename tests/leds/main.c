#include <stdint.h>

volatile uint8_t  *leds         = (uint8_t*) 0x80000000;
volatile uint8_t  *uart_data    = (uint8_t*) 0x70000000;
volatile uint32_t *uart_clk_div = (uint32_t*)0x70000004;
volatile uint8_t  *uart_status  = (uint8_t*) 0x70000008;

int main() {
  *leds = 0xcc;
  for (;;) {
    (*leds)++;
  }
}
