.section .text
.global _start

_start:
    cli                     # Disable interrupts
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss

    call kernel_main        # Call C kernel entry point

halt:
    hlt
    jmp halt
