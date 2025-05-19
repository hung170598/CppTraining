/*
******************************************************************************
**
** @file        : stm32f4xx.ld
**
** @author      : long.truongphi
**
** @brief       : Linker script cho vi điều khiển STM32F407VGTx
**                      - Bộ nhớ FLASH: 1024 KByte (1MB)
**                      - Bộ nhớ RAM: 128 KByte
**
**                - Cấu hình vị trí stack và heap theo yêu cầu ứng dụng.
**                - Định nghĩa các phân vùng cho vector table, code, dữ liệu,
**                  và các phần khởi tạo/không khởi tạo.
**
**                - Nếu sử dụng bộ nhớ ngoài, cần mở rộng vùng MEMORY tương ứng.
**
**  @Target      : Vi điều khiển STM32F4 Series (STM32F407VGTx)
**
**  @Distribution: Tập tin này tự phân phối, không có bất kỳ
**                 đảm bảo nào về tính chính xác hoặc đầy đủ.
**
******************************************************************************
** @attention
**
** Tham khảo bởi STMicroelectronics, 2025.
**
** Tập tin này có thể sử dụng lại hoặc chỉnh sửa trong phạm vi nội bộ dự án.
**
******************************************************************************
*/


/* Entry Point */
ENTRY(Reset_Handler)

/* Định nghĩa các vùng nhớ */
MEMORY {
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 1024K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

/* Định nghĩa kích thước heap và stack */
HEAP_SIZE = 0x200;
STACK_SIZE = 0x400;

__end_stack = ORIGIN(RAM) + LENGTH(RAM);

/* Các phân vùng */
SECTIONS {
    /* Put startup code into FLASH, ALWAYS DO THIS FIRST */
    .isr_vector : {
        . = ALIGN(4);
        KEEP(*(.isr_vector));
        . = ALIGN(4);
    } > FLASH

    /* Đặt mã chương trình và dữ liệu khác vào FLASH */
    .text : {
        . = ALIGN(4);
        __text_start = .;

        *(.text)
        *(.text*)
        *(.glue_7)
        *(.glue_7t)
        *(.eh_frame)

        KEEP(*(.init))
        KEEP(*(.fini))

        . = ALIGN(4);
        __text_end = .;
    } > FLASH

    /* Put constant (read-only) data into FLASH */
    .rodata : {
        . = ALIGN(4);
        __rodata_start = .;

        *(.rodata)
        *(.rodata*)

        . = ALIGN(4);
        __rodata_end = .;
    } > FLASH

    .ARM.extab : {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > FLASH

    .ARM : {
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } > FLASH

    .preinit_array : {
        PROVIDE_HIDDEN(__preinit_array_start = .);
        KEEP(*(.preinit_array*))
        PROVIDE_HIDDEN(__preinit_array_end = .);
    } > FLASH
    .init_array : {
        PROVIDE_HIDDEN(__init_array_start = .);
        KEEP(*(.init_array*))
        PROVIDE_HIDDEN(__init_array_end = .);
    } > FLASH
    .fini_array : {
        PROVIDE_HIDDEN(__fini_array_start = .);
        KEEP(*(.fini_array*))
        PROVIDE_HIDDEN(__fini_array_end = .);
    } > FLASH

    /* Được sử dụng bởi startup để khởi tạo dữ liệu */
    __data_flash_start = LOADADDR(.data);

    /* Các phân vùng dữ liệu đã khởi tạo vào bộ nhớ RAM */
    .data : {
        . = ALIGN(4);
        __data_start = .;

        *(.data)
        *(.data*)

        . = ALIGN(4);
        __data_end = .;
    } > RAM AT> FLASH

    /* Phân vùng dữ liệu chưa khởi tạo vào bộ nhớ RAM */
    .bss : {
        . = ALIGN(4);
        __bss_start = .;
        __bss_start__ = __bss_start;

        *(.bss)
        *(.bss*)
        *(COMMON)

        . = ALIGN(4);
        __bss_end = .;
        __bss_end__ = __bss_end;
    } > RAM

    /* Phân vùng heap và stack của người dùng, dùng để kiểm tra xem còn đủ bộ nhớ RAM không */
    ._user_heap_stack : {
        . = ALIGN(4);
        PROVIDE ( end = . );
        PROVIDE ( _end = . );
        . = . + HEAP_SIZE;
        . = . + STACK_SIZE;
        . = ALIGN(4);
    } > RAM

    /* Loại bỏ thông tin từ các thư viện trình biên dịch */
    /DISCARD/ : {
        libc.a(*)
        libm.a(*)
        libgcc.a(*)
    }

    .ARM.attributes 0 : {
        *(.ARM.attributes)
    }
}