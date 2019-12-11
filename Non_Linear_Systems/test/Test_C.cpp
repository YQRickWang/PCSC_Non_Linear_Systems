//
// Created by Rick Wang on 2019/12/9.
//

#include "Test_C.h"
#include "cmath"

//basic test for 2 dimensions
//simple test
//f1(x) = 2*x^2-y+1
//f2(x) = x+2*y-6
//df11(x) = 4*x
//df12(y) = -1
//df21(x) = 1
//df22(y) = 2


double Test_C_function_1(double* input)
{
    return 2*pow(input[0],2)-input[1]+1;
}

double Test_C_function_2(double* input)
{
    return input[0]+2*input[1]-6;
}

double Test_C_dfunction_11(double* input)
{
    return 4*input[0];
}

double Test_C_dfunction_12(double* input)
{
    return -1;
}

double Test_C_dfunction_21(double* input)
{
    return 1;
}

double Test_C_dfunction_22(double* input)
{
    return 2;
}
