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
  Square square = m_squares[0][0];
  for (const auto &row : m_squares) {
    for (const auto &s : row) {
      if (s != square) {
        return false;
      }
    }
  }
  return true;
}

void Side::rotate_face([[maybe_unused]] Rotation rotation) {
  // TODO
}

void Side::rotate_row([[maybe_unused]] int row,
                      [[maybe_unused]] Rotation rotation) {
  // TODO
}

void Side::rotate_column([[maybe_unused]] int column,
                         [[maybe_unused]] Rotation rotation) {
  // TODO
}
