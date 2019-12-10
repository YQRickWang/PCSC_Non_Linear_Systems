//
// Created by Rick Wang on 2019/12/7.
//

#ifndef NON_LINEAR_SYSTEMS_TEST_A_H
#define NON_LINEAR_SYSTEMS_TEST_A_H

#include "cmath"
#include "NonLinearEquation.h"
#include "NonLinearSolver.h"
#include "TestBase.h"

//basic test for 1 dimension
//simple test
//f(x) = x-1
//df(x) = 1
//g(x) = 1
//x=1
double Test_A_function_1(double* input);
double Test_A_dfunction_11(double* input);
double Test_A_fpfunction(double* input);

class Test_A:public TestBase{
public:
    Test_A();
    ~Test_A();
    void RunTest() override;
    void ShowEquationsInfo() override;
};





#endif //NON_LINEAR_SYSTEMS_TEST_A_H
