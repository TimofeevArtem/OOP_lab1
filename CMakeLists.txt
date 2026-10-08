cmake_minimum_required(VERSION 3.10)
project(OOP_lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

enable_testing()

add_executable(main main.cpp array_ops.cpp)
add_executable(array_ops_tests gtests.cpp array_ops.cpp)
target_link_libraries(array_ops_tests PRIVATE GTest::gtest_main)
add_test(NAME array_ops_tests COMMAND array_ops_tests)
