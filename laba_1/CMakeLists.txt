cmake_minimum_required(VERSION 3.10)
project(oop_example)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(example_1 1.cpp vowel.cpp)

enable_testing()
add_executable(test_1 test_1.cpp  vowel.cpp)
target_link_libraries(test_1 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND test_1)
