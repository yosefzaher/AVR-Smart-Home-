################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../Buzzer_program.c \
../DIO_Program.c \
../EXTI_prog.c \
../GIE_prog.c \
../KPD_program.c \
../LCD_program.c \
../LDR_prog.c \
../LED_program.c \
../LM35_program.c \
../PORT_program.c \
../STEPPER_program.c \
../main.c \
../map.c 

OBJS += \
./ADC_program.o \
./Buzzer_program.o \
./DIO_Program.o \
./EXTI_prog.o \
./GIE_prog.o \
./KPD_program.o \
./LCD_program.o \
./LDR_prog.o \
./LED_program.o \
./LM35_program.o \
./PORT_program.o \
./STEPPER_program.o \
./main.o \
./map.o 

C_DEPS += \
./ADC_program.d \
./Buzzer_program.d \
./DIO_Program.d \
./EXTI_prog.d \
./GIE_prog.d \
./KPD_program.d \
./LCD_program.d \
./LDR_prog.d \
./LED_program.d \
./LM35_program.d \
./PORT_program.d \
./STEPPER_program.d \
./main.d \
./map.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


