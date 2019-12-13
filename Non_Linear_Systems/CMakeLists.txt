cmake_minimum_required(VERSION 3.10.2)
project(Non_Linear_Systems)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

add_compile_options(-bigobj)
add_executable(Non_Linear_Systems main.cpp nonlinear/src/NonLinearSolver.cpp nonlinear/NonLinearSolver.h nonlinear/src/NonLinearEquation.cpp nonlinear/NonLinearEquation.h test/src/Test_A.cpp test/Test_A.h test/src/Test_B.cpp test/Test_B.h nonlinear/MatrixHelper.h nonlinear/src/MatrixHelper.cpp nonlinear/UserInterface.h nonlinear/src/UserInterface.cpp test/Test_C.h test/src/Test_C.cpp test/src/Test_D.cpp test/Test_D.hpp test/src/TestBase.cpp test/TestBase.h nonlinear/ReadFiles.h nonlinear/src/ReadFiles.cpp test/src/RandomFunctions.cpp test/RandomFunctions.h test/src/RandomTest.cpp test/RandomTest.h)
target_link_libraries(Non_Linear_Systems gtest gtest_main)
