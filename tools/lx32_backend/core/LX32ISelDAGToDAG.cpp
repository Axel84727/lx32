//===-- LX32ISelDAGToDAG.cpp - LX32 DAG->DAG Instruction Selector --------===//
//
// Part of the LX32 Project
// SPDX-License-Identifier: MIT
//
//===----------------------------------------------------------------------===//

#include "LX32ISelDAGToDAG.h"

#include "LX32ISelLowering.h"
#include "LX32Subtarget.h"
#include "LX32TargetMachine.h"

#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/Support/MathExtras.h"
#include "llvm/Support/ErrorHandling.h"

#include <memory>

using namespace llvm;

#define DEBUG_TYPE "lx32-isel"

namespace {

class LX32DAGToDAGISel : public SelectionDAGISel {
  const LX32Subtarget *Subtarget = nullptr;

public:
  explicit LX32DAGToDAGISel(LX32TargetMachine &TM, CodeGenOptLevel OptLevel)
      : SelectionDAGISel(TM, OptLevel) {}

  bool runOnMachineFunction(MachineFunction &MF) override {
    Subtarget = &MF.getSubtarget<LX32Subtarget>();
    return SelectionDAGISel::runOnMachineFunction(MF);
  }

  void Select(SDNode *Node) override;

private:
  void SelectFrameIndex(SDNode *Node);

  // Include the auto-generated selection matcher.
  #include "../TableGen/LX32GenDAGISel.inc"
};

class LX32DAGToDAGISelLegacy : public SelectionDAGISelLegacy {
public:
  static char ID;

  LX32DAGToDAGISelLegacy(LX32TargetMachine &TM, CodeGenOptLevel OptLevel)
      : SelectionDAGISelLegacy(
            ID, std::make_unique<LX32DAGToDAGISel>(TM, OptLevel)) {}

  StringRef getPassName() const override {
    return "LX32 DAG->DAG Instruction Selection";
  }
};

} // end anonymous namespace

char LX32DAGToDAGISelLegacy::ID = 0;

void LX32DAGToDAGISel::SelectFrameIndex(SDNode *Node) {
  SDLoc DL(Node);
  int FI = cast<FrameIndexSDNode>(Node)->getIndex();
  SDValue TFI = CurDAG->getTargetFrameIndex(FI, MVT::i32);
  SDValue Zero = CurDAG->getTargetConstant(0, DL, MVT::i32);

  SDNode *Result = CurDAG->getMachineNode(LX32::ADDI, DL, MVT::i32, TFI, Zero);
  ReplaceNode(Node, Result);
}

void LX32DAGToDAGISel::Select(SDNode *Node) {
  if (Node->isMachineOpcode()) {
    Node->setNodeId(-1);
    return;
  }

  switch (Node->getOpcode()) {
  case LX32ISD::CALL: {
    SDLoc DL(Node);

    if (Node->getNumOperands() < 2)
      report_fatal_error("lx32: malformed CALL node");

    SDValue Callee = Node->getOperand(1);
    if (Callee.getOpcode() != ISD::TargetGlobalAddress &&
        Callee.getOpcode() != ISD::TargetExternalSymbol)
      report_fatal_error("lx32: CALL expects target global/external symbol");

    // Materialize symbol address into a register, then call through it.
    SDNode *Addr = CurDAG->getMachineNode(LX32::PseudoLA, DL, MVT::i32, Callee);

    SmallVector<SDValue, 4> Ops;
    Ops.push_back(Node->getOperand(0)); // chain
    Ops.push_back(SDValue(Addr, 0));    // call target register
    if (Node->getNumOperands() > 2)
      Ops.push_back(Node->getOperand(2)); // optional glue

    SDNode *Call = CurDAG->getMachineNode(
        LX32::PseudoCALL, DL, CurDAG->getVTList(MVT::Other, MVT::Glue), Ops);
    ReplaceNode(Node, Call);
    return;
  }
  case LX32ISD::RET: {
    SDLoc DL(Node);
    SmallVector<SDValue, 4> RetOps;
    for (const SDValue &Op : Node->ops())
      RetOps.push_back(Op);

    SDVTList VTs = CurDAG->getVTList(MVT::Other);
    SDNode *Ret = CurDAG->getMachineNode(LX32::PseudoRET, DL, VTs, RetOps);
    ReplaceNode(Node, Ret);
    return;
  }
  case ISD::FrameIndex:
    SelectFrameIndex(Node);
    return;
  default:
    break;
  }

  SelectCode(Node);
}

FunctionPass *llvm::createLX32ISelDag(LX32TargetMachine &TM,
                                      CodeGenOptLevel OptLevel) {
  return new LX32DAGToDAGISelLegacy(TM, OptLevel);
}










