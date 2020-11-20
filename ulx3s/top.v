`default_nettype none
`timescale 1ns / 1ps

module top(input clk_25mhz,
           inout [3:0] sd_d,  // mosi, nc, nc, cs
           output sd_clk,      // spi_clk
           output sd_cmd,     // mosi
           output [7:0] led,
           output ftdi_rxd);

  // initial state
  initial begin
    reset_cnt <= 10'd0;
  end

  // reset generator
  reg [4:0] reset_cnt;
  wire resetn = &reset_cnt;
  always @(posedge clk_25mhz) begin
    reset_cnt <= reset_cnt + !resetn;
  end

  // soc instance
  soc_t #(.ROM_FILE("out.hex")) soc(
    clk_25mhz,
    !resetn,
    sd_d[0]   // spi_miso
    led,
    ftdi_rxd, // tx
    sd_cmd,   // spi_mosi
    sd_clk,   // spi_clk
    sd_d[3]); // spi_cs

endmodule
