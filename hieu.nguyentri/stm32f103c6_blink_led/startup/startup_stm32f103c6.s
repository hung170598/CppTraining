    .syntax unified
    .cpu cortex-m3
    .thumb
    .global Reset_Handler

    .section .isr_vector,"a",%progbits
    .word 0x20005000
    .word Reset_Handler
    @ … các handler khác comment thay cho “...”

    .global Reset_Handler      
Reset_Handler:
    /* Copy .data from flash to RAM */
    ldr   r0, =_etext
    ldr   r1, =_sdata
    ldr   r2, =_edata
1:
    ldr   r3, [r0], #4
    str   r3, [r1], #4
    cmp   r1, r2
    blt   1b

    /* Zero fill .bss */
    ldr   r0, =_sbss
    ldr   r1, =_ebss
2:
    mov   r2, #0
    str   r2, [r0], #4
    cmp   r0, r1
    blt   2b

    /* Call main */
    bl    main

hang:
    b     hang

    @ newline here
