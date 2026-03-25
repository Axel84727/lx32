//===-- LX32CallingConv.td - LX32 Calling Convention --------*- tablegen -*-===//
//
// Part of the LX32 Project
// SPDX-License-Identifier: MIT
//
//===----------------------------------------------------------------------===//


def CSR_LX32_ILP32 : 
    CalleeSavedRegs<(add X1, X8, X9, (sequence "X%u", 18, 27))>;

def CSR_NoRegs : CalleeSavedRegs<(add)>;

def CSR_IPRA : CalleeSavedRegs<(add X1)>;


def RetCC_LX32 : CallingConv<[
    CCIfType<[i1, i8, i16], CCPromoteToType<i32>>,
    CCIfType<[i32], CCAssignToReg<[X10, X11]>>,
    CCIfType<[i64], CCAssignToRegWithShadow<[X10], [X11]>>,
    CCAssignToStack<4, 4>
]>;


def CC_LX32 : CallingConv<[
    CCIfType<[i1, i8, i16], CCPromoteToType<i32>>,
    CCIfType<[i32], CCAssignToReg<[X10, X11, X12, X13, X14, X15, X16, X17]>>,
    CCIfType<[i64], CCAssignToRegWithShadow<[X10, X12, X14, X16],
                                            [X11, X13, X15, X17]>>,

    CCIfType<[i32], CCAssignToStack<4, 4>>,
    CCIfType<[i64], CCAssignToStack<8, 8>>
]>;