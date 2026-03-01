// src/main.rs
#[path = "../tests/test_alu.rs"]
mod test_alu;

#[path = "../tests/test_branch_unit.rs"]
mod test_branch_unit;

#[path = "../tests/test_control_unit.rs"]
mod test_control_unit;

#[path = "../tests/test_lsu.rs"]
mod test_lsu;

#[path = "../tests/test_imm_gen.rs"]
mod test_imm_gen;

#[path = "../tests/test_memory_sim.rs"]
mod test_memory_sim;

#[path = "../tests/test_reg_generic.rs"]
mod test_reg_generic;

#[path = "../tests/test_register_file.rs"]
mod test_register_file;

#[path = "../tests/test_lx32_system.rs"]
mod test_lx32_system;

fn main() {
    println!("{:=^100}", " LX32 FULL HARDWARE VALIDATION ");

    // ALU validation
    test_alu::run_alu_fuzzer(test_alu::AluTestParams {
        iterations: 3000,
        rd_range: (1, 32),
        rs1_range: (0, 32),
        imm_range: (0, 4096),
        enable_logging: false,
    });

    // Branch validation
    test_branch_unit::run_branch_fuzzer(test_branch_unit::BranchTestParams {
        iterations: 10000,
        reg_range: (0, 32),
        offset_word_range: (-128, 128),
        enable_logging: false,
    });

    // Control Unit validation
    test_control_unit::run_control_unit_fuzzer(test_control_unit::ControlUnitTestParams {
        iterations: 500,
        reg_range: (0, 32),
        imm_range: (-2048, 2047),
        enable_logging: false,
    });

    // LSU validation
    test_lsu::run_lsu_fuzzer(test_lsu::LsuTestParams {
        iterations: 2000,
        reg_range: (0, 32),
        imm_range: (-2048, 2047),
        enable_logging: false,
    });

    // IMM_GEN validation
    test_imm_gen::run_imm_gen_fuzzer(test_imm_gen::ImmGenTestParams {
        iterations: 2000,
        rd_range: (1, 32),
        branch_offset_range: (-1024, 1024),
        i_imm_range: (-2048, 2047),
        s_imm_range: (-2048, 2047),
        enable_logging: false,
    });

    // Memory simulation validation
    test_memory_sim::run_memory_sim_fuzzer(test_memory_sim::MemorySimTestParams {
        iterations: 1000,
        addr_range: (0, 4096),
        data_range: (0, u32::MAX),
        enable_logging: false,
    });

    // Register generic validation
    test_reg_generic::run_reg_generic_fuzzer(test_reg_generic::RegGenericTestParams {
        iterations: 2000,
        data_range: (0, u32::MAX),
        enable_logging: false,
    });

    // Register file validation
    test_register_file::run_register_file_fuzzer(test_register_file::RegisterFileTestParams {
        iterations: 2000,
        reg_range: (0, 32),
        data_range: (0, u32::MAX),
        enable_logging: false,
    });

    // LX32 System validation
    test_lx32_system::run_lx32_system_fuzzer(test_lx32_system::LX32SystemTestParams {
        iterations: 500,
        reg_range: (0, 32),
        imm_range: (-2048, 2047),
        enable_logging: false,
    });

    println!("{:=^100}", " ALL TESTS PASSED SUCCESSFULLY ");
}
