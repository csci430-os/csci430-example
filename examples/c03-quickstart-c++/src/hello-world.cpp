/** @file hello-world.cpp
 *
 * @brief Example hello world program
 *
 * @author Derek Harter
 * @note   class: East Texas A&M University - Various Classes
 * @note   ide  : VS Code 1.101.2
 * @note   assg : Hello World
 * @date   July 7, 2025
 *
 * An example hello world program in C++.  Used to illustrate compiling
 * programs using C++ compiler, and the standard library cout stream
 * and standard namespace.
 */
// To use basic C++ streaming I/O include the <iostream> header
#include <iostream>

// Anytime you want to use a function or class provided by another module or the C++ library, you have
// to include the appropriate header
#include "mylib.hpp"

// Namespaces are a more modern feature of C++.  The standard I/O stream
// declarations are in the standard `std` namespace.  If we don't specify
// `using namespace std;` then we have to specify `std::cout` and give
// the full namespace specifier for anything we use from the standard namespce.
using namespace std;

/** @brief Main entry point
 *
 * Example main function.  All C/C++ programs have an entry point which is a
 * function with a specific special name, main.  In this example we
 * demonstrate how you can get command line arguments into the main funciton
 * of a C/C++ program.
 *
 * @param argc The command line argument count, the number of arguments
 *   provided by user on the command line.
 * @param argv An array of char* old style c-strings.  Each argv[x]
 *   that is passed in holds one of the command line arguments provided
 *   by the user to the program when started.
 *
 * @returns int Returns 0 to indicate successfull completion of program,
 *   and a non-zero value to indicate an error code.
 */
int main(int argc, char** argv)
{
  // check that a command line argument was supplied
  if (argc != 3)
  {
    cout << "usage: hello-world num_repeats name" << endl;
    // exit with an error code 1
    return 1;
  }

  // prints the name given in command line argument 1
  cout << "Hello " << argv[2] << "!" << endl;

  // example of using the string class
  string greeting = "Greetings " + string(argv[2]) + ", I hope you are doing well today.";

  // example of calling the mylib library function
  // extract number of repeats from command line argument 1
  int numRepeats = atoi(argv[1]);
  if (not mylibRepeatGreeting(greeting, numRepeats))
  {
    // if the function said we only repeated an odd number of times, repeat 1 more time
    // so we always seen en even number of greetings.
    mylibRepeatGreeting(greeting, 1);
  }

  // return 0 to indicate successful completion
  return 0;
}
