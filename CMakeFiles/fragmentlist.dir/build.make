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
include CMakeFiles/fragmentlist.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fragmentlist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fragmentlist.dir/flags.make

CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o: CMakeFiles/fragmentlist.dir/flags.make
CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o: src/fragmentlist/fragmentlist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o -c /home/nvidia/Documents/sb7code-master/src/fragmentlist/fragmentlist.cpp

CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvidia/Documents/sb7code-master/src/fragmentlist/fragmentlist.cpp > CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.i

CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvidia/Documents/sb7code-master/src/fragmentlist/fragmentlist.cpp -o CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.s

CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o.requires:

.PHONY : CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o.requires

CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o.provides: CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o.requires
	$(MAKE) -f CMakeFiles/fragmentlist.dir/build.make CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o.provides.build
.PHONY : CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o.provides

CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o.provides.build: CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o


# Object files for target fragmentlist
fragmentlist_OBJECTS = \
"CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o"

# External object files for target fragmentlist
fragmentlist_EXTERNAL_OBJECTS =

bin/fragmentlist: CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o
bin/fragmentlist: CMakeFiles/fragmentlist.dir/build.make
bin/fragmentlist: lib/libsb7.a
bin/fragmentlist: CMakeFiles/fragmentlist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/fragmentlist"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fragmentlist.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fragmentlist.dir/build: bin/fragmentlist

.PHONY : CMakeFiles/fragmentlist.dir/build

CMakeFiles/fragmentlist.dir/requires: CMakeFiles/fragmentlist.dir/src/fragmentlist/fragmentlist.cpp.o.requires

.PHONY : CMakeFiles/fragmentlist.dir/requires

CMakeFiles/fragmentlist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fragmentlist.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fragmentlist.dir/clean

CMakeFiles/fragmentlist.dir/depend:
	cd /home/nvidia/Documents/sb7code-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master/CMakeFiles/fragmentlist.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fragmentlist.dir/depend
