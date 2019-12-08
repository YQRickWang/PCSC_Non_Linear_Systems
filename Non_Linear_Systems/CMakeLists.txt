cmake_minimum_required(VERSION 3.15)
project(Non_Linear_Systems)

set(CMAKE_CXX_STANDARD 14)

add_executable(Non_Linear_Systems main.cpp NonLinearSolver.cpp NonLinearSolver.h NonLinearEquation.cpp NonLinearEquation.h Test_A.cpp Test_A.h Test_B.cpp Test_B.h)