//
// Created by Rick Wang on 2019/12/7.
//

#include "Test_B.h"

//basic test for 1 dimension
//simple test
//f(x) = e^x-x-2
//df(x) = e^x-1
//g(x) = e^x-2
//x1 = -1.8414
//x2 = 1.14619
double Test_B::function_1(double *input)
{
    return exp(input[0])-input[0]-2;
}

double Test_B::dfunction_11(double *input)
{
    return exp(input[0])-1;
}

double Test_B::fpfunction(double *input)
{

}