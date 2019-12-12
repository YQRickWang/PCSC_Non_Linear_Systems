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

//Set Member Function
void NonLinearSolver::SetEquations(NonLinearEquation input_equations)
{
    this->equations = input_equations;
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
        std::cout<<"The Aitken is only for 1 dimension, please check again."<<std::endl;
        return;
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

        err = fabs(x - x_prev);
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
    double error = 0.0;

    //initialize
    //set the initial guess as a array of zero values
    initial_guess = new double[dim];
    for(int i=0; i<dim; i++)
    {
        initial_guess[i] = 0.5;
    }

    x_prev = initial_guess;

    //iterations
    do{
        b = equations.GetFunctionValue(x_prev);
        A = equations.GetDfunctionValue(x_prev);
        //modify b a little, negative
        for(int i=0; i<dim; i++)
        {
            b[i] = -1*b[i];
        }

        for(int i=0;i<dim;i++)
        {
            std::cout<<"line:"<<i<<"   ";
            for(int j=0;j<dim;j++)
            {
                std::cout<<A[i][j]<<" ";
            }
            std::cout<<b[i]<<std::endl;
        }

        x_delta = LinearSolver_LU(A,b);

        //test
        std::cout<<"Result of x_delta:"<<"  ";
        for(int i=0;i<dim;i++)
        {
            std::cout<<x_delta[i]<<"  ";
        }
        std::cout<<std::endl;

        x_next = MatrixAdd(x_prev,x_delta,dim);//need to check
        error = GetError(x_prev,x_next,dim);
        x_prev = x_next;
        it_count++;
    }while(it_count<=max_iterations&&error>=tol);

    AddToZeroPoint("Newton",x_next);

}

void NonLinearSolver::ModifiedNewton(double m, int max_iterations)
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
    double error = 0.0;

    //initialize
    //set the initial guess as a array of zero values
    initial_guess = new double[dim];
    for(int i=0; i<dim; i++)
    {
        initial_guess[i] = 0.5;
    }

    x_prev = initial_guess;

    //iterations
    do{
        b = equations.GetFunctionValue(x_prev);
        A = equations.GetDfunctionValue(x_prev);
        //modify b a little, negative
        for(int i=0; i<dim; i++)
        {
            b[i] = -m*b[i];
        }

        for(int i=0;i<dim;i++)
        {
            std::cout<<"line:"<<i<<"   ";
            for(int j=0;j<dim;j++)
            {
                std::cout<<A[i][j]<<" ";
            }
            std::cout<<b[i]<<std::endl;
        }

        x_delta = LinearSolver_LU(A,b);

        //test
        std::cout<<"Result of x_delta:"<<"  ";
        for(int i=0;i<dim;i++)
        {
            std::cout<<x_delta[i]<<"  ";
        }
        std::cout<<std::endl;

        x_next = MatrixAdd(x_prev,x_delta,dim);//need to check
        error = GetError(x_prev,x_next,dim);
        x_prev = x_next;
        it_count++;
    }while(it_count<=max_iterations&&error>=tol);

    AddToZeroPoint("ModifiedNewton",x_next);
}

void NonLinearSolver::Newton1D(double initial_guess, int max_iterations) {
    double tol = 1e-5;
    int it_count = 0;

    double x = initial_guess - equations.GetFunctionValue(initial_guess) / equations.GetDfunctionValue(initial_guess);

    double err = tol + 1;

    while(err >= tol && it_count <= max_iterations){
        double x_prev = x;
        x = x - equations.GetFunctionValue(x) / equations.GetDfunctionValue(x);
        err = fabs(x - x_prev);
        it_count = it_count + 1;
    }

    AddToZeroPoint("Newton1D",x);
}

void NonLinearSolver::ModifiedNewton1D(double initial_guess, double m, int max_iterations) {
    double tol = 1e-5;
    int it_count = 0;

    double x = initial_guess - m*equations.GetFunctionValue(initial_guess) / equations.GetDfunctionValue(initial_guess);

    double err = tol + 1;

    while(err >= tol && it_count <= max_iterations){
        double x_prev = x;
        x = x - equations.GetFunctionValue(x) / equations.GetDfunctionValue(x);
        err = fabs(x - x_prev);
        it_count = it_count + 1;
    }

    AddToZeroPoint("ModifiedNewton1D",x);
}

//helper function, linear solver iterative method
double* NonLinearSolver::LinearSolver_Jacobi(double **A, double *b, int max_iterations) {
    int dim = equations.GetDimension();
    double tol = 1e-6;
    double err;
    err = tol + 1.0;
    double* initial_guess = new double[dim];
    double* x_prev = new double[dim];
    double* x_next = new double[dim];

    for (int i = 0; i < dim; i++){
        initial_guess[i] = 0.0;
        x_prev[i] = initial_guess[i];
    }

    double** P = new double* [dim];
    std::cout<<"print P"<<"\n";
    for(int i = 0; i < dim; i++){
        P[i] = new double[dim];
        for (int j = 0; j < dim; j++){
            if(i == j){
                P[i][j] = A[i][j];
                std::cout<<P[i][j]<<" ";
            }
            else{
                P[i][j] = 0.0;
                std::cout<<P[i][j]<<" ";
            }
        }
        std::cout<<"\n";
    }
    double* res = new double[dim];
    res = MatrixSub(b, MatrixMulti(A, x_prev, dim), dim);
    std::cout<<"print res"<<"\n";
    for(int i = 0; i < dim; i++){
        std::cout<<res[i]<<" ";
    }
    std::cout<<"\n";
    int it_count = 0;
    while(err >= tol && it_count <= max_iterations){
        double* z = new double[dim];
        z = Forward(P, res, dim);
        for(int i =0; i < dim; i++){
            x_next[i] = x_prev[i] + z[i];
        }

        err = GetError(res, MatrixMulti(A, z, dim), dim);
        res = MatrixSub(res, MatrixMulti(A, z, dim), dim);
        for(int i = 0; i < dim; i++){
            x_prev[i] = x_next[i];
        }
        it_count = it_count + 1;
    }

    for(int i=0; i<dim; i++)
    {delete P[i];}

    delete []P;

    return x_prev;
}


double* NonLinearSolver::LinearSolver_LU(double **A, double *b)
{
    int dim = equations.GetDimension();
    double** L = new double*[dim];
    double** U = new double*[dim];
    double* y = nullptr;
    double* x = nullptr;

    for(int i=0;i<dim;i++)
    {
        L[i] = new double[dim];
        U[i] = new double[dim];
    }

    LUDecomposition(A,L,U,dim);
    y = Forward(L,b,dim);
    x = Backward(U,y,dim);


    //delete the sapce
    for(int i=0;i<dim;i++)
    {
        delete L[i];
        delete U[i];
    }

    delete []L;
    delete []U;


    return x;
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

void NonLinearSolver::ClearZeroPoint()
{
    zeroPoint.clear();
}