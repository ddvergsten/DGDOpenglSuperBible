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
include CMakeFiles/indexedcube.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/indexedcube.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/indexedcube.dir/flags.make

CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o: CMakeFiles/indexedcube.dir/flags.make
CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o: src/indexedcube/indexedcube.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o -c /home/nvidia/Documents/sb7code-master/src/indexedcube/indexedcube.cpp

CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvidia/Documents/sb7code-master/src/indexedcube/indexedcube.cpp > CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.i

CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvidia/Documents/sb7code-master/src/indexedcube/indexedcube.cpp -o CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.s

CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o.requires:

.PHONY : CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o.requires

CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o.provides: CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o.requires
	$(MAKE) -f CMakeFiles/indexedcube.dir/build.make CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o.provides.build
.PHONY : CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o.provides

CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o.provides.build: CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o


# Object files for target indexedcube
indexedcube_OBJECTS = \
"CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o"

# External object files for target indexedcube
indexedcube_EXTERNAL_OBJECTS =

bin/indexedcube: CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o
bin/indexedcube: CMakeFiles/indexedcube.dir/build.make
bin/indexedcube: lib/libsb7.a
bin/indexedcube: CMakeFiles/indexedcube.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/indexedcube"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/indexedcube.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/indexedcube.dir/build: bin/indexedcube

.PHONY : CMakeFiles/indexedcube.dir/build

CMakeFiles/indexedcube.dir/requires: CMakeFiles/indexedcube.dir/src/indexedcube/indexedcube.cpp.o.requires

.PHONY : CMakeFiles/indexedcube.dir/requires

CMakeFiles/indexedcube.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/indexedcube.dir/cmake_clean.cmake
.PHONY : CMakeFiles/indexedcube.dir/clean

CMakeFiles/indexedcube.dir/depend:
	cd /home/nvidia/Documents/sb7code-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master/CMakeFiles/indexedcube.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/indexedcube.dir/depend

