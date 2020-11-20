#pragma once
#include <stdint.h>

volatile uint8_t  *hw_leds         = (uint8_t*) 0x10000000;

volatile uint8_t  *hw_uart_data    = (uint8_t*) 0x10000100;
volatile uint32_t *hw_uart_clk_div = (uint32_t*)0x10000104;
volatile uint8_t  *hw_uart_status  = (uint8_t*) 0x10000108;

volatile uint8_t  *hw_spi_tx       = (uint8_t*) 0x10000200;
volatile uint32_t *hw_spi_clk_div  = (uint32_t*)0x10000204;
volatile uint8_t  *hw_spi_rx       = (uint8_t*) 0x10000208;
volatile uint8_t  *hw_spi_status   = (uint8_t*) 0x1000020c;
volatile uint8_t  *hw_spi_cs       = (uint8_t*) 0x10000210;

void spi_set_clock_div(uint32_t div) {
  *hw_spi_clk_div = div;
}

uint8_t spi_send(uint8_t in) {
  *hw_spi_tx = in;
  while (*hw_spi_status != 0) {
  }
  return *hw_spi_rx;
}

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
