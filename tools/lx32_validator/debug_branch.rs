// Quick debug script to trace through branch immediate extraction

fn main() {
    // Test case: Instr: 0x04ea7063, Offset should be: 64
    let instr: u32 = 0x04ea7063;
    
    println!("=== Tracing Instruction: 0x{:08x} ===", instr);
    
    // Decode opcode
    let opcode = instr & 0x7F;
    println!("Opcode: 0x{:02x} (should be 0x63 for BRANCH)", opcode);
    
    // Decode funct3
    let funct3 = (instr >> 12) & 0x7;
    println!("Funct3: 0x{:x} (0=BEQ, 1=BNE, 4=BLT, 5=BGE, 6=BLTU, 7=BGEU)", funct3);
    
    // Decode rs1 and rs2
    let rs1 = (instr >> 15) & 0x1F;
    let rs2 = (instr >> 20) & 0x1F;
    println!("RS1: x{}, RS2: x{}", rs1, rs2);
    
    // Extract B-type immediate
    let bit_12 = (instr >> 31) & 0x1;
    let bit_11 = (instr >> 7) & 0x1;
    let bits_10_5 = (instr >> 25) & 0x3F;
    let bits_4_1 = (instr >> 8) & 0xF;
    
    println!("\nImmediate bit extraction:");
    println!("  bit_12 (instr[31]): {}", bit_12);
    println!("  bit_11 (instr[7]): {}", bit_11);
    println!("  bits_10_5 (instr[30:25]): 0x{:x}", bits_10_5);
    println!("  bits_4_1 (instr[11:8]): 0x{:x}", bits_4_1);
    
    let imm_13b = (bit_12 << 12) | (bit_11 << 11) | (bits_10_5 << 5) | (bits_4_1 << 1);
    println!("\nAssembled 13-bit immediate: 0x{:x} ({})", imm_13b, imm_13b);
    
    let sign_extended = ((imm_13b << 19) as i32 >> 19) as u32;
    println!("Sign-extended: 0x{:08x} ({})", sign_extended, sign_extended as i32);
    
    println!("\n=== Branch Target Calculation ===");
    let pc = 0x0000u32;
    let target = pc.wrapping_add(sign_extended);
    println!("PC: 0x{:08x} + Offset: 0x{:08x} = Target: 0x{:08x}", pc, sign_extended, target);
    
    println!("\n=== Testing other failing instructions ===");
    
    let test_instrs = [
        (0x041af863, "Offset: 80"),
        (0x06c17663, "Offset: 108"),
        (0x03d27663, "Offset: 44"),
    ];
    
    for (instr, expected) in test_instrs {
        println!("\nInstr: 0x{:08x} ({})", instr, expected);
        let bit_12 = (instr >> 31) & 0x1;
        let bit_11 = (instr >> 7) & 0x1;
        let bits_10_5 = (instr >> 25) & 0x3F;
        let bits_4_1 = (instr >> 8) & 0xF;
        let imm_13b = (bit_12 << 12) | (bit_11 << 11) | (bits_10_5 << 5) | (bits_4_1 << 1);
        let sign_extended = ((imm_13b << 19) as i32 >> 19) as u32;
        println!("  Computed offset: {} (0x{:x})", sign_extended as i32, sign_extended);
    }
}
