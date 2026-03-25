add_llvm_component_group(LX32)

add_llvm_target(LX32CodeGen
   core/LX32TargetMachine.cpp

  LINK_COMPONENTS
  MC
  Support
  Target

  ADD_TO_COMPONENT
  LX32
)

add_subdirectory(target)
add_subdirectory(mc)