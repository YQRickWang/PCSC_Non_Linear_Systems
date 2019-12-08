//
// Created by Rick Wang on 2019/12/7.
//

#ifndef NON_LINEAR_SYSTEMS_TEST_A_H
#define NON_LINEAR_SYSTEMS_TEST_A_H

#include "cmath"

//basic test for 1 dimension
//simple test
//f(x) = x-1
//df(x) = 1
//g(x) = 1
//x=1
class Test_A {
public:
    double function_1(double* input);
    double dfunction_11(double* input);
    double fpfunction(double* input);
};


#endif //NON_LINEAR_SYSTEMS_TEST_A_H
