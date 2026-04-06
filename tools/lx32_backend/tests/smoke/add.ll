; RUN: llc -march=lx32 -mtriple=lx32-unknown-elf -filetype=asm -o - %s

define i32 @add(i32 %a, i32 %b) {
entry:
  %r = add i32 %a, %b
  ret i32 %r
}

