/*
        Math library

  Fraction class declaration

*/

#ifndef __FRACT_H__
# define __FRACT_H__


#include <libmath/math.h>

class math::Fract
{
    int d_numerator;
    int d_denominator;

public:
    Fract(int const numerator, int const denominator = 1);
    Fract(float numerator, float denominator = 1);
    
private:
    void manageSign();
    void reduce();
};


#endif
