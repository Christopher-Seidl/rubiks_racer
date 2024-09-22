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

TEST(Cube, RotateFace) {
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
  {
    {
      auto cube = Cube::SolvedCube();
      cube.rotate_face(CubeFace::BACK, Rotation::CLOCKWISE);
      Cube expected_cube({
          {CubeFace::TOP,
           Side({{{Square::RED, Square::RED, Square::RED},
                  {Square::WHITE, Square::WHITE, Square::WHITE},
                  {Square::WHITE, Square::WHITE, Square::WHITE}}})},
          {CubeFace::BOTTOM,
           Side({{{Square::YELLOW, Square::YELLOW, Square::YELLOW},
                  {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                  {Square::ORANGE, Square::ORANGE, Square::ORANGE}}})},
          {CubeFace::FRONT, Side::UniformSide(Square::GREEN)},
          {CubeFace::BACK, Side::UniformSide(Square::BLUE)},
          {CubeFace::LEFT,
           Side({{{Square::WHITE, Square::ORANGE, Square::ORANGE},
                  {Square::WHITE, Square::ORANGE, Square::ORANGE},
                  {Square::WHITE, Square::ORANGE, Square::ORANGE}}})},
          {CubeFace::RIGHT,
           Side({{{Square::RED, Square::RED, Square::YELLOW},
                  {Square::RED, Square::RED, Square::YELLOW},
                  {Square::RED, Square::RED, Square::YELLOW}}})},
      });
      EXPECT_EQ(cube, expected_cube);
    }
    {
      auto cube = Cube::SolvedCube();
      cube.rotate_face(CubeFace::BACK, Rotation::COUNTER_CLOCKWISE);
      Cube expected_cube({
          {CubeFace::TOP,
           Side({{{Square::ORANGE, Square::ORANGE, Square::ORANGE},
                  {Square::WHITE, Square::WHITE, Square::WHITE},
                  {Square::WHITE, Square::WHITE, Square::WHITE}}})},
          {CubeFace::BOTTOM,
           Side({{{Square::YELLOW, Square::YELLOW, Square::YELLOW},
                  {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                  {Square::RED, Square::RED, Square::RED}}})},
          {CubeFace::FRONT, Side::UniformSide(Square::GREEN)},
          {CubeFace::BACK, Side::UniformSide(Square::BLUE)},
          {CubeFace::LEFT,
           Side({{{Square::YELLOW, Square::ORANGE, Square::ORANGE},
                  {Square::YELLOW, Square::ORANGE, Square::ORANGE},
                  {Square::YELLOW, Square::ORANGE, Square::ORANGE}}})},
          {CubeFace::RIGHT,
           Side({{{Square::RED, Square::RED, Square::WHITE},
                  {Square::RED, Square::RED, Square::WHITE},
                  {Square::RED, Square::RED, Square::WHITE}}})},
      });
      EXPECT_EQ(cube, expected_cube);
    }
  }
  {
    {
      auto cube = Cube::SolvedCube();
      cube.rotate_face(CubeFace::LEFT, Rotation::CLOCKWISE);
      Cube expected_cube({
          {CubeFace::TOP,
           Side({{{Square::BLUE, Square::WHITE, Square::WHITE},
                  {Square::BLUE, Square::WHITE, Square::WHITE},
                  {Square::BLUE, Square::WHITE, Square::WHITE}}})},
          {CubeFace::BOTTOM,
           Side({{{Square::GREEN, Square::YELLOW, Square::YELLOW},
                  {Square::GREEN, Square::YELLOW, Square::YELLOW},
                  {Square::GREEN, Square::YELLOW, Square::YELLOW}}})},
          {CubeFace::FRONT,
           Side({{{Square::WHITE, Square::GREEN, Square::GREEN},
                  {Square::WHITE, Square::GREEN, Square::GREEN},
                  {Square::WHITE, Square::GREEN, Square::GREEN}}})},
          {CubeFace::BACK,
           Side({{{Square::BLUE, Square::BLUE, Square::YELLOW},
                  {Square::BLUE, Square::BLUE, Square::YELLOW},
                  {Square::BLUE, Square::BLUE, Square::YELLOW}}})},
          {CubeFace::LEFT, Side::UniformSide(Square::ORANGE)},
          {CubeFace::RIGHT, Side::UniformSide(Square::RED)},
      });
      EXPECT_EQ(cube, expected_cube);
    }
    {
      auto cube = Cube::SolvedCube();
      cube.rotate_face(CubeFace::LEFT, Rotation::COUNTER_CLOCKWISE);
      Cube expected_cube({
          {CubeFace::TOP,
           Side({{{Square::GREEN, Square::WHITE, Square::WHITE},
                  {Square::GREEN, Square::WHITE, Square::WHITE},
                  {Square::GREEN, Square::WHITE, Square::WHITE}}})},
          {CubeFace::BOTTOM,
           Side({{{Square::BLUE, Square::YELLOW, Square::YELLOW},
                  {Square::BLUE, Square::YELLOW, Square::YELLOW},
                  {Square::BLUE, Square::YELLOW, Square::YELLOW}}})},
          {CubeFace::FRONT,
           Side({{{Square::YELLOW, Square::GREEN, Square::GREEN},
                  {Square::YELLOW, Square::GREEN, Square::GREEN},
                  {Square::YELLOW, Square::GREEN, Square::GREEN}}})},
          {CubeFace::BACK,
           Side({{{Square::BLUE, Square::BLUE, Square::WHITE},
                  {Square::BLUE, Square::BLUE, Square::WHITE},
                  {Square::BLUE, Square::BLUE, Square::WHITE}}})},
          {CubeFace::LEFT, Side::UniformSide(Square::ORANGE)},
          {CubeFace::RIGHT, Side::UniformSide(Square::RED)},
      });
      EXPECT_EQ(cube, expected_cube);
    }
  }
  {
    {
      auto cube = Cube::SolvedCube();
      cube.rotate_face(CubeFace::RIGHT, Rotation::CLOCKWISE);
      Cube expected_cube({
          {CubeFace::TOP,
           Side({{{Square::WHITE, Square::WHITE, Square::GREEN},
                  {Square::WHITE, Square::WHITE, Square::GREEN},
                  {Square::WHITE, Square::WHITE, Square::GREEN}}})},
          {CubeFace::BOTTOM,
           Side({{{Square::YELLOW, Square::YELLOW, Square::BLUE},
                  {Square::YELLOW, Square::YELLOW, Square::BLUE},
                  {Square::YELLOW, Square::YELLOW, Square::BLUE}}})},
          {CubeFace::FRONT,
           Side({{{Square::GREEN, Square::GREEN, Square::YELLOW},
                  {Square::GREEN, Square::GREEN, Square::YELLOW},
                  {Square::GREEN, Square::GREEN, Square::YELLOW}}})},
          {CubeFace::BACK,
           Side({{{Square::WHITE, Square::BLUE, Square::BLUE},
                  {Square::WHITE, Square::BLUE, Square::BLUE},
                  {Square::WHITE, Square::BLUE, Square::BLUE}}})},
          {CubeFace::LEFT, Side::UniformSide(Square::ORANGE)},
          {CubeFace::RIGHT, Side::UniformSide(Square::RED)},
      });
      EXPECT_EQ(cube, expected_cube);
    }
    {
      auto cube = Cube::SolvedCube();
      cube.rotate_face(CubeFace::RIGHT, Rotation::COUNTER_CLOCKWISE);
      Cube expected_cube({
          {CubeFace::TOP,
           Side({{{Square::WHITE, Square::WHITE, Square::BLUE},
                  {Square::WHITE, Square::WHITE, Square::BLUE},
                  {Square::WHITE, Square::WHITE, Square::BLUE}}})},
          {CubeFace::BOTTOM,
           Side({{{Square::YELLOW, Square::YELLOW, Square::GREEN},
                  {Square::YELLOW, Square::YELLOW, Square::GREEN},
                  {Square::YELLOW, Square::YELLOW, Square::GREEN}}})},
          {CubeFace::FRONT,
           Side({{{Square::GREEN, Square::GREEN, Square::WHITE},
                  {Square::GREEN, Square::GREEN, Square::WHITE},
                  {Square::GREEN, Square::GREEN, Square::WHITE}}})},
          {CubeFace::BACK,
           Side({{{Square::YELLOW, Square::BLUE, Square::BLUE},
                  {Square::YELLOW, Square::BLUE, Square::BLUE},
                  {Square::YELLOW, Square::BLUE, Square::BLUE}}})},
          {CubeFace::LEFT, Side::UniformSide(Square::ORANGE)},
          {CubeFace::RIGHT, Side::UniformSide(Square::RED)},
      });
      EXPECT_EQ(cube, expected_cube);
    }
  }
}

TEST(Cube, RotateFaceMultiple) {
  auto cube = Cube::SolvedCube();
  cube.rotate_face(CubeFace::TOP, Rotation::COUNTER_CLOCKWISE);
  EXPECT_EQ(cube,
            Cube({
                {CubeFace::TOP,
                 Side({{{Square::WHITE, Square::WHITE, Square::WHITE},
                        {Square::WHITE, Square::WHITE, Square::WHITE},
                        {Square::WHITE, Square::WHITE, Square::WHITE}}})},
                {CubeFace::BOTTOM,
                 Side({{{Square::YELLOW, Square::YELLOW, Square::YELLOW},
                        {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                        {Square::YELLOW, Square::YELLOW, Square::YELLOW}}})},
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
            }));
  cube.rotate_face(CubeFace::RIGHT, Rotation::COUNTER_CLOCKWISE);
  EXPECT_EQ(cube,
            Cube({
                {CubeFace::TOP,
                 Side({{{Square::WHITE, Square::WHITE, Square::BLUE},
                        {Square::WHITE, Square::WHITE, Square::BLUE},
                        {Square::WHITE, Square::WHITE, Square::RED}}})},
                {CubeFace::BOTTOM,
                 Side({{{Square::YELLOW, Square::YELLOW, Square::ORANGE},
                        {Square::YELLOW, Square::YELLOW, Square::GREEN},
                        {Square::YELLOW, Square::YELLOW, Square::GREEN}}})},
                {CubeFace::FRONT,
                 Side({{{Square::ORANGE, Square::ORANGE, Square::WHITE},
                        {Square::GREEN, Square::GREEN, Square::WHITE},
                        {Square::GREEN, Square::GREEN, Square::WHITE}}})},
                {CubeFace::BACK,
                 Side({{{Square::YELLOW, Square::RED, Square::RED},
                        {Square::YELLOW, Square::BLUE, Square::BLUE},
                        {Square::YELLOW, Square::BLUE, Square::BLUE}}})},
                {CubeFace::LEFT,
                 Side({{{Square::BLUE, Square::BLUE, Square::BLUE},
                        {Square::ORANGE, Square::ORANGE, Square::ORANGE},
                        {Square::ORANGE, Square::ORANGE, Square::ORANGE}}})},
                {CubeFace::RIGHT,
                 Side({{{Square::GREEN, Square::RED, Square::RED},
                        {Square::GREEN, Square::RED, Square::RED},
                        {Square::GREEN, Square::RED, Square::RED}}})},
            }));
  cube.rotate_face(CubeFace::BOTTOM, Rotation::COUNTER_CLOCKWISE);
  EXPECT_EQ(cube,
            Cube({
                {CubeFace::TOP,
                 Side({{{Square::WHITE, Square::WHITE, Square::BLUE},
                        {Square::WHITE, Square::WHITE, Square::BLUE},
                        {Square::WHITE, Square::WHITE, Square::RED}}})},
                {CubeFace::BOTTOM,
                 Side({{{Square::ORANGE, Square::GREEN, Square::GREEN},
                        {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                        {Square::YELLOW, Square::YELLOW, Square::YELLOW}}})},
                {CubeFace::FRONT,
                 Side({{{Square::ORANGE, Square::ORANGE, Square::WHITE},
                        {Square::GREEN, Square::GREEN, Square::WHITE},
                        {Square::GREEN, Square::RED, Square::RED}}})},
                {CubeFace::BACK,
                 Side({{{Square::YELLOW, Square::RED, Square::RED},
                        {Square::YELLOW, Square::BLUE, Square::BLUE},
                        {Square::ORANGE, Square::ORANGE, Square::ORANGE}}})},
                {CubeFace::LEFT,
                 Side({{{Square::BLUE, Square::BLUE, Square::BLUE},
                        {Square::ORANGE, Square::ORANGE, Square::ORANGE},
                        {Square::GREEN, Square::GREEN, Square::WHITE}}})},
                {CubeFace::RIGHT,
                 Side({{{Square::GREEN, Square::RED, Square::RED},
                        {Square::GREEN, Square::RED, Square::RED},
                        {Square::YELLOW, Square::BLUE, Square::BLUE}}})},
            }));
  cube.rotate_face(CubeFace::FRONT, Rotation::CLOCKWISE);
  EXPECT_EQ(cube,
            Cube({
                {CubeFace::TOP,
                 Side({{{Square::WHITE, Square::WHITE, Square::BLUE},
                        {Square::WHITE, Square::WHITE, Square::BLUE},
                        {Square::WHITE, Square::ORANGE, Square::BLUE}}})},
                {CubeFace::BOTTOM,
                 Side({{{Square::YELLOW, Square::GREEN, Square::GREEN},
                        {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                        {Square::YELLOW, Square::YELLOW, Square::YELLOW}}})},
                {CubeFace::FRONT,
                 Side({{{Square::GREEN, Square::GREEN, Square::ORANGE},
                        {Square::RED, Square::GREEN, Square::ORANGE},
                        {Square::RED, Square::WHITE, Square::WHITE}}})},
                {CubeFace::BACK,
                 Side({{{Square::YELLOW, Square::RED, Square::RED},
                        {Square::YELLOW, Square::BLUE, Square::BLUE},
                        {Square::ORANGE, Square::ORANGE, Square::ORANGE}}})},
                {CubeFace::LEFT,
                 Side({{{Square::BLUE, Square::BLUE, Square::ORANGE},
                        {Square::ORANGE, Square::ORANGE, Square::GREEN},
                        {Square::GREEN, Square::GREEN, Square::GREEN}}})},
                {CubeFace::RIGHT,
                 Side({{{Square::WHITE, Square::RED, Square::RED},
                        {Square::WHITE, Square::RED, Square::RED},
                        {Square::RED, Square::BLUE, Square::BLUE}}})},
            }));
  cube.rotate_face(CubeFace::LEFT, Rotation::COUNTER_CLOCKWISE);
  EXPECT_EQ(cube,
            Cube({
                {CubeFace::TOP,
                 Side({{{Square::GREEN, Square::WHITE, Square::BLUE},
                        {Square::RED, Square::WHITE, Square::BLUE},
                        {Square::RED, Square::ORANGE, Square::BLUE}}})},
                {CubeFace::BOTTOM,
                 Side({{{Square::ORANGE, Square::GREEN, Square::GREEN},
                        {Square::BLUE, Square::YELLOW, Square::YELLOW},
                        {Square::RED, Square::YELLOW, Square::YELLOW}}})},
                {CubeFace::FRONT,
                 Side({{{Square::YELLOW, Square::GREEN, Square::ORANGE},
                        {Square::YELLOW, Square::GREEN, Square::ORANGE},
                        {Square::YELLOW, Square::WHITE, Square::WHITE}}})},
                {CubeFace::BACK,
                 Side({{{Square::YELLOW, Square::RED, Square::WHITE},
                        {Square::YELLOW, Square::BLUE, Square::WHITE},
                        {Square::ORANGE, Square::ORANGE, Square::WHITE}}})},
                {CubeFace::LEFT,
                 Side({{{Square::ORANGE, Square::GREEN, Square::GREEN},
                        {Square::BLUE, Square::ORANGE, Square::GREEN},
                        {Square::BLUE, Square::ORANGE, Square::GREEN}}})},
                {CubeFace::RIGHT,
                 Side({{{Square::WHITE, Square::RED, Square::RED},
                        {Square::WHITE, Square::RED, Square::RED},
                        {Square::RED, Square::BLUE, Square::BLUE}}})},
            }));
  cube.rotate_face(CubeFace::BACK, Rotation::COUNTER_CLOCKWISE);
  EXPECT_EQ(cube,
            Cube({
                {CubeFace::TOP,
                 Side({{{Square::BLUE, Square::BLUE, Square::ORANGE},
                        {Square::RED, Square::WHITE, Square::BLUE},
                        {Square::RED, Square::ORANGE, Square::BLUE}}})},
                {CubeFace::BOTTOM,
                 Side({{{Square::ORANGE, Square::GREEN, Square::GREEN},
                        {Square::BLUE, Square::YELLOW, Square::YELLOW},
                        {Square::BLUE, Square::RED, Square::RED}}})},
                {CubeFace::FRONT,
                 Side({{{Square::YELLOW, Square::GREEN, Square::ORANGE},
                        {Square::YELLOW, Square::GREEN, Square::ORANGE},
                        {Square::YELLOW, Square::WHITE, Square::WHITE}}})},
                {CubeFace::BACK,
                 Side({{{Square::WHITE, Square::WHITE, Square::WHITE},
                        {Square::RED, Square::BLUE, Square::ORANGE},
                        {Square::YELLOW, Square::YELLOW, Square::ORANGE}}})},
                {CubeFace::LEFT,
                 Side({{{Square::RED, Square::GREEN, Square::GREEN},
                        {Square::YELLOW, Square::ORANGE, Square::GREEN},
                        {Square::YELLOW, Square::ORANGE, Square::GREEN}}})},
                {CubeFace::RIGHT,
                 Side({{{Square::WHITE, Square::RED, Square::GREEN},
                        {Square::WHITE, Square::RED, Square::WHITE},
                        {Square::RED, Square::BLUE, Square::BLUE}}})},
            }));
  cube.rotate_face(CubeFace::TOP, Rotation::CLOCKWISE);
  EXPECT_EQ(cube,
            Cube({
                {CubeFace::TOP,
                 Side({{{Square::RED, Square::RED, Square::BLUE},
                        {Square::ORANGE, Square::WHITE, Square::BLUE},
                        {Square::BLUE, Square::BLUE, Square::ORANGE}}})},
                {CubeFace::BOTTOM,
                 Side({{{Square::ORANGE, Square::GREEN, Square::GREEN},
                        {Square::BLUE, Square::YELLOW, Square::YELLOW},
                        {Square::BLUE, Square::RED, Square::RED}}})},
                {CubeFace::FRONT,
                 Side({{{Square::WHITE, Square::RED, Square::GREEN},
                        {Square::YELLOW, Square::GREEN, Square::ORANGE},
                        {Square::YELLOW, Square::WHITE, Square::WHITE}}})},
                {CubeFace::BACK,
                 Side({{{Square::RED, Square::GREEN, Square::GREEN},
                        {Square::RED, Square::BLUE, Square::ORANGE},
                        {Square::YELLOW, Square::YELLOW, Square::ORANGE}}})},
                {CubeFace::LEFT,
                 Side({{{Square::YELLOW, Square::GREEN, Square::ORANGE},
                        {Square::YELLOW, Square::ORANGE, Square::GREEN},
                        {Square::YELLOW, Square::ORANGE, Square::GREEN}}})},
                {CubeFace::RIGHT,
                 Side({{{Square::WHITE, Square::WHITE, Square::WHITE},
                        {Square::WHITE, Square::RED, Square::WHITE},
                        {Square::RED, Square::BLUE, Square::BLUE}}})},
            }));
  cube.rotate_face(CubeFace::BOTTOM, Rotation::COUNTER_CLOCKWISE);
  EXPECT_EQ(cube,
            Cube({
                {CubeFace::TOP,
                 Side({{{Square::RED, Square::RED, Square::BLUE},
                        {Square::ORANGE, Square::WHITE, Square::BLUE},
                        {Square::BLUE, Square::BLUE, Square::ORANGE}}})},
                {CubeFace::BOTTOM,
                 Side({{{Square::GREEN, Square::YELLOW, Square::RED},
                        {Square::GREEN, Square::YELLOW, Square::RED},
                        {Square::ORANGE, Square::BLUE, Square::BLUE}}})},
                {CubeFace::FRONT,
                 Side({{{Square::WHITE, Square::RED, Square::GREEN},
                        {Square::YELLOW, Square::GREEN, Square::ORANGE},
                        {Square::RED, Square::BLUE, Square::BLUE}}})},
                {CubeFace::BACK,
                 Side({{{Square::RED, Square::GREEN, Square::GREEN},
                        {Square::RED, Square::BLUE, Square::ORANGE},
                        {Square::YELLOW, Square::ORANGE, Square::GREEN}}})},
                {CubeFace::LEFT,
                 Side({{{Square::YELLOW, Square::GREEN, Square::ORANGE},
                        {Square::YELLOW, Square::ORANGE, Square::GREEN},
                        {Square::YELLOW, Square::WHITE, Square::WHITE}}})},
                {CubeFace::RIGHT,
                 Side({{{Square::WHITE, Square::WHITE, Square::WHITE},
                        {Square::WHITE, Square::RED, Square::WHITE},
                        {Square::YELLOW, Square::YELLOW, Square::ORANGE}}})},
            }));
  cube.rotate_face(CubeFace::RIGHT, Rotation::CLOCKWISE);
  EXPECT_EQ(cube,
            Cube({
                {CubeFace::TOP,
                 Side({{{Square::RED, Square::RED, Square::GREEN},
                        {Square::ORANGE, Square::WHITE, Square::ORANGE},
                        {Square::BLUE, Square::BLUE, Square::BLUE}}})},
                {CubeFace::BOTTOM,
                 Side({{{Square::GREEN, Square::YELLOW, Square::YELLOW},
                        {Square::GREEN, Square::YELLOW, Square::RED},
                        {Square::ORANGE, Square::BLUE, Square::RED}}})},
                {CubeFace::FRONT,
                 Side({{{Square::WHITE, Square::RED, Square::RED},
                        {Square::YELLOW, Square::GREEN, Square::RED},
                        {Square::RED, Square::BLUE, Square::BLUE}}})},
                {CubeFace::BACK,
                 Side({{{Square::ORANGE, Square::GREEN, Square::GREEN},
                        {Square::BLUE, Square::BLUE, Square::ORANGE},
                        {Square::BLUE, Square::ORANGE, Square::GREEN}}})},
                {CubeFace::LEFT,
                 Side({{{Square::YELLOW, Square::GREEN, Square::ORANGE},
                        {Square::YELLOW, Square::ORANGE, Square::GREEN},
                        {Square::YELLOW, Square::WHITE, Square::WHITE}}})},
                {CubeFace::RIGHT,
                 Side({{{Square::YELLOW, Square::WHITE, Square::WHITE},
                        {Square::YELLOW, Square::RED, Square::WHITE},
                        {Square::ORANGE, Square::WHITE, Square::WHITE}}})},
            }));
}

TEST(Cube, RotateFaceFailingCase) {
  {
    auto cube = Cube::SolvedCube();
    cube.rotate_face(CubeFace::FRONT, Rotation::COUNTER_CLOCKWISE);
    EXPECT_EQ(cube,
              Cube({
                  {CubeFace::TOP,
                   Side({{{Square::WHITE, Square::WHITE, Square::WHITE},
                          {Square::WHITE, Square::WHITE, Square::WHITE},
                          {Square::RED, Square::RED, Square::RED}}})},
                  {CubeFace::BOTTOM,
                   Side({{{Square::ORANGE, Square::ORANGE, Square::ORANGE},
                          {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                          {Square::YELLOW, Square::YELLOW, Square::YELLOW}}})},
                  {CubeFace::FRONT,
                   Side({{{Square::GREEN, Square::GREEN, Square::GREEN},
                          {Square::GREEN, Square::GREEN, Square::GREEN},
                          {Square::GREEN, Square::GREEN, Square::GREEN}}})},
                  {CubeFace::BACK,
                   Side({{{Square::BLUE, Square::BLUE, Square::BLUE},
                          {Square::BLUE, Square::BLUE, Square::BLUE},
                          {Square::BLUE, Square::BLUE, Square::BLUE}}})},
                  {CubeFace::LEFT,
                   Side({{{Square::ORANGE, Square::ORANGE, Square::WHITE},
                          {Square::ORANGE, Square::ORANGE, Square::WHITE},
                          {Square::ORANGE, Square::ORANGE, Square::WHITE}}})},
                  {CubeFace::RIGHT,
                   Side({{{Square::YELLOW, Square::RED, Square::RED},
                          {Square::YELLOW, Square::RED, Square::RED},
                          {Square::YELLOW, Square::RED, Square::RED}}})},
              }));
    cube.rotate_face(CubeFace::TOP, Rotation::CLOCKWISE);
    EXPECT_EQ(cube,
              Cube({
                  {CubeFace::TOP,
                   Side({{{Square::RED, Square::WHITE, Square::WHITE},
                          {Square::RED, Square::WHITE, Square::WHITE},
                          {Square::RED, Square::WHITE, Square::WHITE}}})},
                  {CubeFace::BOTTOM,
                   Side({{{Square::ORANGE, Square::ORANGE, Square::ORANGE},
                          {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                          {Square::YELLOW, Square::YELLOW, Square::YELLOW}}})},
                  {CubeFace::FRONT,
                   Side({{{Square::YELLOW, Square::RED, Square::RED},
                          {Square::GREEN, Square::GREEN, Square::GREEN},
                          {Square::GREEN, Square::GREEN, Square::GREEN}}})},
                  {CubeFace::BACK,
                   Side({{{Square::ORANGE, Square::ORANGE, Square::WHITE},
                          {Square::BLUE, Square::BLUE, Square::BLUE},
                          {Square::BLUE, Square::BLUE, Square::BLUE}}})},
                  {CubeFace::LEFT,
                   Side({{{Square::GREEN, Square::GREEN, Square::GREEN},
                          {Square::ORANGE, Square::ORANGE, Square::WHITE},
                          {Square::ORANGE, Square::ORANGE, Square::WHITE}}})},
                  {CubeFace::RIGHT,
                   Side({{{Square::BLUE, Square::BLUE, Square::BLUE},
                          {Square::YELLOW, Square::RED, Square::RED},
                          {Square::YELLOW, Square::RED, Square::RED}}})},
              }));
    cube.rotate_face(CubeFace::FRONT, Rotation::COUNTER_CLOCKWISE);
    EXPECT_EQ(cube,
              Cube({
                  {CubeFace::TOP,
                   Side({{{Square::RED, Square::WHITE, Square::WHITE},
                          {Square::RED, Square::WHITE, Square::WHITE},
                          {Square::BLUE, Square::YELLOW, Square::YELLOW}}})},
                  {CubeFace::BOTTOM,
                   Side({{{Square::GREEN, Square::WHITE, Square::WHITE},
                          {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                          {Square::YELLOW, Square::YELLOW, Square::YELLOW}}})},
                  {CubeFace::FRONT,
                   Side({{{Square::RED, Square::GREEN, Square::GREEN},
                          {Square::RED, Square::GREEN, Square::GREEN},
                          {Square::YELLOW, Square::GREEN, Square::GREEN}}})},
                  {CubeFace::BACK,
                   Side({{{Square::ORANGE, Square::ORANGE, Square::WHITE},
                          {Square::BLUE, Square::BLUE, Square::BLUE},
                          {Square::BLUE, Square::BLUE, Square::BLUE}}})},
                  {CubeFace::LEFT,
                   Side({{{Square::GREEN, Square::GREEN, Square::WHITE},
                          {Square::ORANGE, Square::ORANGE, Square::WHITE},
                          {Square::ORANGE, Square::ORANGE, Square::RED}}})},
                  {CubeFace::RIGHT,
                   Side({{{Square::ORANGE, Square::BLUE, Square::BLUE},
                          {Square::ORANGE, Square::RED, Square::RED},
                          {Square::ORANGE, Square::RED, Square::RED}}})},
              }));
  }
  {
    auto cube = Cube::SolvedCube();
    cube.rotate_face(CubeFace::TOP, Rotation::CLOCKWISE);
    EXPECT_EQ(cube,
              Cube({
                  {CubeFace::TOP,
                   Side({{{Square::WHITE, Square::WHITE, Square::WHITE},
                          {Square::WHITE, Square::WHITE, Square::WHITE},
                          {Square::WHITE, Square::WHITE, Square::WHITE}}})},
                  {CubeFace::BOTTOM,
                   Side({{{Square::YELLOW, Square::YELLOW, Square::YELLOW},
                          {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                          {Square::YELLOW, Square::YELLOW, Square::YELLOW}}})},
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
                  {CubeFace::RIGHT,
                   Side({{{Square::BLUE, Square::BLUE, Square::BLUE},
                          {Square::RED, Square::RED, Square::RED},
                          {Square::RED, Square::RED, Square::RED}}})},
              }));
    cube.rotate_face(CubeFace::BACK, Rotation::COUNTER_CLOCKWISE);
    EXPECT_EQ(cube,
              Cube({
                  {CubeFace::TOP,
                   Side({{{Square::ORANGE, Square::ORANGE, Square::GREEN},
                          {Square::WHITE, Square::WHITE, Square::WHITE},
                          {Square::WHITE, Square::WHITE, Square::WHITE}}})},
                  {CubeFace::BOTTOM,
                   Side({{{Square::YELLOW, Square::YELLOW, Square::YELLOW},
                          {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                          {Square::RED, Square::RED, Square::BLUE}}})},
                  {CubeFace::FRONT,
                   Side({{{Square::RED, Square::RED, Square::RED},
                          {Square::GREEN, Square::GREEN, Square::GREEN},
                          {Square::GREEN, Square::GREEN, Square::GREEN}}})},
                  {CubeFace::BACK,
                   Side({{{Square::ORANGE, Square::BLUE, Square::BLUE},
                          {Square::ORANGE, Square::BLUE, Square::BLUE},
                          {Square::ORANGE, Square::BLUE, Square::BLUE}}})},
                  {CubeFace::LEFT,
                   Side({{{Square::YELLOW, Square::GREEN, Square::GREEN},
                          {Square::YELLOW, Square::ORANGE, Square::ORANGE},
                          {Square::YELLOW, Square::ORANGE, Square::ORANGE}}})},
                  {CubeFace::RIGHT,
                   Side({{{Square::BLUE, Square::BLUE, Square::WHITE},
                          {Square::RED, Square::RED, Square::WHITE},
                          {Square::RED, Square::RED, Square::WHITE}}})},
              }));
    cube.rotate_face(CubeFace::BACK, Rotation::CLOCKWISE);
    EXPECT_EQ(cube,
              Cube({
                  {CubeFace::TOP,
                   Side({{{Square::WHITE, Square::WHITE, Square::WHITE},
                          {Square::WHITE, Square::WHITE, Square::WHITE},
                          {Square::WHITE, Square::WHITE, Square::WHITE}}})},
                  {CubeFace::BOTTOM,
                   Side({{{Square::YELLOW, Square::YELLOW, Square::YELLOW},
                          {Square::YELLOW, Square::YELLOW, Square::YELLOW},
                          {Square::YELLOW, Square::YELLOW, Square::YELLOW}}})},
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
                  {CubeFace::RIGHT,
                   Side({{{Square::BLUE, Square::BLUE, Square::BLUE},
                          {Square::RED, Square::RED, Square::RED},
                          {Square::RED, Square::RED, Square::RED}}})},
              }));
    cube.rotate_face(CubeFace::TOP, Rotation::COUNTER_CLOCKWISE);
    EXPECT_EQ(cube, Cube::SolvedCube());
  }
}

TEST(Cube, FuzzTestingRotations) {
  srand(time(nullptr));
  std::vector<std::pair<CubeFace, Rotation>> action_history;
  auto cube = Cube::SolvedCube();
  for (size_t _ = 0; _ < 100000; _++) {
    auto face = static_cast<CubeFace>(rand() % 6);
    auto rotation = static_cast<Rotation>(rand() % 2);
    cube.rotate_face(face, rotation);
    action_history.push_back({face, rotation});
  }
  // iterate backwards to undo the actions
  for (auto it = action_history.rbegin(); it != action_history.rend(); it++) {
    auto [face, rotation] = *it;
    cube.rotate_face(face, reverse_rotation(rotation));
  }
  EXPECT_EQ(cube, Cube::SolvedCube());
}
