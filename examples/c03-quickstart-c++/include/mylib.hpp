/** @file mylib.hpp
 * @brief Header file example for multifile projects.
 *
 * @author Derek Harter
 * @note   class: East Texas A&M University - Various Classes
 * @note   ide  : VS Code 1.101.2
 * @note   assg : Hello World
 * @date   July 7, 2025
 *
 * Example multi file project.  For a library of functions or a module
 * that defines a class or classes, all declarations go in the header file.
 * The header file in a C/C++ project is meant to be included in other
 * files that want to use the functions or classes defined in this
 * library/module.
 */
#include <string>
using namespace std;

// Header guards are necessary still in C/C++ because the #include is a simple
// preprocessor macro that simply copies the contents of this file where the
// #include happens.  If header is included in 2 different source files that use this
// library, the declarations will be done 2 times, which is not allowed.
// The header guards against multipl declarations.
#ifndef MYLIB_HPP
#define MYLIB_HPP
// Although for big projects header guards are still recommended as not all c++ compilers support it,
// The #pragma once is almost ubiquitious at this point, and can be used insted of ifndef macro header guards
// #pragma once

// function or class declarations that this library implements should
// be declared here as function signatures or class declarations
bool mylibRepeatGreeting(string greeting, int numRepeats);

#endif // MYLIB_HPP header guard