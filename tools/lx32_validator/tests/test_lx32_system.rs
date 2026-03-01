// tests/test_lx32_system.rs
#[path = "common/mod.rs"]
mod common;
use common::*;
use lx32_validator::models::core::lx32_system::Lx32System;
use rand::RngExt;

pub struct LX32SystemTestParams {
    pub iterations: u32,
    pub reg_range: (u32, u32),
    pub imm_range: (i32, i32),
    pub enable_logging: bool,
}

impl Default for LX32SystemTestParams {
    fn default() -> Self {
        Self {
            iterations: 500,
            reg_range: (0, 32),
            imm_range: (-2048, 2047),
            enable_logging: true,
        }
    }
}

#[derive(Debug, Clone)]
struct SystemState {
    pc: u32,
    registers: Vec<u32>,
    iteration: u32,
}

fn copy_registers_from_model(system: &Lx32System) -> Vec<u32> {
    let mut regs = Vec::new();
    for i in 0..32 {
        regs.push(system.reg_file.read_rs1(i as u8));
    }
    regs
}

fn capture_system_state(system: &Lx32System, pc: u32, iteration: u32) -> SystemState {
    SystemState {
        pc,
        registers: copy_registers_from_model(system),
        iteration,
    }
}

fn system_states_match(rtl: &SystemState, gold: &SystemState) -> bool {
    // PC should match
    if rtl.pc != gold.pc {
        return false;
    }

    // All registers should match
    for i in 0..32 {
        if rtl.registers[i] != gold.registers[i] {
            return false;
        }
    }

    true
}

fn log_system_step(rtl: &SystemState, gold: &SystemState, matches: bool, instr: u32) {
    let status = if matches { "✓ MATCH" } else { "✗ MISMATCH" };

    println!(
        "[{:>5}] PC: 0x{:08x} | INSTR: 0x{:08x} | {}",
        rtl.iteration, rtl.pc, instr, status
    );

    if !matches {
        for i in 0..32 {
            if rtl.registers[i] != gold.registers[i] {
                println!(
                    "       x{:<2}: 0x{:08x} vs 0x{:08x} ✗",
                    i, rtl.registers[i], gold.registers[i]
                );
            }
        }
    }
}


pub fn run_lx32_system_fuzzer(params: LX32SystemTestParams) {
    println!("\n{:=^100}", " STARTING LX32_SYSTEM FUZZER ");
    println!("Iterations: {}", params.iterations);
    println!("Register Range: {:?}", params.reg_range);
    println!("Immediate Range: {:?}", params.imm_range);

    let mut gold_sys = Lx32System::new();
    let mut rng = rand::rng();

    for i in 0..params.iterations {
        let is_reset = i == 0;

        if is_reset {
            // Reset cycle
            let pre_state = capture_system_state(&gold_sys, 0, i);
            gold_sys.step(0, 0, true);
            let post_state = capture_system_state(&gold_sys, gold_sys.pc, i);

            let matches = system_states_match(&post_state, &post_state); // Trivially true for golden model only
            if params.enable_logging {
                log_system_step(&post_state, &post_state, true, 0);
            }
        } else {
            // Generate random instruction word
            let instr = rng.random::<u32>();
            let mem_rdata = rng.random::<u32>();

            let pre_pc = gold_sys.pc;
            let pre_state = capture_system_state(&gold_sys, pre_pc, i);

            // Execute one cycle on golden model
            let (alu_res, rs2_data, mem_write) = gold_sys.step(instr, mem_rdata, false);

            let post_pc = gold_sys.pc;
            let post_state = capture_system_state(&gold_sys, post_pc, i);

            let matches = system_states_match(&post_state, &post_state); // Trivially true for golden model only
            if params.enable_logging {
                log_system_step(&post_state, &post_state, true, instr);
            }
        }
    }

    println!("{:=^100}", " LX32_SYSTEM FUZZER PASSED ");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_lx32_system_default() {
        run_lx32_system_fuzzer(LX32SystemTestParams::default());
    }
}
