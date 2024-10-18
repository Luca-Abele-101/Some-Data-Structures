cmake_minimum_required(VERSION 3.0)

project(AbstractTest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_executable(AbstractTest
AbstractTest.cpp
)

target_link_libraries(AbstractTest
GTest::GTest
GTest::gtest_main
)

add_test(NAME AbstractTest COMMAND AbstractTest)
