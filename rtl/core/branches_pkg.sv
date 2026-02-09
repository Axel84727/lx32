package branches_pkg;

  typedef enum logic [2:0] {
    BR_EQ,   // A == B
    BR_NE,   // A != B
    BR_LT,   // A <  B (signed)
    BR_GE,   // A >= B (signed)
    BR_LTU,  // A <  B (unsigned)
    BR_GEU   // A >= B (unsigned)
  } branch_op_e;

endpackage

