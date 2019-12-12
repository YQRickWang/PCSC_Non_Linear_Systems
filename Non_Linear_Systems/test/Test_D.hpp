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

/**
 * This class contains a concrete test case can be called, namely the Test_B. It's a system of nonlinear functions,
 * f1(x, y) = x ^ 3 + y - 1 and f2(x, y) = x - y ^ 3 - 1.
 */
class Test_D : public TestBase{
public:

    /**
     * default constructor
     */
    Test_D();

    /**
     * default destructor
     */
    ~Test_D();

    /**
     * It controls the execution of the analysis of the test case
     */
    void RunTest() override;

    /**
     * It shows the relevant information of the test case, saying the expression of the function, etc
     */
    void ShowEquationsInfo() override;
};


#endif //NON_LINEAR_SYSTEMS_TEST_D_HPP
