cmake_minimum_required(VERSION 3.21..3.26)

project(
  RubiksRacer
  VERSION 1.0.0
  DESCRIPTION "A Rubik's Cube racing game"
  LANGUAGES CXX)

# Enable all C++ warnings and treat warnings as errors
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -std=gnu++20")
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
      DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_MakeAvailable(googletest)

# enable tests
enable_testing()
include(GoogleTest)

add_executable(rubicks_racer_test)
target_include_directories(rubicks_racer_test
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(rubicks_racer_test PRIVATE GTest::gtest_main)

add_executable(rubicks_racer ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_include_directories(rubicks_racer
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(src)
