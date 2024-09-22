#include <gtest/gtest.h>

#include "../side.hpp"

TEST(Side, IsSolved) {
  {
    auto side = Side::UniformSide(Square::RED);
    EXPECT_TRUE(side.is_solved());
  }
  {
    Side side({{{Square::RED, Square::RED, Square::RED},
                {Square::RED, Square::RED, Square::RED},
                {Square::RED, Square::RED, Square::RED}}});
    EXPECT_TRUE(side.is_solved());
  }
  {
    Side side({{{Square::RED, Square::RED, Square::RED},
                {Square::RED, Square::RED, Square::RED},
                {Square::RED, Square::RED, Square::BLUE}}});
    EXPECT_FALSE(side.is_solved());
  }
}

TEST(Side, IsCrossSolved) {
  {
    auto side = Side::UniformSide(Square::RED);
    EXPECT_TRUE(side.is_cross_solved());
  }
  {
    Side side({{{Square::BLUE, Square::RED, Square::BLUE},
                {Square::RED, Square::RED, Square::RED},
                {Square::BLUE, Square::RED, Square::BLUE}}});
    EXPECT_TRUE(side.is_cross_solved());
  }
  {
    Side side({{{Square::RED, Square::RED, Square::RED},
                {Square::RED, Square::BLUE, Square::RED},
                {Square::RED, Square::RED, Square::RED}}});
    EXPECT_FALSE(side.is_cross_solved());
  }
}

TEST(Side, NumberOfMatchedSquares) {
  {
    auto side = Side::UniformSide(Square::RED);
    EXPECT_EQ(side.number_of_matched_squares(), 9);
  }
  {
    Side side({{{Square::RED, Square::RED, Square::RED},
                {Square::RED, Square::BLUE, Square::RED},
                {Square::RED, Square::RED, Square::BLUE}}});
    EXPECT_EQ(side.number_of_matched_squares(), 2);
  }
  {
    Side side({{{Square::RED, Square::RED, Square::RED},
                {Square::RED, Square::RED, Square::RED},
                {Square::RED, Square::RED, Square::BLUE}}});
    EXPECT_EQ(side.number_of_matched_squares(), 8);
  }
}

TEST(Side, NumberOfMatchedRowsAndColumns) {
  {
    auto side = Side::UniformSide(Square::RED);
    EXPECT_EQ(side.number_of_matching_rows_and_columns(), 6);
  }
  {
    Side side({{{Square::RED, Square::RED, Square::RED},
                {Square::RED, Square::BLUE, Square::RED},
                {Square::RED, Square::RED, Square::BLUE}}});
    EXPECT_EQ(side.number_of_matching_rows_and_columns(), 2);
  }
  {
    Side side({{{Square::RED, Square::RED, Square::RED},
                {Square::RED, Square::RED, Square::RED},
                {Square::RED, Square::RED, Square::BLUE}}});
    EXPECT_EQ(side.number_of_matching_rows_and_columns(), 4);
  }
}

TEST(Side, RotateFace) {
  {
    Side side({{{Square::WHITE, Square::RED, Square::BLUE},
                {Square::WHITE, Square::RED, Square::BLUE},
                {Square::WHITE, Square::RED, Square::BLUE}}});
    side.rotate_face(Rotation::CLOCKWISE);
    Side expected_side({{{Square::WHITE, Square::WHITE, Square::WHITE},
                         {Square::RED, Square::RED, Square::RED},
                         {Square::BLUE, Square::BLUE, Square::BLUE}}});
    EXPECT_EQ(side, expected_side);
  }
  {
    Side side({{{Square::WHITE, Square::RED, Square::BLUE},
                {Square::WHITE, Square::RED, Square::BLUE},
                {Square::WHITE, Square::RED, Square::BLUE}}});
    side.rotate_face(Rotation::COUNTER_CLOCKWISE);
    Side expected_side({{{Square::BLUE, Square::BLUE, Square::BLUE},
                         {Square::RED, Square::RED, Square::RED},
                         {Square::WHITE, Square::WHITE, Square::WHITE}}});
    EXPECT_EQ(side, expected_side);
  }
}
