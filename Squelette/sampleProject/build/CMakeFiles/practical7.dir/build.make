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
include CMakeFiles/practical7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/practical7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/practical7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/practical7.dir/flags.make

CMakeFiles/practical7.dir/practical7.cpp.o: CMakeFiles/practical7.dir/flags.make
CMakeFiles/practical7.dir/practical7.cpp.o: ../practical7.cpp
CMakeFiles/practical7.dir/practical7.cpp.o: CMakeFiles/practical7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/practical7.dir/practical7.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/practical7.dir/practical7.cpp.o -MF CMakeFiles/practical7.dir/practical7.cpp.o.d -o CMakeFiles/practical7.dir/practical7.cpp.o -c /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/practical7.cpp

CMakeFiles/practical7.dir/practical7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practical7.dir/practical7.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/practical7.cpp > CMakeFiles/practical7.dir/practical7.cpp.i

CMakeFiles/practical7.dir/practical7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practical7.dir/practical7.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/practical7.cpp -o CMakeFiles/practical7.dir/practical7.cpp.s

# Object files for target practical7
practical7_OBJECTS = \
"CMakeFiles/practical7.dir/practical7.cpp.o"

# External object files for target practical7
practical7_EXTERNAL_OBJECTS =

practical7: CMakeFiles/practical7.dir/practical7.cpp.o
practical7: CMakeFiles/practical7.dir/build.make
practical7: ../../sfmlGraphicsPipeline/build/libSFML_GRAPHICS_PIPELINE.a
practical7: /usr/lib/x86_64-linux-gnu/libsfml-system.so
practical7: /usr/lib/x86_64-linux-gnu/libsfml-window.so
practical7: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
practical7: /usr/lib/x86_64-linux-gnu/libGLEW.so
practical7: ../../sfmlGraphicsPipeline/extlib/freetype-2.5.5/build/libfreetype.a
practical7: ../../sfmlGraphicsPipeline/extlib/tinyobjloader/build/libtinyobjloader.a
practical7: /usr/lib/x86_64-linux-gnu/libGL.so
practical7: /usr/lib/x86_64-linux-gnu/libGLU.so
practical7: CMakeFiles/practical7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable practical7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/practical7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/practical7.dir/build: practical7
.PHONY : CMakeFiles/practical7.dir/build

CMakeFiles/practical7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/practical7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/practical7.dir/clean

CMakeFiles/practical7.dir/depend:
	cd /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build/CMakeFiles/practical7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/practical7.dir/depend

