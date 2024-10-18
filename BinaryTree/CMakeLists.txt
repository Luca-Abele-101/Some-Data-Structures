cmake_minimum_required(VERSION 3.0)

project(BinaryTree VERSION 1.0)

set(SRC
src/BinaryTree.hpp
src/BinaryTree.tpp
src/main.cpp
)
add_executable(${PROJECT_NAME} ${SRC})

enable_testing()
add_subdirectory(test)
