#include <iostream>

#include "cube/cube.hpp"
#include "cube/rotation.hpp"
#include "cube/side.hpp"

#include <functional>
#include <queue>
#include <unordered_set>
#include <vector>

void scramble_cube(Cube &cube) {
  for (size_t i = 0; i < 3; i++) {
    CubeFace face = static_cast<CubeFace>(rand() % 6);
    Rotation rotation = static_cast<Rotation>(rand() % 2);
    std::cout << "scrambling face: " << face << " with rotation: " << rotation
              << std::endl;
    ;
    cube.rotate_face(face, rotation);
  }
}

struct CubeQualityComparator {
  bool operator()(const Cube &lhs, const Cube &rhs) const {
    return lhs.number_of_matched_squares() < rhs.number_of_matched_squares();
  }
};

using CubePriorityQueue =
    std::priority_queue<Cube, std::vector<Cube>, CubeQualityComparator>;

int main() {
  srand(time(nullptr));
  Cube starting_cube = Cube::SolvedCube();
  scramble_cube(starting_cube);
  std::cout << "scrambled cube:" << starting_cube << std::endl;

  constexpr std::array<Rotation, 2> rotations = {Rotation::CLOCKWISE,
                                                 Rotation::COUNTER_CLOCKWISE};
  constexpr std::array<CubeFace, 6> faces = {CubeFace::TOP,   CubeFace::BOTTOM,
                                             CubeFace::FRONT, CubeFace::BACK,
                                             CubeFace::LEFT,  CubeFace::RIGHT};

  CubePriorityQueue cube_queue;
  std::unordered_set<Cube> visited_cubes;
  cube_queue.push(starting_cube);

  while (!cube_queue.empty()) {
    Cube current_cube = cube_queue.top();
    // std::cout << "current cube score: " <<
    // current_cube.number_of_matched_squares() << "\n";
    cube_queue.pop();
    if (current_cube.is_solved()) {
      std::cout << "solved cube:" << current_cube << std::endl;
      break;
    }
    for (CubeFace face : faces) {
      for (Rotation rotation : rotations) {
        Cube new_cube = current_cube;
        new_cube.rotate_face(face, rotation);
        if (visited_cubes.find(new_cube) != visited_cubes.end()) {
          continue;
        }
        cube_queue.push(new_cube);
      }
    }
  }
  return 0;
}
