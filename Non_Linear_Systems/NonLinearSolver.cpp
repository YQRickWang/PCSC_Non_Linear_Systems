//
// Created by Rick Wang on 2019/11/22.
//

#include "NonLinearSolver.h"
#include "iostream"


NonLinearSolver::NonLinearSolver()
{
    funPtr = NULL;
    dfunPtr = NULL;
}

NonLinearSolver::NonLinearSolver(double (*)(double) funPtr, double (*)(double) dfunPtr)
{

}
