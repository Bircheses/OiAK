# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jakub\CLionProjects\OiAK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jakub\CLionProjects\OiAK\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OiAK.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OiAK.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OiAK.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OiAK.dir/flags.make

CMakeFiles/OiAK.dir/main.cpp.obj: CMakeFiles/OiAK.dir/flags.make
CMakeFiles/OiAK.dir/main.cpp.obj: C:/Users/jakub/CLionProjects/OiAK/main.cpp
CMakeFiles/OiAK.dir/main.cpp.obj: CMakeFiles/OiAK.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jakub\CLionProjects\OiAK\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OiAK.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OiAK.dir/main.cpp.obj -MF CMakeFiles\OiAK.dir\main.cpp.obj.d -o CMakeFiles\OiAK.dir\main.cpp.obj -c C:\Users\jakub\CLionProjects\OiAK\main.cpp

CMakeFiles/OiAK.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OiAK.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jakub\CLionProjects\OiAK\main.cpp > CMakeFiles\OiAK.dir\main.cpp.i

CMakeFiles/OiAK.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OiAK.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jakub\CLionProjects\OiAK\main.cpp -o CMakeFiles\OiAK.dir\main.cpp.s

CMakeFiles/OiAK.dir/Counter.cpp.obj: CMakeFiles/OiAK.dir/flags.make
CMakeFiles/OiAK.dir/Counter.cpp.obj: C:/Users/jakub/CLionProjects/OiAK/Counter.cpp
CMakeFiles/OiAK.dir/Counter.cpp.obj: CMakeFiles/OiAK.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jakub\CLionProjects\OiAK\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OiAK.dir/Counter.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OiAK.dir/Counter.cpp.obj -MF CMakeFiles\OiAK.dir\Counter.cpp.obj.d -o CMakeFiles\OiAK.dir\Counter.cpp.obj -c C:\Users\jakub\CLionProjects\OiAK\Counter.cpp

CMakeFiles/OiAK.dir/Counter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OiAK.dir/Counter.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jakub\CLionProjects\OiAK\Counter.cpp > CMakeFiles\OiAK.dir\Counter.cpp.i

CMakeFiles/OiAK.dir/Counter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OiAK.dir/Counter.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jakub\CLionProjects\OiAK\Counter.cpp -o CMakeFiles\OiAK.dir\Counter.cpp.s

# Object files for target OiAK
OiAK_OBJECTS = \
"CMakeFiles/OiAK.dir/main.cpp.obj" \
"CMakeFiles/OiAK.dir/Counter.cpp.obj"

# External object files for target OiAK
OiAK_EXTERNAL_OBJECTS =

OiAK.exe: CMakeFiles/OiAK.dir/main.cpp.obj
OiAK.exe: CMakeFiles/OiAK.dir/Counter.cpp.obj
OiAK.exe: CMakeFiles/OiAK.dir/build.make
OiAK.exe: CMakeFiles/OiAK.dir/linkLibs.rsp
OiAK.exe: CMakeFiles/OiAK.dir/objects1.rsp
OiAK.exe: CMakeFiles/OiAK.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jakub\CLionProjects\OiAK\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable OiAK.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OiAK.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OiAK.dir/build: OiAK.exe
.PHONY : CMakeFiles/OiAK.dir/build

CMakeFiles/OiAK.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OiAK.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OiAK.dir/clean

CMakeFiles/OiAK.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jakub\CLionProjects\OiAK C:\Users\jakub\CLionProjects\OiAK C:\Users\jakub\CLionProjects\OiAK\cmake-build-debug C:\Users\jakub\CLionProjects\OiAK\cmake-build-debug C:\Users\jakub\CLionProjects\OiAK\cmake-build-debug\CMakeFiles\OiAK.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/OiAK.dir/depend

