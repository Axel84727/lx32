/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Register Enum Values                                                *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace llvm {

class MCRegisterClass;
extern const MCRegisterClass LX32MCRegisterClasses[];

namespace LX32 {

enum : unsigned {
  NoRegister,
  X0 = 1,
  X1 = 2,
  X2 = 3,
  X3 = 4,
  X4 = 5,
  X5 = 6,
  X6 = 7,
  X7 = 8,
  X8 = 9,
  X9 = 10,
  X10 = 11,
  X11 = 12,
  X12 = 13,
  X13 = 14,
  X14 = 15,
  X15 = 16,
  X16 = 17,
  X17 = 18,
  X18 = 19,
  X19 = 20,
  X20 = 21,
  X21 = 22,
  X22 = 23,
  X23 = 24,
  X24 = 25,
  X25 = 26,
  X26 = 27,
  X27 = 28,
  X28 = 29,
  X29 = 30,
  X30 = 31,
  X31 = 32,
  NUM_TARGET_REGS // 33
};

} // namespace LX32

// Register classes

namespace LX32 {

enum {
  GPRRegClassID = 0,
  GPRNOX0RegClassID = 1,

};

} // namespace LX32

// Register alternate name indices

namespace LX32 {

enum {
  ABIRegAltName,	// 0
  NoRegAltName,	// 1
  NUM_TARGET_REG_ALT_NAMES = 2
};

} // namespace LX32
// Register pressure sets enum.
namespace LX32 {

enum RegisterPressureSets {
  GPR = 0,
};

} // namespace LX32

} // namespace llvm
