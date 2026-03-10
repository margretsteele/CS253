/* File: sort.h
 * Author: Margret Steele
 * Brief: sorting class header file
 * Date: 10/12/2011
 * Class: CS253
 */
#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

template<typename generic>
class Sort
{

 public:
 
 /* Function: merge_sort
 * Brief: Sorting using the merge sort algorithm
 * Pre: The elements of array A must be able to be compared to each other element in such a way that can be sorted. 
 * Post: A’ is now a sorted permutation in decreasing order of A.
 */
  static void merge_sort( vector<generic> &unsorted, int start, int end );
  
 /* Function: heap_sort
 * Brief: Sorting using the heap sort algorithm
 * Pre: A is an array of size n
 * Post: A’ is now a sorted permutation in decreasing order of A.
 */
  static void heap_sort( vector<generic> &unsorted );  
  
 /* Function: max_heapify
 * Brief: takes position i and puts in its proper place according to it's childen
 * Pre: i is an index into A, and there are two heaps left and right
 * Post: A max heap is created at i
 */
  static void max_heapify( vector<generic> &unsorted, int index );
  
 /* Function: merge_sort
 * Brief: makes a max heap 
 * Pre: A is an array of size n
 * Post: A[1], A[2], … , A[n] are roots of max heaps
 */
  static void build_max_heap( vector<generic> &unsorted );

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
 
 /* Function: merge
 * Brief: completes merge sort
 * Pre: The elements of array A must be able to be compared to each other element in such a way that can be sorted.  
 * P, q, and r must all be indexes into A.
 * Post: The elements A[p, …, r] are sorted
 */
 static void merge( vector<generic> &unsorted, int start, int mid, int end );
 
  /* Function: pre_condition_is_array
 * Brief: tests if the thing being passed into sort is an array that can all be accessed
 * Pre: n/a 
 * Post: n/a
 */
 static bool pre_condition_is_array( vector<generic> unsorted );
 
 /* Function: is_max_heap
 * Brief: tests if there is a max heap at index
 * Pre: n/a 
 * Post: n/a
 */
 static bool is_max_heap( vector<generic> unsorted, int index );
 
 /* Variable: heap_size
 * Brief: used in heap sort
 */
 static unsigned int heap_size;
};

template<typename generic>
unsigned int Sort<generic>::heap_size = 0;

#include"sort.hpp"
#endif