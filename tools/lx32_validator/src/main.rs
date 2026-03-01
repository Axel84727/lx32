// src/main.rs
#[path = "../tests/test_alu.rs"]
mod test_alu;

#[path = "../tests/test_branch_unit.rs"]
mod test_branch_unit;

#[path = "../tests/test_control_unit.rs"]
mod test_control_unit;

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
        enable_logging: true,
    });

    println!("{:=^100}", " ALL TESTS PASSED SUCCESSFULLY ");
}
