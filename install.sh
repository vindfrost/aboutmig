#!/bin/bash

show_help() {
	echo "Usage: $0 [options]"
	echo ""
	echo "Options:"
	echo "	-c, --clean					Cleans the build directory."
	echo "	-b, --build					Builds the executable."
	echo "	-h, --help					Display this help message."
}

# Parse arguments
while [[ $# -gt 0 ]]; do
  case "$1" in
    --clean|-c)
      echo "Running clean operation..."
      rm -rf build/
      echo "Cleaning successful!"
      exit 0
      ;;
    --build|-b)
      echo "Building executable"
			mkdir -p ./build
			cd ./build
			cmake ..
			make
      exit 0
      ;;
    --help|-h)
      show_help
      exit 0
      ;;
    *)
      echo "Unknown option: $1"
      show_help
      exit 1
      ;;
  esac
done
