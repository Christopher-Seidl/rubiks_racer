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
  // private:
public: // TODO: allow this to be private
  std::unordered_map<CubeFace, Side> m_sides_from_faces;

public:
  Cube(std::unordered_map<CubeFace, Side> &&);

  static Cube SolvedCube();

  bool is_solved() const;

  size_t number_of_matched_squares() const;

  void rotate_face(CubeFace, Rotation);

  bool operator==(const Cube &other) const {
    return m_sides_from_faces == other.m_sides_from_faces;
  }

  friend std::ostream &operator<<(std::ostream &os, const Cube &cube) {
    // print the top
    os << std::endl << std::endl;
    for (size_t i = 0; i < 3; i++) {
      os << "            ";
      for (size_t j = 0; j < 3; j++) {
        os << cube.top().m_squares[i][j] << " ";
      }
      os << std::endl;
    }
    os << "            - - -" << std::endl;
    // print the left, front, right, and back
    for (size_t i = 0; i < 3; i++) {
      os << "    ";
      for (size_t j = 0; j < 3; j++) {
        os << cube.left().m_squares[i][j] << " ";
      }
      os << "| ";
      for (size_t j = 0; j < 3; j++) {
        os << cube.front().m_squares[i][j] << " ";
      }
      os << "| ";
      for (size_t j = 0; j < 3; j++) {
        os << cube.right().m_squares[i][j] << " ";
      }
      os << "| ";
      for (size_t j = 0; j < 3; j++) {
        os << cube.back().m_squares[i][j] << " ";
      }
      os << std::endl;
    }
    os << "            - - -" << std::endl;
    // print the bottom
    for (size_t i = 0; i < 3; i++) {
      os << "            ";
      for (size_t j = 0; j < 3; j++) {
        os << cube.bottom().m_squares[i][j] << " ";
      }
      os << std::endl;
    }
    os << std::endl;
    return os;
  }

private:
  Side &top() { return m_sides_from_faces.at(CubeFace::TOP); }
  const Side &top() const { return m_sides_from_faces.at(CubeFace::TOP); }
  Side &bottom() { return m_sides_from_faces.at(CubeFace::BOTTOM); }
  const Side &bottom() const { return m_sides_from_faces.at(CubeFace::BOTTOM); }
  Side &front() { return m_sides_from_faces.at(CubeFace::FRONT); }
  const Side &front() const { return m_sides_from_faces.at(CubeFace::FRONT); }
  Side &back() { return m_sides_from_faces.at(CubeFace::BACK); }
  const Side &back() const { return m_sides_from_faces.at(CubeFace::BACK); }
  Side &left() { return m_sides_from_faces.at(CubeFace::LEFT); }
  const Side &left() const { return m_sides_from_faces.at(CubeFace::LEFT); }
  Side &right() { return m_sides_from_faces.at(CubeFace::RIGHT); }
  const Side &right() const { return m_sides_from_faces.at(CubeFace::RIGHT); }
};

namespace std {
template <> struct hash<Cube> {
  size_t operator()(const Cube &cube) const {
    size_t hash = 0;
    for (const auto &pair : cube.m_sides_from_faces) {
      hash ^= (std::hash<Side>()(pair.second))
              << (static_cast<size_t>(pair.first) * 36);
    }
    return hash;
  }
};
} // namespace std
