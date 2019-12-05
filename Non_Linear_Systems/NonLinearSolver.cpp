//
// Created by Rick Wang on 2019/11/22.
//

#include "NonLinearSolver.h"
#include "NonLinearEquation.h"

//Constructor
NonLinearSolver::NonLinearSolver()
{
    equations = new NonLinearEquation();
    zeroPoint.clear();
}

NonLinearSolver::NonLinearSolver(functions_type input_equations)
{
    equations = input_equations;
    zeroPoint.clear();
}

NonLinearSolver::NonLinearSolver(NonLinearSolver& copy)
{
    equations = copy.GetEquations();
    zeroPoint = copy.GetZeroPoint();
}

//Member Function
const NonLinearEquation NonLinearSolver::GetEquations()
{
    return equations;
}

const std::map<std::string,std::list<double>> NonLinearSolver::GetZeroPoint()
{
    return zeroPoint;
}

//Numerical Methods
void NonLinearSolver::Bisection(double a, double b)
{
    double tol = 1e-5;//tolerance of the method
    double c = 0.0;
    int k=0;
    //first to check whether the dimension is 1
    if(equations.GetDimension()>1)
    {
        std::cout<<"Bisection Method can only used for 1 dimension equation"<<std::endl;
        return;
    }

    if(equations.GetFunctionValue(a)*equations.GetFunctionValue(b)>=0){
        std::cout<<"Incorrect a and b"<<std::endl;
        return;
    }

    while((b-a)>=tol){
        c = (a+b)/2;
        if(equations.GetFunctionValue(c)==0){
            //c is the zero point
            break;
        }
        else if(equations.GetFunctionValue(a)*equations.GetFunctionValue(c)<0.0){
            b = c;
        }
        else{
            a = c;
        }
        k++;
    }

    //add to the zeropoint map
    AddToZeroPoint("Bisection",c);
}

void NonLinearSolver::Aitken()
{

}

void NonLinearSolver::Chord(double a, double b)
{
    double tol = 1e-5;//tolerance of the method
    double xnp, xn, xnm;
    xnm = a;
    xn = b;
    xnp = 0.0;

    while(abs(xn-xnm)>=tol)
    {
        xnp = xn - equations.GetFunctionValue(xn)*(xn-xnm)/(equations.GetFunctionValue(xn)-equations.GetFunctionValue(xnm));
        xn = xnp;
        xnm = xn;
    }
    //add xn to the zeroPoint
    AddToZeroPoint("Chord",xn);
}

//fixed point method
void NonLinearSolver::FixedPoint()
{

}

void NonLinearSolver::Newton()
{
    int dim = equations.GetDimension();
    double* initial_guess = nullptr;//initial guess
    double* zeros = nullptr;
    double tol = 1e-5;

    //initialize
    //set the initial guess as a array of zero values
    initial_guess = new double[dim];
    for(int i=0; i<dim; i++)
    {
        initial_guess[i] = 0.0;
    }

    zeros = equations.GetFunArray(initial_guess);

    //iterations


    //solve linear systems



}

//operator

//helper function, linear solver iterative method
double* NonLinearSolver::LinearSolver_Splitting(double **A, double *b)
{
    int dim = equations.GetDimension();
    double* x = nullptr;

    x = new double[dim];

    //need to be finished

}

//other helper functions
void NonLinearSolver::AddToZeroPoint(std::string method, double zero)
{
    std::list<double> zerolist(1,zero);
    zeroPoint.insert(std::pair<std::string,std::list<double>>(method,zerolist));
}

void NonLinearSolver::AddToZeroPoint(std::string method, double* zeros)
{
    int dim = equations.GetDimension();
    std::list<double> zerolist;

    //put zeropoint in list
    for(int i=0; i<dim; i++)
    {
        zerolist.push_back(zeros[i]);
    }

    zeroPoint.insert(std::pair<std::string,std::list<double>>(method,zerolist));
}