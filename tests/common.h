#pragma once
#include <stdint.h>
#include <stdbool.h>


volatile uint8_t  *hw_leds            = (uint8_t*) 0x10000000;

volatile uint8_t  *hw_uart_tx_data    = (uint8_t*) 0x10000100;
volatile uint32_t *hw_uart_tx_clk_div = (uint32_t*)0x10000104;
volatile uint8_t  *hw_uart_tx_status  = (uint8_t*) 0x10000108;

volatile uint8_t  *hw_uart_rx_data    = (uint8_t*) 0x10000300;
volatile uint32_t *hw_uart_rx_clk_div = (uint32_t*)0x10000304;
volatile uint8_t  *hw_uart_rx_status  = (uint8_t*) 0x10000308;

volatile uint8_t  *hw_spi_tx          = (uint8_t*) 0x10000200;
volatile uint32_t *hw_spi_clk_div     = (uint32_t*)0x10000204;
volatile uint8_t  *hw_spi_rx          = (uint8_t*) 0x10000208;
volatile uint8_t  *hw_spi_status      = (uint8_t*) 0x1000020c;
volatile uint8_t  *hw_spi_cs          = (uint8_t*) 0x10000210;

void delay(int32_t cycles) {
  for (;--cycles;) {
    __asm__ __volatile__ ("nop");
  }
}

void spi_set_cs(uint8_t val) {
  *hw_spi_cs = val;
}

void spi_set_clock_div(uint32_t div) {
  *hw_spi_clk_div = div;
}

uint8_t spi_send(uint8_t in) {
  *hw_spi_tx = in;
  while (*hw_spi_status != 0) {
  }
  delay(10);
  return *hw_spi_rx;
}

void uart_send_byte(uint8_t data) {
  while (*hw_uart_tx_status != 0) {
  }
  *hw_uart_tx_data = data;
}

void uart_recv_clear() {
  *hw_uart_rx_status = 0;
}

uint8_t uart_recv_byte() {
  while (*hw_uart_rx_status != 0x01) {
    // busy or not pending
  }
  const uint8_t got = *hw_uart_rx_data;
  uart_recv_clear();
  return got;
}

bool uart_recv_pending() {
  return *hw_uart_rx_status & 0x01 != 0;
}

void uart_send_string(const char *str) {
  while (*str) {
    uart_send_byte(*str);
    ++str;
  }
}

void uart_set_clock_div(uint32_t div) {
  *hw_uart_tx_clk_div = div;
  *hw_uart_rx_clk_div = div;
}
