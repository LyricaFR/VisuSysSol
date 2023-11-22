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
CMAKE_SOURCE_DIR = "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build"

# Include any dependencies generated for this target.
include glimac/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glimac/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include glimac/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include glimac/CMakeFiles/glad.dir/flags.make

glimac/CMakeFiles/glad.dir/third-party/glad/src/glad.c.o: glimac/CMakeFiles/glad.dir/flags.make
glimac/CMakeFiles/glad.dir/third-party/glad/src/glad.c.o: /home/2ing2/dejesusmilitar/Documents/S1/Computer\ Graphics/VisuSysSol/glimac/third-party/glad/src/glad.c
glimac/CMakeFiles/glad.dir/third-party/glad/src/glad.c.o: glimac/CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object glimac/CMakeFiles/glad.dir/third-party/glad/src/glad.c.o"
	cd "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build/glimac" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glimac/CMakeFiles/glad.dir/third-party/glad/src/glad.c.o -MF CMakeFiles/glad.dir/third-party/glad/src/glad.c.o.d -o CMakeFiles/glad.dir/third-party/glad/src/glad.c.o -c "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/glimac/third-party/glad/src/glad.c"

glimac/CMakeFiles/glad.dir/third-party/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/third-party/glad/src/glad.c.i"
	cd "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build/glimac" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/glimac/third-party/glad/src/glad.c" > CMakeFiles/glad.dir/third-party/glad/src/glad.c.i

glimac/CMakeFiles/glad.dir/third-party/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/third-party/glad/src/glad.c.s"
	cd "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build/glimac" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/glimac/third-party/glad/src/glad.c" -o CMakeFiles/glad.dir/third-party/glad/src/glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/third-party/glad/src/glad.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

glimac/libglad.a: glimac/CMakeFiles/glad.dir/third-party/glad/src/glad.c.o
glimac/libglad.a: glimac/CMakeFiles/glad.dir/build.make
glimac/libglad.a: glimac/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglad.a"
	cd "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build/glimac" && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build/glimac" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glimac/CMakeFiles/glad.dir/build: glimac/libglad.a
.PHONY : glimac/CMakeFiles/glad.dir/build

glimac/CMakeFiles/glad.dir/clean:
	cd "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build/glimac" && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : glimac/CMakeFiles/glad.dir/clean

glimac/CMakeFiles/glad.dir/depend:
	cd "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol" "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/glimac" "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build" "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build/glimac" "/home/2ing2/dejesusmilitar/Documents/S1/Computer Graphics/VisuSysSol/build/glimac/CMakeFiles/glad.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : glimac/CMakeFiles/glad.dir/depend

