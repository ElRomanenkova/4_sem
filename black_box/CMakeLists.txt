cmake_minimum_required(VERSION 3.15)
project(black_box C)

set(CMAKE_C_STANDARD 11)

add_executable(black_box main.c vector.h list.h vector.c list.c list.h cmake-build-debug/black_box.h)