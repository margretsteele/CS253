/*
 * File: sort.hpp
 * Author: Margret Steele
 * Brief: This is the sort.h template implimentation file
 * Date: 10/12/2011
 * Class: CS253
*/

#include "assert.h"

using std::vector;
using std::swap;
using std::cout;
using std::endl;

template<typename generic>
void Sort<generic>::merge_sort( vector<generic> &unsorted, int start, int end )
{
  //precondition
  //If they can't be accessed at all return
  assert( Sort<generic>::pre_condition_is_array( unsorted ) );
  
  if( start < end )
  {
    int mid = (start + end) / 2;
    merge_sort( unsorted, start, mid );
    merge_sort( unsorted, (mid + 1), end );    
    merge( unsorted, start, mid, end );
  }
  
  //post condtion is sortedTest function 
  assert( Sort<generic>::sortedTest( unsorted, 0, unsorted.size()) );
}

template<typename generic>
void Sort<generic>::merge( vector<generic> &unsorted, int start, int mid, int end )
{
  //precondition
  //If they can't be accessed at all return
  assert( Sort<generic>::pre_condition_is_array( unsorted ) );
  
  int n =  mid - start + 1;
  int m =  end - mid;
  int i;
  int j;
  
  vector<generic> L( n );
  vector<generic> R( m );
   
  for( i = 0; i < n; i++ )
  {
    L[i] = unsorted[start + i];
    
    //Invariant 1: L[j] = A[p + j - 1], j = {1, … ,i – 1}
    assert( L[i] == unsorted[start + i] );
  }
  
  for( j = 0; j < m; j++ )
  {
    R[j] = unsorted[mid + j + 1];
    
    //Invariant 2: R[r] = A[q + r], r = {1, … ,j – 1}
    assert( R[j] == unsorted[mid + j + 1] );
  }
    
  i = 0;
  j = 0; 
  for( int k = start; k <= end; k++ )
  {
    //Invariant 3: The sub array A[p, …, k - 1] contains the k - p smallest elements of L and R in sorted order.
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
    
    //maintenance
    //it is sorted up until k
    assert( Sort<generic>::sortedTest( unsorted, 0, k ) );
  }
}

template<typename generic>
void Sort<generic>::heap_sort( vector<generic> &unsorted )
{
  //precondition 
  //If they can't be accessed at all return
  assert( Sort<generic>::pre_condition_is_array( unsorted ) );
  
  build_max_heap( unsorted );
  for(int i = unsorted.size() - 1; i > 0; i--)
  {
    generic temp = unsorted[0];
    unsorted[0] = unsorted[i];
    unsorted[i] = temp;
    Sort<generic>::heap_size = Sort<generic>::heap_size - 1;
    max_heapify(unsorted, 0);
    
    //Invariant 2: The subarray A[1, …, i] is a max-heap containing the i smallest elements of A  
    //and the subarray A[i + 1, …, n] contains the n - i largest elements of A sorted.
    //maintenance sortedtest
    assert( Sort<generic>::sortedTest( unsorted, i-1, unsorted.size()) );
    assert(unsorted[i-1] < unsorted[i]);
  }
  
  //post condtion 
  //sortedTest function 
  assert( Sort<generic>::sortedTest( unsorted, 0, unsorted.size() ) );
}

template<typename generic>
void Sort<generic>::build_max_heap( vector<generic> &unsorted )
{
  //precondition 
  //If they can't be accessed at all return
  assert( Sort<generic>::pre_condition_is_array( unsorted ) );
  
  Sort<generic>::heap_size = unsorted.size() - 1;
  for( int i = unsorted.size()/2; i > 0; i--)
  {
    max_heapify(unsorted, i);
    
    //Invariant 1: A[i + 1], …, A[n] are roots of max heaps 
    for( int j = i + 1; j < unsorted.size(); j++)
    {
      assert(is_max_heap( unsorted, j ));
    }
  }
  //postcondition
  //A[1], A[2], … , A[n] are roots of max heaps
  for( int i = 0; i < unsorted.size(); i++)
  {
    assert( Sort<generic>::is_max_heap( unsorted, i ));
  }
}

template<typename generic>
void Sort<generic>::max_heapify( vector<generic> &unsorted, int index )
{
  //precondition
  //index has to be an index into unsorted, and there must be left and right heaps or a it must be a leaf node   
  assert( index < unsorted.size() );
  assert( (index > heap_size/2) || ( (2*index) <= unsorted.size() || (2*index+1) <= unsorted.size() )  );
  
  int left = 2 * index;
  int right = 2 * index + 1;
  int largest;
  
  if( left <= Sort<generic>::heap_size && unsorted[left]>unsorted[index])
  {
    largest = left;
  }
  else
  {
    largest = index;
  }
  if( right <= Sort<generic>::heap_size && unsorted[right]>unsorted[largest])
  {
    largest = right;
  }
  if(largest != index)
  {
    //exchange
    int temp = unsorted[index];
    unsorted[index] = unsorted[largest];
    unsorted[largest] = temp;
    max_heapify(unsorted, largest);
  }
  
  //postcondition
  //A max heap is created at i
  //Checking to see if internal node
  if( index < heap_size/2 )
    assert( unsorted[index] >= unsorted[left] && unsorted[index] >= unsorted[right] );
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
      break;
  }
  if( end == 0 )
    sorted = true;
    
  return sorted;
}

template<typename generic>
bool Sort<generic>::pre_condition_is_array( vector<generic> unsorted )
{
  bool isAnArray = true;
  
  for( int i = 0; i < unsorted.size(); i++)
  {
    //if it wasn't possible to access everything in the array this would seg fault
    unsorted[i];
  }
  
  return( isAnArray );
}  

template<typename generic>
bool Sort<generic>::is_max_heap( vector<generic> unsorted, int index )
{  
  //leaf node
  if(index  > (unsorted.size()-1)/2)
    return true;
    
  //if there are both right and left children check both  
  if( 2*(index+1) -1 < unsorted.size() && ((2*(index+1))) < unsorted.size() )
    return (is_max_heap( unsorted,2*(index+1) -1 )) && (is_max_heap( unsorted, (2*(index+1)) ));
  
  //just left, check left  
  if( (2*(index+1) -1) < unsorted.size() )
      return ((is_max_heap( unsorted, 2*(index+1) -1 ))&& unsorted[2*(index+1) -1]<unsorted[index]);
  
  //just right check right
  if( (2*(index+1)) < unsorted.size() )
    return ((is_max_heap( unsorted, (2*(index+1)) ))&& unsorted[(2*(index+1))]<unsorted[index]);

  return true;
}
