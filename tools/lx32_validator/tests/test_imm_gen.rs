// tests/test_imm_gen.rs
#[path = "common/mod.rs"]
mod common;
use common::*;
use lx32_validator::models::core::imm_gen::imm_gen_golden;
use rand::RngExt;

pub struct ImmGenTestParams {
    pub iterations: u32,
    pub rd_range: (u32, u32),
    pub branch_offset_range: (i32, i32),
    pub i_imm_range: (i32, i32),
    pub s_imm_range: (i32, i32),
    pub enable_logging: bool,
}

impl Default for ImmGenTestParams {
    fn default() -> Self {
        Self {
            iterations: 1000,
            rd_range: (1, 32),
            branch_offset_range: (-1024, 1024),
            i_imm_range: (-2048, 2047),
            s_imm_range: (-2048, 2047),
            enable_logging: true,
        }
    }
}

#[derive(Debug, Clone, Copy)]
enum ImmInstrType {
    IAddi,
    SStore,
    BBeq,
}

#[derive(Debug, Clone)]
struct ImmGenState {
    pre_pc: u32,
    post_pc: u32,
    rd: u8,
    rd_value: u32,
    rs2: u8,
    rs2_value: u32,
    instr: u32,
    imm_ext: u32,
    kind: ImmInstrType,
    iteration: u32,
}

fn encode_addi(rd: u8, imm: i32) -> u32 {
    let rs1 = 0u8;
    let imm12 = (imm as u32) & 0xFFF;
    (imm12 << 20) | ((rs1 as u32) << 15) | (0b000 << 12) | ((rd as u32) << 7) | 0x13
}

fn encode_store(rs2: u8, imm: i32) -> u32 {
    let rs1 = 0u8;
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

fn encode_beq(offset: i32) -> u32 {
    let rs1 = 0u32;
    let rs2 = 0u32;
    let b_imm = (offset as u32) & 0x1FFF;

    let imm12 = (b_imm >> 12) & 0x1;
    let imm11 = (b_imm >> 11) & 0x1;
    let imm10_5 = (b_imm >> 5) & 0x3F;
    let imm4_1 = (b_imm >> 1) & 0xF;

    (imm12 << 31)
        | (imm10_5 << 25)
        | (rs2 << 20)
        | (rs1 << 15)
        | (0b000 << 12)
        | (imm4_1 << 8)
        | (imm11 << 7)
        | 0x63
}

fn imm_states_match(rtl: &ImmGenState, gold: &ImmGenState) -> bool {
    rtl.post_pc == gold.post_pc && rtl.rd_value == gold.rd_value && rtl.rs2_value == gold.rs2_value
}

fn log_imm_step(rtl: &ImmGenState, gold: &ImmGenState, matches: bool) {
    let status = if matches { "✓ MATCH" } else { "✗ MISMATCH" };

    println!(
        "[{:>5}] {:?} Instr: 0x{:08x} | imm_ext:0x{:08x} | PC: 0x{:04x}->[R:0x{:04x} G:0x{:04x}] | x{:>2}(RD): [R:0x{:08x} G:0x{:08x}] | {}",
        rtl.iteration,
        rtl.kind,
        rtl.instr,
        rtl.imm_ext,
        rtl.pre_pc,
        rtl.post_pc,
        gold.post_pc,
        rtl.rd,
        rtl.rd_value,
        gold.rd_value,
        status
    );
}

pub fn run_imm_gen_fuzzer(params: ImmGenTestParams) {
    println!("\n{:=^100}", " STARTING IMM_GEN FUZZER ");
    println!("Iterations: {}", params.iterations);
    println!("RD Range: {:?}", params.rd_range);
    println!("I-Imm Range: {:?}", params.i_imm_range);
    println!("S-Imm Range: {:?}", params.s_imm_range);
    println!("B-Offset Range: {:?}", params.branch_offset_range);

    let mut tb = TestBench::new();
    let mut rng = rand::rng();

    for i in 0..params.iterations {
        let choice = rng.random_range(0..3);

        let rd = rng.random_range(params.rd_range.0..params.rd_range.1) as u8;
        let rs2 = rng.random_range(0..32) as u8;

        let (instr, kind) = match choice {
            0 => {
                let imm = rng.random_range(params.i_imm_range.0..params.i_imm_range.1 + 1);
                (encode_addi(rd, imm), ImmInstrType::IAddi)
            }
            1 => {
                let imm = rng.random_range(params.s_imm_range.0..params.s_imm_range.1 + 1);
                (encode_store(rs2, imm), ImmInstrType::SStore)
            }
            _ => {
                let mut offset_words = rng.random_range(
                    params.branch_offset_range.0..params.branch_offset_range.1 + 1,
                );
                if offset_words == 2 {
                    offset_words = 3;
                }
                let offset = offset_words * 2;
                (encode_beq(offset), ImmInstrType::BBeq)
            }
        };

        let imm_ext = imm_gen_golden(instr);
        let pre_pc_rtl = unsafe { get_pc(tb.rtl) };
        let pre_pc_gold = tb.gold.pc;

        unsafe { tick_core(tb.rtl, 0, instr, 0) };
        tb.gold.step(instr, 0, false);

        let rtl_state = ImmGenState {
            pre_pc: pre_pc_rtl,
            post_pc: unsafe { get_pc(tb.rtl) },
            rd,
            rd_value: unsafe { get_reg(tb.rtl, rd) },
            rs2,
            rs2_value: unsafe { get_reg(tb.rtl, rs2) },
            instr,
            imm_ext,
            kind,
            iteration: i,
        };

        let gold_state = ImmGenState {
            pre_pc: pre_pc_gold,
            post_pc: tb.gold.pc,
            rd,
            rd_value: tb.gold.reg_file.read_rs1(rd),
            rs2,
            rs2_value: tb.gold.reg_file.read_rs1(rs2),
            instr,
            imm_ext,
            kind,
            iteration: i,
        };

        let matches = imm_states_match(&rtl_state, &gold_state);

        if params.enable_logging {
            log_imm_step(&rtl_state, &gold_state, matches);
        }

        if !matches {
            println!("\n{:=^100}", " IMM_GEN MISMATCH DETECTED ");
            println!("Iteration: {}", i);
            println!("Kind: {:?}", kind);
            println!("Instr: 0x{:08x}", instr);
            println!("imm_ext (golden): 0x{:08x}", imm_ext);
            println!(
                "RTL  -> prePC:0x{:04x} postPC:0x{:04x} x{}:0x{:08x}",
                rtl_state.pre_pc, rtl_state.post_pc, rd, rtl_state.rd_value
            );
            println!(
                "GOLD -> prePC:0x{:04x} postPC:0x{:04x} x{}:0x{:08x}",
                gold_state.pre_pc, gold_state.post_pc, rd, gold_state.rd_value
            );
            panic!("🔥 IMM_GEN TEST FAILED AT ITERATION {}", i);
        }
    }

    println!("{:=^100}", " IMM_GEN FUZZER PASSED ");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_imm_gen_default() {
        run_imm_gen_fuzzer(ImmGenTestParams::default());
    }
}
