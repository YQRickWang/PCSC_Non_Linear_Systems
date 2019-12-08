//
// Created by Rick Wang on 2019/12/7.
//

#ifndef NON_LINEAR_SYSTEMS_TEST_B_H
#define NON_LINEAR_SYSTEMS_TEST_B_H

#include "cmath"

//basic test for 1 dimension
//simple test
//f(x) = e^x-x-2
//df(x) = e^x-1
//g(x) = e^x-2
//x1 = -1.8414
//x2 = 1.14619
class Test_B {
public:
    double function_1(double* input);
    double dfunction_11(double* input);
    double fpfunction(double* input);
};


#endif //NON_LINEAR_SYSTEMS_TEST_B_H
