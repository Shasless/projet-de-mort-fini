# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/adriengirard/Downloads/projetdemort-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/adriengirard/Downloads/projetdemort-master/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Projet1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Projet1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projet1.dir/flags.make

CMakeFiles/Projet1.dir/main.c.o: CMakeFiles/Projet1.dir/flags.make
CMakeFiles/Projet1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adriengirard/Downloads/projetdemort-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Projet1.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Projet1.dir/main.c.o   -c /Users/adriengirard/Downloads/projetdemort-master/main.c

CMakeFiles/Projet1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projet1.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/adriengirard/Downloads/projetdemort-master/main.c > CMakeFiles/Projet1.dir/main.c.i

CMakeFiles/Projet1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projet1.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/adriengirard/Downloads/projetdemort-master/main.c -o CMakeFiles/Projet1.dir/main.c.s

# Object files for target Projet1
Projet1_OBJECTS = \
"CMakeFiles/Projet1.dir/main.c.o"

# External object files for target Projet1
Projet1_EXTERNAL_OBJECTS =

Projet1: CMakeFiles/Projet1.dir/main.c.o
Projet1: CMakeFiles/Projet1.dir/build.make
Projet1: CMakeFiles/Projet1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/adriengirard/Downloads/projetdemort-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Projet1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projet1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projet1.dir/build: Projet1

.PHONY : CMakeFiles/Projet1.dir/build

CMakeFiles/Projet1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projet1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projet1.dir/clean

CMakeFiles/Projet1.dir/depend:
	cd /Users/adriengirard/Downloads/projetdemort-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/adriengirard/Downloads/projetdemort-master /Users/adriengirard/Downloads/projetdemort-master /Users/adriengirard/Downloads/projetdemort-master/cmake-build-debug /Users/adriengirard/Downloads/projetdemort-master/cmake-build-debug /Users/adriengirard/Downloads/projetdemort-master/cmake-build-debug/CMakeFiles/Projet1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projet1.dir/depend
