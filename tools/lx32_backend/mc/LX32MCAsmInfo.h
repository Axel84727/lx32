#ifndef LLVM_LIB_TARGET_LX32_MCTARGETDESC_LX32MCASMINFO_H
#define LLVM_LIB_TARGET_LX32_MCTARGETDESC_LX32MCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {
class Triple;
} // namespace llvm

class LX32MCAsmInfo : public llvm::MCAsmInfoELF {
  void anchor() override;
public:
  explicit LX32MCAsmInfo(const llvm::Triple &TargetTriple);
};


#endif