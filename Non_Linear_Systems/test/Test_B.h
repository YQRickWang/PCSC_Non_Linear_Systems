//
// Created by Rick Wang on 2019/12/7.
//

#ifndef NON_LINEAR_SYSTEMS_TEST_B_H
#define NON_LINEAR_SYSTEMS_TEST_B_H

#include "cmath"
#include "../src/NonLinearEquation.h"
#include "../src/NonLinearSolver.h"
#include "TestBase.h"

double Test_B_function_1(double* input);
double Test_B_dfunction_11(double* input);
double Test_B_fpfunction(double* input);
class Test_B:public TestBase{
public:
    Test_B();
    ~Test_B();
    void RunTest() override;
    void ShowEquationsInfo() override;
};



#endif //NON_LINEAR_SYSTEMS_TEST_B_H
