#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <string>
#include <iostream>
#include <sstream>

namespace AWEMath {

class Fraction {
public:
    Fraction();
    Fraction(const char *);
    Fraction(const std::string &);
    Fraction(int, int);

    int getNumerator() const;
    int getDenominator() const;
    int getRawNumerator() const;
    int getRawDenominator() const;

    friend Fraction operator+(const Fraction &, const Fraction &);

    friend Fraction operator-(const Fraction &, const Fraction &);
    Fraction& operator-();

    friend Fraction operator*(const Fraction &, const Fraction &);

    friend Fraction operator/(const Fraction &, const Fraction &);

    Fraction& operator=(const Fraction &);

    std::string toString();
    float valueOf();
private:
    int raw_numerator;
    int raw_denominator;
    int numerator;
    int denominator;
    int sign;
};
Fraction operator+(const Fraction &, const Fraction &);
Fraction operator-(const Fraction &, const Fraction &);
Fraction operator*(const Fraction &, const Fraction &);
Fraction operator/(const Fraction &, const Fraction &);

int GCD(int, int);
int LCM(int, int);
inline int abs(int);
}

#endif
