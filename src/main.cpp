#include <iostream>

#include "cube/cube.hpp"
#include "cube/rotation.hpp"
#include "cube/side.hpp"

#include <chrono>
#include <functional>
#include <queue>
#include <unordered_set>
#include <vector>

void scramble_cube(Cube &cube, size_t num_scrambles) {
  for (size_t i = 0; i < num_scrambles; i++) {
    CubeFace face = static_cast<CubeFace>(rand() % 6);
    Rotation rotation = static_cast<Rotation>(rand() % 2);
    std::cout << " * scrambling: " << face << " " << rotation << std::endl;
    cube.rotate_face(face, rotation);
  }
}

struct CubeSolution {
  Cube cube;
  std::vector<std::pair<CubeFace, Rotation>> moves;

  // TODO: refine this heuristic
  double score() const {
    double score = 1.0;
    for (const auto &[_, side] : cube.m_sides_from_faces) {
      score += 0.1 * side.number_of_matching_rows_and_columns();
    }
    return score / std::max(1.0, (double)moves.size());
  }

  bool operator<(const CubeSolution &other) const {
    return score() < other.score();
  }
};

int main(int argc, char **argv) {

  auto start = std::chrono::high_resolution_clock::now();

  std::cout << std::endl;
  Cube starting_cube = Cube::SolvedCube();

  size_t num_scrambles = 20;
  if (argc >= 2) {
    num_scrambles = std::stoi(argv[1]);
  }

  auto seed = time(nullptr);
  if (argc >= 3) {
    seed = std::stoi(argv[2]);
  }
  std::cout << "seed: " << seed << std::endl;
  srand(seed);

  std::cout << std::endl;
  std::cout << "number of scrambles: " << num_scrambles << std::endl;
  scramble_cube(starting_cube, num_scrambles);
  std::cout << std::endl;

  std::cout << "scrambled cube:" << starting_cube << std::endl;

  std::priority_queue<CubeSolution> cube_solution_queue;
  std::unordered_set<Cube> visited_cubes;
  cube_solution_queue.push({starting_cube, {}});
  size_t num_evaluated_cubes = 0;

  while (!cube_solution_queue.empty()) {
    num_evaluated_cubes++;
    CubeSolution current_cube_solution = cube_solution_queue.top();
    cube_solution_queue.pop();
    if (current_cube_solution.cube.is_solved()) {
      std::cout << "solved cube:" << current_cube_solution.cube << std::endl;
      std::cout << "number of moves: " << current_cube_solution.moves.size()
                << std::endl;
      for (const auto &[face, rotation] : current_cube_solution.moves) {
        std::cout << " * " << face << " " << rotation << std::endl;
      }
      std::cout << std::endl;
      break;
    }
    for (CubeFace face : {CubeFace::TOP, CubeFace::BOTTOM, CubeFace::FRONT,
                          CubeFace::BACK, CubeFace::LEFT, CubeFace::RIGHT}) {
      for (Rotation rotation :
           {Rotation::CLOCKWISE, Rotation::COUNTER_CLOCKWISE}) {
        Cube new_cube = current_cube_solution.cube;
        std::vector<std::pair<CubeFace, Rotation>> new_moves =
            current_cube_solution.moves;
        new_cube.rotate_face(face, rotation);
        new_moves.push_back({face, rotation});
        if (visited_cubes.count(new_cube))
          continue;
        visited_cubes.insert(new_cube);
        cube_solution_queue.push({new_cube, new_moves});
      }
    }
  }

  std::cout << "number of evaluated cubes: " << num_evaluated_cubes
            << std::endl;
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now() - start);
  std::cout << "time taken: " << duration.count() << " ms" << std::endl;
  std::cout << "time per cube evaluation: "
            << duration.count() / (double)num_evaluated_cubes << " ms"
            << std::endl;
  std::cout << std::endl;
  return 0;
}
