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
include CMakeFiles/grass.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/grass.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/grass.dir/flags.make

CMakeFiles/grass.dir/src/grass/grass.cpp.o: CMakeFiles/grass.dir/flags.make
CMakeFiles/grass.dir/src/grass/grass.cpp.o: src/grass/grass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/grass.dir/src/grass/grass.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/grass.dir/src/grass/grass.cpp.o -c /home/nvidia/Documents/sb7code-master/src/grass/grass.cpp

CMakeFiles/grass.dir/src/grass/grass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/grass.dir/src/grass/grass.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvidia/Documents/sb7code-master/src/grass/grass.cpp > CMakeFiles/grass.dir/src/grass/grass.cpp.i

CMakeFiles/grass.dir/src/grass/grass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/grass.dir/src/grass/grass.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvidia/Documents/sb7code-master/src/grass/grass.cpp -o CMakeFiles/grass.dir/src/grass/grass.cpp.s

CMakeFiles/grass.dir/src/grass/grass.cpp.o.requires:

.PHONY : CMakeFiles/grass.dir/src/grass/grass.cpp.o.requires

CMakeFiles/grass.dir/src/grass/grass.cpp.o.provides: CMakeFiles/grass.dir/src/grass/grass.cpp.o.requires
	$(MAKE) -f CMakeFiles/grass.dir/build.make CMakeFiles/grass.dir/src/grass/grass.cpp.o.provides.build
.PHONY : CMakeFiles/grass.dir/src/grass/grass.cpp.o.provides

CMakeFiles/grass.dir/src/grass/grass.cpp.o.provides.build: CMakeFiles/grass.dir/src/grass/grass.cpp.o


# Object files for target grass
grass_OBJECTS = \
"CMakeFiles/grass.dir/src/grass/grass.cpp.o"

# External object files for target grass
grass_EXTERNAL_OBJECTS =

bin/grass: CMakeFiles/grass.dir/src/grass/grass.cpp.o
bin/grass: CMakeFiles/grass.dir/build.make
bin/grass: lib/libsb7.a
bin/grass: CMakeFiles/grass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/grass"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/grass.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/grass.dir/build: bin/grass

.PHONY : CMakeFiles/grass.dir/build

CMakeFiles/grass.dir/requires: CMakeFiles/grass.dir/src/grass/grass.cpp.o.requires

.PHONY : CMakeFiles/grass.dir/requires

CMakeFiles/grass.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/grass.dir/cmake_clean.cmake
.PHONY : CMakeFiles/grass.dir/clean

CMakeFiles/grass.dir/depend:
	cd /home/nvidia/Documents/sb7code-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master/CMakeFiles/grass.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/grass.dir/depend

