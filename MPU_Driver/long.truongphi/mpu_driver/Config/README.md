# Configuration Layer

## Mô tả
Tầng Config chứa các cấu hình cụ thể cho từng module. Các cấu hình này được định nghĩa dựa trên các kiểu dữ liệu từ Config_Type layer.

## Cấu trúc
- `mpu_config.h`: Header file chứa khai báo cấu hình MPU
- `mpu_config.c`: File triển khai cấu hình MPU

## Chức năng
1. Định nghĩa các tham số cấu hình cụ thể cho từng module
2. Cung cấp các giá trị mặc định cho từng module
3. Quản lý các cấu hình runtime của hệ thống
4. Lưu trữ và truy xuất cấu hình cho từng module
5. Xác thực và kiểm tra tính hợp lệ của cấu hình module
