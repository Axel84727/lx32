// tests/test_alu.rs
#[path = "common/mod.rs"]
mod common;
use common::*;
use rand::RngExt;

pub struct AluTestParams {
    pub iterations: u32,
    pub rd_range: (u32, u32),
    pub rs1_range: (u32, u32),
    pub imm_range: (u32, u32),
    pub enable_logging: bool,
}

impl Default for AluTestParams {
    fn default() -> Self {
        Self {
            iterations: 1000,
            rd_range: (1, 32),
            rs1_range: (0, 32),
            imm_range: (0, 4096),
            enable_logging: true,
        }
    }
}

#[derive(Debug, Clone)]
struct AluState {
    pc: u32,
    rd: u8,
    rd_value: u32,
    rs1: u8,
    rs1_value: u32,
    instr: u32,
    iteration: u32,
}

fn capture_alu_state(tb: &TestBench, instr: u32, iteration: u32, rd: u8, rs1: u8) -> (AluState, AluState) {
    let rtl_state = AluState {
        pc: unsafe { get_pc(tb.rtl) },
        rd,
        rd_value: unsafe { get_reg(tb.rtl, rd) },
        rs1,
        rs1_value: unsafe { get_reg(tb.rtl, rs1) },
        instr,
        iteration,
    };

    let gold_state = AluState {
        pc: tb.gold.pc,
        rd,
        rd_value: tb.gold.reg_file.read_rs1(rd),
        rs1,
        rs1_value: tb.gold.reg_file.read_rs1(rs1),
        instr,
        iteration,
    };

    (rtl_state, gold_state)
}

fn alu_states_match(rtl: &AluState, gold: &AluState) -> bool {
    rtl.pc == gold.pc && rtl.rd_value == gold.rd_value && rtl.rs1_value == gold.rs1_value
}

fn log_alu_step(rtl: &AluState, gold: &AluState, matches: bool) {
    let status = if matches { "✓ MATCH" } else { "✗ MISMATCH" };
    println!(
        "[{:>5}] Instr: 0x{:08x} | PC: [R:0x{:04x} G:0x{:04x}] | x{:>2}(RD): [R:0x{:08x} G:0x{:08x}] | x{:>2}(RS1): [R:0x{:08x} G:0x{:08x}] | {}",
        rtl.iteration,
        rtl.instr,
        rtl.pc,
        gold.pc,
        rtl.rd,
        rtl.rd_value,
        gold.rd_value,
        rtl.rs1,
        rtl.rs1_value,
        gold.rs1_value,
        status
    );
}

pub fn run_alu_fuzzer(params: AluTestParams) {
    println!("\n{:=^100}", " STARTING ALU FUZZER ");
    println!("Iterations: {}", params.iterations);
    println!("RD Range: {:?}", params.rd_range);
    println!("RS1 Range: {:?}", params.rs1_range);
    println!("IMM Range: {:?}", params.imm_range);

    let mut tb = TestBench::new();
    let mut rng = rand::rng();
    let funct3_set = [0x0, 0x2, 0x4, 0x6, 0x7];

    for i in 0..params.iterations {
        let rd = rng.random_range(params.rd_range.0..params.rd_range.1) as u8;
        let rs1 = rng.random_range(params.rs1_range.0..params.rs1_range.1) as u8;
        let imm = rng.random_range(params.imm_range.0..params.imm_range.1);
        let funct3 = funct3_set[rng.random_range(0..funct3_set.len())];
        let instr = (imm << 20) | ((rs1 as u32) << 15) | (funct3 << 12) | ((rd as u32) << 7) | 0x13;

        unsafe { tick_core(tb.rtl, 0, instr, 0) };
        tb.gold.step(instr, 0, false);

        let (rtl_state, gold_state) = capture_alu_state(&tb, instr, i, rd, rs1);
        let matches = alu_states_match(&rtl_state, &gold_state);

        if params.enable_logging {
            log_alu_step(&rtl_state, &gold_state, matches);
        }

        if !matches {
            println!("\n{:=^100}", " ALU MISMATCH DETECTED ");
            println!("Iteration: {}", i);
            println!("Instruction: 0x{:08x}", instr);
            println!("RTL  -> PC: 0x{:04x} x{}:0x{:08x} x{}:0x{:08x}", rtl_state.pc, rd, rtl_state.rd_value, rs1, rtl_state.rs1_value);
            println!("GOLD -> PC: 0x{:04x} x{}:0x{:08x} x{}:0x{:08x}", gold_state.pc, rd, gold_state.rd_value, rs1, gold_state.rs1_value);
            panic!("🔥 ALU TEST FAILED AT ITERATION {}", i);
        }
    }

    println!("{:=^100}", " ALU FUZZER PASSED ");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_alu_default() {
        run_alu_fuzzer(AluTestParams::default());
    }
}
