/** @file test-mystatslib.cpp
 *
 * @brief Example of unit testing
 *
 * @author Derek Harter
 * @note   class: East Texas A&M University - Various Classes
 * @note   ide  : VS Code 1.101.2
 * @note   assg : Hello World
 * @date   July 7, 2025
 *
 * An example of performing C++ unit tests using the catch2 framework
 * for a small library of statistics functions.
 */
// include the catch2 framework header file to define and run catch2 unit tests
#include "catch.hpp"
#include <iostream>
#include "mystatslib.hpp"
using namespace std;


/** mean() unit tests
 * Test the mean() function from mystatslib library
 */
TEST_CASE("<mean()> function tests", "[mean]")
{
  // mean of a single value is that value
  int numValues = 1;
  float values1[] = {1.0};
  CHECK(mean(numValues, values1) == Approx(1.0));

  // mean of values symmetric around 0 is 0
  numValues = 5;
  float values2[] = {-3.3, 5.5, 0.0, -5.5, 3.3};
  CHECK(mean(numValues, values2) == Approx(0.0));

  // mean of first 2 values, check that numValues is being used correctly
  numValues = 2;
  CHECK(mean(numValues, values2) == Approx(1.1));

  // mean of 10 random values
  numValues = 10;
  float values3[] = {-1.234, 3.8556, -8.2937, 4.2578, 10.1234, -11.1290, 7.6543, -22.1389, -3.14159, 13.1313};
  CHECK(mean(numValues, values3) == Approx(-0.69148));

  // test edge case, we will define a list of values of size 0 to have a mean of 0.0
  CHECK(mean(0, values3) == Approx(0.0));
}

/** standardDeviation() unit tests
 * Test the std() standard deviation function from mystatslib library
 */
TEST_CASE("<standardDeviation()> function tests", "[standardDeviation]")
{
  // sample deviation of all same value is (close to) 0
  int numValues = 5;
  float values1[] = {3.0, 3.0, 3.0, 3.0, 3.0};
  CHECK(standardDeviation(numValues, values1) == Approx(0.0));

  // sample deviation of values symmetric around 0 is (close to) 2 here
  numValues = 6;
  float values2[] = {2.0, -2.0, 2.0, -2.0, 2.0, -2.0};
  CHECK(standardDeviation(numValues, values2) == Approx(2.1908902));

  // sample standard deviation of 10 random values
  numValues = 10;
  float values3[] = {-1.234, 3.8556, -8.2937, 4.2578, 10.1234, -11.1290, 7.6543, -22.1389, -3.14159, 13.1313};
  CHECK(standardDeviation(numValues, values3) == Approx(10.831431));

  // edge cases, sample std of a single value is not defined, we expect 0 for empty list or list of
  // size 1
  numValues = 1;
  float valuesEdge[] = {1.0};
  CHECK(standardDeviation(numValues, valuesEdge) == Approx(0.0));

  numValues = 0;
  CHECK(standardDeviation(numValues, valuesEdge) == Approx(0.0));
}
