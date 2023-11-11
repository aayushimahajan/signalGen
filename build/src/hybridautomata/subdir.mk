################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/hybridautomata/ha_helper.cpp \
../src/hybridautomata/hybridAutomata.cpp \
../src/hybridautomata/location.cpp \
../src/hybridautomata/transition.cpp \
../src/hybridautomata/variable_to_index_mapping.cpp 

OBJS += \
./src/hybridautomata/ha_helper.o \
./src/hybridautomata/hybridAutomata.o \
./src/hybridautomata/location.o \
./src/hybridautomata/transition.o \
./src/hybridautomata/variable_to_index_mapping.o 

CPP_DEPS += \
./src/hybridautomata/ha_helper.d \
./src/hybridautomata/hybridAutomata.d \
./src/hybridautomata/location.d \
./src/hybridautomata/transition.d \
./src/hybridautomata/variable_to_index_mapping.d 


# Each subdirectory must supply rules for building sources it contributes
src/hybridautomata/%.o: ../src/hybridautomata/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

