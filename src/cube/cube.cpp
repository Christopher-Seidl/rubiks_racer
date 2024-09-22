#include "cube.hpp"

Cube::Cube(std::unordered_map<CubeFace, Side> &&sides_from_faces)
    : m_sides_from_faces(std::move(sides_from_faces)) {}

Cube Cube::SolvedCube() {
  std::unordered_map<CubeFace, Side> sides_from_faces = {
      {CubeFace::TOP, Side::UniformSide(Square::WHITE)},
      {CubeFace::BOTTOM, Side::UniformSide(Square::YELLOW)},
      {CubeFace::FRONT, Side::UniformSide(Square::GREEN)},
      {CubeFace::BACK, Side::UniformSide(Square::BLUE)},
      {CubeFace::LEFT, Side::UniformSide(Square::ORANGE)},
      {CubeFace::RIGHT, Side::UniformSide(Square::RED)},
  };
  return Cube(std::move(sides_from_faces));
}

bool Cube::is_solved() const {
  for (const auto &[_, side] : m_sides_from_faces) {
    if (!side.is_solved()) {
      return false;
    }
  }
  return true;
}

size_t Cube::number_of_matched_squares() const {
  size_t matched_squares = 0;
  for (const auto &[_, side] : m_sides_from_faces) {
    matched_squares += side.number_of_matched_squares();
  }
  return matched_squares;
}

// TODO: this is digusting, fix
void Cube::rotate_face(CubeFace face, Rotation rotation) {
  Side &side = m_sides_from_faces.at(face);
  side.rotate_face(rotation);
  Side &top = m_sides_from_faces.at(CubeFace::TOP);
  Side &bottom = m_sides_from_faces.at(CubeFace::BOTTOM);
  Side &front = m_sides_from_faces.at(CubeFace::FRONT);
  Side &back = m_sides_from_faces.at(CubeFace::BACK);
  Side &left = m_sides_from_faces.at(CubeFace::LEFT);
  Side &right = m_sides_from_faces.at(CubeFace::RIGHT);
  switch (face) {
  case CubeFace::TOP: {
    switch (rotation) {
    case Rotation::CLOCKWISE:
      for (size_t i = 0; i < 3; i++) {
        Square temp = front.m_squares[0][i];
        front.m_squares[0][i] = right.m_squares[0][i];
        right.m_squares[0][i] = back.m_squares[0][i];
        back.m_squares[0][i] = left.m_squares[0][i];
        left.m_squares[0][i] = temp;
      }
      return;
    case Rotation::COUNTER_CLOCKWISE:
      for (size_t i = 0; i < 3; i++) {
        Square temp = front.m_squares[0][i];
        front.m_squares[0][i] = left.m_squares[0][i];
        left.m_squares[0][i] = back.m_squares[0][i];
        back.m_squares[0][i] = right.m_squares[0][i];
        right.m_squares[0][i] = temp;
      }
      return;
    }
  }
  case CubeFace::BOTTOM: {
    switch (rotation) {
    case Rotation::CLOCKWISE:
      for (size_t i = 0; i < 3; i++) {
        Square temp = front.m_squares[2][i];
        front.m_squares[2][i] = left.m_squares[2][i];
        left.m_squares[2][i] = back.m_squares[2][i];
        back.m_squares[2][i] = right.m_squares[2][i];
        right.m_squares[2][i] = temp;
      }
      return;
    case Rotation::COUNTER_CLOCKWISE:
      for (size_t i = 0; i < 3; i++) {
        Square temp = front.m_squares[2][i];
        front.m_squares[2][i] = right.m_squares[2][i];
        right.m_squares[2][i] = back.m_squares[2][i];
        back.m_squares[2][i] = left.m_squares[2][i];
        left.m_squares[2][i] = temp;
      }
      return;
    }
  }
  case CubeFace::FRONT: {
    switch (rotation) {
    case Rotation::CLOCKWISE:
      for (size_t i = 0; i < 3; i++) {
        Square temp = top.m_squares[2][i];
        top.m_squares[2][i] = left.m_squares[2 - i][2];
        left.m_squares[2 - i][2] = bottom.m_squares[0][2 - i];
        bottom.m_squares[0][2 - i] = right.m_squares[i][0];
        right.m_squares[i][0] = temp;
      }
      return;
    case Rotation::COUNTER_CLOCKWISE:
      for (size_t i = 0; i < 3; i++) {
        Square temp = top.m_squares[2][i];
        top.m_squares[2][i] = right.m_squares[i][0];
        right.m_squares[i][0] = bottom.m_squares[0][2 - i];
        bottom.m_squares[0][2 - i] = left.m_squares[2 - i][2];
        left.m_squares[2 - i][2] = temp;
      }
      return;
    }
  }
  case CubeFace::BACK: {
    switch (rotation) {
    case Rotation::CLOCKWISE:
      for (size_t i = 0; i < 3; i++) {
        Square temp = top.m_squares[0][i];
        top.m_squares[0][i] = right.m_squares[i][2];
        right.m_squares[i][2] = bottom.m_squares[2][2 - i];
        bottom.m_squares[2][2 - i] = left.m_squares[2 - i][0];
        left.m_squares[2 - i][0] = temp;
      }
      return;
    case Rotation::COUNTER_CLOCKWISE:
      for (size_t i = 0; i < 3; i++) {
        Square temp = top.m_squares[0][i];
        top.m_squares[0][i] = left.m_squares[2 - i][0];
        left.m_squares[2 - i][0] = bottom.m_squares[2][2 - i];
        bottom.m_squares[2][2 - i] = right.m_squares[i][2];
        right.m_squares[i][2] = temp;
      }
      return;
    }
  }
  case CubeFace::LEFT: {
    switch (rotation) {
    case Rotation::CLOCKWISE:
      for (size_t i = 0; i < 3; i++) {
        Square temp = top.m_squares[i][0];
        top.m_squares[i][0] = back.m_squares[2 - i][2];
        back.m_squares[2 - i][2] = bottom.m_squares[i][0];
        bottom.m_squares[i][0] = front.m_squares[i][0];
        front.m_squares[i][0] = temp;
      }
      return;
    case Rotation::COUNTER_CLOCKWISE:
      for (size_t i = 0; i < 3; i++) {
        Square temp = top.m_squares[i][0];
        top.m_squares[i][0] = front.m_squares[i][0];
        front.m_squares[i][0] = bottom.m_squares[i][0];
        bottom.m_squares[i][0] = back.m_squares[2 - i][2];
        back.m_squares[2 - i][2] = temp;
      }
      return;
    }
  }
  case CubeFace::RIGHT: {
    switch (rotation) {
    case Rotation::CLOCKWISE:
      for (size_t i = 0; i < 3; i++) {
        Square temp = top.m_squares[i][2];
        top.m_squares[i][2] = front.m_squares[i][2];
        front.m_squares[i][2] = bottom.m_squares[i][2];
        bottom.m_squares[i][2] = back.m_squares[2 - i][0];
        back.m_squares[2 - i][0] = temp;
      }
      return;
    case Rotation::COUNTER_CLOCKWISE:
      for (size_t i = 0; i < 3; i++) {
        Square temp = top.m_squares[i][2];
        top.m_squares[i][2] = back.m_squares[2 - i][0];
        back.m_squares[2 - i][0] = bottom.m_squares[i][2];
        bottom.m_squares[i][2] = front.m_squares[i][2];
        front.m_squares[i][2] = temp;
      }
      return;
    }
  }
  }
  __builtin_unreachable();
}
