//
// Created by Rick Wang on 2019/12/11.
//

#include "RandomFunctions.h"
#include "string"
#include "exprtk/exprtk.hpp"

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


double RandomFunction_1(double* input)
{
    typedef double T;
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;

    T x = T(input[0]);

    symbol_table_t symbol_table;
    symbol_table.add_variable("x",x);

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;

    if (!parser.compile(fun_1_expression,expression))
    {
        std::cout<<"Compilation error"<<std::endl;
        return 0.0;
    }

    T result = expression.value();
    return result;
    //std::cout<<result<<std::endl;
}

//double RandomFunction_2(double* input);
//double RandomFunction_3(double* input);
//double RandomFunction_4(double* input);

double RandomDFunction_11(double* input)
{
    typedef double T;
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;

    T x = T(input[0]);

    symbol_table_t symbol_table;
    symbol_table.add_variable("x",x);

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;

    if (!parser.compile(dfun_11_expression,expression))
    {
        std::cout<<"Compilation error"<<std::endl;
        return 0.0;
    }

    T result = expression.value();
    return result;
    //std::cout<<result<<std::endl;
}

//double RandomDFunction_12(double* input);
//double RandomDFunction_13(double* input);
//double RandomDFunction_14(double* input);
//double RandomDFunction_21(double* input);
//double RandomDFunction_22(double* input);
//double RandomDFunction_23(double* input);
//double RandomDFunction_24(double* input);
//double RandomDFunction_31(double* input);
//double RandomDFunction_32(double* input);
//double RandomDFunction_33(double* input);
//double RandomDFunction_34(double* input);
//double RandomDFunction_41(double* input);
//double RandomDFunction_42(double* input);
//double RandomDFunction_43(double* input);
//double RandomDFunction_44(double* input);

double RandomDFunction_fp(double* input)
{
    typedef double T;
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;

    T x = T(input[0]);

    symbol_table_t symbol_table;
    symbol_table.add_variable("x",x);

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;

    if (!parser.compile(fun_fp_expression,expression))
    {
        std::cout<<"Compilation error"<<std::endl;
        return 0.0;
    }

    T result = expression.value();
    return result;
    //std::cout<<result<<std::endl;
}