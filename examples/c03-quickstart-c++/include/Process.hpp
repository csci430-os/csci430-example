/** @file Process.hpp
 *
 * @brief Example class to hold Process information
 *
 * @author Derek Harter
 * @note   class: East Texas A&M University - Various Classes
 * @note   ide  : VS Code 1.101.2
 * @note   assg : Hello World
 * @date   July 7, 2025
 *
 * Simple example of object oriented programming.  A class that holds
 * information about a Process running on and being managed by a
 * system.
 *
 * The .hpp file should hold the declaration of the class (no functions should
 * be implemented here usually).
 */
#include <string>
using namespace std;

#ifndef PROCESS_HPP
#define MYSTATSLIB_HPP

// We use unsigned integers for process identifiers.  A typedef is
// just like an alias, but it makes your code more readable since whenever you see
// Pid used as a type, you know that the variable is meant to hold a process identifier
// for our system.
/// @brief Unique assigned process identifiers.
typedef unsigned int Pid;

/// @brief  Usage times by processes in our system, like cpu usage.
typedef unsigned int Time;

// Always use enumerated types instead of defining some integer mappings when you have
// a variable that takes a discrete list of values like the process state does here.
/// @brief Current process state.
enum State
{
  NEW,
  READY,
  RUNNING,
  BLOCKED,
  TERMINATED
};

/**
 * @class Process
 * @brief Track information about processes in the system.
 *
 * A class whose instance encapsulates all of the information
 * we need to manage and track running processes in our system.
 */
class Process
{
public:
  // constructors and destructors
  Process(Pid pid, string command);
  ~Process();

  // getter methods
  Pid getPid();
  State getState();
  Time getUsage();
  string getCommand();

  // setter methods
  void setState(State newState);
  void updateUsage(Time timeUsed);

  // in general, to enforce encapsulation, all member variables should usually be
  // private member variables in object-oriented programming
private:
  Pid pid;        /// The unique process identifier assigned when process is created
  State state;    /// The current process state
  Time usage;     /// Amount of cpu usage time currently used by the running process
  string command; /// The command line string that invoked/forked the process

  int* fileid; /// Example of dynamically allocated memory, array of file identifiers
};

#endif // MYLIB_HPP header guard