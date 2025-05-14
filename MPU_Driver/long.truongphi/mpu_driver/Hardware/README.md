# Hardware Layer

## Mô tả
Tầng Hardware chứa các driver trực tiếp tương tác với phần cứng. Đây là tầng thấp nhất trong kiến trúc, cung cấp interface cho các tầng trên để tương tác với phần cứng.

## Cấu trúc
- `stm32f4xx.h`: Header file chứa các định nghĩa register và cấu trúc phần cứng
- `mpu_hw.c/h`: Driver cho MPU

## Chức năng
1. Tương tác trực tiếp với phần cứng
2. Quản lý các register và peripheral
3. Xử lý ngắt và exception
4. Cung cấp các hàm điều khiển phần cứng
5. Xử lý lỗi phần cứng 