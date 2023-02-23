################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_f103c6_Drivers/GPIO/Stm32_f103c6_Drivers_Gpio.c 

OBJS += \
./Stm32_f103c6_Drivers/GPIO/Stm32_f103c6_Drivers_Gpio.o 

C_DEPS += \
./Stm32_f103c6_Drivers/GPIO/Stm32_f103c6_Drivers_Gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_f103c6_Drivers/GPIO/Stm32_f103c6_Drivers_Gpio.o: ../Stm32_f103c6_Drivers/GPIO/Stm32_f103c6_Drivers_Gpio.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"F:/Learn-in-depth/unit 7/lesson 3/Section/7-Segment/HAL/Includes" -I"F:/Learn-in-depth/unit 7/lesson 3/Section/7-Segment/Stm32_f103c6_Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_f103c6_Drivers/GPIO/Stm32_f103c6_Drivers_Gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

