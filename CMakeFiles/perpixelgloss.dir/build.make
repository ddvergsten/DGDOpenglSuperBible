# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nvidia/Documents/sb7code-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nvidia/Documents/sb7code-master

# Include any dependencies generated for this target.
include CMakeFiles/perpixelgloss.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/perpixelgloss.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/perpixelgloss.dir/flags.make

CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o: CMakeFiles/perpixelgloss.dir/flags.make
CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o: src/perpixelgloss/perpixelgloss.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o -c /home/nvidia/Documents/sb7code-master/src/perpixelgloss/perpixelgloss.cpp

CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvidia/Documents/sb7code-master/src/perpixelgloss/perpixelgloss.cpp > CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.i

CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvidia/Documents/sb7code-master/src/perpixelgloss/perpixelgloss.cpp -o CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.s

CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o.requires:

.PHONY : CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o.requires

CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o.provides: CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o.requires
	$(MAKE) -f CMakeFiles/perpixelgloss.dir/build.make CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o.provides.build
.PHONY : CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o.provides

CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o.provides.build: CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o


# Object files for target perpixelgloss
perpixelgloss_OBJECTS = \
"CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o"

# External object files for target perpixelgloss
perpixelgloss_EXTERNAL_OBJECTS =

bin/perpixelgloss: CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o
bin/perpixelgloss: CMakeFiles/perpixelgloss.dir/build.make
bin/perpixelgloss: lib/libsb7.a
bin/perpixelgloss: CMakeFiles/perpixelgloss.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/perpixelgloss"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/perpixelgloss.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/perpixelgloss.dir/build: bin/perpixelgloss

.PHONY : CMakeFiles/perpixelgloss.dir/build

CMakeFiles/perpixelgloss.dir/requires: CMakeFiles/perpixelgloss.dir/src/perpixelgloss/perpixelgloss.cpp.o.requires

.PHONY : CMakeFiles/perpixelgloss.dir/requires

CMakeFiles/perpixelgloss.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/perpixelgloss.dir/cmake_clean.cmake
.PHONY : CMakeFiles/perpixelgloss.dir/clean

CMakeFiles/perpixelgloss.dir/depend:
	cd /home/nvidia/Documents/sb7code-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master/CMakeFiles/perpixelgloss.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/perpixelgloss.dir/depend

