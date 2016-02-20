/*
  Math library

  Modulo for floating point type implementation

*/

#include <type_traits>

template<typename T>
std::enable_if_t<std::is_arithmetic<T>{}, T>
    math::fmod(T numer, T denom)
{
    while (numer > denom * 10)
    {
        unsigned int a{}, b{};
        while (numer / math::pow<unsigned int>(10, a++) > 10);
        while (numer / math::pow<unsigned int>(10, a) - ++b > 1);
        numer -= math::pow<unsigned int>(10, a) * b;
    }

    while (numer > denom)
        numer -= denom;

    return numer;
}
