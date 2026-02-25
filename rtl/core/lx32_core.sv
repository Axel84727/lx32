import lx32_pkg::*;
import lx32_arch_pkg::*;
import branches_pkg::*;

module lx32_core (
    input  logic        clk,
    input  logic        rst,
    output logic [31:0] pc_out,
    input  logic [31:0] instr,
    output logic [31:0] mem_addr,
    output logic [31:0] mem_wdata,
    input  logic [31:0] mem_rdata,
    output logic        mem_we
);

  logic [31:0] pc, next_pc;
  logic [31:0] rs1_data, rs2_data, imm_ext, alu_a, alu_b, alu_res, rd_data;
  logic reg_write, alu_src, mem_write, branch_en, alu_branch_true;
  logic    [1:0] result_src;
  alu_op_e       alu_control;

  always_ff @(posedge clk or posedge rst) begin
    if (rst) pc <= 32'h0;
    else pc <= next_pc;
  end

  assign pc_out  = pc;
  assign next_pc = (branch_en && alu_branch_true) ? (pc + imm_ext) : (pc + 4);

  control_unit ctrl (
      .opcode(instr[6:0]),
      .funct3(instr[14:12]),
      .funct7_5(instr[30]),
      .reg_write(reg_write),
      .alu_src(alu_src),
      .mem_write(mem_write),
      .result_src(result_src),
      .branch(branch_en),
      .alu_control(alu_control)
  );

  register_file rf (
      .clk(clk),
      .rst(rst),
      .addr_rs1(instr[19:15]),
      .addr_rs2(instr[24:20]),
      .addr_rd(instr[11:7]),
      .data_rd(rd_data),
      .we(reg_write),
      .data_rs1(rs1_data),
      .data_rs2(rs2_data)
  );

  imm_gen igen (
      .instr(instr),
      .imm  (imm_ext)
  );

  assign alu_a = rs1_data;
  assign alu_b = alu_src ? imm_ext : rs2_data;

  alu core_alu (
      .src_a(alu_a),
      .src_b(alu_b),
      .alu_control(alu_control),
      .is_branch(branch_en),
      .branch_op(branch_op_e'(instr[14:12])),
      .alu_result(alu_res),
      .alu_branch_true(alu_branch_true)
  );

  lsu core_lsu (
      .alu_result(alu_res),
      .write_data(rs2_data),
      .mem_write(mem_write),
      .mem_addr(mem_addr),
      .mem_wdata(mem_wdata),
      .mem_we(mem_we)
  );

  always_comb begin
    case (result_src)
      2'b01:   rd_data = mem_rdata;
      default: rd_data = alu_res;
    endcase
  end

endmodule
