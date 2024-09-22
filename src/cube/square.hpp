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
  bool print_squares = true;
  constexpr const char *WHITE_COLOR = "\033[37m";
  constexpr const char *YELLOW_COLOR = "\033[33m";
  constexpr const char *GREEN_COLOR = "\033[32m";
  constexpr const char *BLUE_COLOR = "\033[34m";
  constexpr const char *ORANGE_COLOR = "\033[38;5;208m";
  constexpr const char *RED_COLOR = "\033[31m";
  constexpr const char *RESET_COLOR = "\033[0m";
  switch (square) {
  case Square::WHITE:
    return print_squares ? (os << WHITE_COLOR << "■" << RESET_COLOR)
                         : (os << "W");
  case Square::YELLOW:
    return print_squares ? (os << YELLOW_COLOR << "■" << RESET_COLOR)
                         : (os << "Y");
  case Square::GREEN:
    return print_squares ? (os << GREEN_COLOR << "■" << RESET_COLOR)
                         : (os << "G");
  case Square::BLUE:
    return print_squares ? (os << BLUE_COLOR << "■" << RESET_COLOR)
                         : (os << "B");
  case Square::ORANGE:
    return print_squares ? (os << ORANGE_COLOR << "■" << RESET_COLOR)
                         : (os << "O");
  case Square::RED:
    return print_squares ? (os << RED_COLOR << "■" << RESET_COLOR)
                         : (os << "R");
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
