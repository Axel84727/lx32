// tests/test_lsu.rs
#[path = "common/mod.rs"]
mod common;
use common::*;
use lx32_validator::models::core::lsu::lsu_golden;
use rand::RngExt;

pub struct LsuTestParams {
    pub iterations: u32,
    pub reg_range: (u32, u32),
    pub imm_range: (i32, i32),
    pub enable_logging: bool,
}

impl Default for LsuTestParams {
    fn default() -> Self {
        Self {
            iterations: 1000,
            reg_range: (0, 32),
            imm_range: (-2048, 2047),
            enable_logging: true,
        }
    }
}

#[derive(Debug, Clone)]
struct LsuState {
    pc: u32,
    rd: u8,
    rd_value: u32,
    rs1: u8,
    rs1_value: u32,
    rs2: u8,
    rs2_value: u32,
    instr: u32,
    mem_rdata: u32,
    iteration: u32,
    is_load: bool,
}

fn encode_lw(rd: u8, rs1: u8, imm: i32) -> u32 {
    let imm12 = (imm as u32) & 0xFFF;
    (imm12 << 20) | ((rs1 as u32) << 15) | (0b010 << 12) | ((rd as u32) << 7) | 0x03
}

fn encode_sw(rs1: u8, rs2: u8, imm: i32) -> u32 {
    let imm12 = (imm as u32) & 0xFFF;
    let imm11_5 = (imm12 >> 5) & 0x7F;
    let imm4_0 = imm12 & 0x1F;
    (imm11_5 << 25)
        | ((rs2 as u32) << 20)
        | ((rs1 as u32) << 15)
        | (0b010 << 12)
        | (imm4_0 << 7)
        | 0x23
}

fn capture_lsu_state(
    tb: &TestBench,
    instr: u32,
    iteration: u32,
    rd: u8,
    rs1: u8,
    rs2: u8,
    mem_rdata: u32,
    is_load: bool,
) -> (LsuState, LsuState) {
    let rtl_state = LsuState {
        pc: unsafe { get_pc(tb.rtl) },
        rd,
        rd_value: unsafe { get_reg(tb.rtl, rd) },
        rs1,
        rs1_value: unsafe { get_reg(tb.rtl, rs1) },
        rs2,
        rs2_value: unsafe { get_reg(tb.rtl, rs2) },
        instr,
        mem_rdata,
        iteration,
        is_load,
    };

    let gold_state = LsuState {
        pc: tb.gold.pc,
        rd,
        rd_value: tb.gold.reg_file.read_rs1(rd),
        rs1,
        rs1_value: tb.gold.reg_file.read_rs1(rs1),
        rs2,
        rs2_value: tb.gold.reg_file.read_rs1(rs2),
        instr,
        mem_rdata,
        iteration,
        is_load,
    };

    (rtl_state, gold_state)
}

fn lsu_states_match(rtl: &LsuState, gold: &LsuState) -> bool {
    rtl.pc == gold.pc
        && rtl.rd_value == gold.rd_value
        && rtl.rs1_value == gold.rs1_value
        && rtl.rs2_value == gold.rs2_value
}

fn log_lsu_step(rtl: &LsuState, gold: &LsuState, matches: bool) {
    let status = if matches { "✓ MATCH" } else { "✗ MISMATCH" };
    let op_name = if rtl.is_load { "LW" } else { "SW" };

    println!(
        "[{:>5}] {:<2} Instr: 0x{:08x} | PC: [R:0x{:04x} G:0x{:04x}] | x{:>2}(RD): [R:0x{:08x} G:0x{:08x}] | x{:>2}: [R:0x{:08x} G:0x{:08x}] | mem_rdata:0x{:08x} | {}",
        rtl.iteration,
        op_name,
        rtl.instr,
        rtl.pc,
        gold.pc,
        rtl.rd,
        rtl.rd_value,
        gold.rd_value,
        rtl.rs2,
        rtl.rs2_value,
        gold.rs2_value,
        rtl.mem_rdata,
        status
    );
}

pub fn run_lsu_fuzzer(params: LsuTestParams) {
    println!("\n{:=^100}", " STARTING LSU FUZZER ");
    println!("Iterations: {}", params.iterations);
    println!("Registers: {:?}", params.reg_range);
    println!("Immediates: {:?}", params.imm_range);

    let mut tb = TestBench::new();
    let mut rng = rand::rng();

    for i in 0..params.iterations {
        let is_load = rng.random_range(0..2) == 0;
        let rs1 = rng.random_range(params.reg_range.0..params.reg_range.1) as u8;
        let rs2 = rng.random_range(params.reg_range.0..params.reg_range.1) as u8;
        let rd = rng.random_range(1..32) as u8;
        let imm = rng.random_range(params.imm_range.0..params.imm_range.1 + 1);
        let mem_rdata = rng.random::<u32>();

        let instr = if is_load {
            encode_lw(rd, rs1, imm)
        } else {
            encode_sw(rs1, rs2, imm)
        };

        unsafe { tick_core(tb.rtl, 0, instr, mem_rdata) };
        let (alu_res, rs2_data, mem_write) = tb.gold.step(instr, mem_rdata, false);

        let lsu_if = lsu_golden(alu_res, rs2_data, mem_write);
        let (rtl_state, gold_state) =
            capture_lsu_state(&tb, instr, i, rd, rs1, rs2, mem_rdata, is_load);
        let matches = lsu_states_match(&rtl_state, &gold_state);

        if params.enable_logging {
            log_lsu_step(&rtl_state, &gold_state, matches);
        }

        if !matches {
            println!("\n{:=^100}", " LSU MISMATCH DETECTED ");
            println!("Iteration: {}", i);
            println!("Instruction: 0x{:08x}", instr);
            println!("Operation: {}", if is_load { "LW" } else { "SW" });
            println!(
                "Expected LSU IF -> addr:0x{:08x} wdata:0x{:08x} we:{}",
                lsu_if.mem_addr, lsu_if.mem_wdata, lsu_if.mem_we
            );
            println!(
                "RTL  -> PC:0x{:04x} x{}:0x{:08x} x{}:0x{:08x}",
                rtl_state.pc, rtl_state.rd, rtl_state.rd_value, rtl_state.rs2, rtl_state.rs2_value
            );
            println!(
                "GOLD -> PC:0x{:04x} x{}:0x{:08x} x{}:0x{:08x}",
                gold_state.pc,
                gold_state.rd,
                gold_state.rd_value,
                gold_state.rs2,
                gold_state.rs2_value
            );
            panic!("🔥 LSU TEST FAILED AT ITERATION {}", i);
        }
    }

    println!("{:=^100}", " LSU FUZZER PASSED ");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_lsu_default() {
        run_lsu_fuzzer(LsuTestParams::default());
    }
}
