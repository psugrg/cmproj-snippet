# Basic CMAKE project snippet

This is a basic Cmake project snippet for x86 linux based applications.
It tries to cover most of the most important
topics in project development in the minimal but functional form. This minimal
approach helps with understanding the topic.
The project intentionally contains some *bugs* in code to show that the
verification works.

## Folder structure

The project contains of three folders: *doc*, *objLibEx* and *libEx*.

### doc

This folder contains the example of Doxygen documentation.

### objLibEx

This folder contains an example of the Object library. It contains the *main*
function but doesn't create an application. It is created by the top level
CMakeLists.txt file instead.

### libEx

This folder contains an example of the library, GoogleTests and library
installation.

## Development Environment

This *CMake project snippet* is designed to run on the
[SADEN](https://github.com/psugrg/saden) development environment where all
requirements are installed. However it should work on any linux system assuming
the required dependencies are installed.

## Code Formatting

Code formatting is based on
[clang-format](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)
utility. It uses the `./.clang-format` file containing the style configuration.
The code formatting operation will not be triggered by build but can
be manually/automatically triggered by the IDE.

### Configuration in VS Code

Hit `Ctrl+Shift+P` and search for `Open User Settings`.
Search for `format` and select `Editor: Format On Save`.

## Static Analysis

Static analysis is done using [cppcheck](https://github.com/danmar/cppcheck)
tool. Custom target `scheck` is handling the static analysis process. This
target is a part of the `ALL` group which means that it'll be run automatically
by make when `make` or `make all` command is executed.

### Static Analysis Usage

- Run `make scheck` in the `./build` folder to start static analysis manually.

## Unit Tests

Unit tests are using [GoogleTest](https://github.com/google/googletest)
framework. This project uses an installed version of the *GoogleTest* framework.

### Unit Tests Usage

- Run `ctest -VV` in the `./build` folder to start tests.

## Memory Leaks Detection

Memory leaks detection is made using [Valgrind](https://valgrind.org/) utility.

### Memory Leaks Detection Usage

- Run `ctest -T memcheck` in the `./build` folder to start memory check.

## Code Coverage

Code coverage analysis is done using the
[gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) as the coverage testing
utility and the [gcovr](https://github.com/gcovr/gcovr) for presentation.

### Code Coverage Usage

- Navigate to the build folder.
- Run `cmake -DCMAKE_BUILD_TYPE-Coverage ..` to configure coverage build.
- Run `make` to build the application.
- Run `ctest -VV` to test the application.
- Run `make coverage` to get the coverage results.

## Installation

Installation is done via the built-in CMake installation mechanism.

### Installation Usage

- Navigate to the build folder.
- Run `cmake -DCMAKE_BUILD_TYPE=Release ..` to configure release build.
- Run `make` to build the release.
- Run `sudo make install` to install application.
- Use `-DCMAKE_INSTALL_PREFIX=/new/prefix` if you want to change the default
`/usr/local/` installation directory prefix.
- Use `-DINSTALL_GTEST=OFF` to
[prevent google tests installation](https://github.com/google/googletest/issues/2829)
with the application.

The example full build and installation:

```bash
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/tmp/test-install \
-DCMAKE_BUILD_TYPE=Release -DINSTALL_GTEST=OFF ..
make all
make install
```

## AppImage

The AppImage creation process description can be found on the
[AppImage documentation](https://docs.appimage.org/packaging-guide/index.html)
pages. The best starting point for the CMake based projects is the
[build-with-cmake.sh](https://docs.appimage.org/packaging-guide/from-source/native-binaries.html#id2)
script explained there.

The adapted version of this script has been added to this project as
`make-appimage.sh`.

### AppImage Generation

- Run `./make-appimage.sh` to generate Appimage of this application.

## Useful links

- [tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- [moder-cmake](https://cliutils.gitlab.io/modern-cmake/)
- [cmake-examples](https://github.com/ttroy50/cmake-examples)

