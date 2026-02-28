// src/main.rs
#[path = "../tests/test_alu.rs"]
mod test_alu;

#[path = "../tests/test_branch_unit.rs"]
mod test_branch_unit;

fn main() {
    println!("{:=^100}", " LX32 FULL HARDWARE VALIDATION ");

    // Test the ALU with 5,000 operations
    //test_alu::run_alu_fuzzer(5000);

    // Test the Branches with 10,000 operations (Huge Test)
    test_branch_unit::run_branch_fuzzer(10000);

    println!("{:=^100}", " ALL TESTS PASSED SUCCESSFULLY ");
}
