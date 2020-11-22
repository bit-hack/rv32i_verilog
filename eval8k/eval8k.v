`default_nettype none
`timescale 1ns / 1ps

module top(input CLK, input RX, output [7:0] LED, output TX);

  // initial state
  initial begin
    reset_cnt <= 10'd0;
    spi_miso <= 1'b0;
  end

  // reset generator
  reg [4:0] reset_cnt;
  wire resetn = &reset_cnt;
  always @(posedge CLK) begin
  
    reset_cnt <= reset_cnt + !resetn;
  end

  wire spi_mosi;
  reg  spi_miso;
  wire spi_clk;
  wire spi_cs;

  // instanciate the soc  
  soc_t #(.ROM_FILE("rom_uart.hex"))
      soc(CLK,
          !resetn,
          spi_miso,
          RX,
          LED,
          TX,
          spi_mosi,
          spi_clk,
          spi_cs);
  
endmodule
