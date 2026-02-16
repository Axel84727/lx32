`timescale 1ns / 1ps

module alu_tb;

  import lx32_pkg::*;
  import branches_pkg::*;

  localparam WIDTH = 32;

  // --- Signals ---
  logic       [WIDTH-1:0] src_a;
  logic       [WIDTH-1:0] src_b;
  alu_op_e                alu_control;
  branch_op_e             branch_op;
  logic                   is_branch;

  logic       [WIDTH-1:0] alu_result;
  logic                   alu_branch_true;

  // --- File I/O Variables ---
  int fd, count;
  logic [WIDTH-1:0] f_a, f_b, f_res;
  logic [3:0] f_op;
  logic f_is_branch, f_br_true;
  logic [2:0] f_br_op;

  // --- DUT Instantiation ---
  alu #(WIDTH) dut (
      .src_a          (src_a),
      .src_b          (src_b),
      .alu_control    (alu_control),
      .is_branch      (is_branch),
      .branch_op      (branch_op),
      .alu_result     (alu_result),
      .alu_branch_true(alu_branch_true)
  );

  // --- Verification Task ---
  task check(input logic [WIDTH-1:0] exp_res, input logic exp_br);
    #1;  // Wait for combinational logic to settle
    if (alu_result !== exp_res || alu_branch_true !== exp_br) begin
      $display("ERR | A:%h B:%h Op:%s Br:%s | Res:%h (Exp:%h) Flag:%b (Exp:%b)", src_a, src_b,
               alu_control.name(), branch_op.name(), alu_result, exp_res, alu_branch_true, exp_br);
    end
  endtask

  // --- Test Logic ---
  initial begin
    count = 0;

    // Open file (relative to project root)
    fd = $fopen("tools/alu_tester/alu_vectors.tv", "r");

    if (fd == 0) begin
      $display("FATAL: Could not open alu_vectors.tv. Check path.");
      $finish;
    end

    $display(">>> Starting Automated Verification (ALU + Branch) <<<");

    // Reading format: A B OP_ALU IS_BR OP_BR RES BR_TRUE
    // We use %h for everything to keep it consistent with Rust's hex output
    while ($fscanf(
        fd, "%h %h %h %h %h %h %h\n", f_a, f_b, f_op, f_is_branch, f_br_op, f_res, f_br_true
    ) == 7) begin

      count++;

      // Apply stimulus
      src_a       = f_a;
      src_b       = f_b;
      alu_control = alu_op_e'(f_op);
      is_branch   = f_is_branch;
      branch_op   = branch_op_e'(f_br_op);

      // Compare DUT output with Golden Model
      check(f_res, f_br_true);

      if (count % 100 == 0) begin
        $display("Processed %0d vectors...", count);
      end
    end

    $display(">>> Verification Finished. Total Vectors: %0d <<<", count);
    $fclose(fd);
    $finish;
  end

endmodule
