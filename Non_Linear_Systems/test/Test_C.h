//
// Created by Rick Wang on 2019/12/9.
//

#ifndef NON_LINEAR_SYSTEMS_TEST_C_H
#define NON_LINEAR_SYSTEMS_TEST_C_H
#include "cmath"
#include "../nonlinear/NonLinearEquation.h"
#include "../nonlinear/NonLinearSolver.h"
#include "TestBase.h"

double Test_C_function_1(double* input);
double Test_C_function_2(double* input);
double Test_C_dfunction_11(double* input);
double Test_C_dfunction_12(double* input);
double Test_C_dfunction_21(double* input);
double Test_C_dfunction_22(double* input);

/**
 * This class contains a concrete test case can be called, namely the Test_B. It's a system of nonlinear functions,
 * f1(x, y) = 2 * x ^ 2 - y + 1 and f2(x, y) = x + 2 * y - 6.
 */
class Test_C:public TestBase{
public:

    /**
     * default constructor
     */
    Test_C();

    /**
     * default destructor
     */
    ~Test_C();

    /**
     * It controls the execution of the analysis of the test case
     */
    void RunTest() override;

    /**
     * It shows the relevant information of the test case, saying the expression of the function, etc
     */
    void ShowEquationsInfo() override;
};

#endif //NON_LINEAR_SYSTEMS_TEST_C_H
