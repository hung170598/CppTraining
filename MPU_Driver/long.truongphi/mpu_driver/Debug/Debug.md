# Các lệnh GDB sử dụng trong quá trình debug

Đặt breakpoint
```terminal 
    break <chỗ cần đặt>
```
VD: 
```terminal
    break main
```

Tiếp tục chương trình từ breakpoint:
```terminal
    continue
```

Thực thi từng bước vào trong hàm (step vào hàm):
```terminal
    step
```

Thực thi từng bước qua hàm (tiến một dòng mã mà không vào trong hàm):
```terminal
    next
```

Kiểm tra giá trị của một biến:
```terminal
    print <tên biến>
```

Xem các thanh ghi:
```terminal
    info registers
```

Xem các giá trị trong stack:
```terminal
    backtrace
```

Xem các function call:
```terminal
    bt
```

Dừng chương trình và thoát khỏi GDB:
```terminal
    quit
```

Kiểm tra danh sách các breakpoint:
```terminal
    info breakpoints
```

Hủy một breakpoint cụ thể:
```terminal
    delete <vị trí breakpoint>
```

Hủy tất cả các breakpoint:
```terminal
    delete
```

Tạm tất cả dừng breakpoint:
```terminal
    disable
```

Tạm dừng một breakpoint cụ thể:
```terminal
    disable <vị trí breakpoint>
```

Kích hoạt lại tất cả các breakpoint:
```terminal
    enable
```

Kích hoạt lại một breakpoint cụ thể:
```terminal
    enable <vị trí breakpoint>
```

# Các lệnh GDB liên quan đến nhúng và thanh ghi

Reset và halt vi điều khiển:
```terminal
    monitor reset halt
```

Reset và init vi điều khiển:
```terminal
    monitor reset init
```

Xem giá trị thanh ghi cụ thể:
```terminal
    p/x $<tên thanh ghi>
```
VD:
```terminal
    p/x $pc    # Xem Program Counter
    p/x $sp    # Xem Stack Pointer
    p/x $lr    # Xem Link Register
```

Xem nội dung bộ nhớ:
```terminal
    x/<số lượng><định dạng> <địa chỉ>
```
VD:
```terminal
    x/10x 0x08000000    # Xem 10 word tại địa chỉ 0x08000000 dạng hex
    x/10i 0x08000000    # Xem 10 lệnh tại địa chỉ 0x08000000 dạng assembly
```

Xem thanh ghi điều khiển:
```terminal
    p/x *((volatile uint32_t*)0xE000ED08)    # Xem VTOR
    p/x *((volatile uint32_t*)0xE000ED00)    # Xem CPUID
    p/x *((volatile uint32_t*)0xE000ED04)    # Xem ICSR
```

Xem thanh ghi lỗi:
```terminal
    p/x *((volatile uint32_t*)0xE000ED28)    # Xem CFSR
    p/x *((volatile uint32_t*)0xE000ED2C)    # Xem HFSR
    p/x *((volatile uint32_t*)0xE000ED30)    # Xem DFSR
    p/x *((volatile uint32_t*)0xE000ED34)    # Xem MMFAR
    p/x *((volatile uint32_t*)0xE000ED38)    # Xem BFAR
```

Xem thanh ghi MPU:
```terminal
    p/x *((volatile uint32_t*)0xE000ED90)    # Xem MPU_TYPE
    p/x *((volatile uint32_t*)0xE000ED94)    # Xem MPU_CTRL
    p/x *((volatile uint32_t*)0xE000ED98)    # Xem MPU_RNR
    p/x *((volatile uint32_t*)0xE000ED9C)    # Xem MPU_RBAR
    p/x *((volatile uint32_t*)0xE000EDA0)    # Xem MPU_RASR
```