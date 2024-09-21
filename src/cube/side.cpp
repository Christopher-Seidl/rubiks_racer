#include "side.hpp"

Side::Side(std::array<std::array<Square, 3>, 3> &&squares)
    : m_squares(std::move(squares)) {}

Side Side::UniformSide(Square square) {
  std::array<std::array<Square, 3>, 3> squares = {{
      {square, square, square},
      {square, square, square},
      {square, square, square},
  }};
  return Side(std::move(squares));
}

bool Side::is_solved() const {
  Square center_square = m_squares[1][1];
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      if (m_squares[i][j] != center_square) {
        return false;
      }
    }
  }
  return true;
}

size_t Side::number_of_matched_squares() const {
  Square center_square = m_squares[1][1];
  size_t matched_squares = 0;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      if (m_squares[i][j] == center_square) {
        matched_squares++;
      }
    }
  }
  return matched_squares;
}

void Side::rotate_face(Rotation rotation) {
  switch (rotation) {
  case Rotation::CLOCKWISE:
    std::swap(m_squares[0][0], m_squares[0][2]);
    std::swap(m_squares[0][0], m_squares[2][2]);
    std::swap(m_squares[0][0], m_squares[2][0]);
    std::swap(m_squares[0][1], m_squares[1][2]);
    std::swap(m_squares[0][1], m_squares[2][1]);
    std::swap(m_squares[0][1], m_squares[1][0]);
    return;
  case Rotation::COUNTER_CLOCKWISE:
    std::swap(m_squares[0][0], m_squares[2][0]);
    std::swap(m_squares[0][0], m_squares[2][2]);
    std::swap(m_squares[0][0], m_squares[0][2]);
    std::swap(m_squares[0][1], m_squares[1][0]);
    std::swap(m_squares[0][1], m_squares[2][1]);
    std::swap(m_squares[0][1], m_squares[1][2]);
    return;
  }
  __builtin_unreachable();
}
