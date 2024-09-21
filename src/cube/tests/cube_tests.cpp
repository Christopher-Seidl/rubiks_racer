#include <gtest/gtest.h>

#include "../cube.hpp"

TEST(Cube, IsSolved) {
  {
    auto cube = Cube::SolvedCube();
    EXPECT_TRUE(cube.is_solved());
  }
  {
    std::unordered_map<CubeFace, Side> sides_from_faces = {
        {CubeFace::TOP, Side::UniformSide(Square::RED)},
        {CubeFace::BOTTOM, Side::UniformSide(Square::RED)},
        {CubeFace::FRONT, Side::UniformSide(Square::RED)},
        {CubeFace::BACK, Side::UniformSide(Square::RED)},
        {CubeFace::LEFT, Side::UniformSide(Square::RED)},
        {CubeFace::RIGHT, Side::UniformSide(Square::RED)},
    };
    Cube cube(std::move(sides_from_faces));
    EXPECT_TRUE(cube.is_solved());
  }
  {
    std::unordered_map<CubeFace, Side> sides_from_faces = {
        {CubeFace::TOP, Side::UniformSide(Square::RED)},
        {CubeFace::BOTTOM, Side::UniformSide(Square::RED)},
        {CubeFace::FRONT, Side::UniformSide(Square::RED)},
        {CubeFace::BACK, Side::UniformSide(Square::RED)},
        {CubeFace::LEFT, Side::UniformSide(Square::RED)},
        {CubeFace::RIGHT, Side({{{Square::RED, Square::RED, Square::RED},
                                 {Square::RED, Square::RED, Square::RED},
                                 {Square::RED, Square::RED, Square::BLUE}}})},
    };
    Cube cube(std::move(sides_from_faces));
    EXPECT_FALSE(cube.is_solved());
  }
}

