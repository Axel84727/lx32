// tests/test_branch_unit.rs
#[path = "common/mod.rs"]
mod common;
use common::*;
use rand::RngExt;

pub fn run_branch_fuzzer(iterations: u32) {
    println!("\n{:=^100}", " STARTING BRANCH UNIT FUZZER ");
    let mut tb = TestBench::new();
    let mut rng = rand::rng();

    for i in 0..iterations {
        // 1. Randomize sources
        let rs1: u32 = rng.random_range(0..32);
        let rs2: u32 = rng.random_range(0..32);

        // 2. Randomize a 12-bit SIGNED offset (multiple of 2)
        // We stay within a safe range to avoid jumping to address 0 or outside memory
        let offset: i32 = rng.random_range(-32..32) * 4;

        // 3. Randomize Branch Condition
        let opcodes = [0x0, 0x1, 0x4, 0x5, 0x6, 0x7];
        let funct3 = opcodes[rng.random_range(0..opcodes.len())];

        // 4. Manual B-type Bit Scrambling (The "Hardware" way)
        let b_imm = offset as u32;
        let imm12 = (b_imm >> 12) & 0x1;
        let imm11 = (b_imm >> 11) & 0x1;
        let imm10_5 = (b_imm >> 5) & 0x3f;
        let imm4_1 = (b_imm >> 1) & 0xf;

        let instr = (imm12 << 31)
            | (imm10_5 << 25)
            | (rs2 << 20)
            | (rs1 << 15)
            | (funct3 << 12)
            | (imm4_1 << 8)
            | (imm11 << 7)
            | 0x63;

        // 5. Capture state BEFORE
        let pre_pc = unsafe { get_pc(tb.rtl) };

        // 6. Execute Step
        unsafe { tick_core(tb.rtl, 0, instr, 0) };
        tb.gold.step(instr, 0, false);

        // 7. Capture state AFTER
        let post_rtl_pc = unsafe { get_pc(tb.rtl) };
        let post_gold_pc = tb.gold.pc;

        let val1 = unsafe { get_reg(tb.rtl, rs1 as u8) };
        let val2 = unsafe { get_reg(tb.rtl, rs2 as u8) };

        // 8. LOGGING (Safe pointer arithmetic for display)
        // wrapping_add avoids the "panic on overflow"
        let taken = post_rtl_pc != pre_pc.wrapping_add(4);
        let status = if post_rtl_pc == post_gold_pc {
            "MATCH"
        } else {
            "!!! MISMATCH !!!"
        };

        println!(
            "[{:>5}] Instr: 0x{:08x} | PC: 0x{:04x}->[R:0x{:04x} G:0x{:04x}] | x{:>2}:0x{:08x} vs x{:>2}:0x{:08x} | Taken: {:<5} | {}",
            i, instr, pre_pc, post_rtl_pc, post_gold_pc, rs1, val1, rs2, val2, taken, status
        );

        if post_rtl_pc != post_gold_pc {
            panic!(
                "🔥 BRANCH MISMATCH!\nIter: {}\nInstr: 0x{:08x}\nOffset: {}\nTarget should be: 0x{:08x}\nRTL jumped to: 0x{:08x}",
                i, instr, offset, post_gold_pc, post_rtl_pc
            );
        }
    }
    println!("{:=^100}", " BRANCH UNIT PASSED ");
}
