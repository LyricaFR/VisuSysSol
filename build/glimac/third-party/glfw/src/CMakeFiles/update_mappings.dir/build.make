# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/lib/python3.9/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.9/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/2ing2/dejesusmilitar/Documents/S1/OTHER/GLImac-Template 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/2ing2/dejesusmilitar/Documents/S1/OTHER/GLImac-Template 2/build"

# Utility rule file for update_mappings.

# Include any custom commands dependencies for this target.
include glimac/third-party/glfw/src/CMakeFiles/update_mappings.dir/compiler_depend.make

# Include the progress variables for this target.
include glimac/third-party/glfw/src/CMakeFiles/update_mappings.dir/progress.make

glimac/third-party/glfw/src/CMakeFiles/update_mappings:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/2ing2/dejesusmilitar/Documents/S1/OTHER/GLImac-Template 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Updating gamepad mappings from upstream repository"
	cd "/home/2ing2/dejesusmilitar/Documents/S1/OTHER/GLImac-Template 2/glimac/third-party/glfw/src" && /usr/local/lib/python3.9/dist-packages/cmake/data/bin/cmake -P "/home/2ing2/dejesusmilitar/Documents/S1/OTHER/GLImac-Template 2/glimac/third-party/glfw/CMake/GenerateMappings.cmake" mappings.h.in mappings.h

update_mappings: glimac/third-party/glfw/src/CMakeFiles/update_mappings
update_mappings: glimac/third-party/glfw/src/CMakeFiles/update_mappings.dir/build.make
.PHONY : update_mappings

# Rule to build all files generated by this target.
glimac/third-party/glfw/src/CMakeFiles/update_mappings.dir/build: update_mappings
.PHONY : glimac/third-party/glfw/src/CMakeFiles/update_mappings.dir/build

glimac/third-party/glfw/src/CMakeFiles/update_mappings.dir/clean:
	cd "/home/2ing2/dejesusmilitar/Documents/S1/OTHER/GLImac-Template 2/build/glimac/third-party/glfw/src" && $(CMAKE_COMMAND) -P CMakeFiles/update_mappings.dir/cmake_clean.cmake
.PHONY : glimac/third-party/glfw/src/CMakeFiles/update_mappings.dir/clean

glimac/third-party/glfw/src/CMakeFiles/update_mappings.dir/depend:
	cd "/home/2ing2/dejesusmilitar/Documents/S1/OTHER/GLImac-Template 2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/2ing2/dejesusmilitar/Documents/S1/OTHER/GLImac-Template 2" "/home/2ing2/dejesusmilitar/Documents/S1/OTHER/GLImac-Template 2/glimac/third-party/glfw/src" "/home/2ing2/dejesusmilitar/Documents/S1/OTHER/GLImac-Template 2/build" "/home/2ing2/dejesusmilitar/Documents/S1/OTHER/GLImac-Template 2/build/glimac/third-party/glfw/src" "/home/2ing2/dejesusmilitar/Documents/S1/OTHER/GLImac-Template 2/build/glimac/third-party/glfw/src/CMakeFiles/update_mappings.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : glimac/third-party/glfw/src/CMakeFiles/update_mappings.dir/depend

