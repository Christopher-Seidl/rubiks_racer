#pragma once

#include "rotation.hpp"
#include "side.hpp"
#include <memory>
#include <unordered_map>

enum class CubeDirection {
  TOP,
  BOTTOM,
  LEFT,
  RIGHT,
  FRONT,
  BACK,
};

class Cube {
private:
  std::unordered_map<CubeDirection, Side> m_sides;

public:
  Cube(std::unordered_map<CubeDirection, Side> &&);

  static Cube SolvedCube();

  bool is_solved() const;

  void rotate_face(CubeDirection, Rotation);
};
