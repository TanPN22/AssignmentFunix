################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE\ (\ C\ include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/eventman.c \
D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE\ (\ C\ include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/timer.c 

OBJS += \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/eventman.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/timer.o 

C_DEPS += \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/eventman.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/timer.d 


# Each subdirectory must supply rules for building sources it contributes
SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/eventman.o: D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE\ (\ C\ include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/eventman.c SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/timer.o: D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE\ (\ C\ include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/timer.c SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Middle-2f-rtos

clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Middle-2f-rtos:
	-$(RM) ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/eventman.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/eventman.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/eventman.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/eventman.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/timer.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/timer.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/timer.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/timer.su

.PHONY: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Middle-2f-rtos

