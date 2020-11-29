// simple uart receiver
//
// base + 0x0   = input data      (read only)   uint8_t
// base + 0x4   = clock divider   (read/write)  uint32_t
// base + 0x8   = uart status     (read/write)  uint8_t
//
// status bits:
//    0x00  - idle
//    0x01  - data pending
//    0x02  - uart busy
//    0x03  - uart busy and data pending
//
// write 0x00 to the status byte to clear pending status.
//
module uart_rx_t(input clk,
                 input wen,
                 input [31:0] addr,
                 input [31:0] wdata,
                 input rx,
                 output reg [31:0] rdata);

  reg [31:0] clk_div;
  reg [31:0] clk_count;
  reg [7:0] data;
  reg [3:0] count;
  reg rx_;

  // busy when currently receiving
  wire busy = count != 0;
  // 1 when data is waiting
  reg pending;

  initial begin
    clk_div   <= 8;
    clk_count <= 8;
    data      <= 0; // idle state
    count     <= 0;
    rx_       <= 1;
    pending   <= 0;
  end

  always @(posedge clk) begin
    if (wen) begin
      // set clock divider
      if (addr[7:0] == 8'd4) begin
        clk_div   <= wdata;
        clk_count <= wdata;
      end
      // clear rx status
      if (addr[7:0] == 8'd8) begin
        pending <= 0;
      end
    end else begin
      // read input data
      if (addr[7:0] == 8'd0) begin
        rdata   <= data;
      end
      // read clock divider
      if (addr[7:0] == 8'd4) begin
        rdata <= clk_div;
      end
      // read rx status
      if (addr[7:0] == 8'd8) begin
        rdata <= { 30'd0, busy, pending };
      end

      // if we are idle
      if (count == 0) begin
        // if start bit has been detected
        if (rx_ == 1 && rx == 0) begin
          // mark that data is pending, yet they wont be able to read it
          // until the busy flag disapears
          pending   <= 1;
          // set clock count to 1/2 clk_div so we start samping half way
          // through the data cycle
          clk_count <= { 1'b0, clk_div[31:1] };
          // 8 bits + start bit
          count <= 9;
        end
      end else begin
        // time to sample the data
        if (clk_count == 0) begin
          // shift the data in
          data <= { rx, data[7:1] };
          // reduce count by one
          count <= count - 1;
          // prime the next counter
          clk_count <= clk_div;
        end else begin
          clk_count <= clk_count - 1;
        end
      end
      // update the edge detector
      rx_ = rx;
    end
  end
endmodule
