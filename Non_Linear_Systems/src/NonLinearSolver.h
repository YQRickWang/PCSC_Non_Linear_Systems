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
#include "NonLinearEquation.h"
#include "MatrixHelper.h"

typedef double (*functions_type)(double*);


class NonLinearSolver {
private:
    NonLinearEquation equations;//contain the equation and the derivation of the functions
    std::map<std::string,std::list<double>> zeroPoint;//store the zero point of the linear systems as well as methods
public:
    //Constructor
    NonLinearSolver();
    NonLinearSolver(NonLinearEquation input_equations);
    NonLinearSolver(NonLinearSolver& copy);

    //Destructor
    ~NonLinearSolver();

    //get member function
    const NonLinearEquation GetEquations();
    const std::map<std::string,std::list<double>> GetZeroPoint();
    //Set member function
    void SetEquations(NonLinearEquation input_equations);


    //method function
    void Bisection(double a, double b);
    void Aitken(double initial_guess = 0.0, int max_iterations = 100);
    void Chord(double a, double b);
    void FixedPoint(double initial_guess = 0.0 , int max_iterations = 100);
    void Newton1D(double initial_guess=0.0, int max_iterations=100);
    void ModifiedNewton1D(double initial_guess = 0.0, double m=1.0, int max_iterations=100);
    void Newton(double* initial_guess, int max_iterations=100);
    void ModifiedNewton(double* initial_guess, double m=1.0, int max_iterations=100);

    //print the zero point list
    void ZeroPointPrint();//print the zeropoint and method of the function


    // linear system solver
    double* LinearSolver_Jacobi(double** A, double* b, int max_iterations = 1000);
    double* LinearSolver_LU(double** A,double* b);

    //other helper functions
    void AddToZeroPoint(std::string method,double* zeros);
    void AddToZeroPoint(std::string method,double zeros);//overload for 1 dimension
    void ClearZeroPoint();

};


#endif //NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H
