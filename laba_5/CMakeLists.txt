cmake_minimum_required(VERSION 3.10)
project(Lab05)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab_05 main.cpp)


enable_testing()
add_executable(
    tests05
    tests.cpp)

target_link_libraries(tests05 ${GTEST_LIBRARIES})

add_test(NAME TESTS COMMAND tests05)
