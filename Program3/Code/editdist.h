/* File: editdist.h
 * Author: Margret Steele
 * Brief: edit distance class header file
 * Date: 10/23/2011
 * Class: CS253
 */
#ifndef EDITDIST_H
#define EDITDIST_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
using std::string;
using std::cout;
using std::endl;
		

using namespace std;

class EditDist
{

 public:
 /* 
  * Function: iterative 
  * Brief: This is the iterative version of the edit distance algorithm
  * Pre: first and second must be strings
  * Post: the most optimal cost has been returned 
  * Author: Gonzales Cenelia
  * URL: http://ai-programming.com/distance.html
  */
  static int iterative(const char *first, const char *second, unsigned int m, unsigned int n);
  
 /* 
  * Function: recursive
  * Brief: This is the recursive version of the edit distance algorithm
  * Pre: first and second must be strings
  * Post: the most optimal cost has been returned 
  * Author: Margret Steele
  */
  static int recursive(string first, string second, int m, int n); 
  
 /* 
  * Function: randomString
  * Brief: creating a random string of size long
  * Pre: n/a 
  * Post: random string that is size 
  * Author: Margret Steele
  */
  static string randomString( int size );
 
 /* 
  * Function: worstRecurse
  * Brief: creating a string of size long
  * Pre: n/a 
  * Post: string that is size long
  * Author: Margret Steele
  */ 
  static string worstCase( int size );
  
  /* 
  * Function: is_string
  * Brief: testing to see if something is a string
  * Pre: n/a 
  * Post: will return true if isString is a string
  * Author: Margret Steele
  */
  static bool is_string( string isString );
  
  /* 
  * Function: _min 
  * Brief: returns the min of a, b, and c
  * Pre: n/a
  * Post: the min of a, b, c will be returned 
  * Author: Gonzales Cenelia
  * URL: http://ai-programming.com/distance.html
  */
  static int _min(int a, int b, int c);
  
  /* 
  * Function: **create_matrix 
  * Brief: This creates the 2D array for the iterative version of the edit distance algorithm
  * Pre: n/a
  * Post: a 2D array of Row x Col 
  * Author: Gonzales Cenelia
  * URL: http://ai-programming.com/distance.html
  */
  static int **create_matrix(int Row, int Col);
  
  /* 
  * Function: **delete_matrix
  * Brief: This deletes the 2D array for the iterative version of the edit distance algorithm
  * Pre: n/a
  * Post: the 2D array is deleted
  * Author: Gonzales Cenelia
  * URL: http://ai-programming.com/distance.html
  */
  static int **delete_matrix(int **array, int Row, int Col);
   
};


#include"EditDist.hpp"
#endif