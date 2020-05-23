cmake_minimum_required(VERSION 3.16)
project(project)

set(CMAKE_CXX_STANDARD 17)

add_executable(project main.cpp red_black_tree.cpp red_black_tree.h tests.cpp tests.h)