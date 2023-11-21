################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE/shared/Middle/Kalman/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Source/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Assignment04.IoT303x
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Assignment04.IoT303x.elf \

MAP_FILES += \
Assignment04.IoT303x.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Assignment04.IoT303x.list \


# All Target
all: main-build

# Main-build Target
main-build: Assignment04.IoT303x.elf secondary-outputs

# Tool invocations
Assignment04.IoT303x.elf Assignment04.IoT303x.map: $(OBJS) $(USER_OBJS) D:\DH\Lumi\Lab\Assignment04.IoT303x\STM32F401RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Assignment04.IoT303x.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\DH\Lumi\Lab\Assignment04.IoT303x\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Assignment04.IoT303x.map" -Wl,--gc-sections -static -L"D:\DH\Lumi\Lab\Assignment04.IoT303x\SDK_1.0.3_NUCLEO-F401RE\lib_stm" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Assignment04.IoT303x.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Assignment04.IoT303x.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Assignment04.IoT303x.elf Assignment04.IoT303x.list Assignment04.IoT303x.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
