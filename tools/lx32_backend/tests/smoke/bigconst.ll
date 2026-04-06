; RUN: llc -march=lx32 -mcpu=generic -mtriple=lx32-unknown-elf -filetype=asm -o - %s

define i32 @bigconst() {
entry:
  ret i32 1000000
}

