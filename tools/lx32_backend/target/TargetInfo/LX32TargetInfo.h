//===-- LX32TargetInfo.h - LX32 Target Implementation -------------------===//
//
// Part of the LX32 Project
// SPDX-License-Identifier: MIT
//
//===----------------------------------------------------------------------===//
#ifndef LLVM_LIB_TARGET_LX32_TARGETINFO_LX32TARGETINFO_H
#define LLVM_LIB_TARGET_LX32_TARGETINFO_LX32TARGETINFO_H
// TODO: USE IMPLEMENTED computeLX32DataLayout IN llvm-project/llvm/lib/TargetParser/TargetDataLayout.cpp:281:20:
namespace llvm {
    class Target;

    Target &getTheLX32TargetInfo();

} // namespace llvm
#endif // LLVM_LIB_TARGET_LX32_TARGETINFO_LX32TARGETINFO_H