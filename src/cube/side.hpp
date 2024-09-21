#pragma once

#include "rotation.hpp"
#include "square.hpp"
#include <array>
#include <initializer_list>
#include <unordered_map>

enum class SideDirection {
  ABOVE,
  BELOW,
  LEFT,
  RIGHT,
};

class Side {
private:
  std::array<std::array<Square, 3>, 3> m_squares;

public:
  Side(std::array<std::array<Square, 3>, 3> &&);

  static Side UniformSide(Square);

  bool is_solved() const;

  void rotate_face(Rotation);

  void rotate_row(int, Rotation);

  void rotate_column(int, Rotation);
};
