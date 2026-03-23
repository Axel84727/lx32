//===-- LX32.td - Main Target Description File -------------*- tablegen -*-===//
//
// Part of the LX32 Project
// SPDX-License-Identifier: MIT
//
//===----------------------------------------------------------------------===//
//
// This file assembles the register information, instruction formats, and 
// basic opcodes to initialize the LX32 backend. 
//
// Verified: ADD instruction generates correct Machine Code (Opcode 0x33).
//
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

// -----------------------------------------------------------------------------
// Component Includes
// -----------------------------------------------------------------------------

include "LX32RegisterInfo.td"
include "LX32InstrFormats.td"

// -----------------------------------------------------------------------------
// Opcode Map (Based on RISC-V 32-bit Base ISA)
// -----------------------------------------------------------------------------

def op_arith : LX32Opcode<"arith", 0b0110011>; // Register-Register ALU
def op_imm   : LX32Opcode<"imm",   0b0010011>; // Register-Immediate ALU
def op_load  : LX32Opcode<"load",  0b0000011>; // Memory Loads
def op_store : LX32Opcode<"store", 0b0100011>; // Memory Stores

// -----------------------------------------------------------------------------
// Instruction Definitions
// -----------------------------------------------------------------------------

// ADD rd, rs1, rs2 (rd = rs1 + rs2)
// Encoding: [funct7][rs2][rs1][funct3][rd][opcode]
def ADD : LXInstR<0b0000000, 0b000, op_arith, 
                 (outs GPR:$rd), 
                 (ins GPR:$rs1, GPR:$rs2), 
                 "add", "$rd, $rs1, $rs2">;

// -----------------------------------------------------------------------------
// Target Initialization
// -----------------------------------------------------------------------------

def LX32InstrInfo : InstrInfo {
  // Global instruction properties for TableGen emitters
  let guessInstructionProperties = 0;
}

def LX32 : Target {
  let InstructionSet = LX32InstrInfo;
}
