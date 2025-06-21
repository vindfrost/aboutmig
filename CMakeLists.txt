cmake_minimum_required(VERSION 3.10)
project(AboutMig
				VERSION 0.1.7
				DESCRIPTION "Store info about yourself!"
				LANGUAGES CXX)

add_executable(aboutmig src/main.cpp src/storage/directory.cpp src/storage/datafiles.cpp)

include(CheckIncludeFiles)
include(CheckFunctionExists)

set(CMAKE_REQUIRED_INCLUDES ${CMAKE_SOURCE_DIR}/include)

# Standard library checks
check_include_files("filesystem" HAVE_FILESYSTEM_H)
check_include_files("fstream" HAVE_FSTREAM_H)
check_include_files("iostream" HAVE_IOSTREAM_H)
check_include_files("string" HAVE_STRING_H)
check_include_files("cstdio" HAVE_CSTDIO_H)
check_include_files("string_view" HAVE_STRING_VIEW_H)
check_include_files("algorithm" HAVE_ALGORITHM_H)

# JSON library check
check_include_files("nlohmann/json.hpp" HAVE_NLOHMANN_JSON_H)

# cxxopts header check
check_include_files("cxxopts/cxxopts.hpp" HAVE_CXXOPTS_H)

# Colorcodes check
check_include_files("colorcodes.h" HAVE_COLORCODES_H)

# Storage checks
check_include_files("storage/datafiles.h" HAVE_STORAGE_DATAFILES_H)
check_include_files("storage/directory.h" HAVE_STORAGE_DIRECORY_H)

include_directories(${CMAKE_SOURCE_DIR}/include)
