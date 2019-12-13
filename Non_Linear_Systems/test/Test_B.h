//
// Created by Rick Wang on 2019/12/7.
//

#ifndef NON_LINEAR_SYSTEMS_TEST_B_H
#define NON_LINEAR_SYSTEMS_TEST_B_H

#include "cmath"
#include "../nonlinear/NonLinearEquation.h"
#include "../nonlinear/NonLinearSolver.h"
#include "TestBase.h"

double Test_B_function_1(double* input);
double Test_B_dfunction_11(double* input);
double Test_B_fpfunction(double* input);

/**
 * This class contains a concrete test case can be called, namely the Test_B. It's a simple function f(x) = exp(x) - x -2
 */
class Test_B:public TestBase{
public:
    /**
     * default constructor
     */
    Test_B();

    /**
     * default destructor
     */
    ~Test_B();

    /**
     *  It controls the execution of the analysis of the test case
     */
    void RunTest() override;

    /**
     * It shows the relevant information of the test case, saying the expression of the function, etc
     */
    void ShowEquationsInfo() override;
};



#endif //NON_LINEAR_SYSTEMS_TEST_B_H
