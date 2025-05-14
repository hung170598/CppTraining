################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MPU_Driver/Src/Interrupt.c \
../MPU_Driver/Src/MPU_DRV.c 

OBJS += \
./MPU_Driver/Src/Interrupt.o \
./MPU_Driver/Src/MPU_DRV.o 

C_DEPS += \
./MPU_Driver/Src/Interrupt.d \
./MPU_Driver/Src/MPU_DRV.d 


# Each subdirectory must supply rules for building sources it contributes
MPU_Driver/Src/%.o MPU_Driver/Src/%.su MPU_Driver/Src/%.cyclo: ../MPU_Driver/Src/%.c MPU_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/VTI_Trainning/STM32/MPU_STM32F4/MPU_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MPU_Driver-2f-Src

clean-MPU_Driver-2f-Src:
	-$(RM) ./MPU_Driver/Src/Interrupt.cyclo ./MPU_Driver/Src/Interrupt.d ./MPU_Driver/Src/Interrupt.o ./MPU_Driver/Src/Interrupt.su ./MPU_Driver/Src/MPU_DRV.cyclo ./MPU_Driver/Src/MPU_DRV.d ./MPU_Driver/Src/MPU_DRV.o ./MPU_Driver/Src/MPU_DRV.su

.PHONY: clean-MPU_Driver-2f-Src

