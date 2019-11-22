cmake_minimum_required(VERSION 3.15)
project(Non_Linear_Systems)

set(CMAKE_CXX_STANDARD 14)

add_executable(Non_Linear_Systems main.cpp NonLinearSolver.cpp NonLinearSolver.h)