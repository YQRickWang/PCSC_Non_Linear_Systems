#include "src/UserInterface.h"

int main() {
<<<<<<< HEAD
    ReadFromFiles();
    RandomTest random_test;
    random_test.RunTest();
    //AnalyzeFunction("5*x^2+exp(3*x)-x-10");
/*Test Case A*/
//Test Case: A
//basic test for 1 dimension
//simple test
//f(x) = x-1
//df(x) = 1
//g(x) = 1
// x=1
//    std::cout<<"Test A"<<std::endl<<std::endl;
//    functions_type* fun_1 = nullptr;
//    functions_type** dfun_1 = nullptr;
//    functions_type fp_1 = nullptr;
//
//    //initialize
//    fun_1 = new functions_type[1];
//    dfun_1 = new functions_type*[1];
//    dfun_1[0] = new functions_type[1];
//
//    fun_1[0] = &Test_A_function_1;
//    dfun_1[0][0] = &Test_A_dfunction_11;
//    fp_1 = &Test_A_fpfunction;
//
//    NonLinearEquation equations_1(fun_1,dfun_1,fp_1,1);
//
//    std::cout<<"Test get function value"<<std::endl;
//    //Test get function value
//    std::cout<<"f(0)="<<equations_1.GetFunctionValue(0.0)<<std::endl;
//    std::cout<<"f(1)="<<equations_1.GetFunctionValue(1.0)<<std::endl;
//    std::cout<<"f(2)="<<equations_1.GetFunctionValue(2.0)<<std::endl;
//    std::cout<<"f(3)="<<equations_1.GetFunctionValue(3.0)<<std::endl;
//    std::cout<<"f(4)="<<equations_1.GetFunctionValue(4.0)<<std::endl;
//
//    //Test fixed point function
//    std::cout<<"Test fixed point value"<<std::endl;
//    std::cout<<"fp(0)="<<equations_1.GetFpFunctionValue(0.0)<<std::endl;
//    std::cout<<"fp(1)="<<equations_1.GetFpFunctionValue(1.0)<<std::endl;
//
//    //Test derivative function
//    std::cout<<"Test derivation function value"<<std::endl;
//    std::cout<<"fp(0)="<<equations_1.GetDfunctionValue(0.0)<<std::endl;
//    std::cout<<"fp(1)="<<equations_1.GetDfunctionValue(1.0)<<std::endl;
//
//    //Test solver
//    std::cout<<"Test solver"<<std::endl;
//    NonLinearSolver solver_1(equations_1);
//    solver_1.Bisection(0,2);
//    solver_1.Chord(0,2);
//    solver_1.FixedPoint();
//    solver_1.Aitken(0.0);
//    solver_1.Newton1D(0.0);
//    solver_1.Newton();
//    solver_1.ModifiedNewton();
//    solver_1.ModifiedNewton1D(0.0,2.0);

//    Test_A test_1;
//    test_1.RunTest();


//    //Print zeropint list and method
//    std::cout<<"Print zero point"<<std::endl;
//    solver_1.ZeroPointPrint();

/*Test Case B*/
//basic test for 1 dimension
//simple test
//f(x) = e^x-x-2
//df(x) = e^x-1
//g(x) = e^x-2
//x1 = -1.8414
//x2 = 1.14619
//    std::cout<<"Test B"<<std::endl<<std::endl;
//    functions_type* fun_2 = nullptr;
//    functions_type** dfun_2 = nullptr;
//    functions_type fp_2 = nullptr;
//
//    //initialize
//    fun_2 = new functions_type[1];
//    dfun_2 = new functions_type*[1];
//    dfun_2[0] = new functions_type[1];
//
//    fun_2[0] = &Test_B_function_1;
//    dfun_2[0][0] = &Test_B_dfunction_11;
//    fp_2 = &Test_B_fpfunction;
//
//    NonLinearEquation equations_2(fun_2,dfun_2,fp_2,1);
//
//    //Test get function value
//    std::cout<<"f(0)="<<equations_2.GetFunctionValue(0.0)<<std::endl;
//    std::cout<<"f(1)="<<equations_2.GetFunctionValue(1.0)<<std::endl;
//    std::cout<<"f(2)="<<equations_2.GetFunctionValue(2.0)<<std::endl;
//    std::cout<<"f(3)="<<equations_2.GetFunctionValue(3.0)<<std::endl;
//    std::cout<<"f(4)="<<equations_2.GetFunctionValue(4.0)<<std::endl;
//    std::cout<<"f(-1.8414)="<<equations_2.GetFunctionValue(-1.8414)<<std::endl;
//    std::cout<<"f(1.14619)="<<equations_2.GetFunctionValue(1.14619)<<std::endl;
//
//    //Test solver
//    std::cout<<"Test solver"<<std::endl;
//    NonLinearSolver solver_2(equations_2);
//    solver_2.Bisection(0,2);
//    solver_2.Chord(0,2);
//    solver_2.Aitken(1.0);
//    solver_2.FixedPoint(1.0);
//    solver_2.Newton1D(1.0);
//    solver_2.Newton();
//    solver_2.ModifiedNewton();
//    solver_2.ModifiedNewton1D(1.0,2.0);
//
//    //Print zeropoint list and method
//    std::cout<<"Print zero point"<<std::endl;
//    solver_2.ZeroPointPrint();

//    double** A=new double*[2];
//    double* x = nullptr;
//    double* b = new double[2];
//    A[0] = new double[2];
//    A[1] = new double[2];
//    A[0][0] = 1;
//    A[0][1] = 1;
//    A[1][0] = 0;
//    A[1][1] = 1;
//    b[0] = 5;
//    b[1] = 4;
//
//    x = solver_2.LinearSolver_Splitting(A,b);
//    std::cout<<x[0]<<std::endl;
//    std::cout<<x[1]<<std::endl;

/*Test Case C*/
//basic test for 2 dimensions
//simple test
//f1(x) = 2*x^2-y+1
//f2(x) = x+2*y-6
//df11(x) = 4*x
//df12(y) = -1
//df21(x) = 1
//df22(y) = 2
//    std::cout<<"Test C"<<std::endl<<std::endl;
//    functions_type* fun_3 = nullptr;
//    functions_type** dfun_3 = nullptr;
//
//    //initialize
//    fun_3 = new functions_type[2];
//    dfun_3 = new functions_type*[2];
//    dfun_3[0] = new functions_type[2];
//    dfun_3[1] = new functions_type[2];
//
//    fun_3[0] = &Test_C_function_1;
//    fun_3[1] = &Test_C_function_2;
//    dfun_3[0][0] = &Test_C_dfunction_11;
//    dfun_3[0][1] = &Test_C_dfunction_12;
//    dfun_3[1][0] = &Test_C_dfunction_21;
//    dfun_3[1][1] = &Test_C_dfunction_22;
//    NonLinearEquation equations_3(fun_3,dfun_3,2);
//
//    //Test solver
//    std::cout<<"Test solver"<<std::endl;
//    NonLinearSolver solver_3(equations_3);
//
//    solver_3.Newton();
//    solver_3.ModifiedNewton(1.0,100);
//    solver_3.ZeroPointPrint();

    //git test
    //git test

=======
    UserInterface();
>>>>>>> branch1
}

