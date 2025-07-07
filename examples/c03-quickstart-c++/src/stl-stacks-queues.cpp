/** @file stl-stacks-queues.cpp
 *
 * @brief Examples of using STL stack and queue adapters.
 *
 * @author Derek Harter
 * @note   class: East Texas A&M University - Various Classes
 * @note   ide  : VS Code 1.101.2
 * @note   assg : Hello World
 * @date   July 7, 2025
 *
 * Some examples of the stack and queue adaptors.
 *
 * Recommend using cplusplus.com https://cplusplus.com/reference/ for online
 * reference of the STL library and other C++ libraries.
 */
// we use our user defined Process class in this example
#include "Process.hpp"

// we include the STL adaptors used in this example
#include <list>
#include <queue>
#include <stack>

#include <iomanip>
#include <iostream>
using namespace std;

/** @brief comparator object used for priority_queue example
 *
 * An example of a custom object that will be called by the
 * priority_queue of Process instances to order the priority queue
 * by Process priority.
 *
 * NOTE: We could and probably would usually put this function
 *   into the Process.hpp header file as part of the Process
 *   definitions.
 */
class ProcessPriorityComparator
{
public:
  bool operator()(Process* lhs, Process* rhs)
  {
    return lhs->getPriority() < rhs->getPriority();
  }
};

/** @brief Main entry point
 *
 * Example main function.  All C/C++ programs have an entry point which is a
 * function with a specific special name, main.
 *
 * @param argc The command line argument count, the number of arguments
 *   provided by user on the command line.
 * @param argv An array of char* old style c-strings.  Each argv[x]
 *   that is passed in holds one of the command line arguments provided
 *   by the user to the program when started.
 *
 * @returns int Returns 0 to indicate successful completion of program,
 *   and a non-zero value to indicate an error code.
 */
int main(int argc, char** argv)
{
  /// stacks and queues are a type of container adaptor.  The stack adaptor is specifically
  /// designed to operat in LIFO (last-in first-out) context.  Any of the vector, deque, list containers can
  /// be used as the actual container for a stack.  By default a deque is used.
  stack<string> mystack;

  // stack is initially empty
  cout << "mystack size: " << mystack.size() << endl;
  cout << "check if the stack is empty: " << boolalpha << mystack.empty() << endl;

  // push three items on the stack
  mystack.push("I'm on the bottom");
  mystack.push("I'm in the middle");
  mystack.push("I'm on top");

  // by design,  you can't iterate over a stack, can only see the top item on the stack
  // for (string item : mystack)
  // {
  //   cout << "mystack item: " << item << endl;
  // }

  cout << "after pushes mystack size: " << mystack.size() << endl;
  cout << "after pushes check if the stack is empty: " << boolalpha << mystack.empty() << endl;

  // access the top item on stack
  cout << "mystack top: " << mystack.top() << endl;

  // top doesn't actually remove the top item, if we want to remove then pop it
  mystack.pop();
  cout << "after pop top item mystack size: " << mystack.size() << endl;
  cout << "after pop tip item check if the stack is empty: " << boolalpha << mystack.empty() << endl;

  // access the top item on stack
  cout << "mystack top is now: " << mystack.top() << endl;

  // can empty out by calling top until stack is empty
  while (not mystack.empty())
  {
    mystack.pop();
  }
  cout << "after clearing stack mystack size: " << mystack.size() << endl;
  cout << "after clearing stack is mystck empty: " << boolalpha << mystack.empty() << endl;

  /// Similarly the queue adaptor can use a deque or a list and it implements a
  /// first-in-first-out queueing discipline.  Items are pushed on to the back
  /// (conventionally) and popped from the front of the queue.
  queue<string> myqueue;

  // queue is initially empty
  cout << "myqueue size: " << myqueue.size() << endl;
  cout << "check if the queue is empty: " << boolalpha << myqueue.empty() << endl;

  // push three items on the stack
  myqueue.push("I'm was on the queue first");
  myqueue.push("I'm in the middle of the items on the queue");
  myqueue.push("I was put onto the queue last");

  // by design,  you can't iterate over a queue, can only see the front or back items
  // on the queue
  // for (string item : myqueue)
  // {
  //   cout << "myqueue item: " << item << endl;
  // }

  cout << "after pushes myqueue size: " << myqueue.size() << endl;
  cout << "after pushes check if the stack is empty: " << boolalpha << myqueue.empty() << endl;

  // access the front and back items on queue
  cout << "myqueue front: " << myqueue.front() << endl;
  cout << "myqueue back: " << myqueue.back() << endl;

  // front or back don't actually remove the items, if we want to remove then
  // need to pop_front.  Notice that there is no pop_back nor push_front, queue items
  // are pushed on the back and popped off the front of a queue adaptor
  myqueue.pop();
  cout << "after pop_front myqueue size: " << myqueue.size() << endl;
  cout << "after pop_front check if the stack is empty: " << boolalpha << myqueue.empty() << endl;

  // access the top item on stack
  cout << "myqueue front is now: " << myqueue.front() << endl;

  // can empty out by calling pop_front until stack is empty
  while (not myqueue.empty())
  {
    myqueue.pop();
  }
  cout << "after clearing queue myqueue size: " << myqueue.size() << endl;
  cout << "after clearing queue is myqueue empty: " << boolalpha << myqueue.empty() << endl;

  /// Priority queues may be useful for some class assignments.  In STL priority queues
  /// are a type of container adaptor designed such that the first element is always the greatest
  /// of the elements it contains.  In this example, create a priority queue of Process instances
  /// and specify that they are orderd by process priority
  /// NOTE: we are putting pointers to Process instances on the queue so we don't make
  /// copies here.
  priority_queue<Process*, vector<Process*>, ProcessPriorityComparator> mySchedulingQueue;

  // create some processes and add them to the queue
  Process p1(1, "ls -alf");
  Process p2(2, "grep -v help");
  Process p3(3, "find . -name *.cpp -print");

  // set p2 priority to highest and p3 to lowest
  p2.setPriority(10);
  p3.setPriority(0);

  // push the items onto the queue
  mySchedulingQueue.push(&p1);
  mySchedulingQueue.push(&p2);
  mySchedulingQueue.push(&p3);

  // popping out elements, we expect highest priority first, followed by middle then
  // lowest priority
  while (not mySchedulingQueue.empty())
  {
    Process* p = mySchedulingQueue.top();
    cout << "Process id: " << p->getPid() << " priority: " << p->getPriority() << endl;

    // remove the top item from the queue now
    mySchedulingQueue.pop();
  }

  // return 0 to indicate successful completion
  return 0;
}
