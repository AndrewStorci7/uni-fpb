# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\sandr\OneDrive\Desktop\UNIpr\uni-fpb\Vector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sandr\OneDrive\Desktop\UNIpr\uni-fpb\Vector\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Vector.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Vector.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Vector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Vector.dir/flags.make

CMakeFiles/Vector.dir/main.cpp.obj: CMakeFiles/Vector.dir/flags.make
CMakeFiles/Vector.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Vector.dir/main.cpp.obj: CMakeFiles/Vector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sandr\OneDrive\Desktop\UNIpr\uni-fpb\Vector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Vector.dir/main.cpp.obj"
	D:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Vector.dir/main.cpp.obj -MF CMakeFiles\Vector.dir\main.cpp.obj.d -o CMakeFiles\Vector.dir\main.cpp.obj -c C:\Users\sandr\OneDrive\Desktop\UNIpr\uni-fpb\Vector\main.cpp

CMakeFiles/Vector.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vector.dir/main.cpp.i"
	D:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\sandr\OneDrive\Desktop\UNIpr\uni-fpb\Vector\main.cpp > CMakeFiles\Vector.dir\main.cpp.i

CMakeFiles/Vector.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vector.dir/main.cpp.s"
	D:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\sandr\OneDrive\Desktop\UNIpr\uni-fpb\Vector\main.cpp -o CMakeFiles\Vector.dir\main.cpp.s

# Object files for target Vector
Vector_OBJECTS = \
"CMakeFiles/Vector.dir/main.cpp.obj"

# External object files for target Vector
Vector_EXTERNAL_OBJECTS =

Vector.exe: CMakeFiles/Vector.dir/main.cpp.obj
Vector.exe: CMakeFiles/Vector.dir/build.make
Vector.exe: CMakeFiles/Vector.dir/linklibs.rsp
Vector.exe: CMakeFiles/Vector.dir/objects1.rsp
Vector.exe: CMakeFiles/Vector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\sandr\OneDrive\Desktop\UNIpr\uni-fpb\Vector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Vector.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Vector.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Vector.dir/build: Vector.exe
.PHONY : CMakeFiles/Vector.dir/build

CMakeFiles/Vector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Vector.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Vector.dir/clean

CMakeFiles/Vector.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sandr\OneDrive\Desktop\UNIpr\uni-fpb\Vector C:\Users\sandr\OneDrive\Desktop\UNIpr\uni-fpb\Vector C:\Users\sandr\OneDrive\Desktop\UNIpr\uni-fpb\Vector\cmake-build-debug C:\Users\sandr\OneDrive\Desktop\UNIpr\uni-fpb\Vector\cmake-build-debug C:\Users\sandr\OneDrive\Desktop\UNIpr\uni-fpb\Vector\cmake-build-debug\CMakeFiles\Vector.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Vector.dir/depend

