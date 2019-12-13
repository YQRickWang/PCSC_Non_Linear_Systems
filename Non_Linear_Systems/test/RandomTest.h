//
// Created by Rick Wang on 2019/12/11.
//

#ifndef NON_LINEAR_SYSTEMS_RANDOMTEST_H
#define NON_LINEAR_SYSTEMS_RANDOMTEST_H

#include "TestBase.h"
#include "cmath"
#include "../nonlinear/NonLinearEquation.h"
#include "../nonlinear/NonLinearSolver.h"
#include "RandomFunctions.h"

class RandomTest:public TestBase{
public:
    /**
    * default constructor for random test
    */
    RandomTest();

    /**
    * default destructor for random test
    */
    ~RandomTest();

    /**
    * It controls the execution of the analysis of the random test case
    */
    void RunTest() override;

    /**
     * It shows the relevant information of the random test case, saying the expression of the function, etc
     */
    void ShowEquationsInfo() override;
};


#endif //NON_LINEAR_SYSTEMS_RANDOMTEST_H
