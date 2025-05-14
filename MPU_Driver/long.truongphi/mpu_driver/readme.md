# MPU Driver Project

## Cấu trúc Project
```
├── App/           # Ứng dụng
├── API/           # API layer
├── Common/        # Common utilities
├── Config/        # Cấu hình
├── Config_Type/   # Định nghĩa kiểu dữ liệu
├── Debug/         # File debug và startup
├── Hardware/      # Driver phần cứng
└── Test/          # Unit test
```

# Hướng dẫn Build và Debug chương trình

## Cấu hình môi trường

Cần có: 
    - ARM Toolchain (Để sử dụng cho quá trình compiler và debug bằng gdb)
    - Make (Để có thể sử dụng makefile)
    - OpenOCD (Dùng để nạp file .elf lên Flash qua ST-Link hoặc debug lỗi)
    - Driver ST-Link (Để tạo kết nối qua cổng USB nạp code)

### ARM Toolchain

    - Có thể tải pack từ: [ARM GNU Toolchain (official)](https://developer.arm.com/downloads/-/gnu-rm)

    - Sau đó thêm đường dẫn thư mục ../bin của toolchain vào biến môi trường `PATH`

### Make

    - Có thể cài Make thông qua MSYS2, CYGWIN, ...
    
    - Sau đó thêm đường dẫn thư mục ../bin của toolchain vào biến môi trường `PATH`

### OpenOCD

    - Có thể tải pack từ: [OPENOCD](https://sourceforge.net/projects/openocd/files/openocd/0.12.0-rc1/)

    - Sau đó thêm đường dẫn thư mục ../bin của toolchain vào biến môi trường `PATH`

## Sử Dụng Project

### Nạp code
    Sử dụng terminal/cmd mở tới đường dẫn chứa makefile "../Debug"
    Chạy lệnh nạp code để nạp code vào VĐK:
 ```terminal
    make flash
 ``` 

### Debug
    Sử dụng terminal/cmd mở tới đường dẫn chứa makefile "../Debug"  
    Chạy lệnh debug để khởi động OpenOCD mở cổng GDB trên port3333 và thiết lập VĐK vào trạng thái dừng (halt) sau khi reset.
 ```terminal
    make debug
 ``` 
    Tiếp tục mở 1 terminal/cmd khác tới đường dẫn chứa makefile "../Debug"
    Chạy lệnh sử dụng GDB:
 ```terminal
    arm-none-eabi-gdb
 ``` 
    Sau đó kết nối GDB với OpenOCD qua port3333 bằng lệnh:
 ```terminal
    target remote localhost:3333
 ``` 
    Chọn file .elf để load lên flash
 ```terminal
    file blink_led.elf
    load
 ```     
Vậy là đã vào được quá trình Debug. Nếu muốn tham khảo các cú pháp sử dụng trong debug thì có thể xem tại "Debug.md"


