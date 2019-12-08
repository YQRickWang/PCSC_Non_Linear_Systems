//
// Created by Rick Wang on 2019/12/7.
//

#include "Test_A.h"

//basic test for 1 dimension
//simple test
//f(x) = x-1
//df(x) = 1
//g(x) = 1
//x=1
double Test_A_function_1(double *input)
{
    return input[0]-1;
}

double Test_A_dfunction_11(double *input)
{
    return 1;
}

double Test_A_fpfunction(double *input)
{
    return 1;
}

