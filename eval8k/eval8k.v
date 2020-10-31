`default_nettype none
`timescale 1ns / 1ps

module top(input CLK, output [7:0] LED, output TX);

  // initial state
  initial begin
    reset_cnt <= 10'd0;
  end

  // reset generator
  reg [4:0] reset_cnt;
  wire resetn = &reset_cnt;
  always @(posedge CLK) begin
    reset_cnt <= reset_cnt + !resetn;
  end

  // instanciate the soc
  soc_t #(.ROM_FILE("rom_uart.hex")) soc(CLK, !resetn, LED, TX);

endmodule
