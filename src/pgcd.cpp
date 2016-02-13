/*
        Math library

  PGCD function inplementation 
  Overloading in order:
    -int

*/


#include <libmath/math.h>


int math::pgcd(int x, int y)
{
    if (!y)
	return x;
    else if (x < y)
	return pgcd(y, x);
    else
	return pgcd(y, x%y);
}
