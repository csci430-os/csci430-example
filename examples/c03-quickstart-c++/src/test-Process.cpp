/** @file test-Process.cpp
 *
 * @brief Example of object oriented programming in C++
 *
 * @author Derek Harter
 * @note   class: East Texas A&M University - Various Classes
 * @note   ide  : VS Code 1.101.2
 * @note   assg : Hello World
 * @date   July 7, 2025
 *
 * Some more examples of testing.  Though here we are demonstrating doing
 * object oriented programming in C++.  We test that the Process class
 * member functions are working as expected in this example.
 */
#include "catch.hpp"
#include <iostream>
#include "Process.hpp"
using namespace std;


/** Process constructor
 */
TEST_CASE("<Process> constructor tests", "[Process constructor]")
{
  // create an instance of a process to test.
  string command1 = "find . -name *.hpp -print";
  Pid pid1 = 1;
  Process process1 = Process(pid1, command1);

  // test parameters passed to constructor are set in the instance
  CHECK(process1.getPid() == pid1);
  CHECK(process1.getCommand() == command1);

  // test defaults were also set
  CHECK(process1.getUsage() == 0);
  CHECK(process1.getState() == NEW);

  // another process instance shouldn't effect the first one
  string command2 = "grep hello *.txt";
  Pid pid2 = 2;
  Process process2 = Process(pid2, command2);
  CHECK(process2.getPid() == pid2);
  CHECK(process2.getCommand() == command2);

  CHECK(process1.getPid() == pid1);
  CHECK(process1.getCommand() == command1);
}


/** Process setState() member method
 */
TEST_CASE("<Process.setState()> member method tests", "[Process.setState()]")
{
  // create an instance of a process to test.
  string command1 = "find . -name *.hpp -print";
  Pid pid1 = 1;
  Process process1 = Process(pid1, command1);

  // initialy should be NEW, set the state to RUNNING
  CHECK(process1.getState() == NEW);
  process1.setState(RUNNING);
  CHECK(process1.getState() == RUNNING);

  // set the state to RUNNING
  process1.setState(BLOCKED);
  CHECK(process1.getState() == BLOCKED);

  // another process instance, their states are independent
  string command2 = "grep hello *.txt";
  Pid pid2 = 2;
  Process process2 = Process(pid2, command2);

  CHECK(process2.getState() == NEW);
  process2.setState(TERMINATED);
  CHECK(process2.getState() == TERMINATED);

  // pid 1 should still be blocked
  CHECK(process1.getState() == BLOCKED);
}

/** Process updateUsage() member method
 */
TEST_CASE("<Process.updateUsage()> member method tests", "[Process.updateUsage()]")
{
  // create an instance of a process to test.
  string command1 = "find . -name *.hpp -print";
  Pid pid1 = 1;
  Process process1 = Process(pid1, command1);

  // initially usage is 0, update it to 5
  CHECK(process1.getUsage() == 0);
  process1.updateUsage(5);
  CHECK(process1.getUsage() == 5);

  // add 3 more
  process1.updateUsage(3);
  CHECK(process1.getUsage() == 8);

  // another process instance, their usages are independent
  string command2 = "grep hello *.txt";
  Pid pid2 = 2;
  Process process2 = Process(pid2, command2);

  CHECK(process2.getUsage() == 0);
  process2.updateUsage(10);
  CHECK(process2.getUsage() == 10);

  // pid 1 should still only have used 8
  CHECK(process1.getUsage() == 8);
}