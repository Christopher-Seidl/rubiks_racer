#!/bin/bash

BUILD_DIR="./build"

if [ -d "$BUILD_DIR" ]; then
  echo "Directory ${BUILD_DIR} exists"
  cd "$BUILD_DIR"
else
  echo "Directory ${BUILD_DIR} does not exist"
  mkdir "$BUILD_DIR"
  cd "$BUILD_DIR"
  cmake .. $@
fi

echo "Copying compile_commands.json"
cp ./compile_commands.json ../compile_commands.json

echo "Building Rubik's Racer"
make

echo "Copying rubicks_racer bin"
cp ./rubicks_racer ../rubicks_racer

echo "Copying rubicks_racer_tests bin"
cp ./rubicks_racer_tests ../rubicks_racer_tests

cd ..
