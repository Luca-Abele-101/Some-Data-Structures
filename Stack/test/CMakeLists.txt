cmake_minimum_required(VERSION 3.0)

project(LimitedSizeStackModuleTests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_executable(${PROJECT_NAME}
bracketsOperations.cpp
bracketsOperations.hpp
LimitedSizeStackModuleTests.cpp
)

target_link_libraries(${PROJECT_NAME}
GTest::GTest
GTest::gtest_main
)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
