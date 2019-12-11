//
// Created by hzhu on 11/12/2019.
//

#ifndef NON_LINEAR_SYSTEMS_TEST_D_HPP
#define NON_LINEAR_SYSTEMS_TEST_D_HPP

#include "cmath"
#include "../src/NonLinearEquation.h"
#include "../src/NonLinearSolver.h"
#include "TestBase.h"

double Test_D_function_1(double* input);
double Test_D_function_2(double* input);
double Test_D_dfunction_11(double* input);
double Test_D_dfunction_12(double* input);
double Test_D_dfunction_21(double* input);
double Test_D_dfunction_22(double* input);

class Test_D : public TestBase{
public:
    Test_D();
    ~Test_D();
    void RunTest() override;
    void ShowEquationsInfo() override;
};


#endif //NON_LINEAR_SYSTEMS_TEST_D_HPP
