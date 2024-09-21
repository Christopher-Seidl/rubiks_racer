#pragma once

#include <iostream>

enum class Square {
  WHITE,
  YELLOW,
  GREEN,
  BLUE,
  ORANGE,
  RED,
};

inline std::ostream &operator<<(std::ostream &os, Square square) {
  switch (square) {
  case Square::WHITE:
    return os << "W";
  case Square::YELLOW:
    return os << "Y";
  case Square::GREEN:
    return os << "G";
  case Square::BLUE:
    return os << "B";
  case Square::ORANGE:
    return os << "O";
  case Square::RED:
    return os << "R";
  }
  __builtin_unreachable();
}

// write a hash function for Square
namespace std {
template <> struct hash<Square> {
  size_t operator()(const Square &square) const {
    return static_cast<size_t>(square);
  }
};
} // namespace std
