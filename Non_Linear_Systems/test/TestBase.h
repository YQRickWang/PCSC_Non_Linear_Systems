//
// Created by Rick Wang on 2019/12/10.
//

#ifndef NON_LINEAR_SYSTEMS_TESTBASE_H
#define NON_LINEAR_SYSTEMS_TESTBASE_H

#include "../src/NonLinearSolver.h"
#include "../src/NonLinearEquation.h"
#include "cmath"
#include "string"

class TestBase {
public:
    NonLinearSolver solver;
    NonLinearEquation equations;
    TestBase();
    ~TestBase();
    virtual void RunTest();//run all test
    virtual void ShowEquationsInfo();//show equations information
    void ChooseMethod(std::string method);
};


#endif //NON_LINEAR_SYSTEMS_TESTBASE_H
