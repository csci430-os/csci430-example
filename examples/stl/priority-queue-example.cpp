/** @file  priority-queue-example.cpp
 *
 * @author Derek Harter
 * @assg   STL List Example
 * @date   Aug 10, 2022
 * @ide    gcc 7.2.0 and emacs 25 editor
 *
 * @descrption Example of using the C++ Standard Template Library
 *    priority queues.
 */
#include "Process.hpp"
#include <iostream>
#include <queue>

using namespace std;

/** Main entry point of program
 *  The main entry point of the example program.
 *  We accept command line arguments if needed in main.
 *
 * @param argc The argument count
 * @param argv The command line argument values. We expect argv[1] to
 *              be the name of a file in the current directory holding
 *              process events to simulate.
 *
 * @returns int Returns 0 to OS to indicate successful completion, or
 *              non zero value to indicate an error.
 */
int main(int argc, char** argv)
{
  cout << "Hello priority queue" << endl;

  // simple example, create queue of ints
  priority_queue<int> pq;

  pq.push(10);
  pq.push(60);
  pq.push(20);
  pq.push(50);

  // iterate over queue, popping off values.  Should pop off values by
  // "priority", highest integer first
  while (not pq.empty())
  {
    cout << "Popped off current highest priority value from pq: " << pq.top() << endl;
    pq.pop();
  }
}