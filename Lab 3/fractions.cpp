#include "fractions.h"
using namespace std;

fractions::Fraction::Fraction(int numerator, int denominator)
{
    // If both are 0, get input from user
    if (numerator == 0 && denominator == 0) {
        cout << "Enter numerator: ";
        cin >> _numerator;
        cout << "Enter denominator: ";
        cin >> _denominator;
    }
    else {
        _numerator = numerator;
        _denominator = denominator;
    }
    // Make sure we don't divide by 0
    if (_denominator == 0) {
        _denominator = 1;
    }
    simplify();
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    // Cross multiply and add
    int new_num = (_numerator * frac._denominator) + (frac._numerator * _denominator);
    int new_den = _denominator * frac._denominator;
    return fractions::Fraction(new_num, new_den);
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    // Cross multiply and subtract
    int new_num = (_numerator * frac._denominator) - (frac._numerator * _denominator);
    int new_den = _denominator * frac._denominator;
    return fractions::Fraction(new_num, new_den);
}

fractions::Fraction fractions::Fraction::operator*(fractions::Fraction const &frac)
{
    // Multiply straight across
    int new_num = _numerator * frac._numerator;
    int new_den = _denominator * frac._denominator;
    return fractions::Fraction(new_num, new_den);
}

fractions::Fraction fractions::Fraction::operator/(fractions::Fraction const &frac)
{
    // Multiply by reciprocal
    int new_num = _numerator * frac._denominator;
    int new_den = _denominator * frac._numerator;
    return fractions::Fraction(new_num, new_den);
}

fractions::Fraction fractions::Fraction::simplify(fractions::Fraction frac)
{
    frac.simplify();
    return frac;
}

void fractions::Fraction::simplify()
{
    // Find GCD and divide both numbers by it
    int divisor = gcd(_numerator, _denominator);
    _numerator = _numerator / divisor;
    _denominator = _denominator / divisor;
    
    // Make sure negative is in numerator
    if (_denominator < 0) {
        _numerator = -_numerator;
        _denominator = -_denominator;
    }
}

int fractions::Fraction::gcd(int a, int b)
{
    // Make numbers positive
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    
    // Keep going until we find GCD
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool fractions::Fraction::operator==(fractions::Fraction const &frac)
{
    // Make copies to simplify and compare
    fractions::Fraction f1 = *this;
    fractions::Fraction f2 = frac;
    f1.simplify();
    f2.simplify();
    return (f1._numerator == f2._numerator && f1._denominator == f2._denominator);
}

ostream &fractions::operator<<(ostream &os, const fractions::Fraction &frac)
{
    os << frac._numerator << "/" << frac._denominator;
    return os;
}
