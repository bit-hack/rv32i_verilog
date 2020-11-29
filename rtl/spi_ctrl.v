module spi_ctrl_t(input clk,
                  input reset,
                  input wen,
                  input [31:0] addr,
                  input [31:0] wdata,
                  input miso,
                  output reg [31:0] rdata,
                  output reg sck,
                  output reg cs,
                  output wire mosi);

  reg [ 7:0] srin;
  reg [ 7:0] srout;
  reg [31:0] clk_div;
  reg [31:0] clk_count;
  reg [ 3:0] remain;

  assign mosi = srout[7];

  initial begin
    clk_div   <= 1;
    clk_count <= 0;
    remain    <= 4'h0;
    srin      <= 8'h00;
    srout     <= 8'h00;
    sck       <= 0;
    cs        <= 1;
  end

  always @(posedge clk) begin
    if (wen) begin
      // new byte to send
      if (addr[7:0] == 8'd0) begin
        srout     <= wdata[7:0];
        remain    <= 4'd8;
        sck       <= 0;
      end
      // set clock divider
      if (addr[7:0] == 8'd4) begin
        clk_div   <= wdata;
        clk_count <= wdata;
      end
      // chip select
      if (addr[7:0] == 8'd16) begin
        cs <= wdata[0];
      end
    end else begin
      if (addr[7:0] == 8'd0) begin
        rdata <= srout;
      end
      if (addr[7:0] == 8'd4) begin
        rdata <= clk_div;
      end
      if (addr[7:0] == 8'd8) begin
        rdata <= srin;
      end
      // read spi busy status
      if (addr[7:0] == 8'd12) begin
        rdata <= (remain == 0) ? 32'd0 : 32'd1;
      end
      // chip select
      if (addr[7:0] == 8'd16) begin
        rdata <= {31'd0, cs};
      end
      // tick the SPI controller
      if (clk_count == 0) begin
        clk_count <= clk_div;
        if (remain != 0) begin
          sck <= !sck;
          if (sck) begin
            srout  <= { srout[6:0], 1'b1 };
            srin   <= {  srin[6:0], miso };
            remain <= remain - 4'd1;
          end
        end
      end else begin
        clk_count <= clk_count - 1;
      end
    end
  end
endmodule
