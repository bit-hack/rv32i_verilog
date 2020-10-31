#include <stdint.h>

volatile uint8_t  *leds         = (uint8_t*) 0x80000000;
volatile uint8_t  *uart_data    = (uint8_t*) 0x70000000;
volatile uint32_t *uart_clk_div = (uint32_t*)0x70000004;
volatile uint8_t  *uart_status  = (uint8_t*) 0x70000008;

const char *message = "Hello World\r\n";

void uart_send_byte(uint8_t data) {
  while (*uart_status != 0) {
  }
  *uart_data = data;
}

void uart_send_string(const char *str) {
  while (*str) {
    uart_send_byte(*str);
    ++str;
  }
}

void delay(int32_t cycles) {
  // 12 cycles per loop
  for (;--cycles;) {
    __asm__ __volatile__ ("nop");
  }
}

int main() {
  *leds = 0;
  *uart_clk_div = 1250;  // (12000000 / 9600)
  for (;;) {
    uart_send_string(message);
    delay(1000000);
    ++(*leds);
  }
}
