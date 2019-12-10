//
// Created by Rick Wang on 2019/12/9.
//

#ifndef NON_LINEAR_SYSTEMS_TEST_C_H
#define NON_LINEAR_SYSTEMS_TEST_C_H

//basic test for 2 dimensions
//simple test
//f1(x) = 2*x^2-y+1
//f2(x) = x+2*y-6
//df11(x) = 4*x
//df12(y) = -1
//df21(x) = 1
//df22(y) = 2
double Test_C_function_1(double* input);
double Test_C_function_2(double* input);
double Test_C_dfunction_11(double* input);
double Test_C_dfunction_12(double* input);
double Test_C_dfunction_21(double* input);
double Test_C_dfunction_22(double* input);

#endif //NON_LINEAR_SYSTEMS_TEST_C_H
