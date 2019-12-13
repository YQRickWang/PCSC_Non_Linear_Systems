//
// Created by Rick Wang on 2019/12/7.
//

#ifndef NON_LINEAR_SYSTEMS_TEST_A_H
#define NON_LINEAR_SYSTEMS_TEST_A_H

#include "cmath"
#include "../nonlinear/NonLinearEquation.h"
#include "../nonlinear/NonLinearSolver.h"
#include "TestBase.h"


double Test_A_function_1(double* input);
double Test_A_dfunction_11(double* input);
double Test_A_fpfunction(double* input);

/**
 * This class contains a concrete test case can be called, namely the Test_A. It's a simple function f(x) = exp(x) - 1
 */
class Test_A:public TestBase{
public:
    /**
     * default constructor
     */
    Test_A();

    /**
     * default destructor
     */
    ~Test_A();

    /**
     * It controls the execution of the analysis of the test case
     */
    void RunTest() override;

    /**
     * It shows the relevant information of the test case, saying the expression of the function, etc
     */
    void ShowEquationsInfo() override;
};





#endif //NON_LINEAR_SYSTEMS_TEST_A_H
