/* File: main.cpp
 * Author: Margret Steele
 * Brief: main to run mindist
 * Date: 10/12/2011
 * Class: CS253
 */
 
#include "assert.h"
#include "editdist.h"

int main()
{
  //srand needed to randomly arrange vectors entries 
  srand( time(NULL) );  
  
  string x = EditDist::randomString( 5 );
  string y = EditDist::randomString( 5 );
  
  unsigned int m = strlen(x.c_str());
  unsigned int n = strlen(y.c_str());
  
  //To track time 
  clock_t start, finish; 
  
  start = clock();  
 
  //EditDist::iterative((x.c_str()), m, (y.c_str()), n);
  
  EditDist::recursive( x, y, 0, 0);
 
  finish = clock();  
  
  //output time
  double time = ( double(finish) - double(start)) / CLOCKS_PER_SEC;  
  //cout << time << endl; 
}
