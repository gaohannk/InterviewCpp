################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../fidessa/MatchingPair.cpp \
../fidessa/MinimumGates.cpp \
../fidessa/MinimumGates2.cpp 

OBJS += \
./fidessa/MatchingPair.o \
./fidessa/MinimumGates.o \
./fidessa/MinimumGates2.o 

CPP_DEPS += \
./fidessa/MatchingPair.d \
./fidessa/MinimumGates.d \
./fidessa/MinimumGates2.d 


# Each subdirectory must supply rules for building sources it contributes
fidessa/%.o: ../fidessa/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


