cmake_minimum_required(VERSION 3.0)

project(Stack VERSION 1.0)

set(SRC
StackVirtual.hpp
LimitedSizeStack.hpp
LimitedSizeStack.tpp
StackExceptions.hpp
LimitedSizeStackTesting.hpp
LimitedSizeStackTesting.cpp
main.cpp
)
add_executable(${PROJECT_NAME} ${SRC})

enable_testing()
add_subdirectory(test)
