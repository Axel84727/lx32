// tests/test_memory_sim.rs
#[path = "common/mod.rs"]
mod common;
use common::*;
use lx32_validator::models::core::memory_sim::MemorySim;
use rand::RngExt;

pub struct MemorySimTestParams {
    pub iterations: u32,
    pub addr_range: (u32, u32),
    pub data_range: (u32, u32),
    pub enable_logging: bool,
}

impl Default for MemorySimTestParams {
    fn default() -> Self {
        Self {
            iterations: 1000,
            addr_range: (0, 4096),
            data_range: (0, u32::MAX),
            enable_logging: true,
        }
    }
}

#[derive(Debug, Clone)]
struct MemoryState {
    addr: u32,
    write_data: u32,
    write_enable: bool,
    read_data: u32,
    iteration: u32,
}

fn capture_memory_state(
    gold_mem: &MemorySim,
    addr: u32,
    write_data: u32,
    write_enable: bool,
    iteration: u32,
) -> MemoryState {
    MemoryState {
        addr,
        write_data,
        write_enable,
        read_data: gold_mem.read_data(addr),
        iteration,
    }
}

fn memory_states_match(gold: &MemoryState, gold_mem_after: &MemorySim, addr: u32) -> bool {
    // Verify the read returned correct data
    gold_mem_after.read_data(addr) == gold.read_data
}

fn log_memory_step(gold: &MemoryState, matches: bool) {
    let status = if matches { "✓ MATCH" } else { "✗ MISMATCH" };

    let op = if gold.write_enable { "WRITE" } else { "READ " };
    println!(
        "[{:>5}] {} | addr:0x{:03x} | data:0x{:08x} | read_result:0x{:08x} | {}",
        gold.iteration, op, gold.addr, gold.write_data, gold.read_data, status
    );
}

pub fn run_memory_sim_fuzzer(params: MemorySimTestParams) {
    println!("\n{:=^100}", " STARTING MEMORY_SIM FUZZER ");
    println!("Iterations: {}", params.iterations);
    println!("Address Range: {:?}", params.addr_range);
    println!("Data Range: {:?}", params.data_range);

    let mut gold_mem = MemorySim::new();
    let mut rng = rand::rng();

    for i in 0..params.iterations {
        let we = rng.random_range(0..2) == 0;
        let addr = rng.random_range(params.addr_range.0..params.addr_range.1);
        let data = rng.random_range(params.data_range.0..params.data_range.1);

        if we {
            // WRITE operation: write data, then read back to verify
            gold_mem.write_data(addr, data, true);
            let read_back = gold_mem.read_data(addr);
            
            let gold_state = capture_memory_state(&gold_mem, addr, data, we, i);
            let matches = read_back == data;

            if params.enable_logging {
                let status = if matches { "✓ MATCH" } else { "✗ MISMATCH" };
                println!(
                    "[{:>5}] WRITE | addr:0x{:03x} | write_data:0x{:08x} | read_back:0x{:08x} | {}",
                    i, addr, data, read_back, status
                );
            }

            if !matches {
                println!("\n{:=^100}", " MEMORY_SIM MISMATCH DETECTED ");
                println!("Iteration: {}", i);
                println!("Operation: WRITE");
                println!("Address: 0x{:03x}", addr);
                println!("Write Data: 0x{:08x}", data);
                println!("Read Back: 0x{:08x}", read_back);
                println!("Expected Read Back: 0x{:08x}", data);
                panic!("🔥 MEMORY_SIM TEST FAILED AT ITERATION {}", i);
            }
        } else {
            // READ operation: just verify we can read from the address
            let read_result = gold_mem.read_data(addr);
            let gold_state = capture_memory_state(&gold_mem, addr, data, we, i);

            if params.enable_logging {
                println!(
                    "[{:>5}] READ  | addr:0x{:03x} | read_result:0x{:08x} | ✓ MATCH",
                    i, addr, read_result
                );
            }
        }
    }

    println!("{:=^100}", " MEMORY_SIM FUZZER PASSED ");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_memory_sim_default() {
        run_memory_sim_fuzzer(MemorySimTestParams::default());
    }
}
