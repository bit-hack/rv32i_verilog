`default_nettype none
`timescale 1ns / 1ps

// TODO:
//  - byte and half addressing
//  - slt/sltu
//  - branch conditions

module regfile_t(
    input clk,
    input [4:0] rs1, output reg [31:0] rs1_data,               // read port
    input [4:0] rs2, output reg [31:0] rs2_data,               // read port
    input [4:0] rd,  input      [31:0] rd_data,  input rd_wr   // write port
    );
  reg [31:0] X1[31:0];
  reg [31:0] X2[31:0];

  wire [31:0] dbg_reg_zero = X1[0];
  wire [31:0] dbg_reg_ra   = X1[1];
  wire [31:0] dbg_reg_sp   = X1[2];
  wire [31:0] dbg_reg_gp   = X1[3];
  wire [31:0] dbg_reg_tp   = X1[4];
  wire [31:0] dbg_reg_t0   = X1[5];
  wire [31:0] dbg_reg_t1   = X1[6];
  wire [31:0] dbg_reg_t2   = X1[7];
  wire [31:0] dbg_reg_fp   = X1[8];
  wire [31:0] dbg_reg_s1   = X1[9];
  wire [31:0] dbg_reg_a0   = X1[10];
  wire [31:0] dbg_reg_a1   = X1[11];
  wire [31:0] dbg_reg_a2   = X1[12];
  wire [31:0] dbg_reg_a3   = X1[13];
  wire [31:0] dbg_reg_a4   = X1[14];
  wire [31:0] dbg_reg_a5   = X1[15];
  wire [31:0] dbg_reg_a6   = X1[16];
  wire [31:0] dbg_reg_a7   = X1[17];

  always @(posedge clk) begin
    if (rd_wr) begin
      X1[rd] <= rd_data;
      X2[rd] <= rd_data;
    end
    rs1_data <= (rs1 == 0) ? 32'd0 : X1[rs1];
    rs2_data <= (rs2 == 0) ? 32'd0 : X2[rs2];
  end
endmodule

