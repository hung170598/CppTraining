# Debug Layer

## Mô tả
Tầng Debug chứa các file liên quan đến debug và startup của hệ thống. Bao gồm file startup, linker script, makefile và các công cụ debug.

## Cấu trúc
- `startup.c`: File khởi tạo hệ thống
- `stm32f4xx.ld`: Linker script
- `makefile`: File build project
- `Debug.md`: Hướng dẫn debug

## Chức năng
1. Khởi tạo hệ thống và vector table
2. Quản lý bộ nhớ và phân vùng
3. Build và deploy code
4. Cung cấp công cụ debug
5. Xử lý lỗi và exception 