# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/mikec_g1kgiu8/OneDrive/Desktop/CS 2341 Projects/21f-srch-ngn-thebraintrust"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/mikec_g1kgiu8/OneDrive/Desktop/CS 2341 Projects/21f-srch-ngn-thebraintrust"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/mnt/c/Users/mikec_g1kgiu8/OneDrive/Desktop/CS 2341 Projects/21f-srch-ngn-thebraintrust/CMakeFiles" "/mnt/c/Users/mikec_g1kgiu8/OneDrive/Desktop/CS 2341 Projects/21f-srch-ngn-thebraintrust/CMakeFiles/progress.marks"
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/mnt/c/Users/mikec_g1kgiu8/OneDrive/Desktop/CS 2341 Projects/21f-srch-ngn-thebraintrust/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named 21f_final_proj_template

# Build rule for target.
21f_final_proj_template: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 21f_final_proj_template
.PHONY : 21f_final_proj_template

# fast build rule for target.
21f_final_proj_template/fast:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/build
.PHONY : 21f_final_proj_template/fast

DSAVLTreeTests.o: DSAVLTreeTests.cpp.o

.PHONY : DSAVLTreeTests.o

# target to build an object file
DSAVLTreeTests.cpp.o:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/DSAVLTreeTests.cpp.o
.PHONY : DSAVLTreeTests.cpp.o

DSAVLTreeTests.i: DSAVLTreeTests.cpp.i

.PHONY : DSAVLTreeTests.i

# target to preprocess a source file
DSAVLTreeTests.cpp.i:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/DSAVLTreeTests.cpp.i
.PHONY : DSAVLTreeTests.cpp.i

DSAVLTreeTests.s: DSAVLTreeTests.cpp.s

.PHONY : DSAVLTreeTests.s

# target to generate assembly for a file
DSAVLTreeTests.cpp.s:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/DSAVLTreeTests.cpp.s
.PHONY : DSAVLTreeTests.cpp.s

DSHashTableTests.o: DSHashTableTests.cpp.o

.PHONY : DSHashTableTests.o

# target to build an object file
DSHashTableTests.cpp.o:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/DSHashTableTests.cpp.o
.PHONY : DSHashTableTests.cpp.o

DSHashTableTests.i: DSHashTableTests.cpp.i

.PHONY : DSHashTableTests.i

# target to preprocess a source file
DSHashTableTests.cpp.i:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/DSHashTableTests.cpp.i
.PHONY : DSHashTableTests.cpp.i

DSHashTableTests.s: DSHashTableTests.cpp.s

.PHONY : DSHashTableTests.s

# target to generate assembly for a file
DSHashTableTests.cpp.s:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/DSHashTableTests.cpp.s
.PHONY : DSHashTableTests.cpp.s

DocumentParser.o: DocumentParser.cpp.o

.PHONY : DocumentParser.o

# target to build an object file
DocumentParser.cpp.o:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/DocumentParser.cpp.o
.PHONY : DocumentParser.cpp.o

DocumentParser.i: DocumentParser.cpp.i

.PHONY : DocumentParser.i

# target to preprocess a source file
DocumentParser.cpp.i:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/DocumentParser.cpp.i
.PHONY : DocumentParser.cpp.i

DocumentParser.s: DocumentParser.cpp.s

.PHONY : DocumentParser.s

# target to generate assembly for a file
DocumentParser.cpp.s:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/DocumentParser.cpp.s
.PHONY : DocumentParser.cpp.s

IndexHandler.o: IndexHandler.cpp.o

.PHONY : IndexHandler.o

# target to build an object file
IndexHandler.cpp.o:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/IndexHandler.cpp.o
.PHONY : IndexHandler.cpp.o

IndexHandler.i: IndexHandler.cpp.i

.PHONY : IndexHandler.i

# target to preprocess a source file
IndexHandler.cpp.i:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/IndexHandler.cpp.i
.PHONY : IndexHandler.cpp.i

IndexHandler.s: IndexHandler.cpp.s

.PHONY : IndexHandler.s

# target to generate assembly for a file
IndexHandler.cpp.s:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/IndexHandler.cpp.s
.PHONY : IndexHandler.cpp.s

