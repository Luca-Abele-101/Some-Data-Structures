cmake_minimum_required(VERSION 3.0)

project(BinaryTree VERSION 1.0)

set(SRC
StackVirtual.hpp
StackArray.hpp
StackArray.cpp
StackArrayExceptions.hpp
StackArrayExceptions.cpp
StackArrayTesting.hpp
StackArrayTesting.cpp
main.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
