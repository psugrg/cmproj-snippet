# Basic CMAKE project snippet
My very basic CMake project snippet

## Development Environment
  - Development environment: https://github.com/psugrg/saden
  - Build system CMake
  - Code Formatting using Clang Format
  - Static analysis: CppCheck
  - Documentation: Doxygen
  - Testing using Google Test framework
  - memory leaks detection
### In Progress
  - installation.

  Installation kind of work. The problem is that it also install tests together with the googletest framework. 
### TODO
  - Documentation should not search in all folders of the project (it tries to parese build folder and release folder)
  - code coverage
  - packages
  - flatpacs/appimages/etc


## Clang Format
Code formatting is based on `clang-format` using the `./.clang-format` file.
The code formatting operation will not be triggered by build but can be manually/automatically triggered by the IDE.

### Install clang-format
This step is necessary only if *SDEN* is not used.

Run `sudo apt install clang-format` on debian-like distributions. 

### Configuration in VS Code
Hit `Ctrl+Shift+P` and search for `Open User Settings`.
Search for `format` and select `Editor: Format On Save`.

### Static Analysis - CppCheck
Use custom target `scheck` to perform static analysis using CppCheck utility.
Run `make scheck` in the `./build` folder to start static analysis.

### Unit tests
Unit tests are using googletest framework
Run `ctest -VV` in the `./build` folder to start tests.

### Memory leaks detection
Memory leaks detection is made using Valgrind tool. 
Run `ctest -T memcheck` in the `./build` folder to start memory check.

### Installation
Navigate to the build folder. 
Run `cmake -DCMAKE_BUILD_TYPE=Release ..` to configure release build.
Run `make` to build the release. 
Run `sudo make install` to install application. 
Uou can use `CMAKE_INSTALL_PREFIX` to change the default installation location. 