//
// Created by Rick Wang on 2019/12/9.
//

#include "UserInterface.h"
#include "iostream"
#include "string"
#include "ReadFiles.h"
#include "../test/RandomTest.h"

void UserInterface()
{
    std::string command;
    std::cout<<"PCSC Non Linear System Solver"<<std::endl;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    WelcomeInfo();
    std::cin>>command;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    while(true)
    {
        if(command=="1")
        {
            TestCaseInterface();
        }
        else if(command=="2")
        {
            KeyboardInterface();
        }
        else if(command=="3")
        {
            TestFileInterface();
        }
        else if(command=="exit"||command=="4")
        {
            std::cout<<"PCSC Non Linear System Solver exit."<<std::endl;
            std::cout<<"------------------------------------------------------------------------"<<std::endl;
            break;
        }
        else{
            std::cout<<"Invalid Command, Please check again."<<std::endl;
            std::cout<<"------------------------------------------------------------------------"<<std::endl;
        }
        WelcomeInfo();
        std::cin>>command;
    }
}

void WelcomeInfo()
{
    std::cout<<"There are several modes you can choose."<<std::endl;
    std::cout<<"1-"<<"Test from existing test cases."<<std::endl;
    std::cout<<"2-"<<"Test from keyboard."<<std::endl;
    std::cout<<"3-"<<"Test from txt files."<<std::endl;
    std::cout<<"4-"<<"Exit"<<std::endl;
    std::cout<<R"(Please type in the mode you want to choose or type "4" or "exit" to exit)"<<std::endl;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    std::cout<<">>";
}

void TestCaseInterface()
{
    std::string command;
    std::cout<<"Test from existing test cases."<<std::endl;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    TestCaseWelcomeInfo();
    std::cin>>command;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    while(true)
    {
        if(command=="1")
        {

        }
        else if(command=="2")
        {

        }
        else if(command=="exit"||command=="3")
        {
            std::cout<<"Test from existing test cases exit."<<std::endl;
            std::cout<<"------------------------------------------------------------------------"<<std::endl;
            break;
        }
        else{
            std::cout<<"Invalid Command, Please check again."<<std::endl;
            std::cout<<"------------------------------------------------------------------------"<<std::endl;
        }
        TestCaseWelcomeInfo();
        std::cin>>command;
    }
}

void TestCaseWelcomeInfo()
{
    std::cout<<"There are several modes you can choose."<<std::endl;
    std::cout<<"1-"<<"Show all the test cases info."<<std::endl;
    std::cout<<"2-"<<"Choose a specific test case."<<std::endl;
    std::cout<<"3-"<<"Exit."<<std::endl;
    std::cout<<R"(Please type in the mode you want to choose or type "3" or "exit" to exit)"<<std::endl;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    std::cout<<">>";
}

void KeyboardInterface()
{
    std::string command;
    std::cout<<"Test from keyboard input."<<std::endl;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    ReadFromInput();
    RandomTest test;
    std::cout<<fun_1_expression<<std::endl;
    std::cout<<dfun_11_expression<<std::endl;
    std::cout<<fun_fp_expression<<std::endl;
    test.RunTest();
}



void TestFileInterface()
{
    std::string command;
    std::cout<<"Test from txt files."<<std::endl;
    std::cout<<R"(Test files should be stored in the "textfiles" directory.)"<<std::endl;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    ReadFromFiles();
    RandomTest test;
    std::cout<<fun_1_expression<<std::endl;
    std::cout<<dfun_11_expression<<std::endl;
    std::cout<<fun_fp_expression<<std::endl;
    test.RunTest();
}
