`default_nettype none
`timescale 1ns / 1ps

module top();

  // clock generator
  reg CLK;
  always @(*) begin
    // toggle the clock
    #20 CLK <= ~CLK;
  end

  // reset generator
  reg [2:0] reset_cnt;
  wire resetn = &reset_cnt;
  always @(posedge CLK) begin
    reset_cnt <= reset_cnt + !resetn;
  end

  // initial state
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    CLK <= 0;
    reset_cnt <= 0;
    #100000 $finish;
  end

  // instanciate the soc
  wire [7:0] leds;
  wire tx;
  soc_t #(.ROM_FILE("tests/leds/out.hex")) soc(CLK, !resetn, leds, tx);

endmodule
