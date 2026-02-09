package lx32_pkg;

    typedef enum logic [3:0] {
    ALU_ADD,   // A + B
    ALU_SUB,   // A - B
    ALU_SLL,   // A << B
    ALU_SLT,   // A < B (signed)
    ALU_SLTU,  // A < B (unsigned)
    ALU_XOR,   // A ^ B
    ALU_SRL,   // A >> B (logical)
    ALU_SRA,   // A >>> B (arithmetic)
    ALU_OR,    // A | B
    ALU_AND    // A & B
    } alu_op_e;

endpackage

