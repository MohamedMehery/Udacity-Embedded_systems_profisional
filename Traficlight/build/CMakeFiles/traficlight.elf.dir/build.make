# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\build"

# Include any dependencies generated for this target.
include CMakeFiles/traficlight.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/traficlight.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/traficlight.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/traficlight.elf.dir/flags.make

CMakeFiles/traficlight.elf.dir/main.c.obj: CMakeFiles/traficlight.elf.dir/flags.make
CMakeFiles/traficlight.elf.dir/main.c.obj: ../main.c
CMakeFiles/traficlight.elf.dir/main.c.obj: CMakeFiles/traficlight.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/traficlight.elf.dir/main.c.obj"
	C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/traficlight.elf.dir/main.c.obj -MF CMakeFiles\traficlight.elf.dir\main.c.obj.d -o CMakeFiles\traficlight.elf.dir\main.c.obj -c "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\main.c"

CMakeFiles/traficlight.elf.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/traficlight.elf.dir/main.c.i"
	C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\main.c" > CMakeFiles\traficlight.elf.dir\main.c.i

CMakeFiles/traficlight.elf.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/traficlight.elf.dir/main.c.s"
	C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\main.c" -o CMakeFiles\traficlight.elf.dir\main.c.s

CMakeFiles/traficlight.elf.dir/MCAL/GPIO.c.obj: CMakeFiles/traficlight.elf.dir/flags.make
CMakeFiles/traficlight.elf.dir/MCAL/GPIO.c.obj: ../MCAL/GPIO.c
CMakeFiles/traficlight.elf.dir/MCAL/GPIO.c.obj: CMakeFiles/traficlight.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/traficlight.elf.dir/MCAL/GPIO.c.obj"
	C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/traficlight.elf.dir/MCAL/GPIO.c.obj -MF CMakeFiles\traficlight.elf.dir\MCAL\GPIO.c.obj.d -o CMakeFiles\traficlight.elf.dir\MCAL\GPIO.c.obj -c "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\MCAL\GPIO.c"

CMakeFiles/traficlight.elf.dir/MCAL/GPIO.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/traficlight.elf.dir/MCAL/GPIO.c.i"
	C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\MCAL\GPIO.c" > CMakeFiles\traficlight.elf.dir\MCAL\GPIO.c.i

CMakeFiles/traficlight.elf.dir/MCAL/GPIO.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/traficlight.elf.dir/MCAL/GPIO.c.s"
	C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\MCAL\GPIO.c" -o CMakeFiles\traficlight.elf.dir\MCAL\GPIO.c.s

CMakeFiles/traficlight.elf.dir/MCAL/TIMER.c.obj: CMakeFiles/traficlight.elf.dir/flags.make
CMakeFiles/traficlight.elf.dir/MCAL/TIMER.c.obj: ../MCAL/TIMER.c
CMakeFiles/traficlight.elf.dir/MCAL/TIMER.c.obj: CMakeFiles/traficlight.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/traficlight.elf.dir/MCAL/TIMER.c.obj"
	C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/traficlight.elf.dir/MCAL/TIMER.c.obj -MF CMakeFiles\traficlight.elf.dir\MCAL\TIMER.c.obj.d -o CMakeFiles\traficlight.elf.dir\MCAL\TIMER.c.obj -c "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\MCAL\TIMER.c"

CMakeFiles/traficlight.elf.dir/MCAL/TIMER.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/traficlight.elf.dir/MCAL/TIMER.c.i"
	C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\MCAL\TIMER.c" > CMakeFiles\traficlight.elf.dir\MCAL\TIMER.c.i

CMakeFiles/traficlight.elf.dir/MCAL/TIMER.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/traficlight.elf.dir/MCAL/TIMER.c.s"
	C:\WinAVR-20100110\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\MCAL\TIMER.c" -o CMakeFiles\traficlight.elf.dir\MCAL\TIMER.c.s

# Object files for target traficlight.elf
traficlight_elf_OBJECTS = \
"CMakeFiles/traficlight.elf.dir/main.c.obj" \
"CMakeFiles/traficlight.elf.dir/MCAL/GPIO.c.obj" \
"CMakeFiles/traficlight.elf.dir/MCAL/TIMER.c.obj"

# External object files for target traficlight.elf
traficlight_elf_EXTERNAL_OBJECTS =

traficlight.elf: CMakeFiles/traficlight.elf.dir/main.c.obj
traficlight.elf: CMakeFiles/traficlight.elf.dir/MCAL/GPIO.c.obj
traficlight.elf: CMakeFiles/traficlight.elf.dir/MCAL/TIMER.c.obj
traficlight.elf: CMakeFiles/traficlight.elf.dir/build.make
traficlight.elf: CMakeFiles/traficlight.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable traficlight.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\traficlight.elf.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/traficlight.elf.dir/build: traficlight.elf
.PHONY : CMakeFiles/traficlight.elf.dir/build

CMakeFiles/traficlight.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\traficlight.elf.dir\cmake_clean.cmake
.PHONY : CMakeFiles/traficlight.elf.dir/clean

CMakeFiles/traficlight.elf.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight" "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight" "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\build" "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\build" "C:\Users\Mohamed Mehery\Documents\GitHub\Udacity-Embedded_systems_profisional\Traficlight\build\CMakeFiles\traficlight.elf.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/traficlight.elf.dir/depend

