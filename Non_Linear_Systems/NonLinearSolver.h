//
// Created by Rick Wang on 2019/11/22.
//

#ifndef NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H
#define NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H

#include "iostream"
#include "map"
#include "string"

typedef double (*function_type)(double);


class NonLinearSolver {
private:
    function_type funPtr;//a function pointer of original function
    function_type dfunPtr;//a function pointer of derivative of the original function
    std::map<std::string,double> zeroPoint;//store the zero point of the function as well as method
public:
    //Constructor
    NonLinearSolver();
    NonLinearSolver(function_type fun, function_type dfun);
    NonLinearSolver(NonLinearSolver& copy);

    //get member function
    const function_type GetFunPtr();
    const function_type GetDfunPtr();
    const std::map<std::string,double> GetZeroPointMap();


    //method function
    void Bisection(double a, double b);//bisection between a and b
    void Bisection();//bisection to find all zeroPoint
    void Aitken();
    void Chord();
    void Newton();
    void FixedPoint();

};


#endif //NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H
