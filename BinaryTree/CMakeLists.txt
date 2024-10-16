cmake_minimum_required(VERSION 3.0)

project(BinaryTree VERSION 1.0)

set(SRC
BinaryTree.h
BinaryTree.tpp
main.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
