/*
**Objective:** Get a first feel of I/O-streams in C++, and test that
  your programming environment works.

Implement function **Hello()** that outputs `Hello world!`, followed by
a newline. You should not use the *printf()* call as in C, but instead
C++ streams and functions that are defined in C++ "iostream" header.
*/
#include "first.hpp"

#include <iostream>

void Hello() {
    std::cout << "Hello world!" << std::endl;
    }

