#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "base_math.hpp"
#include "advanced_math.hpp"
#include "mock_turtle.h"

using ::testing::AtLeast;
using ::testing::InSequence;
using ::testing::Return;

TEST(example,soustraction) {
    EXPECT_EQ(ADVANCED_MATH__PGCD(44, 12),12);
}



/*

TEST(PainterTest, CanDrawSomething) {
  MockTurtle turtle;                          // #2
  EXPECT_CALL(turtle, PenDown())              // #3
      .Times(AtLeast(1));

  //Painter painter(&turtle);                   // #4

  //EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
} */

