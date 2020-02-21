#include "fraction.h"

Fraction::Fraction() : numerator(0), denominator(1)
{
}

Fraction::Fraction(int x, int y) : numerator(x), denominator(y)
{
}

void Fraction::increase(Fraction anotherFraction)
{
    int tmp = anotherFraction.denominator * denominator;
    numerator *= tmp / denominator;
    denominator = tmp;
    anotherFraction.numerator *= tmp / anotherFraction.denominator;
    anotherFraction.denominator = tmp;
    numerator += anotherFraction.numerator;
}

Fraction& Fraction::operator+=(const Fraction& other)
{
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    return *this;
}

Fraction Fraction::operator+(const Fraction& other) const
{
    Fraction tmp(other);
    tmp.numerator = tmp.numerator * denominator + numerator * tmp.denominator;
    tmp.denominator *= denominator;
    return tmp;
}

void Fraction::display(ostream& cout) const
{
    cout << numerator << '/' << denominator;
}

Fraction& Fraction::operator++()
{
    *this += 1;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction tmp(*this);
    *this += 1;
    return tmp;
}