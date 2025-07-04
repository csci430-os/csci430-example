/** @file  map-example.cpp
 *
 * @author Derek Harter
 * @assg   STL List Example
 * @date   June 11, 2018
 * @ide    gcc 7.2.0 and emacs 25 editor
 *
 * @descrption Example of using the C++ Standard Template Library
 *    associate maps.
 */
#include "Process.hpp"
#include <iostream>
#include <list>
#include <map>
#include <string>

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
  map<int, string> myMap;

  // insert a key/value pair into th emap, using the map insert() member function
  // myMap.insert(1234, "Derek Harter") // this does not work, no insert() member method defined that takes 2 parameters
  myMap.insert(pair<int, string>(1234, "Derek Harter"));

  // as a shortcut, can actually use curly braces, which default to creating a pair instances here in c++ stl templates
  myMap.insert({5678, "Susan Programmer"});

  // or simplest approach imho, just use overloaded indexing operator to insert
  myMap[8765] = "Sally Engineer";

  // iterate over the map, displaying all key/value pairs
  // Here we use auto to determine the type automatically, the actual type is pair<int, string>
  cout << "Example of inserting into map" << endl;
  cout << "-----------------------------" << endl << endl;
  for (auto keyValuePair : myMap)
  {
    int id = keyValuePair.first;
    string name = keyValuePair.second;

    cout << "Found id: " << id << " -> " << name << endl;
  }
  cout << endl << endl;

  // find out the current number of key/value pairs in this map
  cout << "Number of key/value pairs in example map: " << myMap.size() << endl << endl;

  // lookup of nonexistent key doesn't cause an error, and in fact returns an empty string here,
  // because a new default instance of the value type is created, added to the map, and returned.
  cout << "Lookup of nonexistent key 1111: " << myMap[1111] << endl << endl;
  cout << "After lookup of nonexistent key, size of map is: " << myMap.size() << endl << endl;

  // If you need to test if a key exists in the map, use find()
  // find returns and end() iterator if not found
  // key 1111 now exists
  if (myMap.find(1111) != myMap.end())
  {
    cout << "We successfully found key 1111, this key exists in the map" << endl << endl;
  }
  else
  {
    cout << "We did not find key 1111, this key does not exist in the map" << endl << endl;
  }

  // but key 2222 does not currently exist in the map
  if (myMap.find(2222) != myMap.end())
  {
    cout << "We successfully found key 2222, this key exists in the map" << endl << endl;
  }
  else
  {
    cout << "We did not find key 2222, this key does not exist in the map" << endl << endl;
  }

  // use a combination of find and erase to remove key/value pairs from the map
  // lets remove the bad key 1111 from the map
  myMap.erase(myMap.find(1111));

  // also erase anohter key, just as an example
  myMap.erase(myMap.find(1234));

  cout << "Final map after removing keys 1111 and 1234" << endl;
  cout << "-------------------------------------------" << endl << endl;
  for (auto keyValuePair : myMap)
  {
    int id = keyValuePair.first;
    string name = keyValuePair.second;

    cout << "Found id: " << id << " -> " << name << endl;
  }
  cout << endl << endl;

  // ---------------------------------------------------------
  // Some more examples, more specific to our assignment 02

  cout << "------------------------ assg 02 examples ---------------------" << endl << endl;

  // A process control block using a map, just like our assignment
  map<Pid, Process> processControlBlock;

  Pid newPid = 5;
  int systemTime = 20;

  // inserting a new process into the pcb
  Process newProcess(newPid, systemTime);
  processControlBlock[newPid] = newProcess;

  cout << "Number of active processes in pcb: " << processControlBlock.size() << endl;

  // access the process to do things with it
  Pid somePid = 5;
  processControlBlock[somePid].ready();

  cout << "We just made process 5 ready, process 5 information: " << processControlBlock[somePid] << endl << endl;

  // insert some other processes in the pcb
  Process newProcess1(1, 5);
  processControlBlock[1] = newProcess1;
  Process newProcess2(2, 10);
  processControlBlock[2] = newProcess2;

  cout << "Number of active processes in pcb after 2 more new processes is: " << processControlBlock.size() << endl;

  // remove proces 5 from the process control block
  processControlBlock.erase(processControlBlock.find(5));

  cout << "Number of active processes in pcb after removing process 5: " << processControlBlock.size() << endl;

  // example of displaying all processes in the pcb
  for (auto pcbPair : processControlBlock)
  {
    // Pid pid = pcbPair.first;
    Process process = pcbPair.second;

    cout << process << endl;
  }
  cout << endl << endl;

  // keep track of which process is blocked waiting on a particular event
  map<EventId, Pid> blockedList;
  EventId eventId = 42;
  Pid cpu = 20;
  blockedList[eventId] = cpu;

  // add some more
  blockedList[55] = 5;
  blockedList[32] = 7;

  // how many processes are currently blocked?
  cout << "Number of processes currently blocked: " << blockedList.size() << endl << endl;

  // Test if a process is waiting on some particular event or not
  // process 20 is waiting on eventId 42
  if (blockedList.find(42) != blockedList.end())
  {
    cout << "Found the following processes waiting on event 42: " << blockedList[42] << endl << endl;
  }
  else
  {
    cout << "No process is currently waiting on event 42" << endl << endl;
  }

  if (blockedList.find(56) != blockedList.end())
  {
    cout << "Found the following processes waiting on event 56: " << blockedList[42] << endl << endl;
  }
  else
  {
    cout << "No process is currently waiting on event 56" << endl << endl;
  }

  // finally lets display all of the processes that are currently blocked according to the blockedList
  cout << "Iterate over the event/pid pairs on the blocked list example" << endl;
  cout << "------------------------------------------------------------" << endl;
  for (auto blockedPair : blockedList)
  {
    EventId eventId = blockedPair.first;
    Pid pid = blockedPair.second;

    cout << "Process: " << pid << " is on our blocked list waiting for event: " << eventId << endl;
  }
  cout << endl << endl;
}