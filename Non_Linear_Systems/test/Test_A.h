//
// Created by Rick Wang on 2019/12/7.
//

#ifndef NON_LINEAR_SYSTEMS_TEST_A_H
#define NON_LINEAR_SYSTEMS_TEST_A_H

#include "cmath"
#include "../src/NonLinearEquation.h"
#include "../src/NonLinearSolver.h"
#include "TestBase.h"


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
