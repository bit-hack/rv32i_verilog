`default_nettype none
`timescale 1ns / 1ps

//
// simple sram model (IS61WV25616EDBLL)
//
module sram_t(input [3:0] addr,   // address bus
              input ce,           // chip enable    (act. low)
              input we,           // write enable   (act. low)
              input oe,           // output enable  (act. low)
              input lb,           // low byte       (act. low)
              input ub,           // upper byte     (act. low)
              inout [15:0] data); // i/o data

  wire [15:0] d0 = { memu[0], meml[0] };    // debug
  wire [15:0] d1 = { memu[1], meml[1] };    // debug

  reg [7:0] meml[15:0];
  reg [7:0] memu[15:0];

  reg [7:0] outl;
  reg [7:0] outh;

  // read
  assign data = { (ce|oe|!we|ub) ? 8'bzzzzzzzz : memu[addr],
                  (ce|oe|!we|lb) ? 8'bzzzzzzzz : meml[addr] };

  // write
  always @* begin
    if (!ce & !we & oe) begin
      if (ub) memu[addr] = data[15:8];
      if (lb) meml[addr] = data[ 7:0];
    end
  end
endmodule
