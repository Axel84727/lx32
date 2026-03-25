add_llvm_component_library(LLVMLX32Desc
  LX32MCAsmInfo.cpp
  LX32MCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  LX32Info
  Support
  TargetParser

  ADD_TO_COMPONENT
  LX32
)