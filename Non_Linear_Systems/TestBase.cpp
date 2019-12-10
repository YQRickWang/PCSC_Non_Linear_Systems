//
// Created by Rick Wang on 2019/12/10.
//

#include "TestBase.h"

TestBase::TestBase()
{
    NonLinearEquation voideq;
    NonLinearSolver voidsolver(voideq);
    this->equations = voideq;
    this->solver = voidsolver;
}