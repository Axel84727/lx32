/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* MC Register Information                                                    *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace llvm {

extern const int16_t LX32RegDiffLists[] = {
  /* 0 */ 0,
};

extern const LaneBitmask LX32LaneMaskLists[] = {
  /* 0 */ LaneBitmask(0xFFFFFFFFFFFFFFFF), 
};

extern const uint16_t LX32SubRegIdxLists[] = {
  /* 0 */ 
  /* dummy */ 0
};


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverlength-strings"
#endif
extern const char LX32RegStrings[] = {
  /* 0 */ "X10\000"
  /* 4 */ "X20\000"
  /* 8 */ "X30\000"
  /* 12 */ "X0\000"
  /* 15 */ "X11\000"
  /* 19 */ "X21\000"
  /* 23 */ "X31\000"
  /* 27 */ "X1\000"
  /* 30 */ "X12\000"
  /* 34 */ "X22\000"
  /* 38 */ "X2\000"
  /* 41 */ "X13\000"
  /* 45 */ "X23\000"
  /* 49 */ "X3\000"
  /* 52 */ "X14\000"
  /* 56 */ "X24\000"
  /* 60 */ "X4\000"
  /* 63 */ "X15\000"
  /* 67 */ "X25\000"
  /* 71 */ "X5\000"
  /* 74 */ "X16\000"
  /* 78 */ "X26\000"
  /* 82 */ "X6\000"
  /* 85 */ "X17\000"
  /* 89 */ "X27\000"
  /* 93 */ "X7\000"
  /* 96 */ "X18\000"
  /* 100 */ "X28\000"
  /* 104 */ "X8\000"
  /* 107 */ "X19\000"
  /* 111 */ "X29\000"
  /* 115 */ "X9\000"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const MCRegisterDesc LX32RegDesc[] = { // Descriptors
  { 3, 0, 0, 0, 0, 0, 0, 0 },
  { 12, 0, 0, 0, 0, 0, 1, 0 },
  { 27, 0, 0, 0, 1, 0, 0, 0 },
  { 38, 0, 0, 0, 2, 0, 0, 0 },
  { 49, 0, 0, 0, 3, 0, 0, 0 },
  { 60, 0, 0, 0, 4, 0, 0, 0 },
  { 71, 0, 0, 0, 5, 0, 0, 0 },
  { 82, 0, 0, 0, 6, 0, 0, 0 },
  { 93, 0, 0, 0, 7, 0, 0, 0 },
  { 104, 0, 0, 0, 8, 0, 0, 0 },
  { 115, 0, 0, 0, 9, 0, 0, 0 },
  { 0, 0, 0, 0, 10, 0, 0, 0 },
  { 15, 0, 0, 0, 11, 0, 0, 0 },
  { 30, 0, 0, 0, 12, 0, 0, 0 },
  { 41, 0, 0, 0, 13, 0, 0, 0 },
  { 52, 0, 0, 0, 14, 0, 0, 0 },
  { 63, 0, 0, 0, 15, 0, 0, 0 },
  { 74, 0, 0, 0, 16, 0, 0, 0 },
  { 85, 0, 0, 0, 17, 0, 0, 0 },
  { 96, 0, 0, 0, 18, 0, 0, 0 },
  { 107, 0, 0, 0, 19, 0, 0, 0 },
  { 4, 0, 0, 0, 20, 0, 0, 0 },
  { 19, 0, 0, 0, 21, 0, 0, 0 },
  { 34, 0, 0, 0, 22, 0, 0, 0 },
  { 45, 0, 0, 0, 23, 0, 0, 0 },
  { 56, 0, 0, 0, 24, 0, 0, 0 },
  { 67, 0, 0, 0, 25, 0, 0, 0 },
  { 78, 0, 0, 0, 26, 0, 0, 0 },
  { 89, 0, 0, 0, 27, 0, 0, 0 },
  { 100, 0, 0, 0, 28, 0, 0, 0 },
  { 111, 0, 0, 0, 29, 0, 0, 0 },
  { 8, 0, 0, 0, 30, 0, 0, 0 },
  { 23, 0, 0, 0, 31, 0, 0, 0 },
};

extern const MCPhysReg LX32RegUnitRoots[][2] = {
  { LX32::X0 },
  { LX32::X1 },
  { LX32::X2 },
  { LX32::X3 },
  { LX32::X4 },
  { LX32::X5 },
  { LX32::X6 },
  { LX32::X7 },
  { LX32::X8 },
  { LX32::X9 },
  { LX32::X10 },
  { LX32::X11 },
  { LX32::X12 },
  { LX32::X13 },
  { LX32::X14 },
  { LX32::X15 },
  { LX32::X16 },
  { LX32::X17 },
  { LX32::X18 },
  { LX32::X19 },
  { LX32::X20 },
  { LX32::X21 },
  { LX32::X22 },
  { LX32::X23 },
  { LX32::X24 },
  { LX32::X25 },
  { LX32::X26 },
  { LX32::X27 },
  { LX32::X28 },
  { LX32::X29 },
  { LX32::X30 },
  { LX32::X31 },
};

namespace {

// Register classes...
  // GPR Register Class...
  const MCPhysReg GPR[] = {
    LX32::X10, LX32::X11, LX32::X12, LX32::X13, LX32::X14, LX32::X15, LX32::X16, LX32::X17, LX32::X5, LX32::X6, LX32::X7, LX32::X28, LX32::X29, LX32::X30, LX32::X31, LX32::X8, LX32::X9, LX32::X18, LX32::X19, LX32::X20, LX32::X21, LX32::X22, LX32::X23, LX32::X24, LX32::X25, LX32::X26, LX32::X27, LX32::X1, LX32::X2, LX32::X3, LX32::X4, LX32::X0, 
  };

  // GPR Bit set.
  const uint8_t GPRBits[] = {
    0xfe, 0xff, 0xff, 0xff, 0x01, 
  };

  // GPRNOX0 Register Class...
  const MCPhysReg GPRNOX0[] = {
    LX32::X10, LX32::X11, LX32::X12, LX32::X13, LX32::X14, LX32::X15, LX32::X16, LX32::X17, LX32::X5, LX32::X6, LX32::X7, LX32::X28, LX32::X29, LX32::X30, LX32::X31, LX32::X8, LX32::X9, LX32::X18, LX32::X19, LX32::X20, LX32::X21, LX32::X22, LX32::X23, LX32::X24, LX32::X25, LX32::X26, LX32::X27, LX32::X1, LX32::X2, LX32::X3, LX32::X4, 
  };

  // GPRNOX0 Bit set.
  const uint8_t GPRNOX0Bits[] = {
    0xfc, 0xff, 0xff, 0xff, 0x01, 
  };

} // namespace

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverlength-strings"
#endif
extern const char LX32RegClassStrings[] = {
  /* 0 */ "GPRNOX0\000"
  /* 8 */ "GPR\000"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const MCRegisterClass LX32MCRegisterClasses[] = {
  { GPR, GPRBits, 8, 32, sizeof(GPRBits), LX32::GPRRegClassID, 32, 1, true, false },
  { GPRNOX0, GPRNOX0Bits, 0, 31, sizeof(GPRNOX0Bits), LX32::GPRNOX0RegClassID, 32, 1, true, false },
};

extern const uint16_t LX32RegEncodingTable[] = {
  0,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
  28,
  29,
  30,
  31,
};
static inline void InitLX32MCRegisterInfo(MCRegisterInfo *RI, unsigned RA, unsigned DwarfFlavour = 0, unsigned EHFlavour = 0, unsigned PC = 0) {
  RI->InitMCRegisterInfo(LX32RegDesc, 33, RA, PC, LX32MCRegisterClasses, 2, LX32RegUnitRoots, 32, LX32RegDiffLists, LX32LaneMaskLists, LX32RegStrings, LX32RegClassStrings, LX32SubRegIdxLists, 1,
LX32RegEncodingTable, nullptr);

}


} // namespace llvm
