################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/misc.c \
../SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_adc.c \
../SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_dma.c \
../SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_exti.c \
../SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_gpio.c \
../SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_i2c.c \
../SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_rcc.c \
../SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_spi.c \
../SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_syscfg.c \
../SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_tim.c \
../SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_usart.c 

OBJS += \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/misc.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_adc.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_dma.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_exti.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_gpio.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_i2c.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_rcc.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_spi.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_syscfg.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_tim.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_usart.o 

C_DEPS += \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/misc.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_adc.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_dma.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_exti.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_gpio.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_i2c.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_rcc.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_spi.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_syscfg.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_tim.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_usart.d 


# Each subdirectory must supply rules for building sources it contributes
SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/misc.o: D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/misc.c SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_adc.o: D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_adc.c SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_dma.o: D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_dma.c SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_exti.o: D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_exti.c SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_gpio.o: D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_gpio.c SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_i2c.o: D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_i2c.c SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_rcc.o: D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_rcc.c SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_spi.o: D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_spi.c SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_syscfg.o: D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_syscfg.c SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_tim.o: D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_tim.c SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_usart.o: D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_usart.c SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/DH/Lumi/Lab/Assignment01.IoT303x/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Drivers-2f-STM32F401RE_StdPeriph_Driver-2f-src

clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Drivers-2f-STM32F401RE_StdPeriph_Driver-2f-src:
	-$(RM) ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/misc.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/misc.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/misc.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/misc.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_adc.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_adc.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_adc.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_adc.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_dma.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_dma.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_dma.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_dma.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_exti.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_exti.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_exti.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_exti.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_gpio.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_gpio.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_gpio.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_gpio.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_i2c.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_i2c.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_i2c.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_i2c.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_rcc.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_rcc.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_rcc.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_rcc.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_spi.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_spi.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_spi.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_spi.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_syscfg.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_syscfg.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_syscfg.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_syscfg.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_tim.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_tim.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_tim.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_tim.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_usart.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_usart.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_usart.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/stm32f401re_usart.su

.PHONY: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Drivers-2f-STM32F401RE_StdPeriph_Driver-2f-src

