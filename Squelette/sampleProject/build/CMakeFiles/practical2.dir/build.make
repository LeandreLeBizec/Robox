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
include CMakeFiles/practical2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/practical2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/practical2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/practical2.dir/flags.make

CMakeFiles/practical2.dir/practical2.cpp.o: CMakeFiles/practical2.dir/flags.make
CMakeFiles/practical2.dir/practical2.cpp.o: ../practical2.cpp
CMakeFiles/practical2.dir/practical2.cpp.o: CMakeFiles/practical2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/practical2.dir/practical2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/practical2.dir/practical2.cpp.o -MF CMakeFiles/practical2.dir/practical2.cpp.o.d -o CMakeFiles/practical2.dir/practical2.cpp.o -c /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/practical2.cpp

CMakeFiles/practical2.dir/practical2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practical2.dir/practical2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/practical2.cpp > CMakeFiles/practical2.dir/practical2.cpp.i

CMakeFiles/practical2.dir/practical2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practical2.dir/practical2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/practical2.cpp -o CMakeFiles/practical2.dir/practical2.cpp.s

# Object files for target practical2
practical2_OBJECTS = \
"CMakeFiles/practical2.dir/practical2.cpp.o"

# External object files for target practical2
practical2_EXTERNAL_OBJECTS =

practical2: CMakeFiles/practical2.dir/practical2.cpp.o
practical2: CMakeFiles/practical2.dir/build.make
practical2: ../../sfmlGraphicsPipeline/build/libSFML_GRAPHICS_PIPELINE.a
practical2: /usr/lib/x86_64-linux-gnu/libsfml-system.so
practical2: /usr/lib/x86_64-linux-gnu/libsfml-window.so
practical2: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
practical2: /usr/lib/x86_64-linux-gnu/libGLEW.so
practical2: ../../sfmlGraphicsPipeline/extlib/freetype-2.5.5/build/libfreetype.a
practical2: ../../sfmlGraphicsPipeline/extlib/tinyobjloader/build/libtinyobjloader.a
practical2: /usr/lib/x86_64-linux-gnu/libGL.so
practical2: /usr/lib/x86_64-linux-gnu/libGLU.so
practical2: CMakeFiles/practical2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable practical2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/practical2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/practical2.dir/build: practical2
.PHONY : CMakeFiles/practical2.dir/build

CMakeFiles/practical2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/practical2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/practical2.dir/clean

CMakeFiles/practical2.dir/depend:
	cd /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build /home/leandre/Info/4a/TP_IG/robox/Squelette/sampleProject/build/CMakeFiles/practical2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/practical2.dir/depend
