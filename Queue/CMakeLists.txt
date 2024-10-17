cmake_minimum_required(VERSION 3.0)

project(Queue VERSION 1.0)

set(SRC
QueueVirtual.hpp
QueueExceptions.hpp
LimitedSizeQueue.hpp
LimitedSizeQueue.tpp
main.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
