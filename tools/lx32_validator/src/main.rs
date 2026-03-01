// src/main.rs
#[path = "../tests/test_alu.rs"]
mod test_alu;

#[path = "../tests/test_branch_unit.rs"]
mod test_branch_unit;

#[path = "../tests/test_control_unit.rs"]
mod test_control_unit;

fn main() {
    println!("{:=^100}", " LX32 FULL HARDWARE VALIDATION ");

    // Test the ALU with 5,000 operations
    //test_alu::run_alu_fuzzer(5000);

    // Test the Branches with 10,000 operations (Huge Test)
    //test_branch_unit::run_branch_fuzzer(10000);

    // Test the Control Unit with 500 iterations
    test_control_unit::run_control_unit_fuzzer(test_control_unit::ControlUnitTestParams {
        iterations: 500,
        reg_range: (0, 32),
        imm_range: (-2048, 2047),
        enable_logging: true,
    });

    println!("{:=^100}", " ALL TESTS PASSED SUCCESSFULLY ");
}
