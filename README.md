# Test-Driven Development Dojo (道場)

A dojo (道場) is a local for practice. The goal of this project is to practice
**the Way of Test-Driven Development**.

Each directory contains a small project, some of the code were extracted from
good references such as books, articles and courses, while other code were created
by own.

The languages used doesn't matter since the focus is the TDD, but I'll try to stick
to: C++, Python, Go and maybe also Rust (since I really want to learn this one).

## Soundex

From Jeff Langr's [*Modern C++ Programming with Test-Driven Development*](https://pragprog.com/titles/lotdd/modern-c-programming-with-test-driven-development).

Each numbered directory contains a different development stage starting from the
most basic test and code possible. Also, it's not guarantee that the code here
follow exactly the same from the book just because at certain point I found
useful to add different tests or change the approach of an existing one.

### Build

To build this project it's necessary to have installed one [C++ compiler which
supports C++17](https://en.cppreference.com/w/cpp/compiler_support/17), *GCC*
version 9 or greater for example along with [*CMake*](https://cmake.org) version
3.18.4 or greater.

I've configured [CPM](https://github.com/cpm-cmake/CPM.cmake) in order to provide
some mandatory dependencies such as [Boost libraries](https://www.boost.org),
[Google Test](https://github.com/google/googletest) and so on. This also differs
from the original codebase provided in the book.

Other tools such as *ccache* and *cppcheck* are optional and can be removed from
the [CMakeLists.txt](./Soundex/01/CMakeLists.txt) files.

From the repository root directory, which contains this [CMakeLists.txt](./CMakeLists.txt),
run:

```console
mkdir build && cd $_
cmake ../ && make
```
