cmake_minimum_required(VERSION 3.22)
project(Programmieraufgaben)

set(CMAKE_CXX_STANDARD 17)

add_executable(Programmieraufgaben main.cpp exercises/blatt7.cpp)

enable_testing()

add_subdirectory(include/googletest)
include_directories(include/googletest/googletest/include)

add_executable(TestSuite tests/blatt7test.cpp exercises/blatt7.cpp)
target_link_libraries(TestSuite GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(TestSuite)