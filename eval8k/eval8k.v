`default_nettype none
`timescale 1ns / 1ps

module top(input CLK,
           input RX,
           input SPI_MISO,
           output SPI_CLK,
           output SPI_MOSI,
           output SPI_CS,
           output [7:0] LED,
           output TX);

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
  soc_t #(.ROM_FILE("../tests/uart_echo/out.hex"))
      soc(CLK,
          !resetn,
          SPI_MISO,
          RX,
          LED,
          TX,
          SPI_MOSI,
          SPI_CLK,
          SPI_CS);
  
endmodule
