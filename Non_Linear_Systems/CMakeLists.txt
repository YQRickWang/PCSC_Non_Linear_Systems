cmake_minimum_required(VERSION 3.14.5)
project(Non_Linear_Systems)

set(CMAKE_CXX_STANDARD 14)
add_executable(Non_Linear_Systems main.cpp src/NonLinearSolver.cpp src/NonLinearSolver.h src/NonLinearEquation.cpp src/NonLinearEquation.h test/Test_A.cpp test/Test_A.h test/Test_B.cpp test/Test_B.h src/Helper.h src/Helper.cpp src/UserInterface.h src/UserInterface.cpp test/Test_C.h test/Test_C.cpp test/Test_D.cpp test/Test_D.hpp test/TestBase.cpp test/TestBase.h src/ReadFiles.h src/ReadFiles.cpp test/RandomFunctions.cpp test/RandomFunctions.h test/RandomTest.cpp test/RandomTest.h)
