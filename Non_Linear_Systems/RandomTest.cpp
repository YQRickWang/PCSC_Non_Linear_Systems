//
// Created by Rick Wang on 2019/12/11.
//

#include "RandomTest.h"

RandomTest::RandomTest()
{
    functions_type* fun_1 = nullptr;
    functions_type** dfun_1 = nullptr;
    functions_type fp_1 = nullptr;

    //initialize
    fun_1 = new functions_type[1];
    dfun_1 = new functions_type*[1];
    dfun_1[0] = new functions_type[1];

    fun_1[0] = &RandomFunction_1;
    dfun_1[0][0] = &RandomDFunction_11;
    fp_1 = &RandomDFunction_fp;

    this->equations.SetDimension(random_dimension);
    this->equations.SetFunArray(fun_1);
    this->equations.SetDFunArray(dfun_1);
    this->equations.SetFpFun(fp_1);
    this->solver.SetEquations(this->equations);
}

RandomTest::~RandomTest()
{
//nothing to do
}

void RandomTest::ShowEquationsInfo()
{
//nothing to do rightnow
}

void RandomTest::RunTest()
{
    std::string command;
    std::cout<<"Random Test is running"<<std::endl;
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
