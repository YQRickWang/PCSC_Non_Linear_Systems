//
// Created by Rick Wang on 2019/12/10.
//

#include "ReadFiles.h"
#include "iostream"
#include "fstream"
#include "string"
#include "list"
#include "cmath"
#include "exprtk/exprtk.hpp"

void ReadFromFiles()
{
    std::string prefix="../testfiles/";
    std::string file_name;
    std::string line;
    std::list<std::string> string_list;

    std::cout<<"Read functions from txt files"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"Please type the file name. E.g. test_function.txt"<<std::endl;
    std::cin>>file_name;
    file_name=prefix+file_name;

    //for debug
//    TCHAR Buffer[MAX_PATH];
//    DWORD dwRet;
//    dwRet = GetCurrentDirectory(MAX_PATH, Buffer);
//    std::wcout << Buffer << std::endl;

    std::ifstream myfile (file_name);
    if(myfile.is_open())
    {
        while(std::getline(myfile,line))
        {
            std::cout<<line<<std::endl;
            string_list.push_back(line);
        }
        myfile.close();
    }
    else{
        std::cout<<"Unable to open file, please check again."<<std::endl;
    }



}

void AnalyzeFiles(std::list<std::string> string_list)
{
    //read dimension first

}

void ReadFromInput()
{

}

void AnalyzeFunction(std::string expression_string)
{
//    typedef double T;
//    typedef exprtk::symbol_table<T> symbol_table_t;
//    typedef exprtk::expression<T>     expression_t;
//    typedef exprtk::parser<T>             parser_t;
//
//    T x = T(0);
//    //T y = T(98.98);
//    //T z = T(0.0);
//
//    symbol_table_t symbol_table;
//    symbol_table.add_variable("x",x);
//    //symbol_table.add_variable("y",y);
//    //symbol_table.add_variable("z",z);
//
//    expression_t expression;
//    expression.register_symbol_table(symbol_table);
//
//    parser_t parser;
//
//    if (!parser.compile(expression_string,expression))
//    {
//        std::cout<<"Compilation error"<<std::endl;
//        return;
//    }
//
//    T result = expression.value();
//    std::cout<<result<<std::endl;
}
