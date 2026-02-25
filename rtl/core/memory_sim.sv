module memory_sim (
    input  logic [31:0] i_addr,
    output logic [31:0] i_data,
    input  logic [31:0] d_addr,
    input  logic [31:0] d_wdata,
    input  logic        d_we,
    output logic [31:0] d_rdata
);
  logic [31:0] ram[0:1023];

  initial $readmemh("program.hex", ram);

  assign i_data  = ram[i_addr[11:2]];
  assign d_rdata = ram[d_addr[11:2]];

  always_latch begin
    if (d_we) ram[d_addr[11:2]] = d_wdata;
  end
endmodule
