#pragma once
#include <stdint.h>
#include <stdbool.h>


#define hw_leds            ((volatile uint8_t*) 0x10000000)
#define hw_uart_tx_data    ((volatile uint8_t*) 0x10000100)
#define hw_uart_tx_clk_div ((volatile uint32_t*)0x10000104)
#define hw_uart_tx_status  ((volatile uint8_t*) 0x10000108)
#define hw_spi_tx          ((volatile uint8_t*) 0x10000200)
#define hw_spi_clk_div     ((volatile uint32_t*)0x10000204)
#define hw_spi_rx          ((volatile uint8_t*) 0x10000208)
#define hw_spi_status      ((volatile uint8_t*) 0x1000020c)
#define hw_spi_cs          ((volatile uint8_t*) 0x10000210)
#define hw_uart_rx_data    ((volatile uint8_t*) 0x10000300)
#define hw_uart_rx_clk_div ((volatile uint32_t*)0x10000304)
#define hw_uart_rx_status  ((volatile uint8_t*) 0x10000308)
#define hw_gpio_data       ((volatile uint8_t*) 0x10000400)
#define hw_gpio_oe         ((volatile uint8_t*) 0x10000404)
#define hw_sram            ((volatile uint8_t*) 0x10000500)


static void delay(int32_t cycles) {
  for (;--cycles;) {
    __asm__ __volatile__ ("nop");
  }
}

static void spi_set_cs(uint8_t val) {
  *hw_spi_cs = val;
}

static void spi_set_clock_div(uint32_t div) {
  *hw_spi_clk_div = div;
}

static uint8_t spi_send(uint8_t in) {
  *hw_spi_tx = in;
  while (*hw_spi_status != 0) {
  }
  delay(10);
  return *hw_spi_rx;
}

static void uart_send_byte(uint8_t data) {
  while (*hw_uart_tx_status != 0) {
  }
  *hw_uart_tx_data = data;
}

static void uart_recv_clear() {
  *hw_uart_rx_status = 0;
}

static uint8_t uart_recv_byte() {
  while (*hw_uart_rx_status != 0x01) {
    // busy or not pending
  }
  const uint8_t got = *hw_uart_rx_data;
  uart_recv_clear();
  return got;
}

static bool uart_recv_pending() {
  return *hw_uart_rx_status & 0x01 != 0;
}

static void uart_send_string(const char *str) {
  while (*str) {
    uart_send_byte(*str);
    ++str;
  }
}

static void uart_set_clock_div(uint32_t div) {
  *hw_uart_tx_clk_div = div;
  *hw_uart_rx_clk_div = div;
}

// set pint output
static void set_gpio_pin(uint8_t in) {
  *hw_gpio_data = in;
}

// read pin input
static uint8_t get_gpio_pin(uint8_t in) {
  return *hw_gpio_data;
}

// 1 = enabled, 0 = disabled
static void set_gpio_oe(uint8_t oe) {
  *hw_gpio_oe = oe;
}

static void set_leds(uint8_t state) {
  *hw_leds = state;
}
