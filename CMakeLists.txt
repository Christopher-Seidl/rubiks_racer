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

# add racer library
add_library(rubicks_racer_lib)
target_include_directories(rubicks_racer_lib
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# add the test executable
add_executable(rubicks_racer_tests)
target_include_directories(rubicks_racer_tests
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(rubicks_racer_tests PUBLIC GTest::gtest_main
                                                 rubicks_racer_lib)
gtest_discover_tests(rubicks_racer_tests)

# add the main executable
add_executable(rubicks_racer ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(rubicks_racer PUBLIC rubicks_racer_lib)
install(TARGETS rubicks_racer DESTINATION bin)

add_subdirectory(src)
