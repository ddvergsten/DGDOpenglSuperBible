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
include CMakeFiles/tessellatedtri.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tessellatedtri.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tessellatedtri.dir/flags.make

CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o: CMakeFiles/tessellatedtri.dir/flags.make
CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o: src/tessellatedtri/tessellatedtri.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o -c /home/nvidia/Documents/sb7code-master/src/tessellatedtri/tessellatedtri.cpp

CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvidia/Documents/sb7code-master/src/tessellatedtri/tessellatedtri.cpp > CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.i

CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvidia/Documents/sb7code-master/src/tessellatedtri/tessellatedtri.cpp -o CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.s

CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o.requires:

.PHONY : CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o.requires

CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o.provides: CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o.requires
	$(MAKE) -f CMakeFiles/tessellatedtri.dir/build.make CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o.provides.build
.PHONY : CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o.provides

CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o.provides.build: CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o


# Object files for target tessellatedtri
tessellatedtri_OBJECTS = \
"CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o"

# External object files for target tessellatedtri
tessellatedtri_EXTERNAL_OBJECTS =

bin/tessellatedtri: CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o
bin/tessellatedtri: CMakeFiles/tessellatedtri.dir/build.make
bin/tessellatedtri: lib/libsb7.a
bin/tessellatedtri: CMakeFiles/tessellatedtri.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/tessellatedtri"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tessellatedtri.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tessellatedtri.dir/build: bin/tessellatedtri

.PHONY : CMakeFiles/tessellatedtri.dir/build

CMakeFiles/tessellatedtri.dir/requires: CMakeFiles/tessellatedtri.dir/src/tessellatedtri/tessellatedtri.cpp.o.requires

.PHONY : CMakeFiles/tessellatedtri.dir/requires

CMakeFiles/tessellatedtri.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tessellatedtri.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tessellatedtri.dir/clean

CMakeFiles/tessellatedtri.dir/depend:
	cd /home/nvidia/Documents/sb7code-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master/CMakeFiles/tessellatedtri.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tessellatedtri.dir/depend
