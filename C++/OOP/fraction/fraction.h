#ifndef fraction_h
#define fraction_h

#include <bits/stdc++.h>

using namespace std;

class Fraction
{
private:
    int numerator, denominator;
public:
    Fraction();
    Fraction(int x, int y = 1);
    void increase(Fraction anotherFraction);
    Fraction& operator+=(const Fraction& other);
    Fraction operator+(const Fraction& other) const;

    void display(ostream& ou = cout) const;

    friend istream& operator>>(istream& in, Fraction& a);
    friend ostream& operator<<(ostream& cout, const Fraction& a);

    Fraction& operator++();
    Fraction operator++(int);
};



#endif