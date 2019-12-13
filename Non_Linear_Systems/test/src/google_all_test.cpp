//
// Created by Rick Wang on 2019/12/13.
//

#include "../google_all_test.h"
#include "../Test_A.h"
#include "../Test_B.h"
#include "../Test_C.h"
#include "../Test_D.hpp"
#include "../../nonlinear/ReadFiles.h"
#include "../RandomTest.h"

#include "iostream"

void TestAll(){
    //Test Existing Test Cases
    std::cout<<"Google Test: Test Existing Test Cases"<<std::endl;
    std::cout<<"There are four test cases in this part: A, B, C, D"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    double max_error = 1e-3;

    //Test_A
    Test_A test1;
    test1.ShowEquationsInfo();
    test1.solver.Newton1D(1.0);
    test1.solver.ModifiedNewton1D(1,1.5);
    test1.solver.Bisection(-1,1);
    test1.solver.Chord(-1,1);
    test1.solver.FixedPoint(-1);
    test1.solver.ZeroPointPrint();
    auto testmap1 = test1.solver.GetZeroPoint();
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;

    //google test check
    std::cout<<"Test A: Google Test Check, if nothing shows, then it's right."<<std::endl;
    ASSERT_NEAR(testmap1["Bisection"].front(),0.0,max_error);
    ASSERT_NEAR(testmap1["Chord"].front(),0.0,max_error);
    ASSERT_NEAR(testmap1["FixedPoint"].front(),0.0,max_error);
    ASSERT_NEAR(testmap1["Newton1D"].front(),0.0,max_error);
    ASSERT_NEAR(testmap1["ModifiedNewton1D"].front(),0.0,max_error);
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;

    //Test_B
    Test_B test2;
    test2.ShowEquationsInfo();
    test2.solver.Newton1D(1.0);
    test2.solver.ModifiedNewton1D(1.0,1.5);
    test2.solver.Bisection(-2,0);
    test2.solver.Chord(-2,0);
    test2.solver.Aitken(-3.0);
    test2.solver.FixedPoint(0.5);
    test2.solver.ZeroPointPrint();
    auto testmap2 = test2.solver.GetZeroPoint();
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;

    //google test check
    std::cout<<"Test B: Google Test Check, if nothing shows, then it's right."<<std::endl;
    ASSERT_NEAR(testmap2["Aitken"].front(),-1.841408,max_error);
    ASSERT_NEAR(testmap2["Bisection"].front(),-1.841408,max_error);
    ASSERT_NEAR(testmap2["Chord"].front(),-1.841408,max_error);
    ASSERT_NEAR(testmap2["FixedPoint"].front(),-1.841408,max_error);
    ASSERT_NEAR(testmap2["Newton1D"].front(),1.146193,max_error);
    ASSERT_NEAR(testmap2["ModifiedNewton1D"].front(),1.146193,max_error);
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;

    //Test_C
    Test_C test3;
    test3.ShowEquationsInfo();
    double* guess_3 = new double[2];
    guess_3[0] = 1.0;
    guess_3[1] = 1.0;
    test3.solver.Newton(guess_3);
    test3.solver.ZeroPointPrint();
    auto testmap3 = test3.solver.GetZeroPoint();
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;
    delete []guess_3;
    std::cout<<"Test C: Google Test Check, if nothing shows, then it's right."<<std::endl;
    ASSERT_NEAR(testmap3["Newton"].front(),0.882782,max_error);
    ASSERT_NEAR(testmap3["Newton"].back(),2.558609,max_error);
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;


    //Test_D
    Test_D test4;
    test4.ShowEquationsInfo();
    double* guess_4 = new double[2];
    guess_4[0] = 1.0;
    guess_4[1] = 1.0;
    test4.solver.Newton(guess_4);
    test4.solver.ZeroPointPrint();
    auto testmap4 = test4.solver.GetZeroPoint();
    std::cout<<"--------------------------------------------------"<<std::endl;
    ASSERT_NEAR(testmap4["Newton"].front(),1.0,max_error);
    ASSERT_NEAR(testmap4["Newton"].back(),0.0,max_error);
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;
    delete []guess_4;

    std::cout<<"Google Test: Test From Txt Files"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;

    //Test Txt Files
    //test1
    std::string file_name = "test1.txt";
    std::cout<<"Test file 1"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    ReadFromFiles(file_name);
    RandomTest random_1;
    std::cout<<"Expected Results: x=-1.31263 or 0.938533"<<std::endl;

    random_1.solver.Newton1D(1.0);
    random_1.solver.Aitken(1.0);
    random_1.solver.Bisection(0,1);
    random_1.solver.Chord(0,1);
    random_1.solver.ModifiedNewton1D(1.0,1.5);
    random_1.solver.ZeroPointPrint();
    auto r1map = random_1.solver.GetZeroPoint();
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"Test file 1: Google Test Check, if nothing shows, then it's right."<<std::endl;
    ASSERT_NEAR(r1map["Newton1D"].front(),0.938533,max_error);
    ASSERT_NEAR(r1map["Aitken"].front(),0.938533,max_error);
    ASSERT_NEAR(r1map["Bisection"].front(),0.938533,max_error);
    ASSERT_NEAR(r1map["Chord"].front(),0.938533,max_error);
    ASSERT_NEAR(r1map["ModifiedNewton1D"].front(),0.938533,max_error);
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;

    //test2
    file_name = "test2.txt";
    ReadFromFiles(file_name);
    RandomTest random_2;
    std::cout<<"Expected Results: x=-1.31263 or 0.938533"<<std::endl;

    random_2.solver.Newton1D(1.0);
    random_2.solver.Aitken(1.0);
    random_2.solver.Bisection(0,2);
    random_2.solver.Chord(0,2);
    random_2.solver.ModifiedNewton1D(1.0,1.5);
    random_2.solver.ZeroPointPrint();
    auto r2map = random_2.solver.GetZeroPoint();
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"Test file 2: Google Test Check, if nothing shows, then it's right."<<std::endl;
    ASSERT_NEAR(r2map["Newton1D"].front(),1.8556,max_error);
    ASSERT_NEAR(r2map["Bisection"].front(),1.8556,max_error);
    ASSERT_NEAR(r2map["Chord"].front(),1.8556,max_error);
    ASSERT_NEAR(r2map["ModifiedNewton1D"].front(),1.8556,max_error);
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;

    //test3
    file_name = "test3.txt";
    ReadFromFiles(file_name);
    RandomTest random_3;
    std::cout<<"Expected Results: x=0.567143"<<std::endl;

    random_3.solver.Newton1D(1.0);
    random_3.solver.Aitken(1.0);
    random_3.solver.Bisection(0,2);
    random_3.solver.Chord(0,2);
    random_3.solver.FixedPoint(1.0);
    random_3.solver.ModifiedNewton1D(1.0,1.5);
    random_3.solver.ZeroPointPrint();
    auto r3map = random_3.solver.GetZeroPoint();
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"Test file 3: Google Test Check, if nothing shows, then it's right."<<std::endl;
    ASSERT_NEAR(r3map["Aitken"].front(),0.567143,max_error);
    ASSERT_NEAR(r3map["FixedPoint"].front(),0.567143,max_error);
    ASSERT_NEAR(r3map["Newton1D"].front(),0.567143,max_error);
    ASSERT_NEAR(r3map["Bisection"].front(),0.567143,max_error);
    ASSERT_NEAR(r3map["Chord"].front(),0.567143,max_error);
    ASSERT_NEAR(r3map["ModifiedNewton1D"].front(),0.567143,max_error);
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;

    //test4
    file_name = "test4.txt";
    ReadFromFiles(file_name);
    RandomTest random_4;
    std::cout<<"Expected Results: x1 = -4.55901 and x2 = -0.579159"<<std::endl;

    random_4.solver.Newton1D(-1.0);
    random_4.solver.Aitken(-1.0);
    random_4.solver.Bisection(-1,1);
    random_4.solver.Chord(-1,1);
    random_4.solver.FixedPoint(-1.0);
    random_4.solver.ModifiedNewton1D(-1.0,1.5);
    random_4.solver.ZeroPointPrint();
    auto r4map = random_4.solver.GetZeroPoint();
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"Test file 4: Google Test Check, if nothing shows, then it's right."<<std::endl;
    ASSERT_NEAR(r4map["Aitken"].front(),-0.579159,max_error);
    ASSERT_NEAR(r4map["FixedPoint"].front(),-0.579159,max_error);
    ASSERT_NEAR(r4map["Newton1D"].front(),-0.579159,max_error);
    ASSERT_NEAR(r4map["Bisection"].front(),-0.579159,max_error);
    ASSERT_NEAR(r4map["Chord"].front(),-0.579159,max_error);
    ASSERT_NEAR(r4map["ModifiedNewton1D"].front(),-0.579159,max_error);
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;


    //test5
    file_name = "test5.txt";
    ReadFromFiles(file_name);
    RandomTest random_5;
    std::cout<<"Expected Results:  x = 0.0 and y = 0.0"<<std::endl;

    double* r5guess = new double[2];
    r5guess[0]=0.5;
    r5guess[1]=0.6;
    random_5.solver.Newton(r5guess);
    delete []r5guess;
    random_5.solver.ZeroPointPrint();
    auto r5map = random_5.solver.GetZeroPoint();
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"Test file 5: Google Test Check, if nothing shows, then it's right."<<std::endl;
    ASSERT_NEAR(r5map["Newton"].front(),0.0,max_error);
    ASSERT_NEAR(r5map["Newton"].back(),0.0,max_error);
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;


    //test6
    file_name = "test6.txt";
    ReadFromFiles(file_name);
    RandomTest random_6;

    std::cout<<"Expected Results:  sol1: x = 1.9631, y = 2, z = 1.4272; sol2: x = -2.4668, y = 2, z = 2.5430  "<<std::endl;

    double* r6guess = new double[3];
    r6guess[0]=-1.0;
    r6guess[1]=2.0;
    r6guess[2]=2.0;
    random_6.solver.Newton(r6guess);
    delete []r6guess;
    random_6.solver.ZeroPointPrint();
    auto r6map = random_6.solver.GetZeroPoint();
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"Test file 3: Google Test Check, if nothing shows, then it's right."<<std::endl;
    auto it_6 = r6map["Newton"].begin();
    ASSERT_NEAR(*(it_6++),-2.4668,max_error);
    ASSERT_NEAR(*(it_6++),2,max_error);
    ASSERT_NEAR(*(it_6++),2.5430,max_error);
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;
}