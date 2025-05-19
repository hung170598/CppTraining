# ==== Project name ====
PROJECT_NAME = MPU_Driver
TARGET = $(PROJECT_NAME)

# ==== Path File ====
HDR_DIRS = ../App ../API ../Config ../Config_Type ../Debug ../Hardware 			# Header file directory
INC_DIRS = $(addprefix -I, $(HDR_DIRS))											# Include directory
LINKER_SCRIPT_DIRS = ../Debug/stm32f4xx.ld										# Linker script directory	


# ==== Toolchain ====
CC 		 	= arm-none-eabi-gcc														# Compiler	
AS 		    = arm-none-eabi-as														# Assembler
OBJCOPY     = arm-none-eabi-objcopy													# Object file to binary
OBJDUMP 	= arm-none-eabi-objdump													# Object file to assembly
SIZE 		= arm-none-eabi-size													# Size of the output file

# ==== Core Options ====
CORE_M4 	= -mcpu=cortex-m4 														# Core M4
THUMB 		= -mthumb																# Thumb
FLOAT_ABI 	= -mfloat-abi=hard -mfpu=fpv4-sp-d16									# Float ABI
DEBUG       = -Wall -g -O0 -fmessage-length=0										# Debug

# ==== Compiler Flags ====
CFLAGS 	= $(CORE_M4) $(THUMB) $(FLOAT_ABI) $(DEBUG)									# Compiler flags
CFLAGS += -MMD -MP																	# Generate dependency files


# ==== Linker Options ====
LIB_NANO 			= -specs=nano.specs												# Library nano
NO_SYS_CALL 		= -specs=nosys.specs											# No system call
LINKER_SCRIPT 		= -T $(LINKER_SCRIPT_DIRS)										# Linker script
MAP_FILE    		= -Wl,-Map=$(TARGET).map										# Map file
NO_STARTUP 	    	= -nostartfiles													# No startupfiles default
NO_SECTION_UN_USED 	= -Wl,--gc-sections												# No section un used

# ==== Linker Flags ====
LDFLAGS = $(LIB_NANO) $(NO_SYS_CALL) $(LINKER_SCRIPT) $(MAP_FILE) $(NO_STARTUP) $(NO_SECTION_UN_USED)


# ==== OpenOCD ====
OPENOCD 	= openocd																# OpenOCD	
OPENOCD_CFG = -f interface/stlink-v2.cfg -f target/stm32f4x.cfg						# OpenOCD config	



# ==== Source File ====
C_SRCS  = $(foreach dir,$(HDR_DIRS),$(wildcard $(dir)/*.c))							# Source files
# ASM_SRCS = $(foreach dir,$(HDR_DIRS),$(wildcard $(dir)/*.s))						# Assembly files
INC_FILES = $(foreach dir,$(HDR_DIRS),$(wildcard $(dir)/*.h)) 						# Include files


# ==== Object File ====
OBJS = $(C_SRCS:.c=.o)
-include $(OBJS:.o=.d)


# ==== Build Rules ====
all: $(TARGET).elf $(TARGET).bin $(TARGET).hex $(TARGET).list

$(TARGET).elf: $(OBJS)															# Build the target elf file
	$(CC) $(CFLAGS) $(INC_DIRS) $(OBJS) $(LDFLAGS) -o $@							# Compile the object files and link them into an elf file
	$(SIZE) $@																		# Show the size of the elf file

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@														# Convert the elf file to a binary file

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@														# Convert the elf file to a hex file

$(TARGET).list: $(TARGET).elf
	$(OBJDUMP) -S $< > $@															# Convert the elf file to a list file

%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@										# Compile the source file into an object file

# ==== Flash ====
flash: $(TARGET).elf
	$(OPENOCD) $(OPENOCD_CFG) -c "program $(TARGET).elf verify reset exit"			# Flash the elf file to the target

# ==== Debug ====
debug: $(TARGET).elf
	$(OPENOCD) $(OPENOCD_CFG) -c "gdb_port 3333" -c "init" -c "reset halt"			# Debug the elf file

# ==== Clean ====
clean: 
	rm -f $(OBJS) $(TARGET).elf $(TARGET).bin $(TARGET).hex $(TARGET).list $(TARGET).map $(OBJS:.o=.d)

.PHONY: all clean flash debug	
