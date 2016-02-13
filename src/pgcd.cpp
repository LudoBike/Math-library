/*
        Math library

  PGCD function implementation 
  Overloading in order:
    -int

*/


#include <libmath/math.h>


int math::pgcd(int const x, int const y)
{
    if (!y)
	return x;
    else if (x < y)
	return pgcd(y, x);
    else
	return pgcd(y, x%y);
}
