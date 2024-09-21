#include <gtest/gtest.h>

#include "../side.hpp"

TEST(Side, IsSolved) {
  {
    auto side = Side::UniformSide(Square::RED);
    EXPECT_TRUE(side.is_solved());
  }
  {
    Side side({
        {Square::RED, Square::RED, Square::RED},
        {Square::RED, Square::RED, Square::RED},
        {Square::RED, Square::RED, Square::BLUE},
    });
    EXPECT_FALSE(side.is_solved());
  }
}
