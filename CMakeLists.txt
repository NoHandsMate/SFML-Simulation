cmake_minimum_required(VERSION 3.18)
project(SFML-Simulation)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -Wall)

add_library(Engine
	include/Engine.hpp
	src/Engine.cpp
	)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS graphics system window)

target_include_directories(Engine PUBLIC include)
add_executable(Simulation src/main.cpp)
target_link_libraries(Simulation PRIVATE Engine PUBLIC sfml-graphics sfml-system sfml-window)
