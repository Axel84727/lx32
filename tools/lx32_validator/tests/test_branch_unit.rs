// tests/test_branch_unit.rs
#[path = "common/mod.rs"]
mod common;
use common::*;
use rand::RngExt;

pub struct BranchTestParams {
    pub iterations: u32,
    pub reg_range: (u32, u32),
    pub offset_word_range: (i32, i32),
    pub enable_logging: bool,
}

impl Default for BranchTestParams {
    fn default() -> Self {
        Self {
            iterations: 1000,
            reg_range: (0, 32),
            offset_word_range: (-32, 32),
            enable_logging: true,
        }
    }
}

#[derive(Debug, Clone)]
struct BranchState {
    pre_pc: u32,
    post_pc: u32,
    rs1: u8,
    rs2: u8,
    rs1_value: u32,
    rs2_value: u32,
    instr: u32,
    offset: i32,
    iteration: u32,
}

fn branch_states_match(rtl: &BranchState, gold: &BranchState) -> bool {
    rtl.post_pc == gold.post_pc
        && rtl.rs1_value == gold.rs1_value
        && rtl.rs2_value == gold.rs2_value
}

fn log_branch_step(rtl: &BranchState, gold: &BranchState, matches: bool) {
    let rtl_taken = rtl.post_pc != rtl.pre_pc.wrapping_add(4);
    let status = if matches { "✓ MATCH" } else { "✗ MISMATCH" };

    println!(
        "[{:>5}] Instr: 0x{:08x} | PC: 0x{:04x}->[R:0x{:04x} G:0x{:04x}] | x{:>2}: [R:0x{:08x} G:0x{:08x}] | x{:>2}: [R:0x{:08x} G:0x{:08x}] | Taken: {:<5} | {}",
        rtl.iteration,
        rtl.instr,
        rtl.pre_pc,
        rtl.post_pc,
        gold.post_pc,
        rtl.rs1,
        rtl.rs1_value,
        gold.rs1_value,
        rtl.rs2,
        rtl.rs2_value,
        gold.rs2_value,
        rtl_taken,
        status
    );
}

pub fn run_branch_fuzzer(params: BranchTestParams) {
    println!("\n{:=^100}", " STARTING BRANCH UNIT FUZZER ");
    println!("Iterations: {}", params.iterations);
    println!("Registers: {:?}", params.reg_range);
    println!("Offset words: {:?}", params.offset_word_range);

    let mut tb = TestBench::new();
    let mut rng = rand::rng();

    for i in 0..params.iterations {
        // 1. Randomize sources
        let rs1 = rng.random_range(params.reg_range.0..params.reg_range.1) as u8;
        let rs2 = rng.random_range(params.reg_range.0..params.reg_range.1) as u8;

        // 2. Randomize a 12-bit SIGNED offset (multiple of 2)
        // We stay within a safe range to avoid jumping to address 0 or outside memory
        let offset: i32 = rng.random_range(params.offset_word_range.0..params.offset_word_range.1) * 4;

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
            | ((rs2 as u32) << 20)
            | ((rs1 as u32) << 15)
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

        let rtl_state = BranchState {
            pre_pc,
            post_pc: post_rtl_pc,
            rs1,
            rs2,
            rs1_value: unsafe { get_reg(tb.rtl, rs1) },
            rs2_value: unsafe { get_reg(tb.rtl, rs2) },
            instr,
            offset,
            iteration: i,
        };

        let gold_state = BranchState {
            pre_pc,
            post_pc: post_gold_pc,
            rs1,
            rs2,
            rs1_value: tb.gold.reg_file.read_rs1(rs1),
            rs2_value: tb.gold.reg_file.read_rs1(rs2),
            instr,
            offset,
            iteration: i,
        };

        let states_match = branch_states_match(&rtl_state, &gold_state);

        if params.enable_logging {
            log_branch_step(&rtl_state, &gold_state, states_match);
        }

        if !states_match {
            panic!(
                "🔥 BRANCH MISMATCH!\nIter: {}\nInstr: 0x{:08x}\nOffset: {}\nPC RTL: 0x{:08x} | GOLD: 0x{:08x}\nRS1 x{} RTL:0x{:08x} | GOLD:0x{:08x}\nRS2 x{} RTL:0x{:08x} | GOLD:0x{:08x}",
                i,
                instr,
                rtl_state.offset,
                rtl_state.post_pc,
                gold_state.post_pc,
                rtl_state.rs1,
                rtl_state.rs1_value,
                gold_state.rs1_value,
                rtl_state.rs2,
                rtl_state.rs2_value,
                gold_state.rs2_value
            );
        }
    }
    println!("{:=^100}", " BRANCH UNIT PASSED ");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_branch_default() {
        run_branch_fuzzer(BranchTestParams::default());
    }
}
