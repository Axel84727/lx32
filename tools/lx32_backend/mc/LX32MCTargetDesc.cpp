
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCTargetOptions.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/TargetParser/Triple.h"
#include "LX32MCTargetDesc.h"
#include "LX32MCAsmInfo.h"
#include <cstddef>
#include "../target/TargetInfo/LX32TargetInfo.h"


static llvm::MCInstrInfo *createLX32InstrInfo(){
    llvm::MCInstrInfo *X = new llvm::MCInstrInfo();
    // initLX32MCInstrInfo();
    return X; 
}

static llvm::MCRegisterInfo *createLX32MCRegisterInfo (const llvm::Triple &TT) {
    llvm::MCRegisterInfo *X = new llvm::MCRegisterInfo();
    /*InitLX32MCRegisterInfo(X, lx32::X1); */
    return X;
}

static llvm::MCAsmInfo *createLX32MCAsmInfo(
    const llvm::MCRegisterInfo &MRI,
    const llvm::Triple &TT,
    const llvm::MCTargetOptions &Options) {
        llvm::MCAsmInfo *MAI = nullptr;
        if(TT.isOSBinFormatELF()) {
            MAI = new LX32MCAsmInfo(TT);
        } else {
            llvm::report_fatal_error("unsupported object format");
        }
    /*unsigned SP = MRI.getDwarfRegNum(lx32::X2, true);
    llvm::MCCFIInstruction Inst = llvm::MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
    MAI->addInitialFrameState(Inst);
    */
    return MAI;
    }

static llvm::MCSubtargetInfo *createLX32MCSubtargetInfo(
    const llvm::Triple &TT, llvm::StringRef CPU, llvm::StringRef FS) {
  if (CPU.empty() || CPU == "generic")
    CPU = "generic-lx32";
  // return createLX32MCSubtargetInfoImpl(TT, CPU, CPU, FS);
  return nullptr;
}

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializeLX32TargetMC() {
    llvm::Target &T = llvm::getTheLX32TargetInfo();
    llvm::TargetRegistry::RegisterMCAsmInfo(T, createLX32MCAsmInfo);
    llvm::TargetRegistry::RegisterMCInstrInfo(T, createLX32InstrInfo);
    llvm::TargetRegistry::RegisterMCRegInfo(T, createLX32MCRegisterInfo);
    llvm::TargetRegistry::RegisterMCSubtargetInfo(T, createLX32MCSubtargetInfo);
}