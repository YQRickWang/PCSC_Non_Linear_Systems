//
// Created by Rick Wang on 2019/12/10.
//

#ifndef NON_LINEAR_SYSTEMS_TESTBASE_H
#define NON_LINEAR_SYSTEMS_TESTBASE_H

#include "../nonlinear/NonLinearSolver.h"
#include "../nonlinear/NonLinearEquation.h"
#include "cmath"
#include "string"

/**
 *This class contains some basic settings of a family of classes that we use for the test.
 */
class TestBase {
public:
    /**
     * this member "solver" contains the methods for solving a nonlinear equation or a system of nonlinear equations
     */
    NonLinearSolver solver;

    /**
     * this member "equations" contains the pointers pointing to the function pointers
     */
    NonLinearEquation equations;

    /**
     * default constructor
     */
    TestBase();

    /**
     * default destructor
     */
    ~TestBase();

    /**
     * It controls how the test will proceed, can override in different test cases
     */
    virtual void RunTest();

    /**
     * It shows the information of the equation or equations being studied, can override in different cases
     */
    virtual void ShowEquationsInfo();

    /**
     * It controls which method will be applied to solve the equation or equations, only the method corresponding to the
     * string variable "method" will be called
     * @param method the name of the method will be called
     */
    void ChooseMethod(std::string method);
};


#endif //NON_LINEAR_SYSTEMS_TESTBASE_H
