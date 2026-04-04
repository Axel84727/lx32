//===-- LX32FrameLowering.cpp - LX32 Frame Lowering Implementation -------===//
//
// Part of the LX32 Project
// SPDX-License-Identifier: MIT
//
//===----------------------------------------------------------------------===//

#include "LX32FrameLowering.h"

#include "LX32InstrInfo.h"
#include "LX32RegisterInfo.h"
#include "LX32Subtarget.h"

#include "llvm/CodeGen/MachineFrameInfo.h"

using namespace llvm;

LX32FrameLowering::LX32FrameLowering(const LX32Subtarget &STI)
    : TargetFrameLowering(StackGrowsDown, Align(16), 0), STI(STI) {}

void LX32FrameLowering::emitPrologue(MachineFunction &MF,
                                     MachineBasicBlock &MBB) const {}

void LX32FrameLowering::emitEpilogue(MachineFunction &MF,
                                     MachineBasicBlock &MBB) const {}

bool LX32FrameLowering::hasFPImpl(const MachineFunction &MF) const {
  const MachineFrameInfo &MFI = MF.getFrameInfo();
  return MFI.hasVarSizedObjects() || MFI.isFrameAddressTaken();
}

bool LX32FrameLowering::hasReservedCallFrame(const MachineFunction &MF) const {
  return !MF.getFrameInfo().hasVarSizedObjects();
}

MachineBasicBlock::iterator LX32FrameLowering::eliminateCallFramePseudoInstr(
    MachineFunction &MF, MachineBasicBlock &MBB,
    MachineBasicBlock::iterator MI) const {
  return MBB.erase(MI);
}

StackOffset LX32FrameLowering::getFrameIndexReference(const MachineFunction &MF,
                                                      int FI,
                                                      Register &FrameReg) const {
  const MachineFrameInfo &MFI = MF.getFrameInfo();
  FrameReg = hasFP(MF) ? LX32::X8 : LX32::X2;
  return StackOffset::getFixed(MFI.getObjectOffset(FI) + MFI.getStackSize());
}


