OUTPUT_ARCH(lx32)
ENTRY(_start)

MEMORY {
    ram (rwx) : ORIGIN = 0x00000000, LENGTH = 4K
}

SECTIONS {
    .text : {
        *(.text.startup)
        *(.text .text.*)
    } > ram

    .rodata : {
        *(.rodata .rodata.*)
    } > ram

    .data : {
        *(.data .data.*)
    } > ram

    .bss : {
        __bss_start = .;
        *(.bss .bss.*)
        *(COMMON)
        __bss_end = .;
    } > ram

    _stack_top = ORIGIN(ram) + LENGTH(ram);
}

