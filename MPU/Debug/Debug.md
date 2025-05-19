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