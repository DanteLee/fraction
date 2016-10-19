#include "fraction.h"

using namespace AWEMath;


int main(int argc, char **argv) {
    Fraction a, b("-5/10"), c(std::string("4/12"));

    std::cout << a.toString() << b.toString() << c.toString();
}
