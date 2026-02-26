module reg_generic #(

  // ------------------------------------------------------------
  // Parameterization
  // ------------------------------------------------------------
  parameter int WIDTH = 8

) (

  // ------------------------------------------------------------
  // Clock & Reset
  // ------------------------------------------------------------
  input  logic                   clk,
  input  logic                   rst,

  // ------------------------------------------------------------
  // Control
  // ------------------------------------------------------------
  input  logic                   en,

  // ------------------------------------------------------------
  // Data Interface
  // ------------------------------------------------------------
  input  logic [WIDTH-1:0]       data_in,
  output logic [WIDTH-1:0]       data_out

);

  // ============================================================
  // LX32 Generic Register
  // ============================================================
  // Parameterizable synchronous register with:
  //
  //   - Asynchronous active-high reset
  //   - Clock enable
  //   - Clean sequential semantics
  //
  // Design Principles:
  //   - No implicit latches
  //   - Non-blocking assignments only
  //   - Reset-safe initialization
  //   - Width scalability
  // ============================================================


  // ------------------------------------------------------------
  // Sequential Logic
  // ------------------------------------------------------------
  always_ff @(posedge clk or posedge rst) begin
    if (rst)
      data_out <= '0;
    else if (en)
      data_out <= data_in;
  end

endmodule
