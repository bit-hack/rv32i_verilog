#pragma once
#include <stdint.h>

volatile uint8_t  *hw_leds         = (uint8_t*) 0x10000000;
volatile uint8_t  *hw_uart_data    = (uint8_t*) 0x10000100;
volatile uint32_t *hw_uart_clk_div = (uint32_t*)0x10000104;
volatile uint8_t  *hw_uart_status  = (uint8_t*) 0x10000108;

void uart_send_byte(uint8_t data) {
  while (*hw_uart_status != 0) {
  }
  *hw_uart_data = data;
}

void uart_send_string(const char *str) {
  while (*str) {
    uart_send_byte(*str);
    ++str;
  }
}

void uart_set_clock_div(uint32_t div) {
  *hw_uart_clk_div = div;
}

void delay(int32_t cycles) {
  for (;--cycles;) {
    __asm__ __volatile__ ("nop");
  }
}
