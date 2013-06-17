################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ColorClass.cpp \
../src/ColorClassProblem.cpp \
../src/Contrainte.cpp \
../src/Etage.cpp 

OBJS += \
./src/ColorClass.o \
./src/ColorClassProblem.o \
./src/Contrainte.o \
./src/Etage.o 

CPP_DEPS += \
./src/ColorClass.d \
./src/ColorClassProblem.d \
./src/Contrainte.d \
./src/Etage.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


