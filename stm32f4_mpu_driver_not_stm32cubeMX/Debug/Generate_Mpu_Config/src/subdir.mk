################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generate_Mpu_Config/src/MPU_Config.c 

OBJS += \
./Generate_Mpu_Config/src/MPU_Config.o 

C_DEPS += \
./Generate_Mpu_Config/src/MPU_Config.d 


# Each subdirectory must supply rules for building sources it contributes
Generate_Mpu_Config/src/%.o Generate_Mpu_Config/src/%.su Generate_Mpu_Config/src/%.cyclo: ../Generate_Mpu_Config/src/%.c Generate_Mpu_Config/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/Workplace/STM32/MPU/stm32f4_mpu_driver_not_stm32cubeMX/mpu_driver/inc" -I"D:/Workplace/STM32/MPU/stm32f4_mpu_driver_not_stm32cubeMX/Generate_Mpu_Config/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Generate_Mpu_Config-2f-src

clean-Generate_Mpu_Config-2f-src:
	-$(RM) ./Generate_Mpu_Config/src/MPU_Config.cyclo ./Generate_Mpu_Config/src/MPU_Config.d ./Generate_Mpu_Config/src/MPU_Config.o ./Generate_Mpu_Config/src/MPU_Config.su

.PHONY: clean-Generate_Mpu_Config-2f-src

