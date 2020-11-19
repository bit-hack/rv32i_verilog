`default_nettype none
`timescale 1ns / 1ps

module top(input clk_25mhz,
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

  // instanciate the soc
  soc_t #(.ROM_FILE("out.hex")) soc(clk_25mhz, !resetn, led, ftdi_rxd);

endmodule
