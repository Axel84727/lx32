// tests/test_alu.rs
#[path = "common/mod.rs"]
mod common;
use common::*;
use rand::RngExt;

pub fn run_alu_fuzzer(iterations: u32) {
    let mut tb = TestBench::new();
    let mut rng = rand::rng();

    for i in 0..iterations {
        let rd: u32 = rng.random_range(1..32);
        let rs1: u32 = rng.random_range(0..32);
        let imm: u32 = rng.random_range(0..4096);
        let funct3 = [0x0, 0x2, 0x4, 0x6, 0x7][rng.random_range(0..5)];
        let instr = (imm << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | 0x13;

        unsafe { tick_core(tb.rtl, 0, instr, 0) };
        tb.gold.step(instr, 0, false);

        let r_val = unsafe { get_reg(tb.rtl, rd as u8) };
        let g_val = tb.gold.reg_file.read_rs1(rd as u8);

        // Call our new detailed debugger
        tb.log_step(i, instr, rd, r_val, g_val);

        if r_val != g_val || unsafe { get_pc(tb.rtl) } != tb.gold.pc {
            panic!("🔥 BREAK AT ITERATION {}", i);
        }
    }
}
