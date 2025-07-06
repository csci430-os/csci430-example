/** @file mylib.cpp
 *
 * @brief Example library / module of functions
 *
 * @author Derek Harter
 * @note   class: East Texas A&M University - Various Classes
 * @note   ide  : VS Code 1.101.2
 * @note   assg : Hello World
 * @date   July 7, 2025
 *
 * A simple example of a library of function declarations and implementations.
 * In a multifile project, all implementations of regular and class member
 * functions should go into the `X.cpp` file.  The declarations of these
 * functions / member functions should go into the corresponding `X.hpp` header
 * file so they can be included in source files that want to use them.
 */
#include <iostream>
using namespace std;

/** @brief mylib example function, repeat a greeting
 *
 * Example of a function implemented in mylib library.  This function
 * can be used by includeing `#include mylib.hpp` and invoking the function
 * with the correct input parameters.
 *
 * This function takes a string and an integer as input.  It displays
 * the string on standard output cout, repeating it the number of times
 * asked for in the numRepeats parameter.
 *
 * @param greeting A string that is given that should be repeated.
 * @param numRepeats Integer, the number of repetitions on standard output
 *   to perform.
 *
 * @returns bool Returns true if repeated an even number of times, and false if
 *   repeated an odd number of times.
 */
bool mylibRepeatGreeting(string greeting, int numRepeats)
{
  // repeat on standard output the number of times asked for
  for (int i = 0; i < numRepeats; i++)
  {
    cout << greeting << endl;
  }

  // return a true result when repeated an even number of times, and false when
  // an odd number of times
  return numRepeats % 2 == 0;
}
