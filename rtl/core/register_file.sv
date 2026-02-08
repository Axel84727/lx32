module register_file (
    input logic        clk,       // Clock signal
    input logic        rst,       // Reset signal (active high)
    input logic [ 4:0] addr_rs1,  // Source Register 1 address
    input logic [ 4:0] addr_rs2,  // Source Register 2 address
    input logic [ 4:0] addr_rd,   // Destination Register address
    input logic [31:0] data_rd,   // Data to be written to RD
    input logic        we,        // Write Enable signal

    output logic [31:0] data_rs1,  // Data output from RS1
    output logic [31:0] data_rs2   // Data output from RS2
);
  // 2D Array: 31 registers (1 to 31), each 32 bits wide
  logic [31:0] regs_out [1:31];

  logic [31:0] write_en;

  assign write_en = (we && (addr_rd != 5'd0)) ? (32'b1 << addr_rd) : 32'b0;

  genvar i;
  generate
    for (i = 1; i < 32; i++) begin : gen_registers
      reg_generic #(
          .WIDTH(32)
      ) regs (
          .clk(clk),
          .rst(rst),
          .en(write_en[i]),
          .data_in(data_rd),
          .data_out(regs_out[i])
      );
    end
  endgenerate

  assign data_rs1 = (addr_rs1 == 5'd0) ? 32'd0 : regs_out[addr_rs1];
  assign data_rs2 = (addr_rs2 == 5'd0) ? 32'd0 : regs_out[addr_rs2];

endmodule
