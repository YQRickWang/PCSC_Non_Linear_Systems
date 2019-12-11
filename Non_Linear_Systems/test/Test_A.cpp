//
// Created by Rick Wang on 2019/12/7.
//

#include "Test_A.h"

//basic test for 1 dimension
//simple test
//f(x) = x-1
//df(x) = 1
//g(x) = 1
//x=1
double Test_A_function_1(double *input)
{
    return input[0]-1;
}

double Test_A_dfunction_11(double *input)
{
    return 1;
}

double Test_A_fpfunction(double *input)
{
    return 1;
}

Test_A::Test_A()
{
    functions_type* fun_1 = nullptr;
    functions_type** dfun_1 = nullptr;
    functions_type fp_1 = nullptr;

    //initialize
    fun_1 = new functions_type[1];
    dfun_1 = new functions_type*[1];
    dfun_1[0] = new functions_type[1];

    fun_1[0] = &Test_A_function_1;
    dfun_1[0][0] = &Test_A_dfunction_11;
    fp_1 = &Test_A_fpfunction;

    this->equations.SetDimension(1);
    this->equations.SetFunArray(fun_1);
    this->equations.SetDFunArray(dfun_1);
    this->equations.SetFpFun(fp_1);
    this->solver.SetEquations(this->equations);
}

void Test_A::RunTest()
{
//    this->solver.Bisection(0,2);
//    this->solver.Chord(0,2);
//    this->solver.FixedPoint();
//    this->solver.Aitken(0.0);
//    this->solver.Newton1D(0.0);
//    this->solver.Newton();
//    this->solver.ModifiedNewton();
//    this->solver.ModifiedNewton1D(0.0,2.0);
//    this->solver.ZeroPointPrint();
    std::string command;
    std::cout<<"Test A is running"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    ShowEquationsInfo();

    while(true){
        std::cout<<"Please Choose Method For Solving"<<std::endl;
        std::cout<<"--------------------------------------------------"<<std::endl;
        std::cout<<"Type \"exit\" to get out the test case."<<std::endl;
        std::cout<<"--------------------------------------------------"<<std::endl;
        std::cin>>command;
        if(command=="exit")
        {
            std::cout<<"Exit from this test case"<<std::endl;
            break;
        }
        ChooseMethod(command);
    }
}

void Test_A::ShowEquationsInfo()
{
    std::cout<<"Test A info: "<<std::endl;
    std::cout<<"Dimension: "<<equations.GetDimension()<<std::endl;
    std::cout<<"f(x) = x - 1"<<std::endl;
    std::cout<<"df(x) = 1"<<std::endl;
    std::cout<<"g(x) = 1"<<std::endl;
    std::cout<<"Expected Result: 1"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"In this case, you can choose following methods: "<<std::endl;
    std::cout<<"Aitken Bisection Chord FixedPoint ModifiedNewton1D Newton1D All"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
}


Test_A::~Test_A()
{
    //delete all the allocated space
}



