#ifndef TIME
#define TIME

#include <cstdint>
#include <string>
using namespace std;

/**
 *A class named Time stores hours and minutes as unsigned shorts.
 *@author Yao Tang
 *@version 3 Sept. 2017
 */

class Time
{
public:

/**
  * constructor with two parameters
  */
  explicit Time (uint8_t hour = 0, uint8_t minute = 0 )
    :hour { hour }, minute { minute }
  {}

/**
 *lvalue copy constuctor
 */
  Time ( const Time & rhs)
    :minute ( rhs.minute ), hour ( rhs.hour )
  {}

/**
 *lvalue operator=
 */
  Time & operator= ( const Time & rhs )
  {
    hour = rhs.hour;
    minute = rhs.minute;
    return *this;
  }

/**
 *disable rvalue copy constructor
 */
  Time ( Time && rhs) = delete;

/**
 *disable rvalue operator=
 */
  Time & operator= ( Time && rhs) = delete;

/**
 *destuctor
 */
  ~Time ()
  {}

/**
 *Accessor
 *@ruturn 5-character string
 */
  string to_string_24() const
  {
    if ( hour < 12 )
    {
      return string( "0" ) + to_string(hour) 
	+ string(":") + to_string(minute);
    }
  else 
  {
    return to_string(hour) + string(":") 
      + to_string(minute);
  }
  }

  string to_string_ap() const
  {
    if ( hour < 12 )
    {
      return to_string(hour) + string(":") 
	    + to_string(minute) + string("AM");
    }
    if ( hour > 12 && hour < 24)
    {
      return to_string(hour-12) + string(":") 
	    + to_string(minute)+ string ("PM");
    }
    if ( hour == 12 )
    {
      return to_string(hour) + string(":")
	    + to_string(minute) + string ("PM");
    }
    if ( hour == 24 )
    {
      return to_string(hour-24) + string(":") 
	    + to_string(minute) + string ("AM");
    }
  }

/**
 *increments the stored time by one minute
 */
  void tick ()
  {
    minute ++;;

    while ( minute > 60)
    {
      minute -= 60;
      hour ++;
    }
  }

private:

 uint8_t hour;
 uint8_t minute;

};
#endif
