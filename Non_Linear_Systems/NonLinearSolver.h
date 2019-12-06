//
// Created by Rick Wang on 2019/11/22.
//

#ifndef NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H
#define NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H

#include "iostream"
#include "map"
#include "cmath"
#include "list"
#include "string"
#include "NonLinearSolver.h"

typedef double (*functions_type)(double*); //do i have to add this line in this file


class NonLinearSolver {
private:
    NonLinearEquation equations;//contain the equation and the derivation of the functions
    std::map<std::string,std::list<double>> zeroPoint;//store the zero point of the linear systems as well as methods
public:
    //Constructor
    NonLinearSolver();
    NonLinearSolver(functions_type input_equations);
    NonLinearSolver(NonLinearSolver& copy);

    //Destructor
    ~NonLinearSolver();

    //get member function
    const NonLinearEquation GetEquations();
    const std::map<std::string,std::list<double>> GetZeroPoint();


    //method function
    void Bisection(double a, double b);//bisection between a and b
    void Aitken(double initial_guess, int max_iterations);
    void Chord(double a, double b);
    void Newton();
    //void Newton(double* initial_guess);
    //Newton1D();
    void FixedPoint(double initial_guess, int max_iterations);//intial_guess and max_iterations are default values
    void Plot();//plot zeropoint?
    void Print();//print the zeropoint and method of the function

    //operator

    //iterative linear system solver, helper function?
    double* LinearSolver_Splitting(double** A, double* b);
    double* LinearSolver_Jacobi(double** A, double* b);
    double* LinearSolver_GaussSeidel(double** A, double* b);

    //other helper functions
    void AddToZeroPoint(std::string method,double* zeros);
    void AddToZeroPoint(std::string method,double zeros);//overload for 1 dimension

    //need to be done
    //1. exception
    //2. plot
    //3. read data from text file?
    //4. solve linear systems by iterative methods
    //5. newton method
};


#endif //NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H
