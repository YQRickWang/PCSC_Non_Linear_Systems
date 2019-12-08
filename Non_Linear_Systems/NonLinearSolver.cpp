//
// Created by Rick Wang on 2019/11/22.
//

#include "NonLinearSolver.h"
#include "NonLinearEquation.h"

//Constructor
NonLinearSolver::NonLinearSolver()
{
    NonLinearEquation voideq;
    this->equations=voideq;
    this->zeroPoint.clear();
}

NonLinearSolver::NonLinearSolver(NonLinearEquation input_equations)
{
    this->equations = input_equations;
    this->zeroPoint.clear();
}

NonLinearSolver::NonLinearSolver(NonLinearSolver& copy)
{
    this->equations = copy.GetEquations();
    this->zeroPoint = copy.GetZeroPoint();
}

NonLinearSolver::~NonLinearSolver()
{
    //nothing to do
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

//basically fixed point method, but using aitken acceleration
void NonLinearSolver::Aitken(double initial_guess, int max_iterations)
{
    int dim = equations.GetDimension();
    double tol = 1e-5;
    double x_prev = initial_guess;
    double x_next = 0.0;
    double x_next_next = 0.0;
    double error = 0.0;
    int it_count = 0;

    if(dim>1)
    {
        std::cout<<"The Fixed Point method (Aitken) is only for 1 dimension, please check again."<<std::endl;
    }

    do{
        x_next = equations.GetFpFunctionValue(x_prev);
        x_next_next = equations.GetFpFunctionValue(x_next);

        //compute next by using aitken acceralation
        x_next = x_prev - (pow(x_next-x_prev,2))/(x_next_next-2*x_next+x_prev);

        error = GetError(x_prev,x_next);
        x_prev = x_next;
        it_count++;
    }while(error>=tol&&it_count<=max_iterations);

    if(error>=tol)
        std::cout<<"The aitken method does not converges."<<std::endl;

    //add to the zeroPoint
    AddToZeroPoint("Aitken",x_next);
}

void NonLinearSolver::Chord(double a, double b)
{
    double tol = 1e-5;//tolerance of the method
    double intervalBegin, x, intervalEnd;
    intervalBegin = a;
    intervalEnd = b;
    x = (intervalBegin * equations.GetFunctionValue(intervalEnd) - intervalEnd * equations.GetFunctionValue(intervalBegin)) / (equations.GetFunctionValue(intervalEnd) - equations.GetFunctionValue(intervalBegin));
    double err = tol + 1;
    while(err >= tol)
    {
        double x_prev = x;
        if(equations.GetFunctionValue(intervalBegin) * equations.GetFunctionValue(intervalEnd) >= 0.0){
            std::cout<< "incorrect interval" <<"\n";
        }
        else if(equations.GetFunctionValue(intervalBegin) * equations.GetFunctionValue(x) < 0){
            intervalEnd = x;
            x = (intervalBegin * equations.GetFunctionValue(intervalEnd) - intervalEnd * equations.GetFunctionValue(intervalBegin)) / (equations.GetFunctionValue(intervalEnd) - equations.GetFunctionValue(intervalBegin));
        }
        else{
            intervalBegin = x;
            x = (intervalBegin * equations.GetFunctionValue(intervalEnd) - intervalEnd * equations.GetFunctionValue(intervalBegin)) / (equations.GetFunctionValue(intervalEnd) - equations.GetFunctionValue(intervalBegin));
        }

        err = abs(x - x_prev);
    }
    //add xn to the zeroPoint
    AddToZeroPoint("Chord",x);
}

//fixed point method
void NonLinearSolver::FixedPoint(double initial_guess, int max_iterations)
{
    int dim = equations.GetDimension();
    double tol = 1e-5;
    double x_prev = initial_guess;
    double x_next = 0.0;
    double error = 0.0;
    int it_count = 0;

    if(dim>1)
    {
        std::cout<<"The fixed point method is only for 1 dimension, please check again."<<std::endl;
    }


    do{
        x_next = equations.GetFpFunctionValue(x_prev);
        error = GetError(x_prev,x_next);
        x_prev = x_next;
        it_count++;
    }while(it_count<=max_iterations&&error>=tol);

    //check the convergence?
    if(error>=tol)
        std::cout<<"The fixed point method does not converges."<<std::endl;

    //add to the zeroPoint
    AddToZeroPoint("FixedPoint",x_next);

}

//for high dimemsion
void NonLinearSolver::Newton(int max_iterations)
{
    int dim = equations.GetDimension();
    int it_count = 0;
    double* initial_guess = nullptr;//initial guess
    double* x_prev = nullptr;
    double* x_next = nullptr;
    double* x_delta = nullptr;
    double** A = nullptr;
    double* b = nullptr;
    double tol = 1e-5;

    //initialize
    //set the initial guess as a array of zero values
    initial_guess = new double[dim];
    for(int i=0; i<dim; i++)
    {
        initial_guess[i] = 0.0;
    }

    x_prev = initial_guess;

    //iterations
    do{
        b = equations.GetFunctionValue(x_prev);
        A = equations.GetDfunctionValue(x_prev);
        //modify b a little, negative
        for(int i=0; i<dim; i++)
        {
            b[i] = -b[i];
        }

        x_delta = LinearSolver_Splitting(A,b);

        x_next = MatrixAdd(x_prev,x_delta,dim);//need to check
        it_count++;
    }while(it_count<=max_iterations&&GetError(x_prev,x_next,dim)>=tol);

    AddToZeroPoint("Newton",x_next);

}

void NonLinearSolver::Newton1D(double initial_guess, int max_iterations) {
    double tol = 1e-5;
    int it_count = 0;

    double x = initial_guess - equations.GetFunctionValue(initial_guess) / equations.GetDfunctionValue(initial_guess);

    double err = tol + 1;

    while(err >= tol && it_count <= max_iterations){
        double x_prev = x;
        x = x - equations.GetFunctionValue(x) / equations.GetDfunctionValue(x);
        err = abs(x - x_prev);
        it_count = it_count + 1;
    }

    AddToZeroPoint("Newton1D",x);
}

//operator

//helper function, linear solver iterative method
//need to check use of the space to avoid memory leakage
double* NonLinearSolver::LinearSolver_Splitting(double **A, double *b, int max_iterations)
/**
 *
 * @param A
 * @param b
 * @return
 */
{
    int dim = equations.GetDimension();
    int it_count = 0;
    double tol = 1e-5;
    double* x_prev = nullptr;
    double* x_next = nullptr;
    double* r = nullptr;
    double* z = nullptr;
    double** P = nullptr;

    x_prev = new double[dim];
    x_next = new double[dim];
    r = new double[dim];
    z = new double[dim];

    //initialize
    P = new double*[dim];
    for(int i=0;i<dim;i++)
    {
        P[i] = new double[dim];
        //initialize x as well
        x_prev[i] = 0.0;
        x_next[i] = 0.0;
        r[i] = 0.0;
    }

    for(int i =0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            if(i==j)
                P[i][j] = 1.0;
            else
                P[i][j] = 0.0;
        }
    }

    r = MatrixSub(b,MatrixMulti(A,x_prev,dim),dim);

    //iterative
    do{
        z = r;
        x_next = MatrixAdd(x_prev,z,dim);
        r = MatrixSub(r,MatrixMulti(A,z,dim),dim);
        it_count++;
    }while(it_count<=max_iterations&&GetError(x_prev,x_next,dim)>=tol);


    if(GetError(x_prev,x_next,dim)>=tol)
    {
        std::cout<<"Solve Linear System Eorror: Splitthing Method, Cannot coverges"<<std::endl;
    }

    //delete P at the end of function
    for(int i=0;i<dim;i++)
        delete P[i];

    delete []P;

    return x_next;

}

void NonLinearSolver::ZeroPointPrint()
{
    //print zero point
    for(auto it = zeroPoint.begin();it!=zeroPoint.end();++it)
    {
        std::cout<<it->first<<":"<<std::endl;


        for(auto it_list = (it->second).begin();it_list!=(it->second).end();++it_list)
        {
            std::cout<<*it_list<<std::endl;
        }
    }
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