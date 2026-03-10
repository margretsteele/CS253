/* File: sort.h
 * Author: Margret Steele
 * Brief: sorting class header file
 * Date: 9/19/2011
 * Class: CS253
 */
#ifndef SORT_H
#define SORT_H

#include <ctime>
#include <math.h>
#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using std::cout;
using std::endl;

template<typename generic>
class Sort
{

 public:
 
 /* Function: merge_sort
 * Brief: Sorting using the merge sort algorithm
 * Pre: The elements of array A must be able to be compared to each other element in such a way that can be sorted. 
 * Post: A’ is now a sorted permutation in decreasing order of A.
 */
  static void merge_sort( vector<generic> &unsorted, int p, int r );
  
 /* Function: insertion
 * Brief: Sorting using the insertion sort algorithm
 * Pre: The elements of array A must be able to be compared to each other element in such a way that can be sorted. 
 * Post: A’ now a sorted permutation in decreasing order of A[p…r].
 */
  static void insertion( vector<generic> &unsorted );

 /* Function: insertEntries
 * Brief: Inserting elements into array
 * Pre: n/a 
 * Post: vector x will have int entires amount of entires, in order
 */
  static void insertEntries( vector<generic> &x, int entires );

 /* Function: shuffleEntries
 * Brief: shuffling elements into array
 * Pre: n/a 
 * Post: vector x will have int entires amount of entires, out of order
 */
  static void shuffleEntries( vector<generic> &x );

 /* Function: sortedTest
 * Brief: returns true is array is sorted in decending order
 * Pre: n/a 
 * Post: n/a
 */
  static bool sortedTest( vector<generic> x, int start, int end );

 private:
 
 /* Function: merge
 * Brief: completes merge sort
 * Pre: n/a 
 * Post: n/a
 */
 static void merge( vector<generic> &unsorted, int p, int q, int r );
 
 vector<generic> x;
};

#include"sort.hpp"
#endif