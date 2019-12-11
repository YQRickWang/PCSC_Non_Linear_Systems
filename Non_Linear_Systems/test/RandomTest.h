//
// Created by Rick Wang on 2019/12/11.
//

#ifndef NON_LINEAR_SYSTEMS_RANDOMTEST_H
#define NON_LINEAR_SYSTEMS_RANDOMTEST_H

#include "TestBase.h"
#include "cmath"
#include "../src/NonLinearEquation.h"
#include "../src/NonLinearSolver.h"
#include "RandomFunctions.h"

class RandomTest:public TestBase{
public:
    RandomTest();
    ~RandomTest();
    void RunTest() override;
    void ShowEquationsInfo() override;
};


#endif //NON_LINEAR_SYSTEMS_RANDOMTEST_H
