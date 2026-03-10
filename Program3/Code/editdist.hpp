/*
 * File: mindist.hpp
 * Author: Margret Steele
 * Brief: This is the template implimentation file
 * Date: 10/12/2011
 * Class: CS253
*/

#include "assert.h"
#include <typeinfo>

#define min(a, b) (((a) < (b)) ? (a) : (b))

//credit to Gonzales Cenelia for the iterative method
int EditDist::iterative(const char *first, const char *second, unsigned int m, unsigned int n)
{
  //precondition: S and T are strings
  assert( is_string(first) );
  assert( is_string(second) );
	if (n == 0) 
  {
		return m;
	} 
	else if (m == 0) 
  {
		return n;
	}

  if( first == second )
  {
    return 0;
  }
	// creating a matrix of m+1 rows and n+1 columns
	int **matrix = create_matrix(m + 1, n + 1);

	// initialising the first row of the matrix
	for(unsigned int i = 0; i <= n; ++i) 
  {
		matrix[0][i] = i; 
    
    //Invariant 1: matrix[j, 0] = j, j = {0, …., i – 1} 
    assert( matrix[0][i] == i );
	}

	// initialising the first column of the matrix
	for(int i = 0; i <= m; ++i) 
  {
		matrix[i][0] = i; 
    
    //Invariant 1: matrix[0, k] = k, k = {0, …., j – 1}
    assert( matrix[i][0] == i );
	}

	unsigned int above_cell, left_cell, diagonal_cell, cost;

	// starting the main process for computing 
	// the distance between the two strings "first" and "second"
	for(int i = 1; i <= m; ++i) 
  {
		for(unsigned int j = 1; j <= n; ++j) 
    {
      //Invariant 3: Every step in converting S to T is the most optimal step
      // with code I would prove by contradiction here. I would assume there 
      // was a more optimal solution and then check my solution against that.
			if (first[i-1] == second[j-1])
      {
				cost = 0;
			} 
			else 
      {
				cost = 2;
			}
			// current cell of the matrix: matrix[i][j]

			// finds the above cell to the current cell
			above_cell = matrix[i-1][j];
      
      //output I for insetion
      cout << "I";

			// finds the left cell to the current cell
			left_cell = matrix[i][j-1];
      
      //output D for deletion
      cout << "D";

			// finds the diagonally above cell to the current cell
			diagonal_cell = matrix[i-1][j-1];
      
      //output R for replacement
      cout << "R";

			// computes the current value of the "edit distance" and place
			// the result into the current matrix cell
			matrix[i][j] = _min(above_cell + 1, left_cell + 1, diagonal_cell + cost);
		}
	}

	unsigned int result = matrix[m][n];

	delete_matrix(matrix, m + 1, n + 1);
	
  //PostCondition: the most optimal cost has been returned
  // with code I would prove by contradiction here. I would assume there 
  // was a more optimal solution and then check my solution against that.
  
	return result;
}


int EditDist::recursive(string first, string second, int m, int n)
{
  //precondition: S and T are strings
  assert( is_string(first) );
  assert( is_string(second) );
  
  if (n == second.length())
  {
    return first.length() - m;
  }

  if (m == first.length())
  {
    return second.length() - n;
  }

  if (first[m] == second[n])
  {
    return recursive(first, second, m + 1, n + 1);
  }
  else
  {
    costInsert = recursive(first, second, m, n + 1) + 1;
    costDelete = recursive(first, second, m + 1, n) + 1);
    costReplace = recursive(first, second, m + 1, n + 1) + 2;
    if( min( min( costInsert, costDelete ), costReplace ) == costInsert )
    {
     //output I for insertion
     cout << "I";
    }
    else if( min( min( costInsert, costDelete ), costReplace ) == costDelete )
    {
     //output D for deletion
     cout << "D";
    }
    else
    {
      //output R for replacement
      cout << "R";
    }
    return min( min(
     recursive(first, second, m, n + 1) + 1,
     recursive(first, second, m + 1, n) + 1),
     recursive(first, second, m + 1, n + 1) + 2 );
  }
  
  //PostCondition: the most optimal cost has been returned
  // with code I would prove by contradiction here. I would assume there 
  // was a more optimal solution and then check my solution against that.
}

string EditDist::randomString( int size )
{
  string randomString;
  static const char alpha[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
  
  for( int i = 0; i < size; i++ )
  {
    randomString += alpha[rand() % (sizeof(alpha) - 1)];
  }
  
  return randomString;
}

string EditDist::worstCase( int size )
{
  string worstString;
  static const char num[] =
    "0123456789";
  
  for( int i = 0; i < size; i++ )
  {
    worstString += num[rand() % (sizeof(num) - 1)];
  }
  
  return worstString;
}

bool EditDist::is_string( string isString )
{
  bool passes = false;
  
  if( typeid(isString).name() == "string" )
    passes = true;
  
  return( passes );
}

// credit to Gonzales Cenelia for the _min method
// finds the minimum of three integers
int EditDist::_min(int a, int b, int c) 
{
	return min(min(a, b), c);
}

// credit to Gonzales Cenelia for the create_matrix method
// allocates a 2D array of integers
int** EditDist::create_matrix(int Row, int Col) 
{
	int **array = new int*[Row];
	for(int i = 0; i < Row; ++i) 
  {
		array[i] = new int[Col];
	}
	return array;
}

// credit to Gonzales Cenelia for the delete_matrix method
// deallocates memory
int** EditDist::delete_matrix(int **array, int Row, int Col) 
{
	for(int i = 0; i < Row; ++i) 
  {
		delete array[i];
	}
	delete [] array;
	return array;
}
