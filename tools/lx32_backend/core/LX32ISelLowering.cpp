//===-- LX32ISelLowering.cpp - LX32 SelectionDAG Lowering ----------------===//
//
// Part of the LX32 Project
// SPDX-License-Identifier: MIT
//
//===----------------------------------------------------------------------===//

#include "LX32ISelLowering.h"

#include "LX32RegisterInfo.h"
#include "LX32Subtarget.h"

#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

LX32TargetLowering::LX32TargetLowering(const TargetMachine &TM,
                                       const LX32Subtarget &STI)
    : TargetLowering(TM, STI), STI(STI) {
  addRegisterClass(MVT::i32, &LX32::GPRRegClass);
  computeRegisterProperties(STI.getRegisterInfo());
}

const char *LX32TargetLowering::getTargetNodeName(unsigned Opcode) const {
  switch (Opcode) {
  case LX32ISD::RET:
    return "LX32ISD::RET";
  case LX32ISD::CALL:
    return "LX32ISD::CALL";
  case LX32ISD::SELECT_CC:
    return "LX32ISD::SELECT_CC";
  default:
    return nullptr;
  }
}

SDValue LX32TargetLowering::LowerFormalArguments(
    SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
    const SmallVectorImpl<ISD::InputArg> &Ins, const SDLoc &DL,
    SelectionDAG &DAG, SmallVectorImpl<SDValue> &InVals) const {
  report_fatal_error("LX32 LowerFormalArguments is not implemented yet");
}

SDValue LX32TargetLowering::LowerCall(
    TargetLowering::CallLoweringInfo &CLI,
    SmallVectorImpl<SDValue> &InVals) const {
  report_fatal_error("LX32 LowerCall is not implemented yet");
}

SDValue LX32TargetLowering::LowerReturn(
    SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
    const SmallVectorImpl<ISD::OutputArg> &Outs,
    const SmallVectorImpl<SDValue> &OutVals, const SDLoc &DL,
    SelectionDAG &DAG) const {
  report_fatal_error("LX32 LowerReturn is not implemented yet");
}

SDValue LX32TargetLowering::LowerOperation(SDValue Op,
                                           SelectionDAG &DAG) const {
  report_fatal_error("LX32 LowerOperation is not implemented yet");
}


