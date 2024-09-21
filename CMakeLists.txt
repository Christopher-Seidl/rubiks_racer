cmake_minimum_required(VERSION 3.10)

project(RubiksRacer
    VERSION 0.1.0
    DESCRIPTION "A Rubik's Cube racing game"
    LANGUAGES CXX)

# Enable all C++ warnings and treat warnings as errors
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -std=gnu++20")
set(CMAKE_CXX_STANDARD 20)

add_executable(RubiksRacer ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)