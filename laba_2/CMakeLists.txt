cmake_minimum_required(VERSION 3.10)
project(laba2)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(laba2 lab_2.cpp four.cpp)

enable_testing()
add_executable(test_2 gtests.cpp  four.cpp)
target_link_libraries(test_2 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND gtests)