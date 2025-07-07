/** @file stl-map-containers.cpp
 *
 * @brief Examples of using STL map containers
 *
 * @author Derek Harter
 * @note   class: East Texas A&M University - Various Classes
 * @note   ide  : VS Code 1.101.2
 * @note   assg : Hello World
 * @date   July 7, 2025
 *
 * Some examples of the map containers, map and unorderd_map.
 *
 * Recommend using cplusplus.com https://cplusplus.com/reference/ for online
 * reference of the STL library and other C++ libraries.
 */
// we include the STL containers used in this example
#include <map>
#include <unordered_map>

#include <iomanip>
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
  /// A map is also known as a dictionary or a key-value pair storage in some other high
  /// level languages.  Maps will be useful in this course.
  // A map stores key-value pairs, here we map a string to an integer.
  map<string, int> birthdays = {{"Derek", 1942}, {"Joe", 2010}, {"Karen", 1980}, {"Susan", 1995}};

  // can iterate over the map key-value pairs, notice that the iteration comes out sorted in order by the key
  for (auto keyvalue : birthdays)
  {
    cout << "key: " << keyvalue.first << " value: " << keyvalue.second << endl;
  }

  // there are various ways to add new items to the map, for example can use overloaded [] operator
  birthdays["Kevin"] = 1972;
  cout << "Kevin's birtyday: " << birthdays["Kevin"] << endl;

  // can query the container with the usual methods
  cout << "Is the birthdays empty: " << boolalpha << birthdays.empty() << endl;
  cout << "Current number of key-value pairs in birthday: " << birthdays.size() << endl;

  // can remove items from the map using erase, nicely allows search to erase by key
  birthdays.erase("Derek");
  birthdays.erase("Kevin");
  for (auto keyvalue : birthdays)
  {
    cout << "key: " << keyvalue.first << " value: " << keyvalue.second << endl;
  }

  // sometimes you might want to know if a particular key exists before
  // erasing or tryint to look it up.  count() is convenient, it retuns 0/false if the key is
  // not present and 1/true if it is present
  // does Derek exist in the map anymore?
  if (not birthdays.count("Derek"))
  {
    cout << "Derek has been erased from the birthdays" << endl;
  }

  if (birthdays.count("Karen"))
  {
    cout << "Karen is still in our database of birthdays" << endl;
  }
  else
  {
    cout << "Karen is not in our databse of birthdays" << endl;
  }

  /// Most high level languages that give a dictionary type just use a
  /// hash table, which gives constant time insertion and deletion time.
  /// However, the C++ STL map, as we noted iterates over the keys in sorted order,
  /// because it uses something like a binary search tree.  The insertion and
  /// removal time is probably something like log(N) for a map.  To get constant
  /// time insertion, lookup  and removal, you can instead use an unordered_map, which uses
  /// a hash table.  Usually the performance difference won't matter unless you are
  /// using truly big maps with many lookups per second.
  // Redo the same above example but use an unordered_map instead
  unordered_map<string, int> unordered_birthdays = {{"Derek", 1942}, {"Joe", 2010}, {"Karen", 1980}, {"Susan", 1995}};

  // can iterate over the map key-value pairs, notice that the iteration comes out sorted in order by the key
  // NOTE: unlike for the map, the iteration order of the keys here may not come out sorted.
  for (auto keyvalue : unordered_birthdays)
  {
    cout << "key: " << keyvalue.first << " value: " << keyvalue.second << endl;
  }

  // there are various ways to add new items to the map, for example can use overloaded [] operator
  unordered_birthdays["Kevin"] = 1972;
  cout << "Kevin's birtyday: " << unordered_birthdays["Kevin"] << endl;

  // can query the container with the usual methods
  cout << "Is the unordered_birthdays empty: " << boolalpha << unordered_birthdays.empty() << endl;
  cout << "Current number of key-value pairs in birthday: " << unordered_birthdays.size() << endl;

  // can remove items from the map using erase, nicely allows search to erase by key
  unordered_birthdays.erase("Derek");
  unordered_birthdays.erase("Kevin");
  for (auto keyvalue : unordered_birthdays)
  {
    cout << "key: " << keyvalue.first << " value: " << keyvalue.second << endl;
  }

  // sometimes you might want to know if a particular key exists before
  // erasing or tryint to look it up.  count() is convenient, it retuns 0/false if the key is
  // not present and 1/true if it is present
  // does Derek exist in the map anymore?
  if (not unordered_birthdays.count("Derek"))
  {
    cout << "Derek has been erased from the unordered_birthdays" << endl;
  }

  if (unordered_birthdays.count("Karen"))
  {
    cout << "Karen is still in our database of unordered_birthdays" << endl;
  }
  else
  {
    cout << "Karen is not in our databse of unordered_birthdays" << endl;
  }

  // return 0 to indicate successful completion
  return 0;
}
