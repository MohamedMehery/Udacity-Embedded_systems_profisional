cmake_minimum_required(VERSION 3.20.5)
# Author Mohamed Abdelnasser
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_COMPILER avr-g++ CACHE STRING "C++ compiler" FORCE)
set(CMAKE_C_COMPILER avr-gcc CACHE STRING "C Complier" FORCE)
Set(CMAKE_OBJCOPY avr-objcopy CACHE STRING "avr objcopy" FORCE)

#set(CMAKE_CXX_FLAGS "-mmcu=atmega32 -O1 -DF_CPU=1000000UL")#compiler take the flags to substitute to run
set(CMAKE_C_FLAGS "-mmcu=atmega32 -O1 -DF_CPU=1000000UL")#compiler take the flags to substitute to run

project(traficlight)

set(SRCS    main.c
            ./MCAL/GPIO.c
            ./MCAL/TIMER.c
            ./MCAL/INT.c
            ./HAL/LED.c
            ./Application/app.c)

set(INCS MCAL/
         HAL/
         Application/)            

# message("Source files are:\n${SRCS}")

add_executable(${PROJECT_NAME}.elf ${SRCS})
target_include_directories(${PROJECT_NAME}.elf PUBLIC ${INCS})
# message("Include files are:\n${INCS}")

#fromating
# message("${FLASH_FLAGS}")
add_custom_target(flash ALL     #add flash target to overall target
                DEPENDS ${PROJECT_NAME}.elf
                COMMAND avr-objcopy -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex)       

