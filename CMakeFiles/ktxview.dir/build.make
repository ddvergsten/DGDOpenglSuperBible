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
include CMakeFiles/ktxview.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ktxview.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ktxview.dir/flags.make

CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o: CMakeFiles/ktxview.dir/flags.make
CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o: src/ktxview/ktxview.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o -c /home/nvidia/Documents/sb7code-master/src/ktxview/ktxview.cpp

CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvidia/Documents/sb7code-master/src/ktxview/ktxview.cpp > CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.i

CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvidia/Documents/sb7code-master/src/ktxview/ktxview.cpp -o CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.s

CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o.requires:

.PHONY : CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o.requires

CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o.provides: CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o.requires
	$(MAKE) -f CMakeFiles/ktxview.dir/build.make CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o.provides.build
.PHONY : CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o.provides

CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o.provides.build: CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o


# Object files for target ktxview
ktxview_OBJECTS = \
"CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o"

# External object files for target ktxview
ktxview_EXTERNAL_OBJECTS =

bin/ktxview: CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o
bin/ktxview: CMakeFiles/ktxview.dir/build.make
bin/ktxview: lib/libsb7.a
bin/ktxview: CMakeFiles/ktxview.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/ktxview"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ktxview.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ktxview.dir/build: bin/ktxview

.PHONY : CMakeFiles/ktxview.dir/build

CMakeFiles/ktxview.dir/requires: CMakeFiles/ktxview.dir/src/ktxview/ktxview.cpp.o.requires

.PHONY : CMakeFiles/ktxview.dir/requires

CMakeFiles/ktxview.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ktxview.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ktxview.dir/clean

CMakeFiles/ktxview.dir/depend:
	cd /home/nvidia/Documents/sb7code-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master/CMakeFiles/ktxview.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ktxview.dir/depend
