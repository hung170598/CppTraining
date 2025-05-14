# Configuration Type Layer

## Mô tả
Tầng Config_Type định nghĩa các kiểu dữ liệu và cấu trúc được sử dụng trong toàn bộ project. Các định nghĩa này cung cấp một interface thống nhất cho việc cấu hình và sử dụng các module.

## Cấu trúc
- `mpu_type.h`: Header file chứa các định nghĩa kiểu dữ liệu cho MPU
- `mpu_type.c`: File triển khai các biến mặc định

## Chức năng
1. Định nghĩa các kiểu dữ liệu cơ bản cho toàn bộ hệ thống
2. Cung cấp các cấu trúc dữ liệu chung cho các module
3. Định nghĩa các enum và constant dùng chung
4. Cung cấp các kiểu dữ liệu cho việc cấu hình module
5. Đảm bảo tính nhất quán của kiểu dữ liệu giữa các module
