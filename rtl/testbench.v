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
    #200000 $finish;
  end

  wire spi_mosi;
  reg  spi_miso;
  wire spi_clk;
  wire spi_cs;

  wire gpio;

  // instanciate the soc
  wire [7:0] leds;
  wire tx;
  wire rx = tx;
  soc_t #(.ROM_FILE("tests/gpio/out.hex"))
      soc(CLK,
          !resetn,
          spi_miso,
          rx,
          leds,
          tx,
          spi_mosi,
          spi_clk,
          spi_cs,
          gpio);

endmodule
