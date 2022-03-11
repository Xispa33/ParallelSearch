#include <gtest/gtest.h>
#include "base_math.hpp"

TEST(example,addition) {
    /* EXPECT_EQ checks the equality between 2 values. If not, moves on to the next one */
    EXPECT_EQ(BASE_MATH__Addition(2U,3U),5U);
}

TEST(example,soustraction) {
    EXPECT_EQ(BASE_MATH__Subtraction(12, 6),6);
}