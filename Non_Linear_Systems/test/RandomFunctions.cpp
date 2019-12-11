//
// Created by Rick Wang on 2019/12/11.
//

#include "RandomFunctions.h"
#include "string"
#include "../exprtk/exprtk.hpp"

int random_dimension;
std::string fun_1_expression;
std::string fun_2_expression;
std::string fun_3_expression;
std::string fun_4_expression;
std::string dfun_11_expression;
std::string dfun_12_expression;
std::string dfun_13_expression;
std::string dfun_14_expression;
std::string dfun_21_expression;
std::string dfun_22_expression;
std::string dfun_23_expression;
std::string dfun_24_expression;
std::string dfun_31_expression;
std::string dfun_32_expression;
std::string dfun_33_expression;
std::string dfun_34_expression;
std::string dfun_41_expression;
std::string dfun_42_expression;
std::string dfun_43_expression;
std::string dfun_44_expression;
std::string fun_fp_expression;

double RandomFunctionBase(std::string str_expression,double* input)
{
    typedef double T;
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;

    symbol_table_t symbol_table;


    T x,y,z,w;
    if(random_dimension==1)
    {
        x = input[0];
        symbol_table.add_variable("x",x);
    }
    else if(random_dimension==2)
    {
        x = input[0];
        y = input[1];
        symbol_table.add_variable("x",x);
        symbol_table.add_variable("y",y);
    }
    else if(random_dimension==3)
    {
        x = input[0];
        y = input[1];
        z = input[2];
        symbol_table.add_variable("x",x);
        symbol_table.add_variable("y",y);
        symbol_table.add_variable("z",z);
    }
    else if(random_dimension==4)
    {
        x = input[0];
        y = input[1];
        z = input[2];
        w = input[3];
        symbol_table.add_variable("x",x);
        symbol_table.add_variable("y",y);
        symbol_table.add_variable("z",z);
        symbol_table.add_variable("w",w);
    }
    else{
        std::cout<<"Error"<<std::endl;
    }



    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;

    if (!parser.compile(str_expression,expression))
    {
        std::cout<<"Compilation error"<<std::endl;
        return 0.0;
    }

    T result = expression.value();
    return result;
}

double RandomFunction_1(double* input)
{
    return RandomFunctionBase(fun_1_expression,input);
}

double RandomFunction_2(double* input)
{
    return RandomFunctionBase(fun_2_expression,input);
}

double RandomFunction_3(double* input)
{
    return RandomFunctionBase(fun_3_expression,input);
}

double RandomFunction_4(double* input)
{
    return RandomFunctionBase(fun_4_expression,input);
}

double RandomDFunction_11(double* input)
{
    return RandomFunctionBase(dfun_11_expression,input);
}

double RandomDFunction_12(double* input)
{
    return RandomFunctionBase(dfun_12_expression,input);
}

double RandomDFunction_13(double* input)
{
    return RandomFunctionBase(dfun_13_expression,input);
}

double RandomDFunction_14(double* input)
{
    return RandomFunctionBase(dfun_14_expression,input);
}

double RandomDFunction_21(double* input)
{
    return RandomFunctionBase(dfun_21_expression,input);
}

double RandomDFunction_22(double* input)
{
    return RandomFunctionBase(dfun_22_expression,input);
}

double RandomDFunction_23(double* input)
{
    return RandomFunctionBase(dfun_23_expression,input);
}

double RandomDFunction_24(double* input)
{
    return RandomFunctionBase(dfun_24_expression,input);
}

double RandomDFunction_31(double* input)
{
    return RandomFunctionBase(dfun_31_expression,input);
}

double RandomDFunction_32(double* input)
{
    return RandomFunctionBase(dfun_32_expression,input);
}

double RandomDFunction_33(double* input)
{
    return RandomFunctionBase(dfun_33_expression,input);
}

double RandomDFunction_34(double* input)
{
    return RandomFunctionBase(dfun_34_expression,input);
}

double RandomDFunction_41(double* input)
{
    return RandomFunctionBase(dfun_41_expression,input);
}

double RandomDFunction_42(double* input)
{
    return RandomFunctionBase(dfun_42_expression,input);
}

double RandomDFunction_43(double* input)
{
    return RandomFunctionBase(dfun_43_expression,input);
}

double RandomDFunction_44(double* input)
{
    return RandomFunctionBase(dfun_44_expression,input);
}

double RandomFunction_fp(double* input)
{
    return RandomFunctionBase(fun_fp_expression,input);
}