QueryEngine.o: QueryEngine.cpp.o

.PHONY : QueryEngine.o

# target to build an object file
QueryEngine.cpp.o:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/QueryEngine.cpp.o
.PHONY : QueryEngine.cpp.o

QueryEngine.i: QueryEngine.cpp.i

.PHONY : QueryEngine.i

# target to preprocess a source file
QueryEngine.cpp.i:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/QueryEngine.cpp.i
.PHONY : QueryEngine.cpp.i

QueryEngine.s: QueryEngine.cpp.s

.PHONY : QueryEngine.s

# target to generate assembly for a file
QueryEngine.cpp.s:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/QueryEngine.cpp.s
.PHONY : QueryEngine.cpp.s

SearchEngine.o: SearchEngine.cpp.o

.PHONY : SearchEngine.o

# target to build an object file
SearchEngine.cpp.o:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/SearchEngine.cpp.o
.PHONY : SearchEngine.cpp.o

SearchEngine.i: SearchEngine.cpp.i

.PHONY : SearchEngine.i

# target to preprocess a source file
SearchEngine.cpp.i:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/SearchEngine.cpp.i
.PHONY : SearchEngine.cpp.i

SearchEngine.s: SearchEngine.cpp.s

.PHONY : SearchEngine.s

# target to generate assembly for a file
SearchEngine.cpp.s:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/SearchEngine.cpp.s
.PHONY : SearchEngine.cpp.s

catch_setup.o: catch_setup.cpp.o

.PHONY : catch_setup.o

# target to build an object file
catch_setup.cpp.o:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/catch_setup.cpp.o
.PHONY : catch_setup.cpp.o

catch_setup.i: catch_setup.cpp.i

.PHONY : catch_setup.i

# target to preprocess a source file
catch_setup.cpp.i:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/catch_setup.cpp.i
.PHONY : catch_setup.cpp.i

catch_setup.s: catch_setup.cpp.s

.PHONY : catch_setup.s

# target to generate assembly for a file
catch_setup.cpp.s:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/catch_setup.cpp.s
.PHONY : catch_setup.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/main.cpp.s
.PHONY : main.cpp.s

porter2_stemmer.o: porter2_stemmer.cpp.o

.PHONY : porter2_stemmer.o

# target to build an object file
porter2_stemmer.cpp.o:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/porter2_stemmer.cpp.o
.PHONY : porter2_stemmer.cpp.o

porter2_stemmer.i: porter2_stemmer.cpp.i

.PHONY : porter2_stemmer.i

# target to preprocess a source file
porter2_stemmer.cpp.i:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/porter2_stemmer.cpp.i
.PHONY : porter2_stemmer.cpp.i

porter2_stemmer.s: porter2_stemmer.cpp.s

.PHONY : porter2_stemmer.s

# target to generate assembly for a file
porter2_stemmer.cpp.s:
	$(MAKE) -f CMakeFiles/21f_final_proj_template.dir/build.make CMakeFiles/21f_final_proj_template.dir/porter2_stemmer.cpp.s
.PHONY : porter2_stemmer.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... 21f_final_proj_template"
	@echo "... DSAVLTreeTests.o"
	@echo "... DSAVLTreeTests.i"
	@echo "... DSAVLTreeTests.s"
	@echo "... DSHashTableTests.o"
	@echo "... DSHashTableTests.i"
	@echo "... DSHashTableTests.s"
	@echo "... DocumentParser.o"
	@echo "... DocumentParser.i"
	@echo "... DocumentParser.s"
	@echo "... IndexHandler.o"
	@echo "... IndexHandler.i"
	@echo "... IndexHandler.s"
	@echo "... QueryEngine.o"
	@echo "... QueryEngine.i"
	@echo "... QueryEngine.s"
	@echo "... SearchEngine.o"
	@echo "... SearchEngine.i"
	@echo "... SearchEngine.s"
	@echo "... catch_setup.o"
	@echo "... catch_setup.i"
	@echo "... catch_setup.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... porter2_stemmer.o"
	@echo "... porter2_stemmer.i"
	@echo "... porter2_stemmer.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

