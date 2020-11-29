`default_nettype none
`timescale 1ns / 1ps


//`define USE_UART_RX
//`define USE_UART_TX
//`define USE_SPI_CTRL
//`define USE_GPIO
`define USE_LEDS
//`define USE_SRAM


module bram_mem #(parameter ROM_FILE="") (
    input clk,
    input [3:0] wen,
    input [11:0] addr,
    input [31:0] wdata,
    output reg [31:0] rdata);

  reg [31:0] mem [0:4096];

  initial begin
    if (ROM_FILE)
      $readmemh(ROM_FILE, mem);
  end

  always @(posedge clk) begin
    rdata <= mem[addr];
    if (wen[0]) mem[addr][ 7: 0] <= wdata[ 7: 0];
    if (wen[1]) mem[addr][15: 8] <= wdata[15: 8];
    if (wen[2]) mem[addr][23:16] <= wdata[23:16];
    if (wen[3]) mem[addr][31:24] <= wdata[31:24];
  end
endmodule

`ifdef USE_SRAM
`include "rtl/sram.v"
`endif

// simple uart receiver
`ifdef USE_UART_RX
`include "uart_rx.v"
`endif  // USE_UART_RX

// simple uart transmitter
`ifdef USE_UART_TX
`include "uart_tx.v"
`endif  // USE_UART_TX

// basic SPI controller
`ifdef USE_SPI_CTRL
`include "spi_ctrl.v"
`endif  // USE_SPI_CTRL

// general purpose input output
`ifdef USE_GPIO
`include "gpio.v"
`endif  // USE_GPIO

// system on chip instance
module soc_t #(parameter ROM_FILE="") (
    input clk,
    input reset,
    input wire spi_miso,
    input wire rx,
    output wire [7:0] leds,
    output wire tx,
    output wire spi_mosi,
    output wire spi_sck,
    output wire spi_cs,
    inout gpio);

`ifdef USE_GPIO
  // GPIO peripheral
  wire [31:0] gpio_dout;
  gpio_t gpio_inst(.clk(clk),
                   .reset(reset),
                   .wen(sel_gpio & is_write),
                   .addr(cpu_addr),
                   .wdata(cpu_out_data),
                   .gpio_pin(gpio),
                   .rdata(gpio_dout));
`endif  // USE_GPIO

`ifdef USE_LEDS
  // LED peripheral
  reg[7:0] led_state;
  assign leds = led_state;
  always @(posedge clk) begin
    if (sel_led && is_write) begin
      led_state <= cpu_out_data[7:0];
    end
  end
`endif  // USE_LEDS

  // address decoding
  wire is_write    = cpu_wr;
  wire sel_bram    = (cpu_addr[31:24] ==  8'hf0);        // 0xf0000000 -> 0xf0ffffff
`ifdef USE_LEDS
  wire sel_led     = (cpu_addr[31: 8] == 24'h100000);    // 0x10000000 -> 0x100000ff
`endif  // USE_LEDS
`ifdef USE_UART_TX
  wire sel_uart_tx = (cpu_addr[31: 8] == 24'h100001);    // 0x10000100 -> 0x100001ff
`endif  // USE_UART_TX
`ifdef USE_SPI_CTRL
  wire sel_spi     = (cpu_addr[31: 8] == 24'h100002);    // 0x10000200 -> 0x100002ff
`endif  // USE_SPI_CTRL
`ifdef USE_UART_RX
  wire sel_uart_rx = (cpu_addr[31: 8] == 24'h100003);    // 0x10000300 -> 0x100003ff
`endif  // USE_UART_RX
`ifdef USE_GPIO
  wire sel_gpio    = (cpu_addr[31: 8] == 24'h100004);    // 0x10000400 -> 0x100004ff
`endif  // USE_GPIO
`ifdef USE_SRAM
  wire sel_sram    = (cpu_addr[31: 8] == 24'h100005);    // 0x10000500 -> 0x100005ff
`endif  // USE_SRAM

  // select data being read into the CPU
  reg [31:0] cpu_in_data;
  always @* begin
    casez (cpu_addr[31:8])
    24'hf0????: cpu_in_data = bram_dout;
`ifdef USE_LEDS
    24'h100000: cpu_in_data = led_state;
`endif
`ifdef USE_UART_TX
    24'h100001: cpu_in_data = uart_tx_dout;
`endif  // USE_UART_TX
`ifdef USE_SPI_CTRL
    24'h100002: cpu_in_data = spi_dout;
`endif  // USE_SPI_CTRL
`ifdef USE_UART_RX
    24'h100003: cpu_in_data = uart_rx_dout;
`endif  // USE_UART_RX
`ifdef USE_GPIO
    24'h100004: cpu_in_data = gpio_dout;
`endif  // USE_GPIO
`ifdef USE_SRAM
    24'h100005: cpu_in_data = { 16'd0, sram_dio };
`endif
    default:    cpu_in_data = 32'dX;
    endcase
  end

`ifdef USE_UART_TX
  // uart transmitter
  wire [31:0] uart_tx_dout;
  uart_tx_t uart_tx(.clk(clk),
                    .wen(sel_uart_tx & is_write),
                    .addr(cpu_addr),
                    .wdata(cpu_out_data),
                    .rdata(uart_tx_dout),
                    .tx(tx));
`endif  // USE_UART_TX

`ifdef USE_SPI_CTRL
  // spi controller
  wire [31:0] spi_dout;
  spi_ctrl_t spi(.clk(clk),
                 .reset(reset),
                 .wen(sel_spi & is_write),
                 .addr(cpu_addr),
                 .wdata(cpu_out_data),
                 .miso(spi_miso),
                 .rdata(spi_dout),
                 .sck(spi_sck),
                 .cs(spi_cs),
                 .mosi(spi_mosi));
`endif  // USE_SPI_CTRL

`ifdef USE_UART_RX
  // uart receiver
  wire [31:0] uart_rx_dout;
  uart_rx_t uart_rx(.clk(clk),
                    .wen(sel_uart_rx & is_write),
                    .addr(cpu_addr),
                    .wdata(cpu_out_data),
                    .rx(rx),
                    .rdata(uart_rx_dout));
`endif  // USE_UART_RX

`ifdef USE_SRAM
sram_t sram(cpu_addr[5:2],
            !sel_sram,
            !(cpu_wr & clk),
            cpu_wr,
            cpu_write_mask[0],
            cpu_write_mask[1],
            sram_dio);
wire [15:0] sram_dio;
assign sram_dio = cpu_wr ? cpu_out_data[15:0] : 16'hzzzz;
`endif  // USE_SRAM

  // block ram (16kb)
  wire [31:0] bram_dout;
  bram_mem #(.ROM_FILE(ROM_FILE))
      ram1(.clk(clk),
           .wen((sel_bram & cpu_wr) ? cpu_write_mask :
                                      4'd0),
           .addr(cpu_addr[13:2]),
           .wdata(cpu_out_data),
           .rdata(bram_dout));

  // the CPU
  wire [31:0] cpu_out_data;
  wire [31:0] cpu_addr;
  wire [ 3:0] cpu_write_mask;
  wire cpu_rd;
  wire cpu_wr;
  rv32i_cpu_t
      #(.RESET_VECTOR (32'hf0000000),
        .STACK_POINTER(32'hf0ffffff))
      cpu(
        .clk(clk),
        .reset(reset),
        .hold(1'b0),
        .in_data(cpu_in_data),
        .out_wr_mask(cpu_write_mask),
        .out_mem_addr(cpu_addr),
        .out_data(cpu_out_data),
        .out_wr(cpu_wr),
        .out_rd(cpu_rd));

endmodule
