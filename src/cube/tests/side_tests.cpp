#include <gtest/gtest.h>

#include "../side.hpp"

TEST(Side, IsSolved) {
  {
    auto side = Side::UniformSide(Square::RED);
    EXPECT_TRUE(side.is_solved());
  }
  {
    Side side(std::array<std::array<Square, 3>, 3>{
        std::array<Square, 3>{Square::RED, Square::RED, Square::RED},
        std::array<Square, 3>{Square::RED, Square::RED, Square::RED},
        std::array<Square, 3>{Square::RED, Square::RED, Square::BLUE}});
    EXPECT_FALSE(side.is_solved());
  }
}
