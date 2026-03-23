include "llvm/Target/Target.td"
include "LX32RegisterInfo.td"
include "LX32InstrFormats.td"

// Aquí metés los defs de arriba (el ADD y el Opcode)
def op_arith : LX32Opcode<"arith", 0b0110011>;
// Asegurate de que los nombres coincidan: rd, rs1, rs2
def op_imm : LX32Opcode<"imm", 0b0010011>;

def ADD : LXInstR<0b0000000, 0b000, op_arith, 
                 (outs GPR:$rd), 
                 (ins GPR:$rs1, GPR:$rs2), 
                 "add", "$rd, $rs1, $rs2">;

def LX32InstrInfo : InstrInfo;
def LX32 : Target {
  let InstructionSet = LX32InstrInfo;
}