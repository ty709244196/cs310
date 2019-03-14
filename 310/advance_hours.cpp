#include <iostream>
#include "advance_hours.h"
using namespace std;

/**
 *function advance_hours
 */
Time advance_hours (Time & t, uint8_t hours )
{
  for (uint8_t i = 0; i < hours * 60; i++)
  {
    t.tick ();
  }
  return t;
}

int main ()
{
  Time t1 {01, 14};
  Time * t2 = new Time {13, 55};
  Time t3 {07, 31};

  advance_hours ( t3, 2 );

  cout << "Time 1 is : " << t1.to_string_24() << endl;

  cout << "Time 2 is : " << t2 -> to_string_ap() << endl;

  cout << "after adding two hours, time 3 is : " 
       << t3.to_string_ap() << endl;

  delete t2;

}
