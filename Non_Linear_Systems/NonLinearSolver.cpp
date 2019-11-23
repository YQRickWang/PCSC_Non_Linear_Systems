//
// Created by Rick Wang on 2019/11/22.
//

#include "NonLinearSolver.h"

//Constructor
NonLinearSolver::NonLinearSolver()
{
    funPtr = NULL;
    dfunPtr = NULL;
    zeroPoint.clear();
}

NonLinearSolver::NonLinearSolver(function_type fun, function_type dfun)
{
    funPtr = fun;
    dfunPtr = dfun;
    zeroPoint.clear();
}

NonLinearSolver::NonLinearSolver(NonLinearSolver& copy)
{
    funPtr = copy.GetFunPtr();
    dfunPtr = copy.GetDfunPtr();
    zeroPoint = copy.GetZeroPointMap();
}

//Member Function
const function_type NonLinearSolver::GetFunPtr()
{
    return funPtr;
}

const function_type NonLinearSolver::GetDfunPtr()
{
    return dfunPtr;
}

const std::map<std::string,double> NonLinearSolver::GetZeroPointMap()
{
    return zeroPoint;
}
