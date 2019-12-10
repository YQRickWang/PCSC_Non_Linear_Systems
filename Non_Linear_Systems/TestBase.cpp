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
        solver.Aitken();
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else if(method=="Bisection"&& dim==1)
    {
        solver.Bisection(0,2);
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else if(method=="Chord"&& dim==1)
    {
        solver.Chord(0,2);
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else if(method=="FixedPoint"&& dim==1)
    {
        solver.FixedPoint();
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else if(method=="Newton1D"&& dim==1)
    {
        solver.Newton1D();
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else if(method=="ModifiedNewton1D"&& dim==1)
    {
        solver.ModifiedNewton1D();
        solver.ZeroPointPrint();
        solver.ClearZeroPoint();
    }
    else
    {
        std::cout<<"There is no such method, please try valid method"<<std::endl;
    }
}

