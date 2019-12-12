//
// Created by Rick Wang on 2019/12/10.
//

#include "ReadFiles.h"
#include "iostream"
#include "fstream"
#include "string"
#include "list"
#include "cmath"
#include "../exprtk/exprtk.hpp"
#include "../test/RandomFunctions.h"

void ReadFromFiles()
{
    std::string prefix="../txt_testfiles/";
    std::string file_name;
    std::string line;
    std::list<std::string> string_list;

    std::cout<<"Read functions from txt files"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"Please type the file name. E.g. test_function.txt"<<std::endl;
    std::cin>>file_name;
    file_name=prefix+file_name;

    std::ifstream myfile (file_name);
    if(myfile.is_open())
    {
        while(std::getline(myfile,line))
        {
            string_list.push_back(line);
        }
        myfile.close();
        AnalyzeFiles(string_list);
    }
    else{
        std::cout<<"Unable to open file, please check again."<<std::endl;
    }
}

void ReadFromInput()
{
    std::string line;
    std::list<std::string> string_list;
    int dim=0;

    std::cout<<"Read functions from keyboard"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"Please type in the dimension (Now we only support dimension less than (or equal to) 4)"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"Dimension: ";
    std::cin>>dim;
    while(dim<=0||dim>4)
    {
        std::cout<<"Invalid dimension, please check and retype"<<std::endl;
        std::cout<<"Dimension: ";
        std::cin>>dim;
    }
    random_dimension = dim;

    //Read Functions
    for(int i=1;i<=dim;i++)
    {
        std::cout<<"Please type in number "<<i<<" function"<<std::endl;
        std::cout<<"Note: We will not check functions right now, we will check it later, please make it correct."<<std::endl;
        std::string str_func;
        std::cin>>str_func;
        if(i==1)
        {
            fun_1_expression = str_func;
        }
        else if(i==2)
        {
            fun_2_expression = str_func;
        }
        else if(i==3)
        {
            fun_3_expression = str_func;
        }
        else if(i==4)
        {
            fun_4_expression = str_func;
        }
        else{
            std::cout<<"Error"<<std::endl;
        }
    }

    //Read Dfunctions
    for(int i=1;i<=dim;i++)
    {
        for(int j=1;j<=dim;j++)
        {
            std::cout<<"Please type in number "<<i<<j<<" Dfunction"<<std::endl;
            std::cout<<"Note: We will not check functions right now, we will check it later, please make it correct."<<std::endl;
            std::string str_dfunc;
            std::cin>>str_dfunc;
            if(i==1)
            {
                if(j==1)
                    dfun_11_expression = str_dfunc;
                else if(j==2)
                    dfun_12_expression = str_dfunc;
                else if(j==3)
                    dfun_13_expression = str_dfunc;
                else if(j==4)
                    dfun_14_expression = str_dfunc;
                else
                    std::cout<<"Error"<<std::endl;
            }
            else if(i==2)
            {
                if(j==1)
                    dfun_21_expression = str_dfunc;
                else if(j==2)
                    dfun_22_expression = str_dfunc;
                else if(j==3)
                    dfun_23_expression = str_dfunc;
                else if(j==4)
                    dfun_24_expression = str_dfunc;
                else
                    std::cout<<"Error"<<std::endl;
            }
            else if(i==3)
            {
                if(j==1)
                    dfun_31_expression = str_dfunc;
                else if(j==2)
                    dfun_32_expression = str_dfunc;
                else if(j==3)
                    dfun_33_expression = str_dfunc;
                else if(j==4)
                    dfun_34_expression = str_dfunc;
                else
                    std::cout<<"Error"<<std::endl;
            }
            else if(i==4)
            {
                if(j==1)
                    dfun_41_expression = str_dfunc;
                else if(j==2)
                    dfun_42_expression = str_dfunc;
                else if(j==3)
                    dfun_43_expression = str_dfunc;
                else if(j==4)
                    dfun_44_expression = str_dfunc;
                else
                    std::cout<<"Error"<<std::endl;
            } else{
                std::cout<<"Error"<<std::endl;
            }
        }
    }

    //Read fixedpoint function (if it exits)
    if(dim==1)
    {
        std::cout<<"Please type in fixed point function "<<std::endl;
        std::cout<<"Note: We will not check functions right now, we will check it later, please make it correct."<<std::endl;
        std::string str_fp;
        std::cin>>str_fp;
        fun_fp_expression = str_fp;
    }
}

void AnalyzeFiles(std::list<std::string> string_list)
{
    //read dimension first
    //the first line is the dimension of the functions
    auto it = string_list.begin();
    int dim = std::stoi(*it);
    int count = 1;
    random_dimension = dim;
    it++;//goes to second line

    if(dim==1)
    {
        for(;it!=string_list.end();it++)
        {
            if(count==1)
                fun_1_expression = *it;
            else if(count==2)
                dfun_11_expression = *it;
            else if(count==3)
                fun_fp_expression = *it;
            else{
                std::cout<<"Count Error"<<std::endl;
            }
            count++;
        }
    }
    else if(dim>1)
    {
        //read functions
        if(dim==2)
        {
            fun_1_expression = *(it++);
            fun_2_expression = *(it++);
            dfun_11_expression = *(it++);
            dfun_12_expression = *(it++);
            dfun_21_expression = *(it++);
            dfun_22_expression = *(it++);
        }
        else if(dim==3)
        {
            fun_1_expression = *(it++);
            fun_2_expression = *(it++);
            fun_3_expression = *(it++);
            dfun_11_expression = *(it++);
            dfun_12_expression = *(it++);
            dfun_13_expression = *(it++);
            dfun_21_expression = *(it++);
            dfun_22_expression = *(it++);
            dfun_23_expression = *(it++);
            dfun_31_expression = *(it++);
            dfun_32_expression = *(it++);
            dfun_33_expression = *(it++);
        }
        else if(dim==4)
        {
            fun_1_expression = *(it++);
            fun_2_expression = *(it++);
            fun_3_expression = *(it++);
            fun_4_expression = *(it++);
            dfun_11_expression = *(it++);
            dfun_12_expression = *(it++);
            dfun_13_expression = *(it++);
            dfun_14_expression = *(it++);
            dfun_21_expression = *(it++);
            dfun_22_expression = *(it++);
            dfun_23_expression = *(it++);
            dfun_24_expression = *(it++);
            dfun_31_expression = *(it++);
            dfun_32_expression = *(it++);
            dfun_33_expression = *(it++);
            dfun_34_expression = *(it++);
            dfun_41_expression = *(it++);
            dfun_42_expression = *(it++);
            dfun_43_expression = *(it++);
            dfun_44_expression = *(it++);
        }
        else
        {
            std::cout<<"Higher Dimension is not supported"<<std::endl;
        }
    } else{
        std::cout<<"Dimension error, please check dimension"<<std::endl;
    }
}

