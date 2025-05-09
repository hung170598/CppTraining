# Toolchain
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m3 -mthumb -O2 -Wall -ffunction-sections -fdata-sections -I$(INC_DIR)
LDFLAGS = -T ldscript/STM32F103C6_FLASH.ld -Wl,--gc-sections

# Directories
SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build

# Sources and objects
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Output
TARGET = $(BUILD_DIR)/blink

all: setup $(TARGET).bin

setup:
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(TARGET).elf: $(OBJS) startup/startup_stm32f103c6.o
	$(CC) $(CFLAGS) $^ -o $(TARGET).elf $(LDFLAGS)

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

all: setup $(TARGET).bin $(TARGET).hex

# Startup file
startup/startup_stm32f103c6.o: startup/startup_stm32f103c6.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
# st-flash write $(TARGET).bin 0x08000000
.PHONY: all clean setup