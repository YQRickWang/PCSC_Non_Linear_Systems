//
// Created by Rick Wang on 2019/12/9.
//

#include "../Test_C.h"
#include "cmath"

double Test_C_function_1(double* input)
{
    return 2*pow(input[0],2)-input[1]+1;
}

double Test_C_function_2(double* input)
{
    return input[0]+2*input[1]-6;
}

double Test_C_dfunction_11(double* input)
{
    return 4*input[0];
}

double Test_C_dfunction_12(double* input)
{
    return -1;
}

double Test_C_dfunction_21(double* input)
{
    return 1;
}

double Test_C_dfunction_22(double* input)
{
    return 2;
}

Test_C::Test_C()
{
    functions_type* fun_1 = nullptr;
    functions_type** dfun_1 = nullptr;
    functions_type fp_1 = nullptr;

    //initialize
    fun_1 = new functions_type[2];
    dfun_1 = new functions_type*[2];
    dfun_1[0] = new functions_type[2];
    dfun_1[1] = new functions_type[2];

    fun_1[0] = &Test_C_function_1;
    fun_1[1] = &Test_C_function_2;
    dfun_1[0][0] = &Test_C_dfunction_11;
    dfun_1[0][1] = &Test_C_dfunction_12;
    dfun_1[1][0] = &Test_C_dfunction_21;
    dfun_1[1][1] = &Test_C_dfunction_22;


    this->equations.SetDimension(2);
    this->equations.SetFunArray(fun_1);
    this->equations.SetDFunArray(dfun_1);
    this->equations.SetFpFun(fp_1);
    this->solver.SetEquations(this->equations);
}

void Test_C::RunTest()
{
    std::string command;
    std::cout<<"Test C is running"<<std::endl;
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

void Test_C::ShowEquationsInfo()
{
    std::cout<<"Test C info: "<<std::endl;
    std::cout<<"Dimension: "<<equations.GetDimension()<<std::endl;
    std::cout<<"The nonlinear system of equations is: "<<std::endl;
    std::cout<<"2 * x ^ 2 - y + 1 = 0"<<std::endl;
    std::cout<<"    x + 2 * y - 6 = 0"<<std::endl;
    std::cout<<"Expected Result: x = , y = "<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"In this case, you can choose following methods: "<<std::endl;
    std::cout<<"ModifiedNewton Newton"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
}


Test_C::~Test_C()
{
    //delete all the allocated space
}
