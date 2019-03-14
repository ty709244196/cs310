/**
 * nqueens
 * @author original author Jon Beck
 * @author modified by Yao Tang
 * @version Nov. 29 2017
 */
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "matrix.h"
using namespace std;
/*
 *New ok function
 * @param queen[] pointer array which rember all the queen's position
 * @param row row for the queen currently placed
 * @param col column for the queen currently placed
 */
bool ok( uint queen[], uint row, uint col )
{
  for( uint i = 0; i < col; i++ )
    {
      //only one queen on each row and each columb
      //calcuate absolute value to make sure they are not on diagonal direction
      if( queen[i] == row || abs( (int)i - (int)col ) ==
	  abs( (int)queen[i] - (int)row ))
      {
	return false;
      }
    }
  return true;
  }
/**
 * This function checks to see if the current placement of queens on
 * the board is ok.  It is ok if no queen attacks another queen.  A
 * return of true means no conflict.  A return of false means at least
 * two queens conflict.  This function is designed for clarity, NOT
 * efficiency.  This function can be vastly improved.
 * @param board the n x n chessboard
 * @return the absence of a conflict with this board arrangement
 *//*
bool ok( const Matrix< bool > & board )
{
  uint n = board.numrows();

  // let row and col range over the entire board
  for( uint row = 0; row < n; row++ )
    for( uint col = 0; col < n; col++ )
      // if row and col designate a queen's position, see if it
      // conflicts with any other queen

      // let tryrow and trycol range over the entire board, looking
      // for a conflicting queen
      for(uint tryrow = 0; tryrow < n; tryrow++ )
        for( uint trycol = 0; trycol < n; trycol++ )
        {
          // if there's a queen at both row,col and tryrow,trycol
          if( board.at(row, col) && board.at(tryrow, trycol) &&
              // and it's not the same spot
              !(row == tryrow && col == trycol ))
          {
            // first check if they're in the same column
            if( col == trycol )
              return false;
            // now check if they're in the sam row
            if( row == tryrow )
              return false;
            // now see if they're in the same "up" diagonal
            if( n - col + row == n - trycol + tryrow )
              return false;
            // and finally the same down diag
            if( row + col + 1 == tryrow + trycol + 1 )
              return false;
          }
	  }
  // if we made it here, then no two queens conflict
  return true;
  }*/

/**
 * a simple procedure to output an ASCII art horizontal line with plus
 * signs where columns will intersect
 */
void hr( uint cols )
{
  cout << "    +";
  for( uint col = 0; col < cols; col++ )
    cout << "---+";
  cout << endl;
}

/**
 * this function dumps the board to std output
 * @param board the board whose arrangement to dump
 */
void printBoard( const Matrix< bool> & board )
{
  hr( board.numrows());
  for( uint row = 0; row < board.numrows(); row++)
  {
    cout << ' ' << setw(2) << board.numrows() - row << " |";
    for( uint col = 0; col < board.numrows(); col++ )
    {
      if( board.at(row, col) )
        cout << " X |";
      else
        cout << "   |";
    }
    cout << endl;
    hr( board.numrows());
  }

  cout << "     ";
  for( uint col = 0; col < board.numrows(); col++ )
    cout << ' ' << (char)( 'a' + col ) << "  ";
  cout << endl;
}

/**
 * This is the recursive backtracking function. When called, k queens
 * have already been placed on the board in columns 0 .. k-1.  We're
 * trying to place the next queen in column k.
 * @param k the column in which to place the current queen
 * @param board the board on which to place the queen
 * @param queen[] the pointer array which record queen's position
 * @param currentRow the vector which remember rows that have a queen
 */
//empty board count as the root of the tree
int c = 1;
void r_backtrack( uint queen[], uint k, Matrix< bool > & board,
		  vector<uint> currentRow )
{
  // are we done?
  if( k == board.numrows() )
  {
    // if so, report and exit
    printBoard( board );
    cout << "number of node examined:" << c << endl;
    exit( 0 );
  }
  // try each row in turn, for this column
  for( uint row = 0; row < board.numrows(); row++ )
    //skip row if row number exsit in currentRow vector
    if( find(currentRow.begin(), currentRow.end(), row ) != currentRow.end() )
    {
    } 
    else
    {
      // put a queen here
      board.at(row, k) = true;
      //remember the row number
      currentRow.push_back (row);
      c++;
      
      // did that cause a conflict?
      if( ok( queen, row, k ))
      {
	//queen in column k is on 'row' row.
	queen[k] = row;
	// keep going
	r_backtrack( queen, k + 1, board, currentRow );
      }
      // if that didn't work, un-try the current attempt
      board.at(row, k) = false;
      //forget the row number
      currentRow.pop_back (); 
    }
}


/**
 * set up the board and start the backtracking algorithm at the
 * top of the search tree
 */
int main( int argc, char* argv[] )
{
  if( argc != 2 )
  {
    cout << "Usage: " << argv[0] << " n" << endl;
    cout << "       where n is the number of queens to place" << endl;
    cout << "       on an n x n chessboard, with 0 < n < 26" << endl;
    exit( 2 );
  }
  uint n = stoul( argv[1] );
  assert (n > 0 && n < 26);
  //use pointer array to rember the queen position
  uint* queen = new uint[n];
  //use vector to rember the row number
  vector< uint > currentRow;

  // initialize a board with no queens
  Matrix< bool > board( n, n );
  for( uint row = 0; row < n; row++)
    for( uint col = 0; col < n; col++ )
      board.at(row, col) = false;

  // start with column 0
  r_backtrack( queen, 0, board, currentRow );
  cout << "No solution" << endl;
  cout << "number of node examined: " << c <<endl;
  exit( 1 );
  delete []queen;
}
