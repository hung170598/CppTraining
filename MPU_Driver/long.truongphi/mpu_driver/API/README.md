# API Layer

## Mô tả
Tầng API cung cấp interface cho ứng dụng để tương tác với các tầng thấp hơn. API layer đóng gói các chi tiết triển khai và cung cấp một interface đơn giản, dễ sử dụng.

## Cấu trúc
- `mpu_driver.h`: API cho MPU driver
- `mpu_driver.c`: Triển khai các API

## Chức năng
1. Cung cấp interface đơn giản cho ứng dụng
2. Đóng gói các chi tiết triển khai phức tạp
3. Xử lý và chuyển đổi dữ liệu giữa các tầng
5. Cung cấp cơ chế xử lý lỗi thống nhất 