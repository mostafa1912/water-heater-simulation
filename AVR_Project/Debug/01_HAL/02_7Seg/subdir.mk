################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../01_HAL/02_7Seg/HAL_SSG_prog.c 

OBJS += \
./01_HAL/02_7Seg/HAL_SSG_prog.o 

C_DEPS += \
./01_HAL/02_7Seg/HAL_SSG_prog.d 


# Each subdirectory must supply rules for building sources it contributes
01_HAL/02_7Seg/%.o: ../01_HAL/02_7Seg/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


