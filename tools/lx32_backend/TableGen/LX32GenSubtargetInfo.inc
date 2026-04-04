/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Subtarget Enumeration Source Fragment                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_SUBTARGETINFO_ENUM
#undef GET_SUBTARGETINFO_ENUM

namespace llvm {


} // namespace llvm

#endif // GET_SUBTARGETINFO_ENUM

#ifdef GET_SUBTARGETINFO_MACRO


#undef GET_SUBTARGETINFO_MACRO
#endif // GET_SUBTARGETINFO_MACRO

#ifdef GET_SUBTARGETINFO_MC_DESC
#undef GET_SUBTARGETINFO_MC_DESC

namespace llvm {


#ifdef DBGFIELD
#error "<target>GenSubtargetInfo.inc requires a DBGFIELD macro"
#endif
#if !defined(NDEBUG) || defined(LLVM_ENABLE_DUMP)
#define DBGFIELD(x) x,
#define DBGVAL_OR_NULLPTR(x) x
#else
#define DBGFIELD(x)
#define DBGVAL_OR_NULLPTR(x) nullptr
#endif

// ===============================================================
// Data tables for the new per-operand machine model.

// {ProcResourceIdx, ReleaseAtCycle, AcquireAtCycle}
extern const llvm::MCWriteProcResEntry LX32WriteProcResTable[] = {
  { 0,  0,  0 }, // Invalid
}; // LX32WriteProcResTable

// {Cycles, WriteResourceID}
extern const llvm::MCWriteLatencyEntry LX32WriteLatencyTable[] = {
  { 0,  0}, // Invalid
}; // LX32WriteLatencyTable

// {UseIdx, WriteResourceID, Cycles}
extern const llvm::MCReadAdvanceEntry LX32ReadAdvanceTable[] = {
  {0,  0,  0}, // Invalid
}; // LX32ReadAdvanceTable

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverlength-strings"
#endif
static constexpr char LX32SchedClassNamesStorage[] =
  "\0"
  "InvalidSchedClass\0"
  ;
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

static constexpr llvm::StringTable
LX32SchedClassNames = LX32SchedClassNamesStorage;

static const llvm::MCSchedModel NoSchedModel = {
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  false, // PostRAScheduler
  false, // CompleteModel
  false, // EnableIntervals
  0, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  DBGVAL_OR_NULLPTR(&LX32SchedClassNames), // SchedClassNames
  nullptr, // No Itinerary
  nullptr // No extra processor descriptor
};

#undef DBGFIELD

#undef DBGVAL_OR_NULLPTR

// Sorted (by key) array of values for CPU subtype.
extern const llvm::SubtargetSubTypeKV LX32SubTypeKV[] = {
};

// Sorted array of names of CPU subtypes, including aliases.
extern const llvm::StringRef LX32Names[] = {
};

namespace LX32_MC {

unsigned resolveVariantSchedClassImpl(unsigned SchedClass,
    const MCInst *MI, const MCInstrInfo *MCII, const MCSubtargetInfo &STI, unsigned CPUID) {
  // Don't know how to resolve this scheduling class.
  return 0;
}

} // namespace LX32_MC
struct LX32GenMCSubtargetInfo : public MCSubtargetInfo {
  LX32GenMCSubtargetInfo(const Triple &TT,
    StringRef CPU, StringRef TuneCPU, StringRef FS,
    ArrayRef<StringRef> PN,
    ArrayRef<SubtargetFeatureKV> PF,
    ArrayRef<SubtargetSubTypeKV> PD,
    const MCWriteProcResEntry *WPR,
    const MCWriteLatencyEntry *WL,
    const MCReadAdvanceEntry *RA, const InstrStage *IS,
    const unsigned *OC, const unsigned *FP) :
      MCSubtargetInfo(TT, CPU, TuneCPU, FS, PN, PF, PD,
                      WPR, WL, RA, IS, OC, FP) { }

  unsigned resolveVariantSchedClass(unsigned SchedClass,
      const MCInst *MI, const MCInstrInfo *MCII,
      unsigned CPUID) const final {
    return LX32_MC::resolveVariantSchedClassImpl(SchedClass, MI, MCII, *this, CPUID);
  }
};

static inline MCSubtargetInfo *createLX32MCSubtargetInfoImpl(const Triple &TT, StringRef CPU, StringRef TuneCPU, StringRef FS) {
  return new LX32GenMCSubtargetInfo(TT, CPU, TuneCPU, FS, {}, {}, {}, 
                      LX32WriteProcResTable, LX32WriteLatencyTable, LX32ReadAdvanceTable, 
                      nullptr, nullptr, nullptr);
}


} // namespace llvm

