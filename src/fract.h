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
    Fract(float  numerator, float  denominator = 1);
    Fract(double numerator, double denominator = 1);
    Fract(Fract const  &other) = default;
    Fract(Fract const &&tmp);

    Fract &operator=(Fract const  &other) = default;
    Fract &operator=(Fract const &&tmp);

    void swap(Fract  &other);
    void swap(Fract &&tmp);
    
private:
    void manageSign();
    void reduce();
};


#endif
