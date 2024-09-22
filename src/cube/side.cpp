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

bool Side::is_cross_solved() const {
  Square center_square = m_squares[1][1];
  for (size_t i = 0; i < 3; i++) {
    if (m_squares[i][1] != center_square || m_squares[1][i] != center_square) {
      return false;
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

size_t Side::number_of_matching_rows_and_columns() const {
  size_t matching_rows_and_columns = 0;
  for (size_t i = 0; i < 3; i++) {
    matching_rows_and_columns += m_squares[i][0] == m_squares[i][1] &&
                                 m_squares[i][1] == m_squares[i][2];
    matching_rows_and_columns += m_squares[0][i] == m_squares[1][i] &&
                                 m_squares[1][i] == m_squares[2][i];
  }
  return matching_rows_and_columns;
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
