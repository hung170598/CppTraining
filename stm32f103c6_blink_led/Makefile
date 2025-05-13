GNU_DIR := C:/GNU_Toolchain/GCC_NEW
GCC_ARM_DIR = $(GNU_DIR)/bin/arm-none-eabi-gcc
OBJ_CPY_DIR = $(GNU_DIR)/arm-none-eabi/bin/objcopy

LD_FILE := STM32F103C8TX_FLASH.ld
STLINK_ULTILITY = Tools/STLINK_Utility/ST-LINK_CLI

CPU = cortex-m3 
#module

#include directory
INC_DIRS += Core/Inc \
			Peripherals/Inc

INC_FILES += $(foreach INC_DIRS, $(INC_DIRS), $(wildcard $(INC_DIRS)/*.h))	

#soure directory
SRC_DIRS += Core/Src \
			Peripherals/Src \

ASM_DIRS += Startup
			
SRC_FILES += $(foreach SRC_DIRS, $(SRC_DIRS), $(wildcard $(SRC_DIRS)/*.c))
ASM_FILES += $(foreach ASM_DIRS, $(ASM_DIRS), $(wildcard $(ASM_DIRS)/*.s))

#output directory
OUT_DIR = ./Debug

#get all .o files
SRC_FILENAMES += $(notdir $(SRC_FILES))
ASM_FILENAMES += $(notdir $(ASM_FILES))
OBJ_FILENAMES += $(subst .c,.o,$(SRC_FILENAMES))
OBJ_FILENAMES += $(subst .s,.o,$(ASM_FILENAMES))
OBJ_FILES += $(foreach OBJ_FILENAMES, $(OBJ_FILENAMES), $(OUT_DIR)/$(OBJ_FILENAMES))


#options and flags
INC_OPTIONS = $(foreach INC_DIRS, $(INC_DIRS), -I$(INC_DIRS))

CCFLAGS = -c -mcpu=$(CPU) -mthumb  -std=gnu11 -O0 $(INC_OPTIONS)
ASFLAGS = -c -mcpu=$(CPU) -mthumb $(INC_OPTIONS) #build assembly
LDFLAGS = -T $(LD_FILE) -Wl,-Map=$(OUT_DIR)/$(MODULE).map -nostdlib

#search for all .c file in SRC_DIRS
vpath %.c $(SRC_DIRS)
vpath %.s $(ASM_DIRS)

build:$(OUT_DIR)/$(MODULE).hex
	@echo "Build success!"

#generalize makefile
%.o:%.c
	@$(GCC_ARM_DIR) $(CCFLAGS) $^ -o $(OUT_DIR)/$@ 

#generalize makefile for .s files
%.o: %.s
	@$(GCC_ARM_DIR) $(ASFLAGS) $^ -o $(OUT_DIR)/$@

#prerequisites must be .o files name only to use for %.o:%.c
$(OUT_DIR)/$(MODULE).elf:$(OBJ_FILENAMES)
	@$(GCC_ARM_DIR) $(LDFLAGS) $(OBJ_FILES) -o $@
	
$(OUT_DIR)/$(MODULE).hex:$(OUT_DIR)/$(MODULE).elf
	@$(OBJ_CPY_DIR) -O ihex  $^ $@
	
run:
	@$(STLINK_ULTILITY) -ME
	@$(STLINK_ULTILITY) -p $(OUT_DIR)/$(MODULE).hex 0x08000000
	@$(STLINK_ULTILITY) -rst
	
clean:
	@rm $(OUT_DIR)/*
	@echo "Output files cleaned!"

print-%:
	@echo $($(subst print-,,$@))