// TODO: build out this unit test to cover all cases
TEST(Cube, RotateFace) {
  std::cout << "Testing top face rotation" << std::endl;
  {
    {
      auto cube = Cube::SolvedCube();
      cube.rotate_face(CubeFace::TOP, Rotation::CLOCKWISE);
      Cube expected_cube({
          {CubeFace::TOP, Side::UniformSide(Square::WHITE)},
          {CubeFace::BOTTOM, Side::UniformSide(Square::YELLOW)},
          {CubeFace::FRONT,
           Side({{{Square::RED, Square::RED, Square::RED},
                  {Square::GREEN, Square::GREEN, Square::GREEN},
                  {Square::GREEN, Square::GREEN, Square::GREEN}}})},
          {CubeFace::BACK,
           Side({{{Square::ORANGE, Square::ORANGE, Square::ORANGE},
                  {Square::BLUE, Square::BLUE, Square::BLUE},
                  {Square::BLUE, Square::BLUE, Square::BLUE}}})},
          {CubeFace::LEFT,
           Side({{{Square::GREEN, Square::GREEN, Square::GREEN},
                  {Square::ORANGE, Square::ORANGE, Square::ORANGE},
                  {Square::ORANGE, Square::ORANGE, Square::ORANGE}}})},
          {CubeFace::RIGHT, Side({{{Square::BLUE, Square::BLUE, Square::BLUE},
                                   {Square::RED, Square::RED, Square::RED},
                                   {Square::RED, Square::RED, Square::RED}}})},
      });
      EXPECT_EQ(cube, expected_cube);
    }
    {
      auto cube = Cube::SolvedCube();
      cube.rotate_face(CubeFace::TOP, Rotation::COUNTER_CLOCKWISE);
      Cube expected_cube({
          {CubeFace::TOP, Side::UniformSide(Square::WHITE)},
          {CubeFace::BOTTOM, Side::UniformSide(Square::YELLOW)},
          {CubeFace::FRONT,
           Side({{{Square::ORANGE, Square::ORANGE, Square::ORANGE},
                  {Square::GREEN, Square::GREEN, Square::GREEN},
                  {Square::GREEN, Square::GREEN, Square::GREEN}}})},
          {CubeFace::BACK,
           Side({{{Square::RED, Square::RED, Square::RED},
                  {Square::BLUE, Square::BLUE, Square::BLUE},
                  {Square::BLUE, Square::BLUE, Square::BLUE}}})},
          {CubeFace::LEFT,
           Side({{{Square::BLUE, Square::BLUE, Square::BLUE},
                  {Square::ORANGE, Square::ORANGE, Square::ORANGE},
                  {Square::ORANGE, Square::ORANGE, Square::ORANGE}}})},
          {CubeFace::RIGHT,
           Side({{{Square::GREEN, Square::GREEN, Square::GREEN},
                  {Square::RED, Square::RED, Square::RED},
                  {Square::RED, Square::RED, Square::RED}}})},
      });
      EXPECT_EQ(cube, expected_cube);
    }
  }
  std::cout << "Testing bottom face rotation" << std::endl;
  {
    {
      auto cube = Cube::SolvedCube();
      cube.rotate_face(CubeFace::BOTTOM, Rotation::CLOCKWISE);
      Cube expected_cube({
          {CubeFace::TOP, Side::UniformSide(Square::WHITE)},
          {CubeFace::BOTTOM, Side::UniformSide(Square::YELLOW)},
          {CubeFace::FRONT,
           Side({{{Square::GREEN, Square::GREEN, Square::GREEN},
                  {Square::GREEN, Square::GREEN, Square::GREEN},
                  {Square::ORANGE, Square::ORANGE, Square::ORANGE}}})},
          {CubeFace::BACK, Side({{{Square::BLUE, Square::BLUE, Square::BLUE},
                                  {Square::BLUE, Square::BLUE, Square::BLUE},
                                  {Square::RED, Square::RED, Square::RED}}})},
          {CubeFace::LEFT,
           Side({{{Square::ORANGE, Square::ORANGE, Square::ORANGE},
                  {Square::ORANGE, Square::ORANGE, Square::ORANGE},
                  {Square::BLUE, Square::BLUE, Square::BLUE}}})},
          {CubeFace::RIGHT,
           Side({{{Square::RED, Square::RED, Square::RED},
                  {Square::RED, Square::RED, Square::RED},
                  {Square::GREEN, Square::GREEN, Square::GREEN}}})},
      });
      EXPECT_EQ(cube, expected_cube);
    }
    {
      auto cube = Cube::SolvedCube();
      cube.rotate_face(CubeFace::BOTTOM, Rotation::COUNTER_CLOCKWISE);
      Cube expected_cube({
          {CubeFace::TOP, Side::UniformSide(Square::WHITE)},
          {CubeFace::BOTTOM, Side::UniformSide(Square::YELLOW)},
          {CubeFace::FRONT,
           Side({{{Square::GREEN, Square::GREEN, Square::GREEN},
                  {Square::GREEN, Square::GREEN, Square::GREEN},
                  {Square::RED, Square::RED, Square::RED}}})},
          {CubeFace::BACK,
           Side({{{Square::BLUE, Square::BLUE, Square::BLUE},
                  {Square::BLUE, Square::BLUE, Square::BLUE},
                  {Square::ORANGE, Square::ORANGE, Square::ORANGE}}})},
          {CubeFace::LEFT,
           Side({{{Square::ORANGE, Square::ORANGE, Square::ORANGE},
                  {Square::ORANGE, Square::ORANGE, Square::ORANGE},
                  {Square::GREEN, Square::GREEN, Square::GREEN}}})},
          {CubeFace::RIGHT,
           Side({{{Square::RED, Square::RED, Square::RED},
                  {Square::RED, Square::RED, Square::RED},
                  {Square::BLUE, Square::BLUE, Square::BLUE}}})},
      });
      EXPECT_EQ(cube, expected_cube);
    }
  }
  std::cout << "Testing front face rotation" << std::endl;
  {
    {
      auto cube = Cube::SolvedCube();
      cube.rotate_face(CubeFace::FRONT, Rotation::CLOCKWISE);
      Cube expected_cube({
          {CubeFace::TOP,
           Side({{{Square::WHITE, Square::WHITE, Square::WHITE},
                  {Square::WHITE, Square::WHITE, Square::WHITE},
                  {Square::ORANGE, Square::ORANGE, Square::ORANGE}}})},
          {CubeFace::BOTTOM,
           Side({{{Square::RED, Square::RED, Square::RED},
                  {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                  {Square::YELLOW, Square::YELLOW, Square::YELLOW}}})},
          {CubeFace::FRONT, Side::UniformSide(Square::GREEN)},
          {CubeFace::BACK, Side::UniformSide(Square::BLUE)},
          {CubeFace::LEFT,
           Side({{{Square::ORANGE, Square::ORANGE, Square::YELLOW},
                  {Square::ORANGE, Square::ORANGE, Square::YELLOW},
                  {Square::ORANGE, Square::ORANGE, Square::YELLOW}}})},
          {CubeFace::RIGHT,
           Side({{{Square::WHITE, Square::RED, Square::RED},
                  {Square::WHITE, Square::RED, Square::RED},
                  {Square::WHITE, Square::RED, Square::RED}}})},
      });
      EXPECT_EQ(cube, expected_cube);
    }
    {
      auto cube = Cube::SolvedCube();
      cube.rotate_face(CubeFace::FRONT, Rotation::COUNTER_CLOCKWISE);
      Cube expected_cube({
          {CubeFace::TOP, Side({{{Square::WHITE, Square::WHITE, Square::WHITE},
                                 {Square::WHITE, Square::WHITE, Square::WHITE},
                                 {Square::RED, Square::RED, Square::RED}}})},
          {CubeFace::BOTTOM,
           Side({{{Square::ORANGE, Square::ORANGE, Square::ORANGE},
                  {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                  {Square::YELLOW, Square::YELLOW, Square::YELLOW}}})},
          {CubeFace::FRONT, Side::UniformSide(Square::GREEN)},
          {CubeFace::BACK, Side::UniformSide(Square::BLUE)},
          {CubeFace::LEFT,
           Side({{{Square::ORANGE, Square::ORANGE, Square::WHITE},
                  {Square::ORANGE, Square::ORANGE, Square::WHITE},
                  {Square::ORANGE, Square::ORANGE, Square::WHITE}}})},
          {CubeFace::RIGHT,
           Side({{{Square::YELLOW, Square::RED, Square::RED},
                  {Square::YELLOW, Square::RED, Square::RED},
                  {Square::YELLOW, Square::RED, Square::RED}}})},
      });
      EXPECT_EQ(cube, expected_cube);
    }
  }
}
