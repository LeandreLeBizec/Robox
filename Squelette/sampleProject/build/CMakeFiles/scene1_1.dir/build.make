# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build

# Include any dependencies generated for this target.
include CMakeFiles/scene1_1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/scene1_1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/scene1_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scene1_1.dir/flags.make

CMakeFiles/scene1_1.dir/scene1_1.cpp.o: CMakeFiles/scene1_1.dir/flags.make
CMakeFiles/scene1_1.dir/scene1_1.cpp.o: ../scene1_1.cpp
CMakeFiles/scene1_1.dir/scene1_1.cpp.o: CMakeFiles/scene1_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/scene1_1.dir/scene1_1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/scene1_1.dir/scene1_1.cpp.o -MF CMakeFiles/scene1_1.dir/scene1_1.cpp.o.d -o CMakeFiles/scene1_1.dir/scene1_1.cpp.o -c /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/scene1_1.cpp

CMakeFiles/scene1_1.dir/scene1_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scene1_1.dir/scene1_1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/scene1_1.cpp > CMakeFiles/scene1_1.dir/scene1_1.cpp.i

CMakeFiles/scene1_1.dir/scene1_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scene1_1.dir/scene1_1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/scene1_1.cpp -o CMakeFiles/scene1_1.dir/scene1_1.cpp.s

# Object files for target scene1_1
scene1_1_OBJECTS = \
"CMakeFiles/scene1_1.dir/scene1_1.cpp.o"

# External object files for target scene1_1
scene1_1_EXTERNAL_OBJECTS =

scene1_1: CMakeFiles/scene1_1.dir/scene1_1.cpp.o
scene1_1: CMakeFiles/scene1_1.dir/build.make
scene1_1: ../../sfmlGraphicsPipeline/build/libSFML_GRAPHICS_PIPELINE.a
scene1_1: /usr/lib/x86_64-linux-gnu/libsfml-system.so
scene1_1: /usr/lib/x86_64-linux-gnu/libsfml-window.so
scene1_1: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
scene1_1: /usr/lib/x86_64-linux-gnu/libGLEW.so
scene1_1: ../../sfmlGraphicsPipeline/extlib/freetype-2.5.5/build/libfreetype.a
scene1_1: ../../sfmlGraphicsPipeline/extlib/tinyobjloader/build/libtinyobjloader.a
scene1_1: /usr/lib/x86_64-linux-gnu/libGL.so
scene1_1: /usr/lib/x86_64-linux-gnu/libGLU.so
scene1_1: CMakeFiles/scene1_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable scene1_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scene1_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scene1_1.dir/build: scene1_1
.PHONY : CMakeFiles/scene1_1.dir/build

CMakeFiles/scene1_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/scene1_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/scene1_1.dir/clean

CMakeFiles/scene1_1.dir/depend:
	cd /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build/CMakeFiles/scene1_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/scene1_1.dir/depend

