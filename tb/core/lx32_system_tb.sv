`timescale 1ns / 1ps

module lx32_system_tb;
  logic clk;
  logic rst;
  logic [31:0] i_addr;
  logic [31:0] i_data;
  logic [31:0] d_addr;
  logic [31:0] d_wdata;
  logic [31:0] d_rdata;
  logic d_we;

  lx32_core dut (
      .clk(clk),
      .rst(rst),
      .pc_out(i_addr),
      .instr(i_data),
      .mem_addr(d_addr),
      .mem_wdata(d_wdata),
      .mem_rdata(d_rdata),
      .mem_we(d_we)
  );

  memory_sim mem (
      .i_addr(i_addr),
      .i_data(i_data),
      .d_addr(d_addr),
      .d_wdata(d_wdata),
      .d_we(d_we),
      .d_rdata(d_rdata)
  );

  // Generador de reloj
  always #5 clk = ~clk;

  // --- EL MONITOR MÁGICO ---
  // Detecta cuando la CPU escribe en la dirección de "consola" 0x7FC
  always @(posedge clk) begin
    if (d_we && d_addr == 32'h7FC) begin
      $display("\n[CPU MONITOR] Valor detectado en 0x7FC:");
      $display("  > Hex: 32'h%h", d_wdata);
      $display("  > Dec: %0d", d_wdata);
      $display("  > Time: %0t ps\n", $time);
    end
  end

  initial begin
    $dumpfile("lx32_system.vcd");
    $dumpvars(0, lx32_system_tb);

    clk = 0;
    rst = 1;
    #22;
    rst = 0;

    // Aumentamos el tiempo para que le de tiempo a terminar el bucle
    #10000;

    $display("Simulacion finalizada. Revisa el archivo VCD.");
    $finish;
  end
endmodule
