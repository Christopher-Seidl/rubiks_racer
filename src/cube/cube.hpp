#pragma once

#include <memory>
#include <unordered_map>
#include "side.hpp"
#include "rotation.hpp"

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
  std::unordered_map<CubeDirection, std::unique_ptr<Side>> m_sides;

public:
  Cube(std::unordered_map<CubeDirection, std::unique_ptr<Side>>&&);

  bool is_solved() const;

  void rotate_face(CubeDirection, Rotation);
};