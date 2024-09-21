#pragma once

#include <iostream>

enum class Rotation {
  CLOCKWISE,
  COUNTER_CLOCKWISE,
};

inline Rotation reverse_rotation(Rotation rotation) {
  switch (rotation) {
  case Rotation::CLOCKWISE:
    return Rotation::COUNTER_CLOCKWISE;
  case Rotation::COUNTER_CLOCKWISE:
    return Rotation::CLOCKWISE;
  }
  __builtin_unreachable();
}

inline std::ostream &operator<<(std::ostream &os, Rotation rotation) {
  switch (rotation) {
  case Rotation::CLOCKWISE:
    return os << "CW";
  case Rotation::COUNTER_CLOCKWISE:
    return os << "CCW";
  }
  __builtin_unreachable();
}
