// tests/test_register_file.rs
#[path = "common/mod.rs"]
mod common;
use common::*;
use lx32_validator::models::core::register_file::RegisterFile;
use rand::RngExt;

pub struct RegisterFileTestParams {
    pub iterations: u32,
    pub reg_range: (u32, u32),
    pub data_range: (u32, u32),
    pub enable_logging: bool,
}

impl Default for RegisterFileTestParams {
    fn default() -> Self {
        Self {
            iterations: 2000,
            reg_range: (0, 32),
            data_range: (0, u32::MAX),
            enable_logging: true,
        }
    }
}

#[derive(Debug, Clone)]
struct RegisterState {
    addr_rd: u8,
    addr_rs1: u8,
    addr_rs2: u8,
    data_wr: u32,
    data_rs1: u32,
    data_rs2: u32,
    write_enable: bool,
    iteration: u32,
}

fn capture_rf_state(
    rf: &RegisterFile,
    addr_rd: u8,
    addr_rs1: u8,
    addr_rs2: u8,
    data_wr: u32,
    we: bool,
    iteration: u32,
) -> RegisterState {
    RegisterState {
        addr_rd,
        addr_rs1,
        addr_rs2,
        data_wr,
        data_rs1: rf.read_rs1(addr_rs1),
        data_rs2: rf.read_rs2(addr_rs2),
        write_enable: we,
        iteration,
    }
}

fn rf_states_match(pre: &RegisterState, post: &RegisterState, reset: bool) -> bool {
    if reset {
        // After reset, all reads should return 0
        post.data_rs1 == 0 && post.data_rs2 == 0
    } else {
        // x0 must always be 0
        if post.addr_rs1 == 0 && post.data_rs1 != 0 {
            return false;
        }
        if post.addr_rs2 == 0 && post.data_rs2 != 0 {
            return false;
        }

        // If we wrote to a non-zero register, reading it back should return the written value
        if pre.write_enable && pre.addr_rd != 0 && pre.addr_rs1 == pre.addr_rd {
            if post.data_rs1 != pre.data_wr {
                return false;
            }
        }
        if pre.write_enable && pre.addr_rd != 0 && pre.addr_rs2 == pre.addr_rd {
            if post.data_rs2 != pre.data_wr {
                return false;
            }
        }

        true
    }
}

fn log_rf_step(pre: &RegisterState, post: &RegisterState, matches: bool) {
    let status = if matches { "✓ MATCH" } else { "✗ MISMATCH" };

    let op = if pre.write_enable { "WRITE" } else { "READ " };
    println!(
        "[{:>5}] {} | x{:<2}(WR): 0x{:08x} | x{:<2}(RS1): 0x{:08x} | x{:<2}(RS2): 0x{:08x} | {}",
        pre.iteration, op, pre.addr_rd, pre.data_wr, pre.addr_rs1, post.data_rs1, pre.addr_rs2, post.data_rs2, status
    );
}

pub fn run_register_file_fuzzer(params: RegisterFileTestParams) {
    println!("\n{:=^100}", " STARTING REGISTER_FILE FUZZER ");
    println!("Iterations: {}", params.iterations);
    println!("Register Range: {:?}", params.reg_range);
    println!("Data Range: {:?}", params.data_range);

    let mut gold_rf = RegisterFile::new();
    let mut rng = rand::rng();

    for i in 0..params.iterations {
        let reset = i == 0;
        let we = !reset && (rng.random_range(0..2) == 0);
        let addr_rd = rng.random_range(params.reg_range.0..params.reg_range.1) as u8;
        let addr_rs1 = rng.random_range(params.reg_range.0..params.reg_range.1) as u8;
        let addr_rs2 = rng.random_range(params.reg_range.0..params.reg_range.1) as u8;
        let data_wr = rng.random_range(params.data_range.0..params.data_range.1);

        let pre_state =
            capture_rf_state(&gold_rf, addr_rd, addr_rs1, addr_rs2, data_wr, we, i);

        // Apply operation
        gold_rf.tick(reset, addr_rd, data_wr, we);

        let post_state =
            capture_rf_state(&gold_rf, addr_rd, addr_rs1, addr_rs2, data_wr, we, i);
        let matches = rf_states_match(&pre_state, &post_state, reset);

        if params.enable_logging {
            log_rf_step(&pre_state, &post_state, matches);
        }

        if !matches {
            println!("\n{:=^100}", " REGISTER_FILE MISMATCH DETECTED ");
            println!("Iteration: {}", i);
            println!("Operation: {}", if reset { "RESET" } else if we { "WRITE" } else { "READ" });
            println!("Write Addr: x{:<2}", addr_rd);
            println!("Write Data: 0x{:08x}", data_wr);
            println!("RS1 (x{}): 0x{:08x}", addr_rs1, post_state.data_rs1);
            println!("RS2 (x{}): 0x{:08x}", addr_rs2, post_state.data_rs2);
            if addr_rs1 == 0 && post_state.data_rs1 != 0 {
                println!("ERROR: x0 must always be 0!");
            }
            if addr_rs2 == 0 && post_state.data_rs2 != 0 {
                println!("ERROR: x0 must always be 0!");
            }
            panic!("🔥 REGISTER_FILE TEST FAILED AT ITERATION {}", i);
        }
    }

    println!("{:=^100}", " REGISTER_FILE FUZZER PASSED ");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_register_file_default() {
        run_register_file_fuzzer(RegisterFileTestParams::default());
    }
}
