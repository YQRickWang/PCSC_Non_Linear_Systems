//
// Created by Rick Wang on 2019/12/7.
//

#include "../Test_A.h"

double Test_A_function_1(double *input)
{
    return exp(input[0])-1;
}

double Test_A_dfunction_11(double *input)
{
    return exp(input[0]);
}

double Test_A_fpfunction(double *input)
{
    return log(1.0);
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
    std::string command;
    std::cout<<"Test A is running"<<std::endl;
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

void Test_A::ShowEquationsInfo()
{
    std::cout<<"Test A info: "<<std::endl;
    std::cout<<"Dimension: "<<equations.GetDimension()<<std::endl;
    std::cout<<"f(x) = exp(x) - 1"<<std::endl;
    std::cout<<"df(x) = exp(x)"<<std::endl;
    std::cout<<"g(x) = log(1)"<<std::endl;
    std::cout<<"Expected Result: 0.0"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"In this case, you can choose following methods: "<<std::endl;
    std::cout<<"Aitken Bisection Chord FixedPoint ModifiedNewton1D Newton1D"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
}


Test_A::~Test_A()
{
    //delete all the allocated space
}



