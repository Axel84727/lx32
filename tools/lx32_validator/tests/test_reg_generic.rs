// tests/test_reg_generic.rs
#[path = "common/mod.rs"]
mod common;
use common::*;
use lx32_validator::models::core::reg_generic::RegGeneric;
use rand::RngExt;

pub struct RegGenericTestParams {
    pub iterations: u32,
    pub data_range: (u32, u32),
    pub enable_logging: bool,
}

impl Default for RegGenericTestParams {
    fn default() -> Self {
        Self {
            iterations: 2000,
            data_range: (0, u32::MAX),
            enable_logging: true,
        }
    }
}

#[derive(Debug, Clone)]
struct RegState {
    data_in: u32,
    enable: bool,
    reset: bool,
    data_out: u32,
    iteration: u32,
}

fn capture_reg_state(reg: &RegGeneric, data_in: u32, enable: bool, reset: bool, iteration: u32) -> RegState {
    RegState {
        data_in,
        enable,
        reset,
        data_out: reg.data_out,
        iteration,
    }
}

fn reg_states_match(pre: &RegState, post: &RegState, reset: bool, enable: bool) -> bool {
    if reset {
        // After reset, output should be 0
        post.data_out == 0
    } else if enable {
        // After enable, output should be the input data
        post.data_out == pre.data_in
    } else {
        // Without enable, output should remain unchanged
        post.data_out == pre.data_out
    }
}

fn log_reg_step(pre: &RegState, post: &RegState, reset: bool, enable: bool, matches: bool) {
    let status = if matches { "✓ MATCH" } else { "✗ MISMATCH" };
    let op = if reset {
        "RESET"
    } else if enable {
        "WRITE"
    } else {
        "HOLD "
    };

    println!(
        "[{:>5}] {} | data_in:0x{:08x} | pre_out:0x{:08x} | post_out:0x{:08x} | {}",
        pre.iteration, op, pre.data_in, pre.data_out, post.data_out, status
    );
}

pub fn run_reg_generic_fuzzer(params: RegGenericTestParams) {
    println!("\n{:=^100}", " STARTING REG_GENERIC FUZZER ");
    println!("Iterations: {}", params.iterations);
    println!("Data Range: {:?}", params.data_range);

    let mut gold_reg = RegGeneric::new(32);
    let mut rng = rand::rng();

    for i in 0..params.iterations {
        // 33% reset, 33% enable, 33% hold
        let op_choice = rng.random_range(0..3);
        let reset = op_choice == 0;
        let enable = op_choice == 1;
        let data_in = rng.random_range(params.data_range.0..params.data_range.1);

        let pre_state = capture_reg_state(&gold_reg, data_in, enable, reset, i);

        // Apply operation to golden model
        gold_reg.tick(reset, enable, data_in);

        let post_state = capture_reg_state(&gold_reg, data_in, enable, reset, i);
        let matches = reg_states_match(&pre_state, &post_state, reset, enable);

        if params.enable_logging {
            log_reg_step(&pre_state, &post_state, reset, enable, matches);
        }

        if !matches {
            println!("\n{:=^100}", " REG_GENERIC MISMATCH DETECTED ");
            println!("Iteration: {}", i);
            println!("Operation: {}", if reset { "RESET" } else if enable { "WRITE" } else { "HOLD" });
            println!("Input Data: 0x{:08x}", data_in);
            println!("Pre Output:  0x{:08x}", pre_state.data_out);
            println!("Post Output: 0x{:08x}", post_state.data_out);
            if reset {
                println!("Expected post output: 0x00000000 (after reset)");
            } else if enable {
                println!("Expected post output: 0x{:08x} (data_in)", data_in);
            } else {
                println!("Expected post output: 0x{:08x} (unchanged)", pre_state.data_out);
            }
            panic!("🔥 REG_GENERIC TEST FAILED AT ITERATION {}", i);
        }
    }

    println!("{:=^100}", " REG_GENERIC FUZZER PASSED ");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_reg_generic_default() {
        run_reg_generic_fuzzer(RegGenericTestParams::default());
    }
}
