# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrey.bespalov/Projects/plytoplane_v1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrey.bespalov/Projects/plytoplane_v1.0

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/opt/homebrew/Cellar/cmake/3.25.1/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/Cellar/cmake/3.25.1/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/andrey.bespalov/Projects/plytoplane_v1.0/CMakeFiles /Users/andrey.bespalov/Projects/plytoplane_v1.0//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/andrey.bespalov/Projects/plytoplane_v1.0/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named plytoplane

# Build rule for target.
plytoplane: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 plytoplane
.PHONY : plytoplane

# fast build rule for target.
plytoplane/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/plytoplane.dir/build.make CMakeFiles/plytoplane.dir/build
.PHONY : plytoplane/fast

PLY.o: PLY.cpp.o
.PHONY : PLY.o

# target to build an object file
PLY.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/plytoplane.dir/build.make CMakeFiles/plytoplane.dir/PLY.cpp.o
.PHONY : PLY.cpp.o

PLY.i: PLY.cpp.i
.PHONY : PLY.i

# target to preprocess a source file
PLY.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/plytoplane.dir/build.make CMakeFiles/plytoplane.dir/PLY.cpp.i
.PHONY : PLY.cpp.i

PLY.s: PLY.cpp.s
.PHONY : PLY.s

# target to generate assembly for a file
PLY.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/plytoplane.dir/build.make CMakeFiles/plytoplane.dir/PLY.cpp.s
.PHONY : PLY.cpp.s

PSBColors/PSBColors.o: PSBColors/PSBColors.cpp.o
.PHONY : PSBColors/PSBColors.o

# target to build an object file
PSBColors/PSBColors.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/plytoplane.dir/build.make CMakeFiles/plytoplane.dir/PSBColors/PSBColors.cpp.o
.PHONY : PSBColors/PSBColors.cpp.o

PSBColors/PSBColors.i: PSBColors/PSBColors.cpp.i
.PHONY : PSBColors/PSBColors.i

# target to preprocess a source file
PSBColors/PSBColors.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/plytoplane.dir/build.make CMakeFiles/plytoplane.dir/PSBColors/PSBColors.cpp.i
.PHONY : PSBColors/PSBColors.cpp.i

PSBColors/PSBColors.s: PSBColors/PSBColors.cpp.s
.PHONY : PSBColors/PSBColors.s

# target to generate assembly for a file
PSBColors/PSBColors.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/plytoplane.dir/build.make CMakeFiles/plytoplane.dir/PSBColors/PSBColors.cpp.s
.PHONY : PSBColors/PSBColors.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/plytoplane.dir/build.make CMakeFiles/plytoplane.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/plytoplane.dir/build.make CMakeFiles/plytoplane.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/plytoplane.dir/build.make CMakeFiles/plytoplane.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... plytoplane"
	@echo "... PLY.o"
	@echo "... PLY.i"
	@echo "... PLY.s"
	@echo "... PSBColors/PSBColors.o"
	@echo "... PSBColors/PSBColors.i"
	@echo "... PSBColors/PSBColors.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

