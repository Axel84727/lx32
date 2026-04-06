; RUN: llc -march=lx32 -mcpu=generic -mtriple=lx32-unknown-elf -filetype=asm -o - %s

declare i32 @ext(i32)

define i32 @call_ext(i32 %a) {
entry:
  %r = call i32 @ext(i32 %a)
  ret i32 %r
}

