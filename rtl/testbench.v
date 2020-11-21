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
    spi_miso <= 0;
    #2000000 $finish;
  end

  wire spi_mosi;
  reg  spi_miso;
  wire spi_clk;
  wire spi_cs;
  
  // instanciate the soc
  wire [7:0] leds;
  wire tx;
  soc_t #(.ROM_FILE("tests/sd_card/out.hex"))
      soc(CLK,
          !resetn,
          spi_miso,
          leds,
          tx,
          spi_mosi,
          spi_clk,
          spi_cs);

endmodule
