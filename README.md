# Basic CMAKE project snippet
My very basic CMake project snippet

## Development Environment
  - Development environment: https://github.com/psugrg/saden
  - Build system CMake
  - Code Formatting using Clang Format
  - Static analysis: CppCheck
  - Testing using Google Test framework
### TODO
  - Documentation: Doxygen
  - memory leaks detection


## Clang Format
Code formatting is based on `clang-format` using the `./.clang-format` file.
The code formatting operation will not be triggered by build but can be manually/automatically triggered by the IDE.

### Install clang-format
This step is necessary only if *SDEN* is not used.

Run `sudo apt install clang-format` on debian-like distributions. 

### Configuration in VS Code
Hit `Ctrl+Shift+P` and search for `Open User Settings`.
Search for `format` and select `Editor: Format On Save`.