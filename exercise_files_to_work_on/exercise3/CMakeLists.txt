cmake_minimum_required(VERSION 3.22)
project(Programmieraufgaben)

set(CMAKE_CXX_STANDARD 17)

add_executable(Programmieraufgaben main.cpp exercises/blatt3.cpp include/blatt3.h)

enable_testing()

add_subdirectory(include/googletest)
include_directories(include/googletest/googletest/include)

add_executable(TestSuite tests/blatt3test.cpp include/blatt3.h exercises/blatt3.cpp)
target_link_libraries(TestSuite GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(TestSuite)