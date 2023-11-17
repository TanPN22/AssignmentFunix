################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE\ (\ C\ include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/buzzer.c \
D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE\ (\ C\ include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/melody.c 

OBJS += \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/buzzer.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/melody.o 

C_DEPS += \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/buzzer.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/melody.d 


# Each subdirectory must supply rules for building sources it contributes
SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/buzzer.o: D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE\ (\ C\ include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/buzzer.c SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/melody.o: D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE\ (\ C\ include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/melody.c SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE ( C include)/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Middle-2f-buzzer

clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Middle-2f-buzzer:
	-$(RM) ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/buzzer.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/buzzer.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/buzzer.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/buzzer.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/melody.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/melody.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/melody.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/melody.su

.PHONY: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Middle-2f-buzzer

