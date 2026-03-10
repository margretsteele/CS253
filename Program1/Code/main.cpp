/* File: main.cpp
 * Author: Margret Steele
 * Brief: main to run sorts
 * Date: 9/19/2011
 * Class: CS253
 */
 
#include "assert.h"
#include "sort.h"

int main()
{

  //srand needed to randomly arrange vectors entries 
  srand( time(NULL) );  
  
  //To track time 
  clock_t start, finish; 
  
  vector<int> a;  
  
  //INSERT AND SHUFFLE ENTIRES
  Sort<int>::insertEntries( a, 2000 );  
  Sort<int>::shuffleEntries( a ); 
  
  start = clock();  
  
  //SORT ENTRIES
  Sort<int>::insertion( a );
  Sort<int>::merge_sort( a, 0, a.size()-1 );   
  
  finish = clock();  
  
  //output time
  double time = ( double(finish) - double(start)) / CLOCKS_PER_SEC;  
  cout << time << endl; 
}
