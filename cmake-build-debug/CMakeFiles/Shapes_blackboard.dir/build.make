# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anastasia_d/CLionProjects/Shapes-blackboard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anastasia_d/CLionProjects/Shapes-blackboard/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Shapes_blackboard.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Shapes_blackboard.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Shapes_blackboard.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Shapes_blackboard.dir/flags.make

CMakeFiles/Shapes_blackboard.dir/main.cpp.o: CMakeFiles/Shapes_blackboard.dir/flags.make
CMakeFiles/Shapes_blackboard.dir/main.cpp.o: /Users/anastasia_d/CLionProjects/Shapes-blackboard/main.cpp
CMakeFiles/Shapes_blackboard.dir/main.cpp.o: CMakeFiles/Shapes_blackboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anastasia_d/CLionProjects/Shapes-blackboard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Shapes_blackboard.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shapes_blackboard.dir/main.cpp.o -MF CMakeFiles/Shapes_blackboard.dir/main.cpp.o.d -o CMakeFiles/Shapes_blackboard.dir/main.cpp.o -c /Users/anastasia_d/CLionProjects/Shapes-blackboard/main.cpp

CMakeFiles/Shapes_blackboard.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shapes_blackboard.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anastasia_d/CLionProjects/Shapes-blackboard/main.cpp > CMakeFiles/Shapes_blackboard.dir/main.cpp.i

CMakeFiles/Shapes_blackboard.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shapes_blackboard.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anastasia_d/CLionProjects/Shapes-blackboard/main.cpp -o CMakeFiles/Shapes_blackboard.dir/main.cpp.s

# Object files for target Shapes_blackboard
Shapes_blackboard_OBJECTS = \
"CMakeFiles/Shapes_blackboard.dir/main.cpp.o"

# External object files for target Shapes_blackboard
Shapes_blackboard_EXTERNAL_OBJECTS =

Shapes_blackboard: CMakeFiles/Shapes_blackboard.dir/main.cpp.o
Shapes_blackboard: CMakeFiles/Shapes_blackboard.dir/build.make
Shapes_blackboard: CMakeFiles/Shapes_blackboard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/anastasia_d/CLionProjects/Shapes-blackboard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Shapes_blackboard"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Shapes_blackboard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Shapes_blackboard.dir/build: Shapes_blackboard
.PHONY : CMakeFiles/Shapes_blackboard.dir/build

CMakeFiles/Shapes_blackboard.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Shapes_blackboard.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Shapes_blackboard.dir/clean

CMakeFiles/Shapes_blackboard.dir/depend:
	cd /Users/anastasia_d/CLionProjects/Shapes-blackboard/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anastasia_d/CLionProjects/Shapes-blackboard /Users/anastasia_d/CLionProjects/Shapes-blackboard /Users/anastasia_d/CLionProjects/Shapes-blackboard/cmake-build-debug /Users/anastasia_d/CLionProjects/Shapes-blackboard/cmake-build-debug /Users/anastasia_d/CLionProjects/Shapes-blackboard/cmake-build-debug/CMakeFiles/Shapes_blackboard.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Shapes_blackboard.dir/depend

