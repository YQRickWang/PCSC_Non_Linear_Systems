//
// Created by Rick Wang on 2019/12/9.
//

#ifndef NON_LINEAR_SYSTEMS_TEST_C_H
#define NON_LINEAR_SYSTEMS_TEST_C_H
#include "cmath"
#include "../src/NonLinearEquation.h"
#include "../src/NonLinearSolver.h"
#include "TestBase.h"

double Test_C_function_1(double* input);
double Test_C_function_2(double* input);
double Test_C_dfunction_11(double* input);
double Test_C_dfunction_12(double* input);
double Test_C_dfunction_21(double* input);
double Test_C_dfunction_22(double* input);
class Test_C:public TestBase{
public:
    Test_C();
    ~Test_C();
    void RunTest() override;
    void ShowEquationsInfo() override;
};

#endif //NON_LINEAR_SYSTEMS_TEST_C_H
