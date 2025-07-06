/** @file io-string.cpp
 *
 * @brief Examples of using I/O streams and strings
 *
 * @author Derek Harter
 * @note   class: East Texas A&M University - Various Classes
 * @note   ide  : VS Code 1.101.2
 * @note   assg : Hello World
 * @date   July 7, 2025
 *
 * A few more quick examples of I/O streams and stream formatting
 * in C++, as well as using the string type and string streams.
 */
// provides the standard input stream cin and standard output stream cout
#include <iostream>

// we want to create inputfile stream and output file streams
#include <fstream>

// also want to give an example of string streams
#include <sstream>

// iomanip provides stream manipulators, like setw and setfill
#include <iomanip>
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
  /// Simple cout output stream example

  // We have already seen the basic way to output a string on a stream using standard
  // output cout stream.  We can format output using string manipulators
  string name = "Derek Harter";
  string department = "Computer_Science";
  float salary = 4830.3;
  int age = 42;
  bool adjunct = false;

  // output a header for a table of employee info
  int rowWidth = 25 + 20 + 10 + 5 + 8;
  // clang-format off
  cout << setw(25) << left << "Employee name" 
       << setw(20) << left << "Department"
       << setw(10) << right << "salary" 
       << setw(5) << "age" 
       << setw(8) << "adjunct" << endl;
  cout << string(rowWidth, '-') << endl;

  // output the actual line of information
  // clang-format off
  cout << setw(25) << setfill('.') << left << name 
       << setw(20) << setfill('.') << left << department
       << setw(10) << setfill('_') << right << fixed << showpoint << setprecision(2) << salary
       << setw(5) << setfill('_') << age 
       << setw(8) << setfill('_') << boolalpha << adjunct << endl;

  /// open an input stream and read in same data from it
  string filename = "data/io-string-input-database.txt";
  ifstream fin;

  // some minimal file checking, if file was not found or some other issue, the fin stream is not defined
  fin.open(filename);
  if (not fin.is_open())
  {
    cerr << "Could not find or correctly open file <" << filename << ">" << endl;
    exit(1);
  }

  // we hardcode the input file format to expect first 25 characters hold the employee name
  string name2;
  string lastName;
  string firstName;
  fin >> lastName >> firstName;
  name2 = firstName + " " + lastName;

  // rest of the data we assume are correctly formatted string, float, int and boolean
  string department2;
  float salary2;
  int age2;
  bool adjunct2;
  fin >> department2 >> salary2 >> age2 >> adjunct2;

  // display the data for this employee
  // clang-format off
  cout << setw(25) << setfill('.') << left << name2
       << setw(20) << setfill('.') << left << department2
       << setw(10) << setfill('_') << right << fixed << showpoint << setprecision(2) << salary2
       << setw(5) << setfill('_') << age2 
       << setw(8) << setfill('_') << boolalpha << adjunct2 << endl;

  /// String Stream example
  // often better to use string streams so can use iomanip formatters
  // output a header for a table of employee info
  ostringstream headerout;
  // clang-format off
  headerout << setw(25) << left << "Employee name" 
            << setw(20) << left << "Department"
            << setw(10) << right << "salary" 
            << setw(5) << "age" 
            << setw(8) << "adjunct" << endl;
  headerout << string(rowWidth, '-') << endl;

  ostringstream e1out;
  // clang-format off
  e1out << setw(25) << setfill('.') << left << name 
        << setw(20) << setfill('.') << left << department
        << setw(10) << setfill('_') << right << fixed << showpoint << setprecision(2) << salary
        << setw(5) << setfill('_') << age 
        << setw(8) << setfill('_') << boolalpha << adjunct << endl;

  ostringstream e2out;
  // clang-format off
  e2out << setw(25) << setfill('.') << left << name2 
        << setw(20) << setfill('.') << left << department2
        << setw(10) << setfill('_') << right << fixed << showpoint << setprecision(2) << salary2 
        << setw(5) << setfill('_') << age2 
        << setw(8) << setfill('_') << boolalpha << adjunct2 << endl;

  cout << headerout.str() << e1out.str() << e2out.str();

  // Example of file output using file output stream
  ofstream fout;
  filename = "data/io-string-output-table.txt";
  fout.open(filename);

  if (not fout.is_open())
  {
    cerr << "Could not open output file to generate table filename <" << filename << ">" << endl;
    exit(1);
  }

  fout << headerout.str() << e1out.str() << e2out.str();

  // return 0 to indicate successful completion
  return 0;
}
