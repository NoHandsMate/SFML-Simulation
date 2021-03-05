cmake_minimum_required(VERSION 3.19)

project(Simulation)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SFML_STATIC_LIBRARIES True)
find_package(SFML COMPONENTS graphics audio system window)


add_executable(Simulation src/main.cpp)
target_link_libraries(Simulation sfml-graphics sfml-audio sfml-system sfml-window)

