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

n_build_cores=1
echo "Building Rubik's Racer with ${n_build_cores} cores"
make -j$n_build_cores

echo "Copying rubicks_racer bin"
cp ./rubicks_racer ../rubicks_racer

cd ..
