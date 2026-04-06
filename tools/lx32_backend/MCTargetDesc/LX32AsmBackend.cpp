//===-- LX32AsmBackend.cpp - LX32 Assembler Backend -------------------------===//
//
// Part of the LX32 Project
// SPDX-License-Identifier: MIT
//
//===----------------------------------------------------------------------===//

#include "LX32MCTargetDesc.h"
#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCAssembler.h"
#include "llvm/MC/MCDirectives.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCValue.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
class LX32AsmBackend : public MCAsmBackend {
public:
  LX32AsmBackend(const MCSubtargetInfo &STI, uint8_t OSABI)
      : MCAsmBackend(llvm::endianness::little) {}
  ~LX32AsmBackend() override {}

  void applyFixup(const MCFragment &Fragment, const MCFixup &Fixup,
                  const MCValue &Target, uint8_t *Data, uint64_t Value,
                  bool IsResolved) override {
    // TODO: implement fixup application
  }

  bool writeNopData(raw_ostream &OS, uint64_t Count,
                    const MCSubtargetInfo *STI) const override {
    // 4-byte NOPs = addi x0, x0, 0 = 0x00000013
    uint64_t NumNops = Count / 4;
    for (uint64_t i = 0; i != NumNops; ++i)
      OS.write("\x13\x00\x00\x00", 4);

    OS.write_zeros(Count % 4);
    return true;
  }

  std::unique_ptr<MCObjectTargetWriter>
  createObjectTargetWriter() const override {
    return createLX32ELFObjectWriter(0);
  }
};
} // end anonymous namespace

MCAsmBackend *llvm::createLX32AsmBackend(const Target &T,
                                         const MCSubtargetInfo &STI,
                                         const MCRegisterInfo &MRI,
                                         const MCTargetOptions &Options) {
  return new LX32AsmBackend(STI, 0); // OSABI 0
}

