// ============================================================
// LX32 Load/Store Unit (LSU)
// ============================================================
// Minimal pass-through LSU for single-cycle memory interface.
//
// Design Principles:
//   - Pure combinational datapath
//   - No internal state
//   - Clear separation between execute and memory stages
//   - Tool-friendly (no qualifiers, no implicit latches)
// ============================================================

/// Represents the Memory Interface ports
#[derive(Debug, Default, PartialEq, Eq)]
pub struct MemInterface {
    pub mem_addr: u32,
    pub mem_wdata: u32,
    pub mem_we: bool,
}

pub fn lsu_golden(alu_result: u32, write_data: u32, mem_write: bool) -> MemInterface {
    // In SV:
    // assign mem_addr  = alu_result;
    // assign mem_wdata = write_data;
    // assign mem_we    = mem_write;

    MemInterface {
        mem_addr: alu_result,
        mem_wdata: write_data,
        mem_we: mem_write,
    }
}
