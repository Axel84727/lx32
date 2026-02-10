package lx32_arch_pkg;
  localparam [6:0] OP_IMM = 7'b0010011;
  localparam [6:0] OP_LUI = 7'b0110111;
  localparam [6:0] OP_AUIPC = 7'b0010111;
  localparam [6:0] OP_STORE = 7'b0100011;
  localparam [6:0] OP_LOAD = 7'b0000011;
  localparam [6:0] OP_JAL = 7'b1101111;
  localparam [6:0] OP_JALR = 7'b1100111;
  localparam [6:0] OP_BRANCH = 7'b1100011;

  function automatic logic [31:0] get_i_imm(logic [31:0] i);
    return {{20{i[31]}}, i[31:20]};
  endfunction

  function automatic logic [31:0] get_s_imm(logic [31:0] i);
    return {{20{i[31]}}, i[31:25], i[11:7]};
  endfunction

  function automatic logic [31:0] get_b_imm(logic [31:0] i);
    return {{19{i[31]}}, i[31], i[7], i[30:25], i[11:8], 1'b0};
  endfunction

  function automatic logic [31:0] get_u_imm(logic [31:0] i);
    return {i[31:12], 12'b0};
  endfunction

  function automatic logic [31:0] get_j_imm(logic [31:0] i);
    return {{11{i[31]}}, i[31], i[19:12], i[20], i[30:21], 1'b0};
  endfunction

endpackage



