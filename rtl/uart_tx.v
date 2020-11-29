module uart_tx_t(input clk,
                 input wen,
                 input [31:0] addr,
                 input [31:0] wdata,
                 output reg [31:0] rdata,
                 output reg tx);

  localparam STATE_IDLE   = 0;
  localparam STATE_START  = 1;
  localparam STATE_SEND   = 2;
  localparam STATE_STOP   = 3;

  reg [31:0] clk_div;
  reg [31:0] clk_count;
  reg [7:0] data;
  reg [2:0] count;
  reg [1:0] state;

  initial begin
    clk_div   <= 1;
    clk_count <= 0;
    data      <= 0;
    count     <= 0;
    state     <= STATE_IDLE;
  end
  
  always @(posedge clk) begin
    if (wen) begin
      // new byte to send
      if (addr[7:0] == 8'd0) begin
        state     <= STATE_START;
        clk_count <= clk_div;
        data      <= wdata[7:0];
      end
      // set clock divider
      if (addr[7:0] == 8'd4) begin
        clk_div   <= wdata;
        clk_count <= wdata;
      end
    end else begin
      // read clock divider
      if (addr[7:0] == 8'd4) begin
        rdata <= clk_div;
      end
      // read uart busy status
      if (addr[7:0] == 8'd8) begin
        rdata <= (state == STATE_IDLE) ? 32'd0 : 32'd1;
      end
      // tick the uart
      if (clk_count == 0) begin
        clk_count <= clk_div;

        // uart state machine
        case (state)
        STATE_IDLE: begin
          tx <= 1;
        end
        // send the start bit
        STATE_START: begin
          tx    <= 0;
          state <= STATE_SEND;
          count <= 0;
        end
        // send the data bits
        STATE_SEND: begin
          tx    <= data[0:0];
          data  <= { 1'b0, data[7:1] };
          count <= count + 1;
          if (count == 7) begin
            state <= STATE_STOP;
          end
        end
        // send the stop bit
        default: begin
          tx    <= 1;
          state <= STATE_IDLE;
        end
        endcase

      end else begin
        clk_count <= clk_count - 1;
      end
    end
  end
endmodule
