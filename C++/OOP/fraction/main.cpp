#include <bits/stdc++.h>
#include "fraction.h"

using namespace std;

ostream& operator<<(ostream& ou, const Fraction& a)
{
    ou << a.numerator << ' ' << a.denominator;
    return ou;
}

istream& operator>>(istream& in, Fraction& a)
{
    in >> a.numerator >> a.denominator;
    return in;
}

int main()
{
    Fraction a(1, 2), b(2, 3);
    // a += b;
    cout << a << '\n';
    Fraction c = a + b;
    cout << c << '\n';
    ++ ++c;
    cout << c << '\n';
    c++ ++;
    cout << c << '\n';
    return 0;
}