/** @file stl-sequence-containers.cpp
 *
 * @brief Examples of using STL sequence containers
 *
 * @author Derek Harter
 * @note   class: East Texas A&M University - Various Classes
 * @note   ide  : VS Code 1.101.2
 * @note   assg : Hello World
 * @date   July 7, 2025
 *
 * Some examples of the basic sequence containers, Array, Vector, List.
 *
 * Recommend using cplusplus.com https://cplusplus.com/reference/ for online
 * reference of the STL library and other C++ libraries.
 */
// we include the STL containers used in this example
#include <array>
#include <list>
#include <vector>

#include <iostream>
using namespace std;

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
  /// Arrays are fixed-size sequence containers, they hold a specific number of elements.
  /// The class merely adds a layer of member and global functions so it can be used as a standard
  /// container, otherwise it is the same as declaring an old style int values[5] type array in C.

  // declare an array to hold 5 integers
  array<int, 5> myarray = {5, 10, 15, 20, 25};

  // can access using [] operator
  for (int i = 0; i < 5; i++)
  {
    cout << "myarray[" << i << "] = " << myarray[i] << endl;
  }

  // can use new range based iterators and member methods, notice don't need to know size to iterate
  // over c++ array containers
  for (int myint : myarray)
  {
    cout << "myarray[] = " << myint << endl;
  }

  cout << "first element: " << myarray[0] << endl;
  cout << "last element: " << myarray[4] << endl;
  cout << "first element: " << myarray.at(0) << endl;
  cout << "last element: " << myarray.at(4) << endl;
  myarray[2] = 42;
  cout << "third element is now: " << myarray[2] << endl;
  myarray.at(2) = 52;
  cout << "third element is now: " << myarray.at(2) << endl;
  cout << "size of myarray: " << myarray.size() << endl;

  // can't resize an array
  try
  {
    // this is a bit safer than using regular c arrays, this will at least
    // throw an out_of_range exception
    myarray[5] = 100;
    cout << "last element: " << myarray.at(5) << endl;
  }
  catch (out_of_range& o)
  {
    cout << "out of range exception thrown trying to go beyond end of array" << endl;
  }
  cout << "size of myarray: " << myarray.size() << endl;

  /// vector used to store sequence of items, unlike an array the vector can
  /// grow dynamically as needed.
  vector<int> myvector = {2, 4, 6, 8, 10};

  // can access and modify elements like an array
  myvector[3] = 42;
  cout << "myvector[3] is now: " << myvector[3] << endl;
  myvector.at(4) = 52;
  cout << "myvector.at(4) is now:" << myvector.at(4) << endl;

  cout << "size of myvector: " << myvector.size() << endl;
  for (int myint : myvector)
  {
    cout << "myvector[] = " << myint << endl;
  }

  // vector overloads the [], so can use it like an array
  for (size_t i = 0; i < myvector.size(); i++)
  {
    cout << "myvector[" << i << "] = " << myvector[i] << endl;
  }

  // vector can grow, you can insert items on back or take them off the back.
  // vector is still a contiguous array, may need to dynamically allocate a new array
  // to grow, usually doubles array size
  // size and capacity are not necessarily the same for a vector
  cout << "myvector current size: " << myvector.size() << endl;
  cout << "myvector current max size: " << myvector.capacity() << endl;

  myvector.push_back(55);
  cout << "after first push myvector current size: " << myvector.size() << endl;
  cout << "after first push myvector current max size: " << myvector.capacity() << endl;

  myvector.push_back(66);
  cout << "after second push myvector current size: " << myvector.size() << endl;
  cout << "after second push myvector current max size: " << myvector.capacity() << endl;

  // can insert and erase items from middle.  These will cause copying/shifting as needed as
  // the memory remains an internal allocated contiguous block
  // erase the element at position/index 2
  myvector.erase(myvector.begin() + 2);

  // insert an element after index 1
  myvector.insert(myvector.begin() + 1, 99);
  cout << "after erase and insert myvector current size: " << myvector.size() << endl;
  cout << "after erase and insert myvector current max size: " << myvector.capacity() << endl;

  // after the erase and insert, we now have
  for (int myint : myvector)
  {
    cout << "myvector[] = " << myint << endl;
  }

  /// A list is a STL sequence container that stores elements randomly in unrelated
  /// locations, basically implemented as a doubly linked list.
  /// This means it is constant time O(1) to insert at front or back and can iterate
  /// over list in either direction efficiently.  Can insert and remove items inside of
  /// the list in O(n) time, but have to place an iterator at location to remove or insert first
  list<int> mylist = {1, 3, 5, 7, 9};

  // can iterate over using ranged based iteration, but can't access using [] operator
  for (int myint : mylist)
  {
    cout << "mylist[] = " << myint << endl;
  }

  // mylist[3] = 32; // error, the operator[] is not defined because it is not efficient to implement on list

  cout << "mylist size: " << mylist.size() << endl;

  mylist.push_front(42);
  mylist.push_back(52);
  for (int myint : mylist)
  {
    cout << "mylist[] = " << myint << endl;
  }
  cout << "mylist size: " << mylist.size() << endl;

  mylist.pop_front();
  mylist.pop_back();
  for (int myint : mylist)
  {
    cout << "mylist[] = " << myint << endl;
  }
  cout << "mylist size: " << mylist.size() << endl;

  // return 0 to indicate successful completion
  return 0;
}
