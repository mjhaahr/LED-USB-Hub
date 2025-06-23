################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/stm32l5xx_hal_msp.c \
../Src/stm32l5xx_hal_timebase_tim.c \
../Src/stm32l5xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32l5xx.c 

OBJS += \
./Src/main.o \
./Src/stm32l5xx_hal_msp.o \
./Src/stm32l5xx_hal_timebase_tim.o \
./Src/stm32l5xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32l5xx.o 

C_DEPS += \
./Src/main.d \
./Src/stm32l5xx_hal_msp.d \
./Src/stm32l5xx_hal_timebase_tim.d \
./Src/stm32l5xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32l5xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L552xx -c -I../Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/stm32l5xx_hal_msp.cyclo ./Src/stm32l5xx_hal_msp.d ./Src/stm32l5xx_hal_msp.o ./Src/stm32l5xx_hal_msp.su ./Src/stm32l5xx_hal_timebase_tim.cyclo ./Src/stm32l5xx_hal_timebase_tim.d ./Src/stm32l5xx_hal_timebase_tim.o ./Src/stm32l5xx_hal_timebase_tim.su ./Src/stm32l5xx_it.cyclo ./Src/stm32l5xx_it.d ./Src/stm32l5xx_it.o ./Src/stm32l5xx_it.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32l5xx.cyclo ./Src/system_stm32l5xx.d ./Src/system_stm32l5xx.o ./Src/system_stm32l5xx.su

.PHONY: clean-Src

