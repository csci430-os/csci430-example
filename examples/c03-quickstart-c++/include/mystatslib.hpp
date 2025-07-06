/** @file mystatslib.hpp
 * @brief Example library / module of functions to be tested
 *
 * @author Derek Harter
 * @note   class: East Texas A&M University - Various Classes
 * @note   ide  : VS Code 1.101.2
 * @note   assg : Hello World
 * @date   July 7, 2025
 *
 * Simple example of library functions to calculate mean and
 * standard deviation of values.

 */
#include <string>
using namespace std;

// Header guards are necessary still in C/C++ because the #include is a simple
// preprocessor macro that simply copies the contents of this file where the
// #include happens.  If header is included in 2 different source files that use this
// library, the declarations will be done 2 times, which is not allowed.
// The header guards against multiple declarations.
#ifndef MYSTATSLIB_HPP
#define MYSTATSLIB_HPP
// Although for big projects header guards are still recommended as not all c++ compilers support it,
// The #pragma once is almost ubiquitous at this point, and can be used insted of ifndef macro header guards
// #pragma once

// function or class declarations that this library implements should
// be declared here as function signatures or class declarations
float mean(int numValues, float values[]);
float standardDeviation(int numValues, float values[]);

#endif // MYLIB_HPP header guard