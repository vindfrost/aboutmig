cmake_minimum_required(VERSION 3.10)
project(AboutMig
				VERSION 0.0.1
				DESCRIPTION "Store info about yourself!"
				LANGUAGES CXX)

add_executable(aboutmig src/main.cpp src/storage/directory.cpp src/storage/datafiles.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)
