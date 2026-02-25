module lsu (
    input  logic [31:0] alu_result,
    input  logic [31:0] write_data,
    input  logic        mem_write,
    output logic [31:0] mem_addr,
    output logic [31:0] mem_wdata,
    output logic        mem_we
);
  assign mem_addr  = alu_result;
  assign mem_wdata = write_data;
  assign mem_we    = mem_write;
endmodule
