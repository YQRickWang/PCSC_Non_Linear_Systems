//
// Created by Rick Wang on 2019/12/7.
//

#include "Test_B.h"

//basic test for 1 dimension
//simple test
//f(x) = e^x-x-2
//df(x) = e^x-1
//g(x) = e^x-2
//x1 = -1.8414
//x2 = 1.14619
double Test_B_function_1(double *input)
{
    return exp(input[0])-input[0]-2;
}

double Test_B_dfunction_11(double *input)
{
    return exp(input[0])-1;
}

double Test_B_fpfunction(double *input)
{
    return exp(input[0])-2;
}

Test_B::Test_B()
{
    functions_type* fun_1 = nullptr;
    functions_type** dfun_1 = nullptr;
    functions_type fp_1 = nullptr;

    //initialize
    fun_1 = new functions_type[1];
    dfun_1 = new functions_type*[1];
    dfun_1[0] = new functions_type[1];

    fun_1[0] = &Test_B_function_1;
    dfun_1[0][0] = &Test_B_dfunction_11;
    fp_1 = &Test_B_fpfunction;

    this->equations.SetDimension(1);
    this->equations.SetFunArray(fun_1);
    this->equations.SetDFunArray(dfun_1);
    this->equations.SetFpFun(fp_1);
    this->solver.SetEquations(this->equations);
}

void Test_B::RunTest()
{
    std::string command;
    std::cout<<"Test B is running"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    ShowEquationsInfo();

    while(true){
        std::cout<<"Please Choose Method For Solving"<<std::endl;
        std::cout<<"--------------------------------------------------"<<std::endl;
        std::cout<<"Type \"exit\" to get out the test case."<<std::endl;
        std::cout<<"--------------------------------------------------"<<std::endl;
        std::cout << ">>";
        std::cin>>command;
        if(command=="exit")
        {
            std::cout<<"Exit from this test case"<<std::endl;
            break;
        }
        ChooseMethod(command);
    }
}

void Test_B::ShowEquationsInfo()
{
    std::cout<<"Test B info: "<<std::endl;
    std::cout<<"Dimension: "<<equations.GetDimension()<<std::endl;
    std::cout<<"f(x) = exp(x) - x - 2"<<std::endl;
    std::cout<<"df(x) = exp(x) - 1"<<std::endl;
    std::cout<<"g(x) = exp(x) - 2"<<std::endl;
    std::cout<<"Expected Result: -1.8414, 1.14619"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"In this case, you can choose following methods: "<<std::endl;
    std::cout<<"Aitken Bisection Chord FixedPoint ModifiedNewton1D Newton1D"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
}


Test_B::~Test_B()
{
    //delete all the allocated space
}