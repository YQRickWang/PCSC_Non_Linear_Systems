//
// Created by Rick Wang on 2019/12/11.
//

#ifndef NON_LINEAR_SYSTEMS_RANDOMFUNCTIONS_H
#define NON_LINEAR_SYSTEMS_RANDOMFUNCTIONS_H

#include "iostream"

double RandomFunction_1(double* input);
double RandomFunction_2(double* input);
double RandomFunction_3(double* input);
double RandomFunction_4(double* input);
double RandomDFunction_11(double* input);
double RandomDFunction_12(double* input);
double RandomDFunction_13(double* input);
double RandomDFunction_14(double* input);
double RandomDFunction_21(double* input);
double RandomDFunction_22(double* input);
double RandomDFunction_23(double* input);
double RandomDFunction_24(double* input);
double RandomDFunction_31(double* input);
double RandomDFunction_32(double* input);
double RandomDFunction_33(double* input);
double RandomDFunction_34(double* input);
double RandomDFunction_41(double* input);
double RandomDFunction_42(double* input);
double RandomDFunction_43(double* input);
double RandomDFunction_44(double* input);
double RandomDFunction_fp(double* input);

//define global value
//define global variable for random function
extern std::string fun_1_expression;
extern std::string fun_2_expression;
extern std::string fun_3_expression;
extern std::string fun_4_expression;
extern std::string dfun_11_expression;
extern std::string dfun_12_expression;
extern std::string dfun_13_expression;
extern std::string dfun_14_expression;
extern std::string dfun_21_expression;
extern std::string dfun_22_expression;
extern std::string dfun_23_expression;
extern std::string dfun_24_expression;
extern std::string dfun_31_expression;
extern std::string dfun_32_expression;
extern std::string dfun_33_expression;
extern std::string dfun_34_expression;
extern std::string dfun_41_expression;
extern std::string dfun_42_expression;
extern std::string dfun_43_expression;
extern std::string dfun_44_expression;
extern std::string fun_fp_expression;
extern int random_dimension; //should be assigned to a certain value, 0 at first

#endif //NON_LINEAR_SYSTEMS_RANDOMFUNCTIONS_H
