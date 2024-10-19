cmake_minimum_required(VERSION 3.0)

project(BinaryTree VERSION 1.0)

set(SRC
src/BinaryTree.hpp
src/BinaryTree.tpp
)

# Include interface for submodules (tests)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} INTERFACE)

# Files for BinaryTree directory
target_include_directories(${PROJECT_NAME} INTERFACE
${CMAKE_CURRENT_SOURCE_DIR}/src)

enable_testing()
add_subdirectory(test)
