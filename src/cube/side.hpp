#pragma once

#include <array>
#include <unordered_map>
#include "square.hpp"
#include "rotation.hpp"

enum class SideDirection {
  ABOVE,
  BELOW,
  LEFT,
  RIGHT,
};

class Side {
private:
  std::array<std::array<Square, 3>, 3> m_squares;
  std::unordered_map<SideDirection, Side*> m_neighbors;

public:
  Sider(std::array<std::array<Square, 3>, 3>&&, std::unordered_map<SideDirection, Side*>&&);

  bool is_solved() const;

  void rotate_face(Rotation);

  void rotate_row(int, Rotation);

  void rotate_column(int, Rotation);
};