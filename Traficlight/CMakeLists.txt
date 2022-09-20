cmake_minimum_required(VERSION 3.20.5)
# Author Mohamed Abdelnasser
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_COMPILER avr-g++ CACHE STRING "C++ compiler" FORCE)
set(CMAKE_C_COMPILER avr-gcc CACHE STRING "C Complier" FORCE)
Set(CMAKE_OBJCOPY avr-objcopy CACHE STRING "avr objcopy" FORCE)

set(CMAKE_CXX_FLAGS "-mmcu=atmega32 -01 -DF_CPU=1000000UL")

project(traficlight)

set(SRCS    main.c
            \MCAL\)
set(INCS    main.h
            \MCAL\)            
message("Source files are:\n${SRCS}")

target_include_directories(${PROJECT_NAME}.elf PUBLIC ${INCS})
message("Include files are:\n${INCS}")

add_executable(${PROJECT_NAME}.elf ${SRCS})
#fromating
message("${FLASH_FLAGS}")
add_custom_target(flash ALL     #add flash target to overall target
                DEPENDS ${PROJECT_NAME}.elf
                COMMAND avr-objcopy -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex)       

