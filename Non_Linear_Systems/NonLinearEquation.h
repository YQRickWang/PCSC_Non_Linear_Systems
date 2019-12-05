//
// Created by Rick Wang on 2019/12/2.
//

#ifndef NON_LINEAR_SYSTEMS_NONLINEAREQUATION_H
#define NON_LINEAR_SYSTEMS_NONLINEAREQUATION_H

#include "iostream"

typedef double (*functions_type)(double*);

class NonLinearEquation {
private:
    int dim;//number of unknown variables in NonLinearSystems
    functions_type* funPtrArray;//the pointer points to the first element of the function pointer array 1*n
    functions_type** dfunPtrArray;//the pointer points to the first element of the derivation function pointer array n*n

public:
    //Constructor
    NonLinearEquation();
    NonLinearEquation(functions_type* funArray,functions_type** dfunArray,int dimension);
    NonLinearEquation(NonLinearEquation& copy);
    //Destructor
    ~NonLinearEquation();

    //Member functions
    double* GetFunctionValue(double** input);
    double GetFunctionValue(double input);//overload for dimension 1
    double** GetDfunctionValue(double** input);
    double GetDfunctionValue(double input);//overload for dimesion 1
    //void Plot(double a,double b);//only plot for 1d dimension, need to check if 1d

    //Get Member Function
    int GetDimension();
    functions_type* GetFunArray();
    functions_type** GetDfunArray();

    //operator
    NonLinearEquation& operator=(NonLinearEquation& other);//copy assignment

    //Helper functions
};


#endif //NON_LINEAR_SYSTEMS_NONLINEAREQUATION_H
