/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Register and Register Classes Information                           *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace llvm {

extern const MCRegisterClass LX32MCRegisterClasses[];

static const MVT::SimpleValueType LX32VTLists[] = {
  /* 0 */ MVT::i32, MVT::Other,
};
static constexpr char LX32SubRegIndexStrings[] = {
  /* dummy */ 0
};


static constexpr uint32_t LX32SubRegIndexNameOffsets[] = {
  /* dummy */ 0
};

static const TargetRegisterInfo::SubRegCoveredBits LX32SubRegIdxRangeTable[] = {
  { 65535, 65535 },
};


static const LaneBitmask LX32SubRegIndexLaneMaskTable[] = {
  LaneBitmask::getAll(),
 };



static const TargetRegisterInfo::RegClassInfo LX32RegClassInfos[] = {
  // Mode = 0 (DefaultMode)
  { 32, 32, 32, /*LX32VTLists+*/0 },    // GPR
  { 32, 32, 32, /*LX32VTLists+*/0 },    // GPRNOX0
};
static const uint32_t GPRSubClassMask[] = {
  0x00000003, 
};

static const uint32_t GPRNOX0SubClassMask[] = {
  0x00000002, 
};

static const uint16_t SuperRegIdxSeqs[] = {
  /* 0 */ 0,
};

static unsigned const GPRNOX0Superclasses[] = {
  LX32::GPRRegClassID,
};

namespace LX32 {

// Register class instances.
  extern const TargetRegisterClass GPRRegClass = {
    &LX32MCRegisterClasses[GPRRegClassID],
    GPRSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    nullptr, 0,
    nullptr
  };

  extern const TargetRegisterClass GPRNOX0RegClass = {
    &LX32MCRegisterClasses[GPRNOX0RegClassID],
    GPRNOX0SubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    GPRNOX0Superclasses,  1,
    nullptr
  };


} // namespace LX32
static const TargetRegisterClass *const LX32RegisterClasses[] = {
    &LX32::GPRRegClass,
    &LX32::GPRNOX0RegClass,
  };

static const uint8_t LX32CostPerUseTable[] = { 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };


static const bool LX32InAllocatableClassTable[] = { 
false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, };


static const TargetRegisterInfoDesc LX32RegInfoDesc = { // Extra Descriptors
LX32CostPerUseTable, 1, LX32InAllocatableClassTable};

/// Get the weight in units of pressure for this register class.
const RegClassWeight &LX32GenRegisterInfo::
getRegClassWeight(const TargetRegisterClass *RC) const {
  static const RegClassWeight RCWeightTable[] = {
    {1, 32},  	// GPR
    {1, 31},  	// GPRNOX0
  };
  return RCWeightTable[RC->getID()];
}

/// Get the weight in units of pressure for this register unit.
unsigned LX32GenRegisterInfo::
getRegUnitWeight(MCRegUnit RegUnit) const {
  assert(static_cast<unsigned>(RegUnit) < 32 && "invalid register unit");
  // All register units have unit weight.
  return 1;
}


// Get the number of dimensions of register pressure.
unsigned LX32GenRegisterInfo::getNumRegPressureSets() const {
  return 1;
}

// Get the name of this register unit pressure set.
const char *LX32GenRegisterInfo::
getRegPressureSetName(unsigned Idx) const {
  static const char *PressureNameTable[] = {
    "GPR",
  };
  return PressureNameTable[Idx];
}

// Get the register unit pressure limit for this dimension.
// This limit must be adjusted dynamically for reserved registers.
unsigned LX32GenRegisterInfo::
getRegPressureSetLimit(const MachineFunction &MF, unsigned Idx) const {
  static const uint8_t PressureLimitTable[] = {
    32,  	// 0: GPR
  };
  return PressureLimitTable[Idx];
}

/// Table of pressure sets per register class or unit.
static const int RCSetsTable[] = {
  /* 0 */ 0, -1,
};

/// Get the dimensions of register pressure impacted by this register class.
/// Returns a -1 terminated array of pressure set IDs
const int *LX32GenRegisterInfo::
getRegClassPressureSets(const TargetRegisterClass *RC) const {
  static const uint8_t RCSetStartTable[] = {
    0,0,};
  return &RCSetsTable[RCSetStartTable[RC->getID()]];
}

/// Get the dimensions of register pressure impacted by this register unit.
/// Returns a -1 terminated array of pressure set IDs
const int *LX32GenRegisterInfo::
getRegUnitPressureSets(MCRegUnit RegUnit) const {
  assert(static_cast<unsigned>(RegUnit) < 32 && "invalid register unit");
  static const uint8_t RUSetStartTable[] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
  return &RCSetsTable[RUSetStartTable[static_cast<unsigned>(RegUnit)]];
}

extern const MCRegisterDesc LX32RegDesc[];
extern const int16_t LX32RegDiffLists[];
extern const LaneBitmask LX32LaneMaskLists[];
extern const char LX32RegStrings[];
extern const char LX32RegClassStrings[];
extern const MCPhysReg LX32RegUnitRoots[][2];
extern const uint16_t LX32SubRegIdxLists[];
extern const uint16_t LX32RegEncodingTable[];

LX32GenRegisterInfo::
LX32GenRegisterInfo(unsigned RA, unsigned DwarfFlavour, unsigned EHFlavour,
    unsigned PC, unsigned HwMode)
  : TargetRegisterInfo(&LX32RegInfoDesc, LX32RegisterClasses,
      LX32SubRegIndexStrings, LX32SubRegIndexNameOffsets,
      LX32SubRegIdxRangeTable, LX32SubRegIndexLaneMaskTable,

  LaneBitmask(0xFFFFFFFFFFFFFFFF), LX32RegClassInfos, LX32VTLists, HwMode) {
  InitMCRegisterInfo(LX32RegDesc, 33, RA, PC,
    LX32MCRegisterClasses, 2, LX32RegUnitRoots, 32, LX32RegDiffLists,
    LX32LaneMaskLists, LX32RegStrings, LX32RegClassStrings, LX32SubRegIdxLists, 1,
    LX32RegEncodingTable, nullptr);

}

static const MCPhysReg CSR_IPRA_SaveList[] = { LX32::X1, 0 };
static const uint32_t CSR_IPRA_RegMask[] = { 0x00000006, 0x00000000, };
static const MCPhysReg CSR_LX32_ILP32_SaveList[] = { LX32::X1, LX32::X8, LX32::X9, LX32::X18, LX32::X19, LX32::X20, LX32::X21, LX32::X22, LX32::X23, LX32::X24, LX32::X25, LX32::X26, LX32::X27, 0 };
static const uint32_t CSR_LX32_ILP32_RegMask[] = { 0x1ff80606, 0x00000000, };
static const MCPhysReg CSR_NoRegs_SaveList[] = { 0 };
static const uint32_t CSR_NoRegs_RegMask[] = { 0x00000002, 0x00000000, };


ArrayRef<const uint32_t *> LX32GenRegisterInfo::getRegMasks() const {
  static const uint32_t *const Masks[] = {
    CSR_IPRA_RegMask,
    CSR_LX32_ILP32_RegMask,
    CSR_NoRegs_RegMask,
  };
  return ArrayRef(Masks);
}

bool LX32GenRegisterInfo::
isGeneralPurposeRegister(const MachineFunction &MF, MCRegister PhysReg) const {
  return
      false;
}

bool LX32GenRegisterInfo::
isGeneralPurposeRegisterClass(const TargetRegisterClass *RC) const {
  return
      false;
}

bool LX32GenRegisterInfo::
isFixedRegister(const MachineFunction &MF, MCRegister PhysReg) const {
  return
      false;
}

bool LX32GenRegisterInfo::
isArgumentRegister(const MachineFunction &MF, MCRegister PhysReg) const {
  return
      false;
}

bool LX32GenRegisterInfo::
isConstantPhysReg(MCRegister PhysReg) const {
  return
      PhysReg == LX32::X0 ||
      false;
}

ArrayRef<const char *> LX32GenRegisterInfo::getRegMaskNames() const {
  static const char *Names[] = {
    "CSR_IPRA",
    "CSR_LX32_ILP32",
    "CSR_NoRegs",
  };
  return ArrayRef(Names);
}

const LX32FrameLowering *
LX32GenRegisterInfo::getFrameLowering(const MachineFunction &MF) {
  return static_cast<const LX32FrameLowering *>(
      MF.getSubtarget().getFrameLowering());
}


} // namespace llvm
