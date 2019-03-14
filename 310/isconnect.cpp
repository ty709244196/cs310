/*
 * a program to determine whetger an undirected graph is connected
 * uses adjacency matrix representation of a graph
 * @author Yao Tang
 * @version sept. 9 2017
 */
#include <cstdint>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include "matrix.h"
using namespace std;

bool is_connected ( const Matrix <bool> & graph)
{
  vector <bool> reached ( graph.numrows(), false );

  queue <uint8_t> to_be_explored;
  to_be_explored.push ( 0 );

  while ( !to_be_explored.empty() )
  {
    uint8_t current_node = to_be_explored.front();
    to_be_explored.pop ();

    reached.at ( current_node ) = true;
    for ( uint8_t adjacent = 0; adjacent < graph.numrows(); adjacent++ )
    {
      if ( graph.at ( current_node , adjacent ) == true )
      {
	if ( !reached.at ( adjacent ) )
	{
	  to_be_explored.push ( adjacent );
	}
      }
    }
  }
  return find ( reached.begin (), reached.end (), false ) == reached.end ();
}

int main ()
{
  Matrix <bool> graph (4,4);
  graph.at (0, 0) = false;
  graph.at (0, 1) = true;
  graph.at (0, 2) = false;
  graph.at (0, 3) = true;

  graph.at (1, 0) = true;
  graph.at (1, 1) = false;
  graph.at (1, 2) = true;
  graph.at (1, 3) = false;

  graph.at (2, 0) = false;
  graph.at (2, 1) = true;
  graph.at (2, 2) = false;
  graph.at (2, 3) = false;

  graph.at (3, 0) = true;
  graph.at (3, 1) = false;
  graph.at (3, 2) = false;
  graph.at (3, 3) = false;
  
  cout<<"connected?"<<endl;
  
  if (is_connected (graph))
  {
    cout << "True"<< endl;
  }else
  {
    cout << "False"<< endl;
  }
  return 0;
  
}
