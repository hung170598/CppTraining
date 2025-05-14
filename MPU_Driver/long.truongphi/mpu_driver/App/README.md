# Application Layer

## Mô tả
Thư mục này chứa code ứng dụng, là tầng cao nhất trong kiến trúc. Ứng dụng sử dụng các API được cung cấp bởi các tầng thấp hơn để thực hiện các chức năng cụ thể.

## Cấu trúc
- `main.c`: File chính của ứng dụng
- `app_config.h`: Cấu hình ứng dụng

## Chức năng
1. Khởi tạo và cấu hình hệ thống
2. Xử lý các sự kiện và tương tác người dùng
3. Quản lý luồng chương trình chính
4. Xử lý lỗi và exception
5. Giao tiếp với các tầng thấp hơn thông qua API
