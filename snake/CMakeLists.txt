cmake_minimum_required(VERSION 3.15)
project(snake)

set(CMAKE_CXX_STANDARD 17)

add_executable(snake main.cpp tui.cpp tui.h ui.cpp ui.h human.cpp human.h control.cpp control.h game.cpp game.h)