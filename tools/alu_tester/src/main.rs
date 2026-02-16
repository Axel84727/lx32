use rand::RngExt;
use std::fs::File;
use std::io::{Write, Result};

#[derive(Debug, Clone, Copy)]
enum BranchOp {
    Eq, Ne, Lt, Ge, Ltu, Geu,
}

fn check_branch(a: u32, b: u32, op: BranchOp) -> bool {
    match op {
        BranchOp::Eq  => a == b,
        BranchOp::Ne  => a != b,
        BranchOp::Lt  => (a as i32) < (b as i32),
        BranchOp::Ge  => (a as i32) >= (b as i32),
        BranchOp::Ltu => a < b,
        BranchOp::Geu => a >= b,
    }
}

#[derive(Debug, PartialEq, Clone, Copy)]
enum OpCode {
    Add, Sub, Sll, Slt, Sltu, Xor, Srl, Sra, Or, And,
}

fn alu(src_a: u32, src_b: u32, op: OpCode) -> u32 {
    match op {
        OpCode::Add  => src_a.wrapping_add(src_b),
        OpCode::Sub  => src_a.wrapping_sub(src_b),
        OpCode::Sll  => src_a << (src_b & 0x1F),
        OpCode::Slt  => if (src_a as i32) < (src_b as i32) {1} else {0},
        OpCode::Sltu => if src_a < src_b {1} else {0},
        OpCode::Xor  => src_a ^ src_b,
        OpCode::Srl  => src_a >> (src_b & 0x1F),
        OpCode::Sra  => ((src_a as i32) >> (src_b & 0x1F)) as u32,
        OpCode::Or   => src_a | src_b,
        OpCode::And  => src_a & src_b,
    }
}

fn main() -> Result<()> {
    let mut file = File::create("alu_vectors.tv")?;
    let mut rng = rand::rng();

    for _ in 0..1000 {
        let a: u32 = rng.random_range(0..300000);
        let b: u32 = rng.random_range(0..300000);

        let op_num = rng.random_range(0..10);
        let op = match op_num {
            0 => OpCode::Add,
            1 => OpCode::Sub,
            2 => OpCode::Sll,
            3 => OpCode::Slt,
            4 => OpCode::Sltu,
            5 => OpCode::Xor,
            6 => OpCode::Srl,
            7 => OpCode::Sra,
            8 => OpCode::Or,
            _ => OpCode::And,
        };

        let is_branch: u8 = rng.random_range(0..2);
        let br_op_num = rng.random_range(0..6);
        let br_op = match br_op_num {
            0 => BranchOp::Eq,
            1 => BranchOp::Ne,
            2 => BranchOp::Lt,
            3 => BranchOp::Ge,
            4 => BranchOp::Ltu,
            _ => BranchOp::Geu,
        };

        let res = alu(a, b, op);
        let br_true = if is_branch == 1 { check_branch(a, b, br_op) } else { false };
writeln!(
    file,
    "{:08x} {:08x} {:x} {:x} {:x} {:08x} {:x}",
    a, b, op_num, is_branch, br_op_num, res, br_true as u8
)?;
    }  
    Ok(())
}
