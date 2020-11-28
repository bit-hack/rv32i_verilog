`default_nettype none
`timescale 1ns / 1ps


`define USE_UART_RX
`define USE_UART_TX
`define USE_SPI_CTRL
`define USE_GPIO
`define USE_LEDS


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
`ifdef USE_UART_RX
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
`endif  // USE_UART_RX

// simple uart transmitter
`ifdef USE_UART_TX
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
`endif  // USE_UART_TX

// basic SPI controller
`ifdef USE_SPI_CTRL
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
`endif  // USE_SPI_CTRL

// general purpose input output
`ifdef USE_GPIO
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
`endif  // USE_GPIO

// system on chip instance
module soc_t #(parameter ROM_FILE="") (
    input clk,
    input reset,
    input wire spi_miso,
    input wire rx,
    output wire [7:0] leds,
    output wire tx,
    output wire spi_mosi,
    output wire spi_sck,
    output wire spi_cs,
    inout gpio);

`ifdef USE_GPIO
  // GPIO peripheral
  wire [31:0] gpio_dout;
  gpio_t gpio_inst(.clk(clk),
                   .reset(reset),
                   .wen(sel_gpio & is_write),
                   .addr(cpu_addr),
                   .wdata(cpu_out_data),
                   .gpio_pin(gpio),
                   .rdata(gpio_dout));
`endif  // USE_GPIO

`ifdef USE_LEDS
  // LED peripheral
  reg[7:0] led_state;
  assign leds = led_state;
  always @(posedge clk) begin
    if (sel_led && is_write) begin
      led_state <= cpu_out_data[7:0];
    end
  end
`endif  // USE_LEDS

  // address decoding
  wire is_write    = cpu_wr;
  wire sel_bram    = (cpu_addr[31:24] ==  8'hf0);        // 0xf0000000 -> 0xf0ffffff
`ifdef USE_LEDS
  wire sel_led     = (cpu_addr[31: 8] == 24'h100000);    // 0x10000000 -> 0x100000ff
`endif  // USE_LEDS
`ifdef USE_UART_TX
  wire sel_uart_tx = (cpu_addr[31: 8] == 24'h100001);    // 0x10000100 -> 0x100001ff
`endif  // USE_UART_TX
`ifdef USE_SPI_CTRL
  wire sel_spi     = (cpu_addr[31: 8] == 24'h100002);    // 0x10000200 -> 0x100002ff
`endif  // USE_SPI_CTRL
`ifdef USE_UART_RX
  wire sel_uart_rx = (cpu_addr[31: 8] == 24'h100003);    // 0x10000300 -> 0x100003ff
`endif  // USE_UART_RX
`ifdef USE_GPIO
  wire sel_gpio    = (cpu_addr[31: 8] == 24'h100004);    // 0x10000400 -> 0x100004ff
`endif  // USE_GPIO

  // select data being read into the CPU
  reg [31:0] cpu_in_data;
  always @* begin
    casez (cpu_addr[31:8])
    24'hf0????: cpu_in_data = bram_dout;
`ifdef USE_LEDS
    24'h100000: cpu_in_data = led_state;
`endif
`ifdef USE_UART_TX
    24'h100001: cpu_in_data = uart_tx_dout;
`endif  // USE_UART_TX
`ifdef USE_SPI_CTRL
    24'h100002: cpu_in_data = spi_dout;
`endif  // USE_SPI_CTRL
`ifdef USE_UART_RX
    24'h100003: cpu_in_data = uart_rx_dout;
`endif  // USE_UART_RX
`ifdef USE_GPIO
    24'h100004: cpu_in_data = gpio_dout;
`endif  // USE_GPIO
    default:    cpu_in_data = 32'dX;
    endcase
  end

`ifdef USE_UART_TX
  // uart transmitter
  wire [31:0] uart_tx_dout;
  uart_tx_t uart_tx(.clk(clk),
                    .wen(sel_uart_tx & is_write),
                    .addr(cpu_addr),
                    .wdata(cpu_out_data),
                    .rdata(uart_tx_dout),
                    .tx(tx));
`endif  // USE_UART_TX

`ifdef USE_SPI_CTRL
  // spi controller
  wire [31:0] spi_dout;
  spi_ctrl_t spi(.clk(clk),
                 .reset(reset),
                 .wen(sel_spi & is_write),
                 .addr(cpu_addr),
                 .wdata(cpu_out_data),
                 .miso(spi_miso),
                 .rdata(spi_dout),
                 .sck(spi_sck),
                 .cs(spi_cs),
                 .mosi(spi_mosi));
`endif  // USE_SPI_CTRL

`ifdef USE_UART_RX
  // uart receiver
  wire [31:0] uart_rx_dout;
  uart_rx_t uart_rx(.clk(clk),
                    .wen(sel_uart_rx & is_write),
                    .addr(cpu_addr),
                    .wdata(cpu_out_data),
                    .rx(rx),
                    .rdata(uart_rx_dout));
`endif  // USE_UART_RX

  // block ram (16kb)
  wire [31:0] bram_dout;
  bram_mem #(.ROM_FILE(ROM_FILE))
      ram1(.clk(clk),
           .wen((sel_bram & cpu_wr) ? cpu_write_mask :
                                      4'd0),
           .addr(cpu_addr[13:2]),
           .wdata(cpu_out_data),
           .rdata(bram_dout));

  // the CPU
  wire [31:0] cpu_out_data;
  wire [31:0] cpu_addr;
  wire [ 3:0] cpu_write_mask;
  wire cpu_rd;
  wire cpu_wr;
  rv32i_cpu_t
      #(.RESET_VECTOR (32'hf0000000),
        .STACK_POINTER(32'hf0ffffff))
      cpu(
        .clk(clk),
        .reset(reset),
        .hold(1'b0),
        .in_data(cpu_in_data),
        .out_wr_mask(cpu_write_mask),
        .out_mem_addr(cpu_addr),
        .out_data(cpu_out_data),
        .out_wr(cpu_wr),
        .out_rd(cpu_rd));

endmodule
