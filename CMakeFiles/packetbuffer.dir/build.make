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
include CMakeFiles/packetbuffer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/packetbuffer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/packetbuffer.dir/flags.make

CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o: CMakeFiles/packetbuffer.dir/flags.make
CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o: src/packetbuffer/packetbuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o -c /home/nvidia/Documents/sb7code-master/src/packetbuffer/packetbuffer.cpp

CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvidia/Documents/sb7code-master/src/packetbuffer/packetbuffer.cpp > CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.i

CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvidia/Documents/sb7code-master/src/packetbuffer/packetbuffer.cpp -o CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.s

CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o.requires:

.PHONY : CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o.requires

CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o.provides: CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o.requires
	$(MAKE) -f CMakeFiles/packetbuffer.dir/build.make CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o.provides.build
.PHONY : CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o.provides

CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o.provides.build: CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o


# Object files for target packetbuffer
packetbuffer_OBJECTS = \
"CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o"

# External object files for target packetbuffer
packetbuffer_EXTERNAL_OBJECTS =

bin/packetbuffer: CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o
bin/packetbuffer: CMakeFiles/packetbuffer.dir/build.make
bin/packetbuffer: lib/libsb7.a
bin/packetbuffer: CMakeFiles/packetbuffer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nvidia/Documents/sb7code-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/packetbuffer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/packetbuffer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/packetbuffer.dir/build: bin/packetbuffer

.PHONY : CMakeFiles/packetbuffer.dir/build

CMakeFiles/packetbuffer.dir/requires: CMakeFiles/packetbuffer.dir/src/packetbuffer/packetbuffer.cpp.o.requires

.PHONY : CMakeFiles/packetbuffer.dir/requires

CMakeFiles/packetbuffer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/packetbuffer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/packetbuffer.dir/clean

CMakeFiles/packetbuffer.dir/depend:
	cd /home/nvidia/Documents/sb7code-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master /home/nvidia/Documents/sb7code-master/CMakeFiles/packetbuffer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/packetbuffer.dir/depend
