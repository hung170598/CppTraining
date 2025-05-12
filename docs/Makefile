1. Cấu hình các toolchain và options make
CC          := arm-none-eabi-gcc
OBJCOPY     := arm-none-eabi-objcopy
MACH        := cortex-m3


CC: chọn compiler cho ARM (dòng STM32).

OBJCOPY: dùng để convert .elf → .bin.

MACH: đặt tên kiến trúc CPU để tái sử dụng trong flags.



🔧 2. Compiler và Linker flags make

CFLAGS := -Ilib -mcpu=$(MACH) -mthumb -mfloat-abi=soft -Wall -O0
-Ilib: include thư mục lib để tìm các header files.

-mcpu=cortex-m3: CPU target là Cortex-M3 (dòng STM32F1).

-mthumb: compile chế độ Thumb (chuẩn của STM32).

-mfloat-abi=soft: không dùng FPU (hợp lý cho STM32F1).

-Wall: bật tất cả warning.

-O0: không tối ưu, phù hợp khi đang debug.


LDFLAGS := -nostdlib -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs \
           -T linker.ld -Wl,-Map=build/final.map
-nostdlib: không dùng thư viện tiêu chuẩn (vì hệ nhúng).

--specs=nano.specs: dùng phiên bản nhỏ gọn của stdlib.

-T linker.ld: dùng linker script để gán địa chỉ.

-Wl,-Map=...: tạo file .map để debug địa chỉ vùng nhớ.

📁 3. Cấu trúc thư mục
SRC_DIR     := src
LIB_DIR     := lib
DRV_DIR     := $(SRC_DIR)/drivers
STARTUP_DIR := Startup
BUILD_DIR   := build
Tách rõ ràng các phần:


Thư mục	Vai trò
Startup/	File khởi động startup.c
lib/	Các file thư viện như gpio.c, uart.c, ...
src/	main.c và logic chính
src/drivers/	driver phụ trợ như log_info, temp.c
build/	Thư mục chứa .o, .elf, .bin
🧱 4. Danh sách source và đối tượng
SRC_FILES := \
	$(STARTUP_DIR)/startup.c \
	$(SRC_DIR)/main.c \
	...
Tập hợp tất cả các file .c trong project.

OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
📌 Dòng này rất hay: nó chuyển tất cả *.c thành build/*.o bằng cách giữ nguyên path.

Ví dụ:
src/main.c → build/src/main.o
lib/gpio.c → build/lib/gpio.o

Giữ cấu trúc thư mục y chang trong build/ → cực gọn và sạch!

🎯 5. Target chính

TARGET_ELF := build/firmware.elf
TARGET_BIN := build/firmware.bin
Chỉ định output .elf và .bin.

🔄 6. Rules
✅ Rule chính:
all: $(TARGET_BIN)
Chạy make sẽ build đến firmware.bin.

📦 Biên dịch từng file .c → .o
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@
$<: là input file (%.c)

$@: là output file (build/%.o)

mkdir -p $(dir $@): tự động tạo thư mục nếu chưa có → rất tiện

🔗 Link tất cả .o thành .elf

$(TARGET_ELF): $(OBJS) linker.ld
	$(CC) $(LDFLAGS) $(OBJS) -o $@
🔧 Tạo .bin từ .elf


$(TARGET_BIN): $(TARGET_ELF)
	$(OBJCOPY) -O binary $< $@
🚀 Flash firmware


flash: $(TARGET_BIN)
	st-flash --reset write $(TARGET_BIN) 0x8000000
Dùng st-flash để nạp firmware vào STM32 qua ST-Link.

🧹 Clean:


clean:
	rm -rf $(BUILD_DIR)
Xóa hết file đã build.

🧠 Tổng kết

Phần	Vai trò
SRC_FILES + OBJS	Tự động hóa danh sách build
Rule $(BUILD_DIR)/%.o: %.c	Build thông minh, tạo thư mục tự động
make	Build hoàn toàn
make flash	Nạp chương trình
make clean	Xóa sạch file build

