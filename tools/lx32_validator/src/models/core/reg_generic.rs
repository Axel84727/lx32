// ============================================================
// LX32 Generic Register
// ============================================================
// Parameterizable synchronous register with:
//
//   - Asynchronous active-high reset
//   - Clock enable
//   - Clean sequential semantics
//
// Design Principles:
//   - No implicit latches
//   - Non-blocking assignments only
//   - Reset-safe initialization
//   - Width scalability
// ============================================================

/// Replicates a synchronous register with asynchronous reset
/// and clock enable.
pub struct RegGeneric {
    pub data_out: u32,
    width: u32,
}

impl RegGeneric {
    /// Initialize the register with a specific width (e.g., XLEN=32)
    pub fn new(width: u32) -> Self {
        Self { data_out: 0, width }
    }

    /// Sequential Logic: This mirrors the always_ff block
    /// In the simulation, this is called on the "Clock Edge"
    pub fn tick(&mut self, rst: bool, en: bool, data_in: u32) {
        // --- 1. Asynchronous Reset (Active High) ---
        if rst {
            self.data_out = 0;
        }
        // --- 2. Clock Enable ---
        else if en {
            // Apply a mask to ensure data stays within WIDTH
            let mask = if self.width == 32 {
                0xFFFFFFFF
            } else {
                (1 << self.width) - 1
            };
            self.data_out = data_in & mask;
        }
        // else: data_out holds its previous value (implicit)
    }
}
