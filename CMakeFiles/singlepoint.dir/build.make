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
include CMakeFiles/singlepoint.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/singlepoint.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/singlepoint.dir/flags.make

CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o: CMakeFiles/singlepoint.dir/flags.make
CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o: src/singlepoint/singlepoint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o -c /home/nvidia/Documents/sb7code-master/src/singlepoint/singlepoint.cpp

CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvidia/Documents/sb7code-master/src/singlepoint/singlepoint.cpp > CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.i

CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvidia/Documents/sb7code-master/src/singlepoint/singlepoint.cpp -o CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.s

CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o.requires:

.PHONY : CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o.requires

CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o.provides: CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o.requires
	$(MAKE) -f CMakeFiles/singlepoint.dir/build.make CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o.provides.build
.PHONY : CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o.provides

CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o.provides.build: CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o


# Object files for target singlepoint
singlepoint_OBJECTS = \
"CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o"

# External object files for target singlepoint
singlepoint_EXTERNAL_OBJECTS =

bin/singlepoint: CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o
bin/singlepoint: CMakeFiles/singlepoint.dir/build.make
bin/singlepoint: lib/libsb7.a
bin/singlepoint: CMakeFiles/singlepoint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/singlepoint"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/singlepoint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/singlepoint.dir/build: bin/singlepoint

.PHONY : CMakeFiles/singlepoint.dir/build

CMakeFiles/singlepoint.dir/requires: CMakeFiles/singlepoint.dir/src/singlepoint/singlepoint.cpp.o.requires

.PHONY : CMakeFiles/singlepoint.dir/requires

CMakeFiles/singlepoint.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/singlepoint.dir/cmake_clean.cmake
.PHONY : CMakeFiles/singlepoint.dir/clean

CMakeFiles/singlepoint.dir/depend:
	cd /home/nvidia/Documents/sb7code-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master/CMakeFiles/singlepoint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/singlepoint.dir/depend
