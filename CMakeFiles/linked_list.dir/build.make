# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/derevyanko/univer/algo&DS/linked_list"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/derevyanko/univer/algo&DS/linked_list"

# Include any dependencies generated for this target.
include CMakeFiles/linked_list.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/linked_list.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/linked_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linked_list.dir/flags.make

CMakeFiles/linked_list.dir/main.cpp.o: CMakeFiles/linked_list.dir/flags.make
CMakeFiles/linked_list.dir/main.cpp.o: main.cpp
CMakeFiles/linked_list.dir/main.cpp.o: CMakeFiles/linked_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/derevyanko/univer/algo&DS/linked_list/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linked_list.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linked_list.dir/main.cpp.o -MF CMakeFiles/linked_list.dir/main.cpp.o.d -o CMakeFiles/linked_list.dir/main.cpp.o -c "/Users/derevyanko/univer/algo&DS/linked_list/main.cpp"

CMakeFiles/linked_list.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linked_list.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/derevyanko/univer/algo&DS/linked_list/main.cpp" > CMakeFiles/linked_list.dir/main.cpp.i

CMakeFiles/linked_list.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linked_list.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/derevyanko/univer/algo&DS/linked_list/main.cpp" -o CMakeFiles/linked_list.dir/main.cpp.s

CMakeFiles/linked_list.dir/readFunctions.cpp.o: CMakeFiles/linked_list.dir/flags.make
CMakeFiles/linked_list.dir/readFunctions.cpp.o: readFunctions.cpp
CMakeFiles/linked_list.dir/readFunctions.cpp.o: CMakeFiles/linked_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/derevyanko/univer/algo&DS/linked_list/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/linked_list.dir/readFunctions.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linked_list.dir/readFunctions.cpp.o -MF CMakeFiles/linked_list.dir/readFunctions.cpp.o.d -o CMakeFiles/linked_list.dir/readFunctions.cpp.o -c "/Users/derevyanko/univer/algo&DS/linked_list/readFunctions.cpp"

CMakeFiles/linked_list.dir/readFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linked_list.dir/readFunctions.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/derevyanko/univer/algo&DS/linked_list/readFunctions.cpp" > CMakeFiles/linked_list.dir/readFunctions.cpp.i

CMakeFiles/linked_list.dir/readFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linked_list.dir/readFunctions.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/derevyanko/univer/algo&DS/linked_list/readFunctions.cpp" -o CMakeFiles/linked_list.dir/readFunctions.cpp.s

CMakeFiles/linked_list.dir/writeFunctions.cpp.o: CMakeFiles/linked_list.dir/flags.make
CMakeFiles/linked_list.dir/writeFunctions.cpp.o: writeFunctions.cpp
CMakeFiles/linked_list.dir/writeFunctions.cpp.o: CMakeFiles/linked_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/derevyanko/univer/algo&DS/linked_list/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/linked_list.dir/writeFunctions.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linked_list.dir/writeFunctions.cpp.o -MF CMakeFiles/linked_list.dir/writeFunctions.cpp.o.d -o CMakeFiles/linked_list.dir/writeFunctions.cpp.o -c "/Users/derevyanko/univer/algo&DS/linked_list/writeFunctions.cpp"

CMakeFiles/linked_list.dir/writeFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linked_list.dir/writeFunctions.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/derevyanko/univer/algo&DS/linked_list/writeFunctions.cpp" > CMakeFiles/linked_list.dir/writeFunctions.cpp.i

CMakeFiles/linked_list.dir/writeFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linked_list.dir/writeFunctions.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/derevyanko/univer/algo&DS/linked_list/writeFunctions.cpp" -o CMakeFiles/linked_list.dir/writeFunctions.cpp.s

# Object files for target linked_list
linked_list_OBJECTS = \
"CMakeFiles/linked_list.dir/main.cpp.o" \
"CMakeFiles/linked_list.dir/readFunctions.cpp.o" \
"CMakeFiles/linked_list.dir/writeFunctions.cpp.o"

# External object files for target linked_list
linked_list_EXTERNAL_OBJECTS =

linked_list: CMakeFiles/linked_list.dir/main.cpp.o
linked_list: CMakeFiles/linked_list.dir/readFunctions.cpp.o
linked_list: CMakeFiles/linked_list.dir/writeFunctions.cpp.o
linked_list: CMakeFiles/linked_list.dir/build.make
linked_list: CMakeFiles/linked_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/derevyanko/univer/algo&DS/linked_list/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable linked_list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linked_list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linked_list.dir/build: linked_list
.PHONY : CMakeFiles/linked_list.dir/build

CMakeFiles/linked_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linked_list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linked_list.dir/clean

CMakeFiles/linked_list.dir/depend:
	cd "/Users/derevyanko/univer/algo&DS/linked_list" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/derevyanko/univer/algo&DS/linked_list" "/Users/derevyanko/univer/algo&DS/linked_list" "/Users/derevyanko/univer/algo&DS/linked_list" "/Users/derevyanko/univer/algo&DS/linked_list" "/Users/derevyanko/univer/algo&DS/linked_list/CMakeFiles/linked_list.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/linked_list.dir/depend

