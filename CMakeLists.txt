cmake_minimum_required(VERSION 3.16)
project(cpp_learning_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable all warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Create directories for organized learning modules
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/src/basics)
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/src/oop)
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/src/stl)

# Main executable
add_executable(cpp_learning main.cpp)

# Basic concepts examples
add_executable(basics_variables src/basics/variables.cpp)
add_executable(basics_loops src/basics/loops.cpp)
add_executable(basics_functions src/basics/functions.cpp)

# Object-oriented programming examples
add_executable(oop_classes src/oop/classes.cpp)
add_executable(oop_inheritance src/oop/inheritance.cpp)
add_executable(oop_polymorphism src/oop/polymorphism.cpp)

# STL examples
add_executable(stl_containers src/stl/containers.cpp)
add_executable(stl_algorithms src/stl/algorithms.cpp)
