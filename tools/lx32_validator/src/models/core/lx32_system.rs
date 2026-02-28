// ============================================================
// LX32 Processor System (Single Cycle)
// ============================================================
// Integration of all core sub-modules:
// - Control Unit, ALU, Branch Unit, LSU, RF and ImmGen.
//
// Design Principles:
//   - Clear signal naming and hierarchical structure.
//   - Single-cycle execution datapath.
//   - Asynchronous reset for Program Counter.
// ============================================================

use crate::models::arch::lx32_branch_pkg::branch_op_e;
use crate::models::arch::lx32_isa_pkg::opcode_t;
use crate::models::core::alu::alu_golden_model;
use crate::models::core::branch_unit::branch_unit_golden;
use crate::models::core::control_unit::control_unit_golden;
use crate::models::core::imm_gen::imm_gen_golden;
use crate::models::core::register_file::RegisterFile;

pub struct Lx32System {
    pub pc: u32,
    pub reg_file: RegisterFile,
}

impl Lx32System {
    pub fn new() -> Self {
        Self {
            pc: 0,
            reg_file: RegisterFile::new(),
        }
    }

    pub fn step(&mut self, instr: u32, mem_rdata: u32, rst: bool) -> (u32, u32, bool) {
        // --- 1. Reset Logic ---
        if rst {
            self.pc = 0;
            self.reg_file.tick(true, 0, 0, false);
            return (0, 0, false);
        }

        // --- 2. Decode Stage ---
        // Calling the methods defined in arch/
        let opcode = opcode_t::from_bits((instr & 0x7F) as u8);
        let funct3 = ((instr >> 12) & 0x7) as u8;
        let funct7_5 = ((instr >> 30) & 0x1) != 0;
        let branch_op = branch_op_e::from_bits(funct3);

        let ctrl = control_unit_golden(opcode, funct3, funct7_5);
        let imm_ext = imm_gen_golden(instr);

        // --- 3. Register File Read ---
        let rs1_addr = ((instr >> 15) & 0x1F) as u8;
        let rs2_addr = ((instr >> 20) & 0x1F) as u8;
        let rd_addr = ((instr >> 7) & 0x1F) as u8;

        let rs1_data = self.reg_file.read_rs1(rs1_addr);
        let rs2_data = self.reg_file.read_rs2(rs2_addr);

        // --- 4. Execution Stage ---
        let alu_a = rs1_data;
        let alu_b = if ctrl.alu_src { imm_ext } else { rs2_data };

        // ALU and Branch evaluation
        let alu_res = alu_golden_model(alu_a, alu_b, ctrl.alu_control);
        let branch_taken = branch_unit_golden(alu_a, rs2_data, ctrl.branch, branch_op);

        // --- 5. Write-Back Selection ---
        let rd_data = if ctrl.result_src == 0b01 {
            mem_rdata
        } else {
            alu_res
        };

        // --- 6. State Update ---
        self.reg_file.tick(false, rd_addr, rd_data, ctrl.reg_write);

        let next_pc = if ctrl.branch && branch_taken {
            self.pc.wrapping_add(imm_ext)
        } else {
            self.pc.wrapping_add(4)
        };
        self.pc = next_pc;

        // --- 7. Memory Interface Outputs (LSU) ---
        (alu_res, rs2_data, ctrl.mem_write)
    }
}
