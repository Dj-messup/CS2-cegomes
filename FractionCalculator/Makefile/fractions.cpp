#include "fractions.h"

// Constructor: initializes the fraction
Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) { // Handle division by zero
        _numerator = 0;
        _denominator = 1;
        return;
    }
    _numerator = numerator;
    _denominator = denominator;
    simplify();
}

// Finds the greatest common divisor (GCD) for simplification
int Fraction::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Simplifies the fraction (e.g., 4/6 becomes 2/3)
void Fraction::simplify() {
    int divisor = gcd(abs(_numerator), abs(_denominator));
    _numerator /= divisor;
    _denominator /= divisor;

    // Ensure the denominator is always positive
    if (_denominator < 0) {
        _numerator = -_numerator;
        _denominator = -_denominator;
    }
}

// Adds two fractions
Fraction Fraction::operator+(Fraction const &frac) {
    int newNumerator = (_numerator * frac._denominator) + (frac._numerator * _denominator);
    int newDenominator = _denominator * frac._denominator;
    return Fraction(newNumerator, newDenominator);
}

// Subtracts one fraction from another
Fraction Fraction::operator-(Fraction const &frac) {
    int newNumerator = (_numerator * frac._denominator) - (frac._numerator * _denominator);
    int newDenominator = _denominator * frac._denominator;
    return Fraction(newNumerator, newDenominator);
}

// Multiplies two fractions
Fraction Fraction::operator*(Fraction const &frac) {
    int newNumerator = _numerator * frac._numerator;
    int newDenominator = _denominator * frac._denominator;
    return Fraction(newNumerator, newDenominator);
}

// Divides one fraction by another
Fraction Fraction::operator/(Fraction const &frac) {
    if (frac._numerator == 0) { // Avoid division by zero
        return Fraction(0, 1);
    }
    int newNumerator = _numerator * frac._denominator;
    int newDenominator = _denominator * frac._numerator;
    return Fraction(newNumerator, newDenominator);
}

// Checks if two fractions are equal
bool Fraction::operator==(Fraction const &frac) {
    return (_numerator == frac._numerator && _denominator == frac._denominator);
}

// Outputs the fraction in "numerator/denominator" format
ostream &operator<<(ostream &os, const Fraction &frac) {
    os << frac._numerator << "/" << frac._denominator;
    return os;
}
