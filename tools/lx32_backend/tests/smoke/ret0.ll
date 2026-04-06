; RUN: llc -march=lx32 -mtriple=lx32-unknown-elf -filetype=asm -o - %s

define i32 @ret0() {
entry:
  ret i32 0
}