#endif // GET_SUBTARGETINFO_MC_DESC

#ifdef GET_SUBTARGETINFO_TARGET_DESC
#undef GET_SUBTARGETINFO_TARGET_DESC

#include "llvm/ADT/BitmaskEnum.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"

// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
void llvm::LX32Subtarget::ParseSubtargetFeatures(StringRef CPU, StringRef TuneCPU, StringRef FS) {
  LLVM_DEBUG(dbgs() << "\nFeatures:" << FS);
  LLVM_DEBUG(dbgs() << "\nCPU:" << CPU);
  LLVM_DEBUG(dbgs() << "\nTuneCPU:" << TuneCPU << "\n\n");
}

#endif // GET_SUBTARGETINFO_TARGET_DESC

#ifdef GET_SUBTARGETINFO_HEADER
#undef GET_SUBTARGETINFO_HEADER

namespace llvm {

class DFAPacketizer;
namespace LX32_MC {

unsigned resolveVariantSchedClassImpl(unsigned SchedClass, const MCInst *MI, const MCInstrInfo *MCII, const MCSubtargetInfo &STI, unsigned CPUID);

} // namespace LX32_MC
struct LX32GenSubtargetInfo : public TargetSubtargetInfo {
  explicit LX32GenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef TuneCPU, StringRef FS);
public:
  unsigned resolveSchedClass(unsigned SchedClass,  const MachineInstr *DefMI, const TargetSchedModel *SchedModel) const final;
  unsigned resolveVariantSchedClass(unsigned SchedClass, const MCInst *MI, const MCInstrInfo *MCII, unsigned CPUID) const final;
  DFAPacketizer *createDFAPacketizer(const InstrItineraryData *IID) const;
};

} // namespace llvm

#endif // GET_SUBTARGETINFO_HEADER

#ifdef GET_SUBTARGETINFO_CTOR
#undef GET_SUBTARGETINFO_CTOR

#include "llvm/CodeGen/TargetSchedule.h"

namespace llvm {

extern const llvm::StringRef LX32Names[];
extern const llvm::SubtargetFeatureKV LX32FeatureKV[];
extern const llvm::SubtargetSubTypeKV LX32SubTypeKV[];
extern const llvm::MCWriteProcResEntry LX32WriteProcResTable[];
extern const llvm::MCWriteLatencyEntry LX32WriteLatencyTable[];
extern const llvm::MCReadAdvanceEntry LX32ReadAdvanceTable[];
LX32GenSubtargetInfo::LX32GenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef TuneCPU, StringRef FS)
  : TargetSubtargetInfo(TT, CPU, TuneCPU, FS, {}, {}, {}, 
                        LX32WriteProcResTable, LX32WriteLatencyTable, LX32ReadAdvanceTable, 
                        nullptr, nullptr, nullptr) {}

unsigned LX32GenSubtargetInfo
::resolveSchedClass(unsigned SchedClass, const MachineInstr *MI, const TargetSchedModel *SchedModel) const {
  report_fatal_error("Expected a variant SchedClass");
} // LX32GenSubtargetInfo::resolveSchedClass

unsigned LX32GenSubtargetInfo
::resolveVariantSchedClass(unsigned SchedClass, const MCInst *MI, const MCInstrInfo *MCII, unsigned CPUID) const {
  return LX32_MC::resolveVariantSchedClassImpl(SchedClass, MI, MCII, *this, CPUID);
} // LX32GenSubtargetInfo::resolveVariantSchedClass


} // namespace llvm

#endif // GET_SUBTARGETINFO_CTOR

#ifdef GET_STIPREDICATE_DECLS_FOR_MC_ANALYSIS
#undef GET_STIPREDICATE_DECLS_FOR_MC_ANALYSIS


#endif // GET_STIPREDICATE_DECLS_FOR_MC_ANALYSIS

#ifdef GET_STIPREDICATE_DEFS_FOR_MC_ANALYSIS
#undef GET_STIPREDICATE_DEFS_FOR_MC_ANALYSIS


#endif // GET_STIPREDICATE_DEFS_FOR_MC_ANALYSIS

