SRC_DIR := Source
SRC_DIR += User_Exercise/$(MODULE)
SRC_FILE := $(foreach dir,$(SRC_DIR),$(wildcard $(dir)/*.c))

ASM_FILE := $(notdir $(SRC_FILE))
ASM_FILE := $(patsubst %.c,%.s,$(ASM_FILE))
ASM_FILE := $(addprefix Out/asm/,$(ASM_FILE))
ASM_FILE += Startup/startup_stm32f103xb.s

OBJ_FILE := $(notdir $(ASM_FILE))
OBJ_FILE := $(patsubst %.s,%.o,$(OBJ_FILE))
OBJ_FILE := $(addprefix Out/obj/,$(OBJ_FILE))

ELF_FILE := Out/prg/$(MODULE).elf
HEX_FILE := Out/prg/$(MODULE).hex

INC_DIR := Include
INC_DIR += Gnu/lib/gcc/arm-none-eabi/10.3.1/include
INC_OPT := $(addprefix -I,$(INC_DIR))

CC := Gnu/bin/arm-none-eabi-gcc
CFLAGS := -mcpu=cortex-m3 -mthumb -std=gnu11 -Wall $(INC_OPT)

LINKER_TOOL := Gnu/bin/arm-none-eabi-ld
LINKER_FILE := Linker/STM32F103C8TX_FLASH.ld
LINKER_OPT  := -T$(LINKER_FILE) -nostdlib

OBJCOPY_TOOL := Gnu/bin/arm-none-eabi-objcopy

STLINK := STLink/STM32_ST_LINKUtility/STLINKUtility/ST_LINK_CLI.exe

vpath %.c $(SRC_DIR)
Out/asm/%.s: %.c
	$(CC) $(CFLAGS) -S $< -o $@

Out/obj/%.o: Out/asm/%.s
	$(CC) $(CFLAGS) -c $< -o $@
Out/obj/%.o: Startup/%.s
	$(CC) $(CFLAGS) -c $< -o $@

$(ELF_FILE): $(OBJ_FILE)
	$(CC) $(LINKER_OPT) $(OBJ_FILE) -o $@ 
$(HEX_FILE) : $(ELF_FILE)
	$(OBJCOPY_TOOL) -O ihex $(ELF_FILE) $(HEX_FILE)

all: $(HEX_FILE)

flash:
	$(STLINK) -c SWD -P $(HEX_FILE) -Rst -Run

clean: 
	rm -rf Out/asm/*
	rm -rf Out/obj/*
	rm -rf Out/prg/*
print-%:
	@echo $($(subst print-,,$@))