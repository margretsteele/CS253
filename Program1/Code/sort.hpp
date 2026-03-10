/*
 * File: sort.hpp
 * Author: Margret Steele
 * Brief:This is the sort.h template implimentation file
 * Date: 9/19/2011
 * Class: CS253
*/

#include "assert.h"

using std::vector;
using std::swap;
using std::cout;
using std::endl;

template<typename generic>
void Sort<generic>::merge_sort( vector<generic> &unsorted, int p, int r )
{
//precondition implimentation
//If they can't be compared at all return
assert( unsorted[0] == unsorted[1] || (unsorted[0] != unsorted[1]) );
  if( p < r )
  {
    int q = (p + r) / 2;
    merge_sort( unsorted, p, q );
    merge_sort( unsorted, q + 1, r );    
    merge( unsorted, p, q, r );
  }
  
//post condtion is sortedTest function 
assert( Sort<generic>::sortedTest( unsorted, 0, unsorted.size() ) );
}

template<typename generic>
void Sort<generic>::merge( vector<generic> &unsorted, int p, int q, int r )
{
  int n =  q - p + 1;
  int m =  r - q;
  int i;
  int j;
  
  vector<generic> L( n );
  vector<generic> R( m );
   
  for( i = 0; i < n; i++ )
  {
    L[i] = unsorted[p + i];
  }
  
  for( j = 0; j < m; j++ )
  {
    R[j] = unsorted[q + j + 1];
  }
    
  i = 0;
  j = 0; 
  
  
  for( int k = p; k <= r; k++ )
  {
  
  //Invariant implimentation
  //The sub array A[p…k - 1] contains the k - p smallest elements of L and R in sorted order.
  assert( unsorted[k - 1] < L[i] || unsorted[k - 1] < R[j] );
    if( (i < n && L[i] <= R[j]) || j == m )
    {
      unsorted[k] = L[i];
      i = i + 1;
    }
    else
    {
      unsorted[k] = R[j];
      j = j + 1;
    }
  }
}

template<typename generic>
void Sort<generic>::insertion(  vector<generic> &unsorted )
{
//precondition implimentation
//If they can't be compared at all return
assert( (unsorted[0] == unsorted[1]) || (unsorted[0] != unsorted[1]) );
  int key = 0;
  int i;
  
  //have the initial vector A being passed in, used later to prove invariance
  vector<generic> copyVector = unsorted;
  
  for( int j = 1; j < unsorted.size(); j++)
  {
    key = unsorted[j];
    i = j - 1;
    while( i >= 0 && unsorted[i] > key)
    {
      //Invariant 2 Implimentation: 
      //A[i .. j] are each >= key
      for( int z = i; z < j; z++)
      {
        assert( unsorted[z] >= key );
      }
      unsorted[i + 1] = unsorted [i];
      i = i - 1;
    }
    unsorted[i + 1] = key;
  } 
  
  //Invariant 1 Implimentation: 
  //A[1..j-1] is a sorted permutation of the original A[1..j-1]
  for( int z = 0; z < unsorted.size(); z++)
  {
    bool found = false;
    for( int y = 0; y < copyVector.size(); y++)
    { 
      //you've found a part of the permutation
      if( unsorted[z] == copyVector[y] )
      {
        //Make it so you can no longer access that value
        copyVector[y] = NULL;
        found = true;
      }
    }
    //wasn't in the new vector
    assert( found );
  }
  
//post condtion is sortedTest function 
assert( Sort<generic>::sortedTest( unsorted, 0, unsorted.size() ) );
}

template<typename generic>
void Sort<generic>::insertEntries( vector<generic> &x, int entries )
{
  for( int i = 0; i < entries; i++ )
  {
    x.push_back( i );
  }
}

template<typename generic>
void Sort<generic>::shuffleEntries( vector<generic> &x )
{
  int k;
  for( int i = x.size() ; i > 1 ; i-- )
  {
    k = rand() % i;
    swap( x[i-1], x[k] );
  }
}

template<typename generic>
bool Sort<generic>::sortedTest( vector<generic> x, int start, int end)
{
  bool sorted = false;
  for( int i = start; i < end - 1; i++)
  {
    if( x[i] <= x[i + 1] )
      sorted = true;
    else
      sorted = false;
  }
  if( end == 0 )
    sorted = true;
    
  return sorted;
}