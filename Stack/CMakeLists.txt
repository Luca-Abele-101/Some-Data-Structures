cmake_minimum_required(VERSION 3.0)

project(Stack VERSION 1.0)

set(SRC
src/StackVirtual.hpp
src/LimitedSizeStack.hpp
src/LimitedSizeStack.tpp
src/StackExceptions.hpp
src/LimitedSizeStackTesting.hpp
src/LimitedSizeStackTesting.cpp
src/main.cpp
)
add_executable(${PROJECT_NAME} ${SRC})

enable_testing()
add_subdirectory(test)