// control:
// . 0000000001  add
// . 0000000010  sub
// . 0000000100  xor
// . 0000001000  or
// . 0000010000  and
// . 0000100000  shl
// . 0001000000  shr
// . 0011000000  sar
// . 0100000000  slt
// . 1000000000  sltu
//
module alu_t(
    input clk,
    input [31:0] lhs,
    input [31:0] rhs,
    input [ 9:0] control,
    output reg [31:0] result
    );
  always @(posedge clk) begin
    case (1'b1)
    control[0]: result <= lhs + rhs;
    control[1]: result <= lhs - rhs;
    control[2]: result <= lhs ^ rhs;
    control[3]: result <= lhs | rhs;
    control[4]: result <= lhs & rhs;
    control[5]: result <= lhs << rhs[4:0];
    /* verilator lint_off WIDTH */
    control[6]: result <= { control[7] & lhs[31], lhs } >> rhs[4:0];
    /* verilator lint_on WIDTH */
    control[8]: result <= { 31'd0, lhs < rhs };
    control[9]: result <= { 31'd0, $signed(lhs) < $signed(rhs) };
    endcase
  end
endmodule

module rv32i_cpu_rev2_t(
    input             clk,
    input             reset,
    input             hold,
    input      [31:0] mem_data_in,
    output reg [ 3:0] mem_wr_mask,
    output reg [31:0] mem_addr,
    output reg [31:0] mem_data_out,
    output reg        mem_wr,
    output reg        mem_rd
    );

  reg [31:0] PC;
  reg [31:0] PC_NEXT;

  // instruction decode
  reg [ 4:0] rs1;
  reg [ 4:0] rs2;
  reg [ 4:0] rd;
  reg [31:0] imm;
  reg        bit30;  // funct7

  // funct3 decoder
  reg [7:0] funct3; // one-hot expansion
  wire is_SHIFTI = is_ALUI & (funct3[1] | funct3[5]);  // SLLI/SRLI/SRAI

  // group decoder
  reg [8:0] group;  // one-hot expansion
  wire is_LOAD  = group[0]; // LB/LH/LW/LBU/LHU
  wire is_ALUI  = group[1]; // ADDI/SLTI/SLTIU/XORI/ORI/ANDI/SLLI/SRLI/SRAI
  wire is_AUIPC = group[2]; // AUIPC
  wire is_STORE = group[3]; // SB/SH/SW
  wire is_ALU   = group[4]; // ADD/SUB/SLL/SLT/SLTU/XOR/SRL/SRA/OR/AND
  wire is_LUI   = group[5]; // LUI
  wire is_BRA   = group[6]; // BEQ/BNE/BLT/BGE/BLTU/BGEU
  wire is_JALR  = group[7]; // JALR
  wire is_JAL   = group[8]; // JAL

  // register file
  reg  [31:0] rd_data;
  reg         rd_wr;
  wire [31:0] rs1_data;
  wire [31:0] rs2_data;
  regfile_t regs(clk,
                 is_LUI ? 0 : rs1, rs1_data,  // read port
                 rs2, rs2_data,               // read port
                 rd, rd_data, rd_wr);         // write port

  // alu
  wire [31:0] alu_res;
  reg  [ 9:0] alu_ctrl;
  alu_t alu(clk,
    (is_AUIPC | is_JAL) ? PC : rs1_data,                    // alu input 1
    is_SHIFTI ? { 27'd0, rs2 } :
                ((is_ALUI | is_JAL | is_JALR | is_LUI | is_AUIPC) ? imm :   // note: flip this around to just the rs2_data cases?
                                                rs2_data),  // alu input 2
    alu_ctrl,                                               // alu control
    alu_res);                                               // alu result

  always @(posedge clk) begin
    // select rd value
    case (1'b1)
    is_JAL,
    is_JALR: rd_data = PC + 4;          // link addr
    is_LOAD: rd_data = mem_data_in;     // load value
    default: rd_data = alu_res;         // alu result
    endcase
  end

  // alu control code generation
  always @(posedge clk) begin
    if (is_ALU | is_ALUI) begin
      case (1'b1)
      funct3[0]: begin
        alu_ctrl = (is_ALU & bit30) ? 'b0000000010 : // sub
                                      'b0000000001;  // add
      end
      funct3[1]: alu_ctrl =           'b0000100000;  // sll
      funct3[2]: alu_ctrl =           'b0100000000;  // slt
      funct3[3]: alu_ctrl =           'b1000000000;  // sltu
      funct3[4]: alu_ctrl =           'b0000000100;  // xor
      funct3[5]: begin
        alu_ctrl = (bit30) ?          'b0011000000 : // sra
                                      'b0001000000;  // srl
      end
      funct3[6]: alu_ctrl =           'b0000001000;  // or
      funct3[7]: alu_ctrl =           'b0000010000;  // and
      endcase
    end else begin
      alu_ctrl =                      'b0000000001;  // add
    end
  end

  // comparisons used for branches
  // TODO: push this into the ALU please
  wire is_LT  = $signed(alu_res) < $signed(rs1_data);
  wire is_LTU = alu_res < rs1_data;
  wire is_EQ  = (alu_res == 0);

  // control logic
  reg [8:0] stage;
  always @(posedge clk) begin
    stage  <= 0;
    rd_wr  <= 0;
    mem_wr <= 0;
    mem_rd <= 0;
    if (reset) begin
      stage[0] <= 1;
      rd    <= 0;
      PC    <= 32'hf0000000; // reset address
    end else begin
      case (1'b1)
      // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
      stage[0]: begin   // fetch
        mem_addr <= PC;
        mem_rd   <= 1;
        stage[1] <= 1;
      end
      // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
      stage[1]: begin   // delay
        // delay here to wait for `mem_data_in` to become valid.
        stage[2] <= 1;
      end
      // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
      stage[2]: begin   // decode
        rd     <= mem_data_in[11: 7];
        rs1    <= mem_data_in[19:15];
        rs2    <= mem_data_in[24:20];
        bit30  <= mem_data_in[30];
        // decode group
        case (mem_data_in[6:2])
        default   group <= 0;
        5'b00000: group <= 9'b000000001; // LB/LH/LW/LBU/LHU
        5'b00100: group <= 9'b000000010; // ADDI/SLTI/SLTIU/XORI/ORI/ANDI/SLLI/SRLI/SRAI
        5'b00101: group <= 9'b000000100; // AUIPC
        5'b01000: group <= 9'b000001000; // SB/SH/SW
        5'b01100: group <= 9'b000010000; // ADD/SUB/SLL/SLT/SLTU/XOR/SRL/SRA/OR/AND
        5'b01101: group <= 9'b000100000; // LUI
        5'b11000: group <= 9'b001000000; // BEQ/BNE/BLT/BGE/BLTU/BGEU
        5'b11001: group <= 9'b010000000; // JALR
        5'b11011: group <= 9'b100000000; // JAL
        endcase
        // decode funct3
        case (mem_data_in[14:12])
        3'b000: funct3 <= 8'b00000001;
        3'b001: funct3 <= 8'b00000010;
        3'b010: funct3 <= 8'b00000100;
        3'b011: funct3 <= 8'b00001000;
        3'b100: funct3 <= 8'b00010000;
        3'b101: funct3 <= 8'b00100000;
        3'b110: funct3 <= 8'b01000000;
        3'b111: funct3 <= 8'b10000000;
        endcase
        stage[3] <= 1;
      end
      // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
      stage[3]: begin   // delay / imm decode
        // decode immediate
        case (1'b1)
        is_STORE: imm <= {{21{mem_data_in[31]}}, mem_data_in[30:25], mem_data_in[11:7]};
        is_BRA:   imm <= {{20{mem_data_in[31]}}, mem_data_in[7], mem_data_in[30:25], mem_data_in[11:8], 1'b0};
        is_LUI,
        is_AUIPC: imm <= {mem_data_in[31:12], 12'b0};
        is_JAL:   imm <= {{13{mem_data_in[31]}}, mem_data_in[19:12], mem_data_in[30:21], 1'b0};
        is_JALR,
        is_LOAD,
        is_ALUI:  imm <= {{21{mem_data_in[31]}}, mem_data_in[30:20]};
        endcase
        // delay here to wait for `rs1_data` and `rs2_data` to become valid.
        stage[4] <= 1;
      end
      // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
      stage[4]: begin   // load
        mem_addr <= rs1_data + imm;
        mem_rd   <= is_LOAD;
        stage[5] <= 1;
      end
      // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
      stage[5]: begin   // delay
        stage[6] <= 1;
      end
      // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
      stage[6]: begin   // execute
        // all these groups write to rd
        rd_wr <= is_ALU | is_ALUI | is_JAL | is_JALR | is_AUIPC | is_LOAD | is_LUI;
        // select next PC
        case (1'b1)
        is_BRA: begin
          case (1'b1)
          funct3[0]: PC_NEXT =  is_EQ  ? PC + imm : PC + 4; // BEQ
          funct3[1]: PC_NEXT = !is_EQ  ? PC + imm : PC + 4; // BNE
          funct3[4]: PC_NEXT =  is_LT  ? PC + imm : PC + 4; // BLT
          funct3[5]: PC_NEXT = !is_LT  ? PC + imm : PC + 4; // BGE
          funct3[6]: PC_NEXT =  is_LTU ? PC + imm : PC + 4; // BLTU
          funct3[7]: PC_NEXT = !is_LTU ? PC + imm : PC + 4; // BGEU
          endcase
        end
        is_JAL,
        is_JALR: PC_NEXT = alu_res;
        default: PC_NEXT = PC + 4;
        endcase
        stage[7] <= 1;
      end
      // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
      stage[7]: begin  // store
        mem_data_out <= rs2_data;
        mem_addr     <= rs1_data + imm;
        mem_wr       <= is_STORE;
        stage[8] <= 1;
      end
      // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
      stage[8]: begin  // advance
        PC <= PC_NEXT;
        stage[0] <= 1;
      end
      endcase
    end
  end
endmodule
