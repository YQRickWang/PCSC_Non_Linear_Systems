//
// Created by Rick Wang on 2019/12/10.
//

#include "TestBase.h"

TestBase::TestBase()
{
    NonLinearEquation voideq;
    NonLinearSolver voidsolver(voideq);
    this->equations = voideq;
    this->solver = voidsolver;
}

TestBase::~TestBase()
{
    delete [](this->equations.GetFunArray());

    for(int i=0; i<this->equations.GetDimension();i++)
    {
        delete this->equations.GetDfunArray()[i];
    }

    delete [](this->equations.GetDfunArray());
}

void TestBase::RunTest()
{
    std::cout<<"Test is running"<<std::endl;
}

void TestBase::ShowEquationsInfo()
{
    std::cout<<"Show Equations information"<<std::endl;
}

void TestBase::ChooseMethod(std::string method)
{
    int dim = this->equations.GetDimension();
    if(method=="Aitken"&& dim==1)
    {
        double initial_guess;
        std::cout<<"Enter the initial guess: "<<"\n";
        std::cin>>initial_guess;
        solver.Aitken(initial_guess);
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else if(method=="Bisection"&& dim==1)
    {
        double a,b;
        std::cout<<"Enter the interval of your guess: "<<std::endl;
        std::cin>>a>>b;
        solver.Bisection(a, b);
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else if(method=="Chord"&& dim==1)
    {
        double a,b;
        std::cout<<"Enter the interval of your guess: "<<std::endl;
        std::cin>>a>>b;
        solver.Chord(a, b);
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else if(method=="FixedPoint"&& dim==1)
    {
        double initial_guess;
        std::cout<<"Enter the initial guess: "<<"\n";
        std::cin>>initial_guess;
        solver.FixedPoint();
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else if(method=="Newton1D"&& dim==1)
    {
        double initial_guess;
        std::cout<<"Enter the initial guess: "<<"\n";
        std::cin>>initial_guess;
        solver.Newton1D(initial_guess);
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else if(method=="ModifiedNewton1D"&& dim==1)
    {
        double initial_guess;
        std::cout<<"Enter the initial guess: "<<"\n";
        std::cin>>initial_guess;
        double m;
        std::cout<<"Enter the weight m in the modified Newton method: "<<"\n";
        std::cin>>m;
        solver.ModifiedNewton1D(initial_guess, m);
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else if(method=="Newton" && dim != 1){
        solver.Newton();
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else if(method=="ModifiedNewton" && dim != 1){
        double m;
        std::cout<<"Enter the weight m in the modified Newton method: "<<"\n";
        std::cin>>m;
        solver.ModifiedNewton(m);
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else
    {
        std::cout<<"There is no such method, please try valid method"<<std::endl;
    }
}
