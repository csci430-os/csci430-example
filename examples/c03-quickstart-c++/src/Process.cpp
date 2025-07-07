/** @file Process.cpp
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
 * The .cpp file should hold all implementations of class member functions that are
 * declared in the class header file.
 */
#include "Process.hpp"

/** @brief basic Process constructor
 *
 * The normal way to construct a new Process class is to first generate the
 * next process id, then create an instance of the class assigning it the
 * next generated process identifier.
 *
 * @param pid The process identifier that has been assigned to this new
 *   Process instance.
 */
Process::Process(Pid pid, string command)
  : pid(pid)
  , command(command)
{
  // initialize other private member variables to beginning default values
  // could also be done using initializer list
  state = NEW;
  usage = 0;

  // example of dynamic memory, the most basic type of memory management is to create
  // memory needed by an instance in the constructor, and free it back up in the class
  // destructor
  // dynamically allocate room for 10 file identifiers for this process
  fileid = new int[10];
  fileid[0] = 0; // stdin
  fileid[1] = 1; // stdout
  fileid[2] = 2; // stderr
}

/** @brief Process destructor
 *
 * Basic example of a destructor.  Most common type of memory management in C++
 * is to dynamically allocate needed memory in constructor, which is available for
 * the life of the instance.  When the instance goes out of scope and is destroyed,
 * this destructor is automatically called, where any cleanup including deallocating
 * dynamically allocated memory occurs.
 */
Process::~Process()
{
  // deallocate the dynamically allocated block of file identifiers
  delete[] fileid;
}

/** @brief setter method for process state
 *
 * Since process member variables are private by design to enforce encapsulation,
 * we need to provide setter methods for internal state that want users of the
 * class to be able to change.
 *
 * This setter is simple, but in more complex objects we can enforce for example that
 * you can't make illegal state transistion (e.g. for a Process if the state is
 * currently BLOCKED), it cannot legally be changed back to a RUNNING state).
 * Also we can update any other state in a setter method when this state changes that
 * we need to.
 *
 * @param newState The new state to transition the process too.
 */
void Process::setState(State newState)
{
  // just set the state, but we should add checks that the state transition
  // is valid here in the future.
  state = newState;
}

/** @brief getter method for process identifier
 *
 * Likewise any internal state that users of this class might need to know
 * the current value of can be exposed by giving appropriate getter methods.
 *
 * This method simply returns the assigned unique process identifier for this
 * process instance.
 *
 * @returns Pid Returns the unique process identifier of this process instance.
 */
Pid Process::getPid()
{
  return pid;
}

/** @brief getter method for process state
 *
 * This getter method gets and returns the current process state.
 *
 * @returns State Returns the current process state.
 */
State Process::getState()
{
  return state;
}

/** @brief getter method for process usage
 *
 * This getter method gets and returns the current
 * amount of CPU usage time used so far by this
 * process.
 *
 * @returns Time Returns the amount of cpu usage time
 *   currently used by this process.
 */
Time Process::getUsage()
{
  return usage;
}

/** @brief getter method for process command
 *
 * Likewise any internal state that users of this class might need to know
 * the current value of can be exposed by giving appropriate getter methods.
 *
 * This method simply returns the command line string invocation of the process,
 * e.g. the name of the executable used when forking this process.
 *
 * @returns string Returns the name of this process.
 */
string Process::getCommand()
{
  return command;
}

/** @brief Update amount of usage for process
 *
 * This method is used after a process has used cpu time,
 * to keep track of the total amount of cpu time usage used
 * so far by this process.
 *
 * @param timeUsed The amount of time used in the most recent burst
 *   of cpu usage.
 */
void Process::updateUsage(Time timeUsed)
{
  usage += timeUsed;
}