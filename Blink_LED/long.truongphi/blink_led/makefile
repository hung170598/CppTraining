# Project name
PROJECT = blink_led
TARGET = $(PROJECT)

# PATH
LINKER_SCRIPT = stm32f1xx.ld

# Toolchain
CC      = arm-none-eabi-gcc				# Conpiler và linker
AS      = arm-none-eabi-as				# Trình dịch assembly
OBJCOPY = arm-none-eabi-objcopy			# Chuyển đổi ELF -> HEX
OBJDUMP = arm-none-eabi-objdump			# Tạo file disassembly
SIZE    = arm-none-eabi-size			# Hiển thị size bộ nhớ của ELF

# Core
CORE = -mcpu=cortex-m3
THUMB = -mthumb
DEBUG = -g -O0 -Wall

# Flags
CFLAGS  = $(CORE) $(THUMB) $(DEBUG)

# Assembly flags
ASFLAGS = $(CORE) $(THUMB)

NO_STARTUP = -nostartfiles
GC_SECTIONS = -Wl,--gc-sections
MAP_FILE = -Wl,-Map=$(TARGET).map
LIBS = -Wl,--start-group -lc -lm -Wl,--end-group

# Linker script
LDFLAGS = -T $(LINKER_SCRIPT) $(NO_STARTUP) $(GC_SECTIONS) $(MAP_FILE) $(LIBS)

# OpenOCD Configuration
OPENOCD = openocd
OPENOCD_CFG = -f interface/stlink.cfg -f target/stm32f1x.cfg


# Sources
C_SRCS = $(wildcard *.c)
ASM_SRCS = $(wildcard *.s)
OBJS = $(C_SRCS:.c=.o) 
# $(ASM_SRCS:.s=.o)

# Build rules
all: $(TARGET).elf $(TARGET).hex $(TARGET).list

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)
	$(SIZE) $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

# Tạo file .bin từ .elf
$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

$(TARGET).list: $(TARGET).elf
	$(OBJDUMP) -h -S $< > $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# %.o: %.s
# 	$(AS) $(ASFLAGS) $< -o $@

flash: $(TARGET).bin
	$(OPENOCD) $(OPENOCD_CFG) -c "program $< verify reset exit"


debug: $(TARGET).elf
	$(OPENOCD) $(OPENOCD_CFG) -c "gdb_port 3333" -c "init" -c "reset halt"


clean:
	rm -f *.o *.elf *.hex *.list *.map *.bin

.PHONY: all clean flash
