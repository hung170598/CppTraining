# Nạp code
    Sử dụng terminal/cmd mở tới đường dẫn chứa makefile "../Debug"
    Chạy lệnh nạp code để nạp code vào VĐK:
 ```terminal
    make flash
 ``` 


# DEBUG bằng OPENOCD

mở Terminal đến file chứa makefile
chạy lệnh để debug:
    make debug

=> khởi động OpenOCD, mở cổng GDB trên cổng 3333 và thiết lập vi điều khiển vào trạng thái dừng (halt) sau khi reset.

mở Terminal khác đến file và chạy lệnh:
    arm-none-eabi-gdb

Sau đó kết nối GDB với OpenOCD qua cổng 3333:
    target remote localhost:3333

Tiếp tục chọn file .elf để load chương trình ELF vào bộ nhớ của STM32:
    file blink_led.elf
    load

