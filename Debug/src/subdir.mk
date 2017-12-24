################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bit.c \
../src/config_v7.c \
../src/cps1848.c \
../src/iic_slave.c \
../src/iic_srio1848.c \
../src/main.c \
../src/shell.c \
../src/show_v7.c \
../src/uartMenu.c \
../src/udp_net.c \
../src/xadc_core.c \
../src/xil_io.c 

OBJS += \
./src/bit.o \
./src/config_v7.o \
./src/cps1848.o \
./src/iic_slave.o \
./src/iic_srio1848.o \
./src/main.o \
./src/shell.o \
./src/show_v7.o \
./src/uartMenu.o \
./src/udp_net.o \
./src/xadc_core.o \
./src/xil_io.o 

C_DEPS += \
./src/bit.d \
./src/config_v7.d \
./src/cps1848.d \
./src/iic_slave.d \
./src/iic_srio1848.d \
./src/main.d \
./src/shell.d \
./src/show_v7.d \
./src/uartMenu.d \
./src/udp_net.d \
./src/xadc_core.d \
./src/xil_io.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 Linux gcc compiler'
	arm-linux-gnueabihf-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


