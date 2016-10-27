################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
INO_SRCS += \
..\Control-Panel.ino \
..\Engine-Devices.ino \
..\Engine-Loops.ino \
..\Engine-Serial.ino \
..\Engine.ino \
..\Operations-Backend.ino \
..\Operations-Director.ino \
..\Operations-ErrorHandler.ino \
..\Operations-Functions.ino \
..\Operations-StopsHandler.ino \
..\OperationsOne.ino \
..\Startup-Director.ino \
..\Startup-Methods.ino \
..\zDevelopment.ino 

CPP_SRCS += \
..\.ino.cpp \
..\Engine.cpp 

LINK_OBJ += \
.\.ino.cpp.o \
.\Engine.cpp.o 

INO_DEPS += \
.\Control-Panel.ino.d \
.\Engine-Devices.ino.d \
.\Engine-Loops.ino.d \
.\Engine-Serial.ino.d \
.\Engine.ino.d \
.\Operations-Backend.ino.d \
.\Operations-Director.ino.d \
.\Operations-ErrorHandler.ino.d \
.\Operations-Functions.ino.d \
.\Operations-StopsHandler.ino.d \
.\OperationsOne.ino.d \
.\Startup-Director.ino.d \
.\Startup-Methods.ino.d \
.\zDevelopment.ino.d 

CPP_DEPS += \
.\.ino.cpp.d \
.\Engine.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
.ino.cpp.o: ../.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Control-Panel.o: ../Control-Panel.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Engine-Devices.o: ../Engine-Devices.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Engine-Loops.o: ../Engine-Loops.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Engine-Serial.o: ../Engine-Serial.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Engine.cpp.o: ../Engine.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Engine.o: ../Engine.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Operations-Backend.o: ../Operations-Backend.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Operations-Director.o: ../Operations-Director.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Operations-ErrorHandler.o: ../Operations-ErrorHandler.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Operations-Functions.o: ../Operations-Functions.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Operations-StopsHandler.o: ../Operations-StopsHandler.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

OperationsOne.o: ../OperationsOne.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Startup-Director.o: ../Startup-Director.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

Startup-Methods.o: ../Startup-Methods.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

zDevelopment.o: ../zDevelopment.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Matt\Programs\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\cores\arduino" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\variants\mega" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial" -I"C:\dev\Arduino\libraries\LiquidCrystal_I2C" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\Wire\src" -I"C:\Users\Matt\Programs\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.14\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '


