    .section .text.startup, "ax", @progbits
    .globl  _start
    .type   _start, @function
_start:
    lui     x2, 0   # using absolute numbers to test
    addi    x2, x2, 4096
_bss_loop:
    bge     x10, x11, _bss_done
    sw      x0, 0(x10)
    addi    x10, x10, 4
    jal     x0, _bss_loop
_bss_done:
    addi    x10, x0, 0
    addi    x11, x0, 0
    jal     x1, main
    .globl  _exit
    .type   _exit, @function
_exit:
    lui     x5, 0xFFFFF
    sw      x10, 4(x5)
_halt:
    jal     x0, _halt
    .size   _start, . - _start
    .size   _exit,  . - _exit
