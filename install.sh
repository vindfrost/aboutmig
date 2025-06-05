#!/bin/bash

while [[ $# -gt 0 ]]; do
  case "$1" in
    --clean|-c) # For --clean or -c command
      echo "Running clean operation..."
      rm -rf build/
      echo "Cleaning sucessful!"
      exit 0
      ;;
    *)
      echo "Unknown option: $1"
      exit 1
      ;;
  esac
done

mkdir -p ./build
cd ./build
cmake ..
make
