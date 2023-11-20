cmake_minimum_required(VERSION 3.10)


project(4_lab)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON) 

add_executable(launch_main main.cpp Figure.h point.h pentagon.h trapezoid.h rhombus.h Vector.h)

enable_testing() 
add_executable(launch_tests all_tests.cpp Figure.h point.h pentagon.h trapezoid.h rhombus.h Vector.h)

target_link_libraries(launch_tests ${GTEST_LIBRARIES})
add_test(NAME BASIC COMMAND launch_tests)