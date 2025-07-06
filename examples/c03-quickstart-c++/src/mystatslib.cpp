/** @file mystatslib.cpp
 *
 * @brief Example library / module of functions to be tested
 *
 * @author Derek Harter
 * @note   class: East Texas A&M University - Various Classes
 * @note   ide  : VS Code 1.101.2
 * @note   assg : Hello World
 * @date   July 7, 2025
 *
 * Simple example of library functions to calculate mean and
 * standard deviation of values.
 */
#include <iostream>
#include <cmath>
using namespace std;

/** @brief mean
 *
 * Given a simple array of floating point values and the number of
 * values in the array, calculate the mean of the values in the array
 * and return the calculated sample mean
 *
 * @param numValues An integer that indicates the number of floating points
 *   values given in the array to be averaged.
 * @param values An array of some number of floats.  This function will calculate
 *   the sample mean of the given values and return it.
 *
 * @returns float Returns the calculated sample mean of the given values.
 */
float mean(int numValues, float values[])
{
  float sum = 0.0;

  // handle special case, if list is empty return 0
  if (numValues <= 0)
  {
    return sum;
  }

  // first sum up the values in the sample
  for (int i = 0; i < numValues; i++)
  {
    sum += values[i];
  }

  // sample mean or average is then just the sum divided by the number of values
  return sum / float(numValues);
}


/** @brief standard deviation
 *
 * Given a simple array of floating point values and the number of
 * values in the array, calculate the sample standard deviation
 * of the values.
 *
 * @param numValues An integer that indicates the number of floating points
 *   values given in the array to be used in calculation of std.
 * @param values An array of some number of floats.  This function will calculate
 *   the sample standard deviation of the given values and return it.
 *
 * @returns float Returns the calculated sample mean of the given values.
 */
float standardDeviation(int numValues, float values[])
{
  // handle special case of empty list or list of size 1 which does not really
  // have a defined sample standard deviation
  if (numValues <= 1)
  {
    return 0.0;
  }

  // first need the sample mean to calculate the standard deviation
  float sampleMean = mean(numValues, values);

  // the standard deviation is the average of the squared difference of each value from
  // the sample mean
  float sum = 0.0;
  for (int i = 0; i < numValues; i++)
  {
    // the squared difference of each value from the mean
    sum += pow(values[i] - sampleMean, 2.0);
  }

  // average the sum of the squared differences and take square root to get sample
  // standard deviation, sample std uses numValues-1 which removes some sample bias
  float res = sum / float(numValues - 1);
  res = sqrt(res);
  return res;
}