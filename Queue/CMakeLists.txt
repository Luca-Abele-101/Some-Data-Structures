cmake_minimum_required(VERSION 3.0)

project(Queue VERSION 1.0)

set(SRC
src/QueueVirtual.hpp
src/QueueExceptions.hpp
src/LimitedSizeQueue.hpp
src/LimitedSizeQueue.tpp
src/main.cpp
)
add_executable(${PROJECT_NAME} ${SRC})

enable_testing()
add_subdirectory(test)
