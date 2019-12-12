//
// Created by Rick Wang on 2019/12/11.
//

#include "RandomTest.h"

RandomTest::RandomTest()
{
    functions_type* fun = nullptr;
    functions_type** dfun = nullptr;
    functions_type fp = nullptr;
    int dim = random_dimension;

    //initialize
    fun = new functions_type[dim];
    dfun = new functions_type*[dim];
    for(int i=0;i<dim;i++)
    {
        dfun[i] = new functions_type[dim];
    }

    //functions and dfunctions
    if(dim>=1)
    {
        if(dim==1)
        {
            fun[0] = &RandomFunction_1;
            dfun[0][0] =&RandomDFunction_11;
        }
        else if(dim==2)
        {
            fun[0] = &RandomFunction_1;
            fun[1] = &RandomFunction_2;
            dfun[0][0]=&RandomDFunction_11;
            dfun[0][1]=&RandomDFunction_12;
            dfun[1][0]=&RandomDFunction_21;
            dfun[1][1]=&RandomDFunction_22;
        }
        else if(dim==3)
        {
            fun[0] = &RandomFunction_1;
            fun[1] = &RandomFunction_2;
            fun[2] = &RandomFunction_3;
            dfun[0][0]=&RandomDFunction_11;
            dfun[0][1]=&RandomDFunction_12;
            dfun[0][2]=&RandomDFunction_13;
            dfun[1][0]=&RandomDFunction_21;
            dfun[1][1]=&RandomDFunction_22;
            dfun[1][2]=&RandomDFunction_23;
            dfun[2][0]=&RandomDFunction_31;
            dfun[2][1]=&RandomDFunction_32;
            dfun[2][2]=&RandomDFunction_33;
        }
        else if(dim==4)
        {
            fun[0] = &RandomFunction_1;
            fun[1] = &RandomFunction_2;
            fun[2] = &RandomFunction_3;
            fun[3] = &RandomFunction_4;
            dfun[0][0]=&RandomDFunction_11;
            dfun[0][1]=&RandomDFunction_12;
            dfun[0][2]=&RandomDFunction_13;
            dfun[0][3]=&RandomDFunction_14;
            dfun[1][0]=&RandomDFunction_21;
            dfun[1][1]=&RandomDFunction_22;
            dfun[1][2]=&RandomDFunction_23;
            dfun[1][3]=&RandomDFunction_24;
            dfun[2][0]=&RandomDFunction_31;
            dfun[2][1]=&RandomDFunction_32;
            dfun[2][2]=&RandomDFunction_33;
            dfun[2][3]=&RandomDFunction_34;
            dfun[3][0]=&RandomDFunction_41;
            dfun[3][1]=&RandomDFunction_42;
            dfun[3][2]=&RandomDFunction_43;
            dfun[3][3]=&RandomDFunction_44;
        }
        else{
            std::cout<<"Higher dimension is not supported"<<std::endl;
        }
    }
    else{
        std::cout<<"Dimension Error: The dimension should be at least 1."<<std::endl;
    }

    //fixed point function
    if(dim==1)
        fp = &RandomFunction_fp;
    else
        fp = nullptr;
    this->equations.SetDimension(dim);
    this->equations.SetFunArray(fun);
    this->equations.SetDFunArray(dfun);
    this->equations.SetFpFun(fp);
    this->solver.SetEquations(this->equations);
}

RandomTest::~RandomTest()
{
//nothing to do
}

void RandomTest::ShowEquationsInfo()
{
    int dim=equations.GetDimension();
    std::cout<<"Random Test info: "<<std::endl;
    std::cout<<"Dimension: "<<dim<<std::endl;
    std::cout<<"The nonlinear system of equations is: "<<std::endl;
    if(dim==1)
    {
        std::cout<<"f(x)="<<fun_1_expression<<std::endl;
        std::cout<<"df(x)="<<dfun_11_expression<<std::endl;
        std::cout<<"g(x)="<<fun_fp_expression<<std::endl;
        std::cout<<"--------------------------------------------------"<<std::endl;
        std::cout<<"In this case, you can choose following methods: "<<std::endl;
        std::cout<<"Aitken Bisection Chord FixedPoint ModifiedNewton1D Newton1D"<<std::endl;
        std::cout<<"--------------------------------------------------"<<std::endl;
    }
    else if(dim==2)
    {
        std::cout<<"f1(x)="<<fun_1_expression<<std::endl;
        std::cout<<"f2(x)="<<fun_2_expression<<std::endl;
        std::cout<<"--------------------------------------------------"<<std::endl;
        std::cout<<"In this case, you can choose following methods: "<<std::endl;
        std::cout<<"ModifiedNewton Newton"<<std::endl;
        std::cout<<"--------------------------------------------------"<<std::endl;
    }
    else if(dim==3)
    {
        std::cout<<"f1(x)="<<fun_1_expression<<std::endl;
        std::cout<<"f2(x)="<<fun_2_expression<<std::endl;
        std::cout<<"f3(x)="<<fun_3_expression<<std::endl;
        std::cout<<"--------------------------------------------------"<<std::endl;
        std::cout<<"In this case, you can choose following methods: "<<std::endl;
        std::cout<<"ModifiedNewton Newton"<<std::endl;
        std::cout<<"--------------------------------------------------"<<std::endl;
    }
    else if(dim==4)
    {
        std::cout<<"f1(x)="<<fun_1_expression<<std::endl;
        std::cout<<"f2(x)="<<fun_2_expression<<std::endl;
        std::cout<<"f3(x)="<<fun_3_expression<<std::endl;
        std::cout<<"f4(x)="<<fun_4_expression<<std::endl;
        std::cout<<"--------------------------------------------------"<<std::endl;
        std::cout<<"In this case, you can choose following methods: "<<std::endl;
        std::cout<<"ModifiedNewton Newton"<<std::endl;
        std::cout<<"--------------------------------------------------"<<std::endl;
    }
    else{
        std::cout<<"Dimension Error"<<std::endl;
    }
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
