################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mpu_driver/src/MPU.c 

OBJS += \
./mpu_driver/src/MPU.o 

C_DEPS += \
./mpu_driver/src/MPU.d 


# Each subdirectory must supply rules for building sources it contributes
mpu_driver/src/%.o mpu_driver/src/%.su mpu_driver/src/%.cyclo: ../mpu_driver/src/%.c mpu_driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/Workplace/STM32/MPU/stm32f4_mpu_driver_not_stm32cubeMX/mpu_driver/inc" -I"D:/Workplace/STM32/MPU/stm32f4_mpu_driver_not_stm32cubeMX/Generate_Mpu_Config/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mpu_driver-2f-src

clean-mpu_driver-2f-src:
	-$(RM) ./mpu_driver/src/MPU.cyclo ./mpu_driver/src/MPU.d ./mpu_driver/src/MPU.o ./mpu_driver/src/MPU.su

.PHONY: clean-mpu_driver-2f-src

