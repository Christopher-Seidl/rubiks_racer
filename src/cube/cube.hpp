#pragma once

#include "rotation.hpp"
#include "side.hpp"
#include "square.hpp"
#include <iostream>
#include <memory>
#include <unordered_map>

enum class CubeFace {
  TOP,
  BOTTOM,
  LEFT,
  RIGHT,
  FRONT,
  BACK,
};

inline std::ostream &operator<<(std::ostream &os, CubeFace face) {
  switch (face) {
  case CubeFace::TOP:
    return os << "Top";
  case CubeFace::BOTTOM:
    return os << "Bottom";
  case CubeFace::LEFT:
    return os << "Left";
  case CubeFace::RIGHT:
    return os << "Right";
  case CubeFace::FRONT:
    return os << "Front";
  case CubeFace::BACK:
    return os << "Back";
  }
  __builtin_unreachable();
}

class Cube {
private:
  std::unordered_map<CubeFace, Side> m_sides_from_faces;

public:
  Cube(std::unordered_map<CubeFace, Side> &&);

  static Cube SolvedCube();

  bool is_solved() const;

  void rotate_face(CubeFace, Rotation);

  bool operator==(const Cube &other) const {
    return m_sides_from_faces == other.m_sides_from_faces;
  }

  friend std::ostream &operator<<(std::ostream &os, const Cube &cube) {
    for (const auto &[face, side] : cube.m_sides_from_faces) {
      os << face << std::endl;
      os << side << std::endl;
    }
    return os;
  }
};
