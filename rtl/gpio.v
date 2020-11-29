module gpio_t(input clk,
              input reset,
              input wen,
              input [31:0] addr,
              input [31:0] wdata,
              inout gpio_pin,
              output reg [31:0] rdata);

  reg gpio_out;
  reg gpio_oe;

  // tri-state pin interface
  assign gpio_pin = gpio_oe ? gpio_out : 1'bz;

  always @(posedge clk) begin
    if (reset) begin
      gpio_out <= 0;
      gpio_oe  <= 0;
    end else begin
      if (wen) begin
        // write GPIO state
        case (addr[7:0])
        8'h00:   gpio_out <= wdata[0];  // output
        8'h04:   gpio_oe  <= wdata[0];  // enable
        endcase
      end
    end
    // read GPIO state
    case (addr[7:0])
    8'h00:   rdata <= { 31'd0, gpio_pin };  // input
    8'h04:   rdata <= { 31'd0, gpio_oe };   // enable
    default: rdata <=   32'd0;
    endcase
  end
endmodule
