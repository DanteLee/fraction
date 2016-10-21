#include "fraction.h"

using namespace AWEMath;

int AWEMath::GCD(int a, int b) {
    int x = a >= b ? a : b;
    int y = a + b - x;

    while (x % y != 0) {
        int t = x % y;
        x = y;
        y = t;
    }

    return y;
}

int AWEMath::LCM(int a, int b) {
    if (a * b == 0) return 0;

    int gcd = GCD(a, b);

    return (a / gcd) * b;
}

inline int AWEMath::abs(int a) {
    return a >= 0 ? a : -a;
}

Fraction::Fraction() {
    this->raw_numerator = this->numerator = 0;
    this->raw_denominator = this->denominator = 1;
    this->sign = 1;
}

Fraction::Fraction(const char *input) {
    std::string inp(input);

    new (this) Fraction(inp);
}

Fraction::Fraction(const int up) {
    new (this) Fraction(up, 1);
}

Fraction::Fraction(const std::string &input) {
    int up = 0, down = 1;
    size_t spliter = input.find('/');
    std::stringstream ss;

    if (spliter != std::string::npos) {
        ss << input.substr(0, spliter);
        ss >> up;
        ss.clear();
        ss << input.substr(spliter+1, -1);
        ss >> down;
    } else {
        ss << input;
        ss >> up;
    }

    // placement new
    new(this) Fraction(up, down);
}

Fraction::Fraction(int up, int down) {
    int gcd;

    this->sign = up < 0 || down < 0 ? 0 : 1;
    this->raw_numerator = up;
    this->raw_denominator = down;

    // down > 0, 'up' can both greater or less than 0
    up = sign == 0 ? -abs(up) : abs(up);
    down = abs(down);

    if (up == 0) {
        this->numerator = up;
        this->denominator = 1;
    } else {
        gcd = GCD(abs(up), down);
        this->numerator = up / gcd;
        this->denominator = down / gcd;
    }
}

int Fraction::getNumerator() const {
    return this->numerator;
}

int Fraction::getDenominator() const {
    return this->denominator;
}

int Fraction::getRawNumerator() const {
    return this->raw_numerator;
}

int Fraction::getRawDenominator() const {
    return this->raw_denominator;
}

std::string Fraction::toString() {
    std::stringstream ss;

    if (this->denominator == 1) {
        ss << this->numerator;
    } else {
        ss << this->numerator << '/' << this->denominator;
    }

    return ss.str();
}

float Fraction::valueOf() {
    return (float)(this->numerator) / float(this->denominator);
}

Fraction AWEMath::operator+(const Fraction &a, const Fraction &b) {
    int up, down;

    down = LCM(a.getDenominator(), b.getDenominator());
    up = a.getNumerator() * (down / a.getDenominator()) +
        b.getNumerator() * (down / b.getDenominator());

    return Fraction(up, down);
}

Fraction AWEMath::operator-(const Fraction &a, const Fraction &b) {
    int up, down;

    down = LCM(a.getDenominator(), b.getDenominator());
    up = a.getNumerator() * (down / a.getDenominator()) -
        b.getNumerator() * (down / b.getDenominator());

    return Fraction(up, down);
}

Fraction& Fraction::operator-() {
    this->numerator = -this->numerator;

    return *this;
}

Fraction AWEMath::operator*(const Fraction &a, const Fraction &b) {
    int up, down,
        gcd = GCD(a.getNumerator(), b.getDenominator()),
        gcd1 = GCD(a.getDenominator(), b.getNumerator());

    up = (a.getNumerator() / gcd) *
        (b.getNumerator() / gcd1);
    down = (a.getDenominator() / gcd1) *
        (b.getDenominator() / gcd);

    return Fraction(up, down);
}

Fraction AWEMath::operator/(const Fraction &a, const Fraction &b) {
    int up, down,
        gcd = GCD(a.getNumerator(), b.getNumerator()),
        gcd1 = GCD(a.getDenominator(), b.getDenominator());

    up = (a.getNumerator() / gcd) *
        (b.getDenominator() / gcd1);
    down = (a.getDenominator() / gcd1) *
        (b.getNumerator() / gcd);

    return Fraction(up, down);
}


Fraction& Fraction::operator=(const Fraction &a) {
    this->raw_numerator = this->numerator = a.getNumerator();
    this->raw_denominator = this->denominator = a.getDenominator();
    this->sign = this->valueOf() < 0 ? 0 : 1;

    return *this;
}
