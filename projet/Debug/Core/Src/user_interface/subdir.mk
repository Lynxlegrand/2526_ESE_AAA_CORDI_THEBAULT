################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/user_interface/button.c \
../Core/Src/user_interface/led.c \
../Core/Src/user_interface/shell.c 

OBJS += \
./Core/Src/user_interface/button.o \
./Core/Src/user_interface/led.o \
./Core/Src/user_interface/shell.o 

C_DEPS += \
./Core/Src/user_interface/button.d \
./Core/Src/user_interface/led.d \
./Core/Src/user_interface/shell.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/user_interface/%.o Core/Src/user_interface/%.su Core/Src/user_interface/%.cyclo: ../Core/Src/user_interface/%.c Core/Src/user_interface/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32G4xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"D:/Githubs/2526_ESE_AAA_CORDI_THEBAULT/projet/Core/Src/acquisition" -I"D:/Githubs/2526_ESE_AAA_CORDI_THEBAULT/projet/Core/Src/motor_control" -I"D:/Githubs/2526_ESE_AAA_CORDI_THEBAULT/projet/Core/Src/user_interface" -I"D:/Githubs/2526_ESE_AAA_CORDI_THEBAULT/projet/Core/Inc/acquisition" -I"D:/Githubs/2526_ESE_AAA_CORDI_THEBAULT/projet/Core/Inc/motor_control" -I"D:/Githubs/2526_ESE_AAA_CORDI_THEBAULT/projet/Core/Inc/user_interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-user_interface

clean-Core-2f-Src-2f-user_interface:
	-$(RM) ./Core/Src/user_interface/button.cyclo ./Core/Src/user_interface/button.d ./Core/Src/user_interface/button.o ./Core/Src/user_interface/button.su ./Core/Src/user_interface/led.cyclo ./Core/Src/user_interface/led.d ./Core/Src/user_interface/led.o ./Core/Src/user_interface/led.su ./Core/Src/user_interface/shell.cyclo ./Core/Src/user_interface/shell.d ./Core/Src/user_interface/shell.o ./Core/Src/user_interface/shell.su

.PHONY: clean-Core-2f-Src-2f-user_interface

