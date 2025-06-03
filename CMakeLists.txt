cmake_minimum_required(VERSION 3.10)

project(AboutMig VERSION 0.0.1
								 DESCRIPTION "Store info about yourself!"
							 	 LANGUAGES CXX)

add_executable(AboutMig src/main.cpp)
set(CMAKE_CXX_FLAGS "-Wall")
