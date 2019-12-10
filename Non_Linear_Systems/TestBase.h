//
// Created by Rick Wang on 2019/12/10.
//

#ifndef NON_LINEAR_SYSTEMS_TESTBASE_H
#define NON_LINEAR_SYSTEMS_TESTBASE_H

#include "NonLinearSolver.h"
#include "NonLinearEquation.h"

class TestBase {
public:
    NonLinearSolver solver;
    NonLinearEquation equations;
    TestBase();
};


#endif //NON_LINEAR_SYSTEMS_TESTBASE_H
