# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/112/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/112/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liza/GitProjects/4_sem/snake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liza/GitProjects/4_sem/snake/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/snake.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/snake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/snake.dir/flags.make

CMakeFiles/snake.dir/main.cpp.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liza/GitProjects/4_sem/snake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/snake.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snake.dir/main.cpp.o -c /home/liza/GitProjects/4_sem/snake/main.cpp

CMakeFiles/snake.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liza/GitProjects/4_sem/snake/main.cpp > CMakeFiles/snake.dir/main.cpp.i

CMakeFiles/snake.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liza/GitProjects/4_sem/snake/main.cpp -o CMakeFiles/snake.dir/main.cpp.s

CMakeFiles/snake.dir/tui.cpp.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/tui.cpp.o: ../tui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liza/GitProjects/4_sem/snake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/snake.dir/tui.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snake.dir/tui.cpp.o -c /home/liza/GitProjects/4_sem/snake/tui.cpp

CMakeFiles/snake.dir/tui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake.dir/tui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liza/GitProjects/4_sem/snake/tui.cpp > CMakeFiles/snake.dir/tui.cpp.i

CMakeFiles/snake.dir/tui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake.dir/tui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liza/GitProjects/4_sem/snake/tui.cpp -o CMakeFiles/snake.dir/tui.cpp.s

CMakeFiles/snake.dir/ui.cpp.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/ui.cpp.o: ../ui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liza/GitProjects/4_sem/snake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/snake.dir/ui.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snake.dir/ui.cpp.o -c /home/liza/GitProjects/4_sem/snake/ui.cpp

CMakeFiles/snake.dir/ui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake.dir/ui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liza/GitProjects/4_sem/snake/ui.cpp > CMakeFiles/snake.dir/ui.cpp.i

CMakeFiles/snake.dir/ui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake.dir/ui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liza/GitProjects/4_sem/snake/ui.cpp -o CMakeFiles/snake.dir/ui.cpp.s

CMakeFiles/snake.dir/human.cpp.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/human.cpp.o: ../human.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liza/GitProjects/4_sem/snake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/snake.dir/human.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snake.dir/human.cpp.o -c /home/liza/GitProjects/4_sem/snake/human.cpp

CMakeFiles/snake.dir/human.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake.dir/human.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liza/GitProjects/4_sem/snake/human.cpp > CMakeFiles/snake.dir/human.cpp.i

CMakeFiles/snake.dir/human.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake.dir/human.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liza/GitProjects/4_sem/snake/human.cpp -o CMakeFiles/snake.dir/human.cpp.s

CMakeFiles/snake.dir/control.cpp.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/control.cpp.o: ../control.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liza/GitProjects/4_sem/snake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/snake.dir/control.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snake.dir/control.cpp.o -c /home/liza/GitProjects/4_sem/snake/control.cpp

CMakeFiles/snake.dir/control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake.dir/control.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liza/GitProjects/4_sem/snake/control.cpp > CMakeFiles/snake.dir/control.cpp.i

CMakeFiles/snake.dir/control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake.dir/control.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liza/GitProjects/4_sem/snake/control.cpp -o CMakeFiles/snake.dir/control.cpp.s

CMakeFiles/snake.dir/game.cpp.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/game.cpp.o: ../game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liza/GitProjects/4_sem/snake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/snake.dir/game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snake.dir/game.cpp.o -c /home/liza/GitProjects/4_sem/snake/game.cpp

CMakeFiles/snake.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake.dir/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liza/GitProjects/4_sem/snake/game.cpp > CMakeFiles/snake.dir/game.cpp.i

CMakeFiles/snake.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake.dir/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liza/GitProjects/4_sem/snake/game.cpp -o CMakeFiles/snake.dir/game.cpp.s

# Object files for target snake
snake_OBJECTS = \
"CMakeFiles/snake.dir/main.cpp.o" \
"CMakeFiles/snake.dir/tui.cpp.o" \
"CMakeFiles/snake.dir/ui.cpp.o" \
"CMakeFiles/snake.dir/human.cpp.o" \
"CMakeFiles/snake.dir/control.cpp.o" \
"CMakeFiles/snake.dir/game.cpp.o"

# External object files for target snake
snake_EXTERNAL_OBJECTS =

snake: CMakeFiles/snake.dir/main.cpp.o
snake: CMakeFiles/snake.dir/tui.cpp.o
snake: CMakeFiles/snake.dir/ui.cpp.o
snake: CMakeFiles/snake.dir/human.cpp.o
snake: CMakeFiles/snake.dir/control.cpp.o
snake: CMakeFiles/snake.dir/game.cpp.o
snake: CMakeFiles/snake.dir/build.make
snake: CMakeFiles/snake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liza/GitProjects/4_sem/snake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable snake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/snake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/snake.dir/build: snake

.PHONY : CMakeFiles/snake.dir/build

CMakeFiles/snake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/snake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/snake.dir/clean

CMakeFiles/snake.dir/depend:
	cd /home/liza/GitProjects/4_sem/snake/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liza/GitProjects/4_sem/snake /home/liza/GitProjects/4_sem/snake /home/liza/GitProjects/4_sem/snake/cmake-build-debug /home/liza/GitProjects/4_sem/snake/cmake-build-debug /home/liza/GitProjects/4_sem/snake/cmake-build-debug/CMakeFiles/snake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/snake.dir/depend
