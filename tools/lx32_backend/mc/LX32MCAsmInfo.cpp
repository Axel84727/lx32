#include "LX32MCAsmInfo.h"
#include "llvm/TargetParser/Triple.h"

void LX32MCAsmInfo::anchor() {}

LX32MCAsmInfo::LX32MCAsmInfo(const llvm::Triple &TT) {
  IsLittleEndian = true;           
  CodePointerSize = 4;             
  CalleeSaveStackSlotSize = 4;     
  CommentString = "#";             
  AlignmentIsInBytes = false;
  SupportsDebugInformation = true;
  ExceptionsType = llvm::ExceptionHandling::DwarfCFI;
  Data16bitsDirective = "\t.half\t";
  Data32bitsDirective = "\t.word\t";
}