  module memory_sim (
      input  logic [31:0] i_addr,
      output logic [31:0] i_data,
      input  logic [31:0] d_addr,
      input  logic [31:0] d_wdata,
      input  logic        d_we,
      output logic [31:0] d_rdata
  );
    logic [31:0] ram[0:1023];

    integer i;
    initial begin
      for (i = 0; i < 1024; i = i + 1) ram[i] = 32'b0;
      $readmemh("program.hex", ram);
    end

    logic [9:0] i_index;
    logic [9:0] d_index;
    assign i_index = i_addr[11:2];
    assign d_index = d_addr[11:2];
    assign i_data  = ram[i_index];
    assign d_rdata = ram[d_index];

    logic [9:0] d_index_wr;
    assign d_index_wr = d_addr[11:2];
    always_latch begin
      if (d_we) ram[d_index_wr] = d_wdata;
    end
  endmodule
