/**
 * exhaustive-search discrete knapsack
 * @author originally written by Jon Beck
 * @author modified by Yao Tang
 * @version Sept. 30, 2017
 */
#define FIELD_WIDTH 6
#include <climits>
#include <iomanip>
#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

/**
 * C++ has floating-point exponentiation named pow in the cmath library,
 * but no integer exponentiation. This is unsigned integer exponentiation.
 * @param base the base which is being raised to a power
 * @param exp the exponent to which to raise the base
 * @return base raised to the exp power
 */
uint ipow(uint base, uint exp)
{
  if( base == 0 )
    return 1;
  uint result = 1;
  while( exp > 0 )
  {
    if( (exp & 1) == 1 )
      result *= base;
    exp >>= 1;
    base *= base;
  }
  return result;
}

int main()
{
  uint capacity = 20;
  /**
   *input a
   *creat two vectors, weights and values with a elements
   *fill in with random number form 1 to 10
   */
  vector<uint> weights;
  srand((unsigned)time(NULL));
  int a;
  cin >> a;
    
  for (int i =0; i < a; i++)
  {
    int weight = rand() % 10 + 1;
    weights.push_back(weight);
  }

  vector<uint> values;
  srand((unsigned)time(NULL));
    
  for (int i =0; i < a; i++)
  {
    int value = rand() % 10 + 1;
    values.push_back(value);
  }
  // cin >> capacity;

  /*vector<uint> weights;
  vector<uint> values;

  while( ! cin.eof() )
  {
    uint weight;
    uint value;
    cin >> weight >> value;
    if( ! cin.eof() )
    {
      weights.push_back( weight );
      values.push_back( value );
    }
    }*/

  uint n = weights.size();
  uint ps_size = ipow( 2, n );
  uint count = 0;
  for( uint subset_count = 0; subset_count < ps_size; subset_count++ )
  {
    string subset = "{ ";
    uint total_value = 0;
    uint total_weight = 0;
    uint current_value = subset_count;
    uint bit_position = 0;
    count++;
    while( current_value > 0 )
    {
      if(( current_value & 1 ) == 1 )
      {
        total_value += values.at( bit_position );
        total_weight += weights.at( bit_position );
        subset += to_string( bit_position ) + " ";
      }
      bit_position++;
      current_value >>= 1;
      
    }
    

    subset += "}";
    cout << setw( n * 3 ) << left << subset;
    cout << setw( FIELD_WIDTH ) << right << total_weight;
    if( total_weight > capacity )
    {
      cout << setw( FIELD_WIDTH ) << right << "NF" << endl;
    }
    else
    {
      cout << setw( FIELD_WIDTH ) << right << total_value << endl;
    }
    
  }
  cerr << weights.size() << " " <<count << endl;
  return 0;
}
