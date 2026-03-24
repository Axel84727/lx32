//===-- LX32InstrInfo.td - LX32 Instruction Definitions --------*- tablegen -*-===//
//
// Part of the LX32 Project
// SPDX-License-Identifier: MIT
//
//===----------------------------------------------------------------------===//
//
// This file describes the LX32 instruction set (ISA).
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Section 1 — Operand Definitions
//===----------------------------------------------------------------------===//

/// Generic Immediate Operands
def simm12 : Operand<i32> { let EncoderMethod = "getImmOpValue"; }
def uimm5  : Operand<i32> { let EncoderMethod = "getImmOpValue"; }
def uimm12 : Operand<i32> { let EncoderMethod = "getImmOpValue"; }
def uimm20 : Operand<i32> { let EncoderMethod = "getImmOpValue"; }

/// Displacement/Target Operands (require custom bit-shuffling/fixups)
def simm13 : Operand<OtherVT> { let EncoderMethod = "getBranchTargetOpValue"; }
def simm21 : Operand<OtherVT> { let EncoderMethod = "getJumpTargetOpValue"; }

//===----------------------------------------------------------------------===//
// Section 2 — Opcode Map
//===----------------------------------------------------------------------===//

def OPC_LOAD    : LX32Opcode<"load",    0b0000011>;
def OPC_STORE   : LX32Opcode<"store",   0b0100011>;
def OPC_BRANCH  : LX32Opcode<"branch",  0b1100011>;
def OPC_JAL     : LX32Opcode<"jal",     0b1101111>;
def OPC_JALR    : LX32Opcode<"jalr",    0b1100111>;
def OPC_LUI     : LX32Opcode<"lui",     0b0110111>;
def OPC_AUIPC   : LX32Opcode<"auipc",   0b0010111>;
def OPC_IMM     : LX32Opcode<"imm",     0b0010011>;
def OPC_ARITH   : LX32Opcode<"arith",   0b0110011>;
def OPC_SYSTEM  : LX32Opcode<"system",  0b1110011>;

//===----------------------------------------------------------------------===//
// Section 3 — R-Type Instructions (Register-Register)
//===----------------------------------------------------------------------===//

class ALU_R<bits<7> funct7, bits<3> funct3, string opcodestr> :
  LXInstR<funct7, funct3, OPC_ARITH, (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
          opcodestr, "$rd, $rs1, $rs2">;

def ADD  : ALU_R<0b0000000, 0b000, "add">;
def SUB  : ALU_R<0b0100000, 0b000, "sub">;
def SLL  : ALU_R<0b0000000, 0b001, "sll">;
def SLT  : ALU_R<0b0000000, 0b010, "slt">;
def SLTU : ALU_R<0b0000000, 0b011, "sltu">;
def XOR  : ALU_R<0b0000000, 0b100, "xor">;
def SRL  : ALU_R<0b0000000, 0b101, "srl">;
def SRA  : ALU_R<0b0100000, 0b101, "sra">;
def OR   : ALU_R<0b0000000, 0b110, "or">;
def AND  : ALU_R<0b0000000, 0b111, "and">;

//===----------------------------------------------------------------------===//
// Section 4 — I-Type Instructions (Arithmetic Immediate)
//===----------------------------------------------------------------------===//

class ALU_I<bits<3> funct3, string opcodestr> :
  LXInstI<funct3, OPC_IMM, (outs GPR:$rd), (ins GPR:$rs1, simm12:$imm12),
          opcodestr, "$rd, $rs1, $imm12">;

def ADDI  : ALU_I<0b000, "addi">;
def SLTI  : ALU_I<0b010, "slti">;
def SLTIU : ALU_I<0b011, "sltiu">;
def XORI  : ALU_I<0b100, "xori">;
def ORI   : ALU_I<0b110, "ori">;
def ANDI  : ALU_I<0b111, "andi">;

/// Shift Immediates (utilize uimm5 within the imm12 field)
def SLLI  : LXInstI<0b001, OPC_IMM, (outs GPR:$rd), (ins GPR:$rs1, uimm5:$imm12),
                    "slli", "$rd, $rs1, $imm12"> { let imm12{11-5} = 0b0000000; }
def SRLI  : LXInstI<0b101, OPC_IMM, (outs GPR:$rd), (ins GPR:$rs1, uimm5:$imm12),
                    "srli", "$rd, $rs1, $imm12"> { let imm12{11-5} = 0b0000000; }
def SRAI  : LXInstI<0b101, OPC_IMM, (outs GPR:$rd), (ins GPR:$rs1, uimm5:$imm12),
                    "srai", "$rd, $rs1, $imm12"> { let imm12{11-5} = 0b0100000; }

//===----------------------------------------------------------------------===//
// Section 5 — Load Instructions
//===----------------------------------------------------------------------===//

class Load_I<bits<3> funct3, string opcodestr> :
  LXInstI<funct3, OPC_LOAD, (outs GPR:$rd), (ins GPR:$rs1, simm12:$imm12),
          opcodestr, "$rd, ${imm12}(${rs1})">;

def LW  : Load_I<0b010, "lw">;
def LH  : Load_I<0b001, "lh">;
def LHU : Load_I<0b101, "lhu">;
def LB  : Load_I<0b000, "lb">;
def LBU : Load_I<0b100, "lbu">;

//===----------------------------------------------------------------------===//
// Section 6 — Store Instructions
//===----------------------------------------------------------------------===//

class Store_S<bits<3> funct3, string opcodestr> :
  LXInstS<funct3, OPC_STORE, (outs), (ins GPR:$rs2, GPR:$rs1, simm12:$imm12),
          opcodestr, "$rs2, ${imm12}(${rs1})">;

def SW : Store_S<0b010, "sw">;
def SH : Store_S<0b001, "sh">;
def SB : Store_S<0b000, "sb">;

//===----------------------------------------------------------------------===//
// Section 7 — Branch Instructions
//===----------------------------------------------------------------------===//

class Branch_B<bits<3> funct3, string opcodestr> :
  LXInstB<funct3, OPC_BRANCH, (outs), (ins GPR:$rs1, GPR:$rs2, simm13:$imm13),
          opcodestr, "$rs1, $rs2, $imm13">;

def BEQ  : Branch_B<0b000, "beq">;
def BNE  : Branch_B<0b001, "bne">;
def BLT  : Branch_B<0b100, "blt">;
def BGE  : Branch_B<0b101, "bge">;
def BLTU : Branch_B<0b110, "bltu">;
def BGEU : Branch_B<0b111, "bgeu">;

//===----------------------------------------------------------------------===//
// Section 8 — Jump Instructions
//===----------------------------------------------------------------------===//

def JAL  : LXInstJ<OPC_JAL, (outs GPR:$rd), (ins simm21:$imm21),
                  "jal", "$rd, $imm21">;

def JALR : LXInstI<0b000, OPC_JALR, (outs GPR:$rd), (ins GPR:$rs1, simm12:$imm12),
                  "jalr", "$rd, ${imm12}(${rs1})">;

//===----------------------------------------------------------------------===//
// Section 9 — Upper Immediate Instructions
//===----------------------------------------------------------------------===//

def LUI   : LXInstU<OPC_LUI, (outs GPR:$rd), (ins uimm20:$imm20),
                    "lui", "$rd, $imm20">;
def AUIPC : LXInstU<OPC_AUIPC, (outs GPR:$rd), (ins uimm20:$imm20),
                    "auipc", "$rd, $imm20">;