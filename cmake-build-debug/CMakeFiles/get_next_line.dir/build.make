# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Users/mshagga/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/mshagga/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mshagga/CLionProjects/get_next_line

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mshagga/CLionProjects/get_next_line/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/get_next_line.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/get_next_line.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/get_next_line.dir/flags.make

CMakeFiles/get_next_line.dir/gnl_beta.c.o: CMakeFiles/get_next_line.dir/flags.make
CMakeFiles/get_next_line.dir/gnl_beta.c.o: ../gnl_beta.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mshagga/CLionProjects/get_next_line/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/get_next_line.dir/gnl_beta.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/get_next_line.dir/gnl_beta.c.o   -c /Users/mshagga/CLionProjects/get_next_line/gnl_beta.c

CMakeFiles/get_next_line.dir/gnl_beta.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/get_next_line.dir/gnl_beta.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mshagga/CLionProjects/get_next_line/gnl_beta.c > CMakeFiles/get_next_line.dir/gnl_beta.c.i

CMakeFiles/get_next_line.dir/gnl_beta.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/get_next_line.dir/gnl_beta.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mshagga/CLionProjects/get_next_line/gnl_beta.c -o CMakeFiles/get_next_line.dir/gnl_beta.c.s

CMakeFiles/get_next_line.dir/libft/ft_memdup.c.o: CMakeFiles/get_next_line.dir/flags.make
CMakeFiles/get_next_line.dir/libft/ft_memdup.c.o: ../libft/ft_memdup.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mshagga/CLionProjects/get_next_line/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/get_next_line.dir/libft/ft_memdup.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/get_next_line.dir/libft/ft_memdup.c.o   -c /Users/mshagga/CLionProjects/get_next_line/libft/ft_memdup.c

CMakeFiles/get_next_line.dir/libft/ft_memdup.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/get_next_line.dir/libft/ft_memdup.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mshagga/CLionProjects/get_next_line/libft/ft_memdup.c > CMakeFiles/get_next_line.dir/libft/ft_memdup.c.i

CMakeFiles/get_next_line.dir/libft/ft_memdup.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/get_next_line.dir/libft/ft_memdup.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mshagga/CLionProjects/get_next_line/libft/ft_memdup.c -o CMakeFiles/get_next_line.dir/libft/ft_memdup.c.s

# Object files for target get_next_line
get_next_line_OBJECTS = \
"CMakeFiles/get_next_line.dir/gnl_beta.c.o" \
"CMakeFiles/get_next_line.dir/libft/ft_memdup.c.o"

# External object files for target get_next_line
get_next_line_EXTERNAL_OBJECTS =

get_next_line: CMakeFiles/get_next_line.dir/gnl_beta.c.o
get_next_line: CMakeFiles/get_next_line.dir/libft/ft_memdup.c.o
get_next_line: CMakeFiles/get_next_line.dir/build.make
get_next_line: ../libft/libft.a
get_next_line: CMakeFiles/get_next_line.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mshagga/CLionProjects/get_next_line/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable get_next_line"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/get_next_line.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/get_next_line.dir/build: get_next_line

.PHONY : CMakeFiles/get_next_line.dir/build

CMakeFiles/get_next_line.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/get_next_line.dir/cmake_clean.cmake
.PHONY : CMakeFiles/get_next_line.dir/clean

CMakeFiles/get_next_line.dir/depend:
	cd /Users/mshagga/CLionProjects/get_next_line/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mshagga/CLionProjects/get_next_line /Users/mshagga/CLionProjects/get_next_line /Users/mshagga/CLionProjects/get_next_line/cmake-build-debug /Users/mshagga/CLionProjects/get_next_line/cmake-build-debug /Users/mshagga/CLionProjects/get_next_line/cmake-build-debug/CMakeFiles/get_next_line.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/get_next_line.dir/depend

