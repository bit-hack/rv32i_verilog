`default_nettype none
`timescale 1ns / 1ps

module bram_mem #(parameter ROM_FILE="") (
    input clk,
    input [3:0] wen,
    input [11:0] addr,
    input [31:0] wdata,
    output reg [31:0] rdata);

  reg [31:0] mem [0:4096];

  initial begin
    if (ROM_FILE)
      $readmemh(ROM_FILE, mem);
  end

  always @(posedge clk) begin
    rdata <= mem[addr];
    if (wen[0]) mem[addr][ 7: 0] <= wdata[ 7: 0];
    if (wen[1]) mem[addr][15: 8] <= wdata[15: 8];
    if (wen[2]) mem[addr][23:16] <= wdata[23:16];
    if (wen[3]) mem[addr][31:24] <= wdata[31:24];
  end
endmodule

// simple uart transmitter
module uart_t(input clk,
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

// basic SPI controller
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
        clk_count <= clk_div;
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
            srout  <= { srout[6:0], 1'b0 };
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

// system on chip instance
module soc_t #(parameter ROM_FILE="") (
    input CLK,
    input reset,
    input wire spi_miso,
    output wire [7:0] leds,
    output wire tx,
    output wire spi_mosi,
    output wire spi_sck,
    output wire spi_cs);

  // LED peripheral
  reg[7:0] led_state;
  assign leds = led_state;
  always @(negedge CLK) begin
    if (sel_led && is_write) begin
      led_state <= cpu_out_data[7:0];
    end
  end

  // address decoding
  wire is_write  = |cpu_write_mask;
  wire is_read   = !is_write;
  wire sel_bram  = (cpu_addr[31:24] ==  8'hf0);        // 0xf0000000 -> 0xf0ffffff
  wire sel_led   = (cpu_addr[31: 8] == 24'h100000);    // 0x10000000 -> 0x100000ff
  wire sel_uart  = (cpu_addr[31: 8] == 24'h100001);    // 0x10000100 -> 0x100001ff
  wire sel_spi   = (cpu_addr[31: 8] == 24'h100002);    // 0x10000200 -> 0x100002ff

  // uart transmitter
  wire [31:0] uart_dout;
  uart_t uart(CLK,
              sel_uart & is_write,
              cpu_addr,
              cpu_out_data,
              uart_dout,
              tx);

  // spi controller
  wire [31:0] spi_dout;
  spi_ctrl_t spi(CLK,
                 reset,
                 sel_spi & is_write,
                 cpu_addr,
                 cpu_out_data,
                 spi_miso,
                 spi_dout,
                 spi_sck,
                 spi_cs,
                 spi_mosi);

  // data being read into the CPU
  wire [31:0] cpu_in_data = (sel_bram  ? bram_dout :
                            (sel_led   ? led_state :
                            (sel_uart  ? uart_dout :
                            (sel_spi   ? spi_dout  :
                                         32'd0))));

  // block ram (16kb)
  wire [31:0] bram_dout;
  bram_mem #(.ROM_FILE(ROM_FILE))
      ram1(CLK,
           (sel_bram ? cpu_write_mask : 4'd0),
           cpu_addr[13:2],
           cpu_out_data,
           bram_dout);

  // the CPU
  wire [31:0] cpu_out_data;
  wire [31:0] cpu_addr;
  wire [ 3:0] cpu_write_mask;
  rv32i_cpu_t
      #(.RESET_VECTOR (32'hf0000000),
        .STACK_POINTER(32'hf0ffffff))
      cpu(
        CLK,
        reset,
        1'b0,
        cpu_in_data,
        cpu_write_mask,
        cpu_addr,
        cpu_out_data
      );
endmodule
