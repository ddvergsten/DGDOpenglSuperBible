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
include CMakeFiles/wrapmodes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wrapmodes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wrapmodes.dir/flags.make

CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o: CMakeFiles/wrapmodes.dir/flags.make
CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o: src/wrapmodes/wrapmodes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o -c /home/nvidia/Documents/sb7code-master/src/wrapmodes/wrapmodes.cpp

CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvidia/Documents/sb7code-master/src/wrapmodes/wrapmodes.cpp > CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.i

CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvidia/Documents/sb7code-master/src/wrapmodes/wrapmodes.cpp -o CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.s

CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o.requires:

.PHONY : CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o.requires

CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o.provides: CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o.requires
	$(MAKE) -f CMakeFiles/wrapmodes.dir/build.make CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o.provides.build
.PHONY : CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o.provides

CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o.provides.build: CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o


# Object files for target wrapmodes
wrapmodes_OBJECTS = \
"CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o"

# External object files for target wrapmodes
wrapmodes_EXTERNAL_OBJECTS =

bin/wrapmodes: CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o
bin/wrapmodes: CMakeFiles/wrapmodes.dir/build.make
bin/wrapmodes: lib/libsb7.a
bin/wrapmodes: CMakeFiles/wrapmodes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/wrapmodes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wrapmodes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wrapmodes.dir/build: bin/wrapmodes

.PHONY : CMakeFiles/wrapmodes.dir/build

CMakeFiles/wrapmodes.dir/requires: CMakeFiles/wrapmodes.dir/src/wrapmodes/wrapmodes.cpp.o.requires

.PHONY : CMakeFiles/wrapmodes.dir/requires

CMakeFiles/wrapmodes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wrapmodes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wrapmodes.dir/clean

CMakeFiles/wrapmodes.dir/depend:
	cd /home/nvidia/Documents/sb7code-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master/CMakeFiles/wrapmodes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wrapmodes.dir/depend

