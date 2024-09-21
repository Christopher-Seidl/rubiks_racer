#pragma once

#include "rotation.hpp"
#include "square.hpp"
#include <array>
#include <initializer_list>
#include <iostream>
#include <unordered_map>

enum class SideDirection {
  ABOVE,
  BELOW,
  LEFT,
  RIGHT,
};

class Side {
  // private:
public: // TODO: make this private later...
  std::array<std::array<Square, 3>, 3> m_squares;

public:
  Side(std::array<std::array<Square, 3>, 3> &&);

  static Side UniformSide(Square);

  bool is_solved() const;

  void rotate_face(Rotation);

  bool operator==(const Side &other) const {
    return m_squares == other.m_squares;
  }

  friend std::ostream &operator<<(std::ostream &os, const Side &side) {
    for (size_t i = 0; i < 3; i++) {
      for (size_t j = 0; j < 3; j++) {
        os << side.m_squares[i][j] << " ";
      }
      os << std::endl;
    }
    return os;
  }
};
