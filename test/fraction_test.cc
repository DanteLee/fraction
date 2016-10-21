#include "gtest/gtest.h"
#include "../src/fraction.h"

using namespace AWEMath;

TEST(Fraction, constructor) {
    Fraction a, b("-5/10"), c(std::string("3/12")), d(12);
    EXPECT_STREQ(a.toString().c_str(), "0");
    EXPECT_STREQ(b.toString().c_str(), "-1/2");
    EXPECT_STREQ(c.toString().c_str(), "1/4");
    EXPECT_STREQ(d.toString().c_str(), "12");
}

TEST(Fraction, getXFunction) {
    Fraction a("5/-10");

    EXPECT_EQ(a.getRawNumerator(), 5);
    EXPECT_EQ(a.getRawDenominator(), -10);
    EXPECT_EQ(a.getNumerator(), -1);
    EXPECT_EQ(a.getDenominator(), 2);
}

TEST(Fraction, valueOf) {
    Fraction a("9/27");
    float c=9, d=27;

    EXPECT_EQ(a.valueOf(), c/d);
}

TEST(Fraction, toString) {
    Fraction a("12/-6");

    EXPECT_STREQ(a.toString().c_str(), "-2");
}

TEST(Fraction, operatorOverride) {
    Fraction a, b("5/-10"), c("9/27");

    a = b + c;
    EXPECT_STREQ(a.toString().c_str(), "-1/6");
    EXPECT_STREQ((c-b).toString().c_str(), "5/6");
    EXPECT_STREQ((c*b).toString().c_str(), "-1/6");
    EXPECT_STREQ((c/b).toString().c_str(), "-2/3");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
