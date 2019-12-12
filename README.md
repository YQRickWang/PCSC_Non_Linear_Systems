# PCSC NonLinear Systems Solver

**Author: Yuqi Wang, Haojun Zhu**

**Contact: yuqi.wang@epfl.ch, haojun.zhu@epfl.ch**

**Note: This read me document is only for github, the readme for project is under "Non-Linear-Systems" Folder**

### 1. Overview
This project is a course project of **Programming Concepts In Scientific Computing (MATH-458)** in EPFL. The aim of the project is to solve non linear systems by using numerical methods including bisection, fixed point (aitken acceleration as well), chord, newton and modified newton method.

Now, the tool can support solving nonlinear equation with **only 1 variable** by following methods.

- Bisection
- Fixed Point
- Aitken (an acceleration method on Fixed Point)
- Chord
- Newton
- Modified Newton

The tool also supports solving nonlinear systems with **equal or less than 4 variables** by following methods.

- Newton
- Modified Newton

### 2. How to Compile

### 3. How to Use And EXAMPLES

When the compling, linking and generating is done. The program is executive. In the executive program, user can choose three different ways to test. Each of them have input standard. **Please follow the standard.**

- 1. Test from existing test cases.
- 2. Test from keyborad input.
- 3. Test from reading txt files.

#### A. Test from existing test cases

In the project, there are already some pre-defined test cases. Functions are defined in these test cases. For example, if we wants to **test "Test-B" with "Newton1D"** and exit finally. Type following command. Instructions are made in the programs, and they are easy to follow. The gif also shows the process.
	
	//Test from existing test cases: Example 1
	//Command to type in
	>>1
	>>2
	>>B
	>>Newton1D
	>>1.0
	//to exit
	>>exit
	>>exit
	>>exit
	>>exit

![Test from existing test cases process](https://i.imgur.com/EulPPrI.gif)


#### B. Test from keyboard input

The tool also supports reading input from keyboard. User can type in any test cases into the program. For 1d, the variable name should be "x". For 2d, variable should be "x" and "y". For 3d, variables should be "x", "y" and "z". For 4d, variables should be "x", "y", "z" and "w". Higher dimension is not supported yet. The order of input should follow in order of dimension, functions, derivative functions (derivative for all variables in function 1 then function 2 ...) and fixed point function (only for 1d). Following are two examples. Gifs also show the process.

	//Test from keyboard input: Example 1
	//Command to type in
	//Expected results:
	//choose mode 
	>>2
	//input information about a nonlinear equation
	>>1
	>>exp(x)-x-4
	//Test
	>>Bisection
	>>0 2
	>>Chord
	>>0 2
	>>Aitken
	>>0
	>>FixedPoint
	>>0
	>>Newton1D
	>>1.0
	>>ModfiedNewton
	>>1.0
	>>2.0
	//to exit
	>>exit
	>>exit

//remember to insert gif

	//Tes from keyboard input: Example 2
	//Expected results: (1.28868 4.28868) or (-1.5071 1.4929)
	//Command to type in
	//choose mode
	>>2
	//Input information about nonlinear systems
	>>2
	>>x^2-y+exp(x)-1
	>>x-y+3
	>>2*x+exp(x)
	>>-1
	>>1
	>>-1
	//Test
	>>Newton
	>>1.0 1.0
	>>ModfiedNewton
	>>-1 -1
	>>1
	
//remember to insert gif

#### C. Test from reading txt files

Our tool can also test from existing txt files. The content in the file should following the standard. No extra lines are allowed in txt files. And all the files shoulde be in the directory "txt_testfiles". The order of lines should follow in order of dimension, functions, derivative functions (derivative for all variables in function 1 then function 2 ...) and fixed point function (only for 1d). Following are two examples of test from txt files. 

Txt file Content:

	1
	5*x^2+exp(2*x)-x-10
	10*x+2*exp(2*x)-1
	5*x^2+exp(2*x)-10

Command type in

Txt file Content:

	2
	x^2-y+exp(x)-1
	x-y+3
	2*x+exp(x)
	-1
	1
	-1

Command type in

### 4. List of Features

#### A. Interactive user experience

We provide a basic user interface to load existing test cases, read random equations from keyboard as well as read from txt files. This interactive interface helps user to switch between different approches.

#### B. Multiple input approches 

As mentioned in previous part, the tool provides three input ways. The first is to load pre-defined test cases which are already defined in the program. The second is to read equations from keyboard. User can type any appropriate equation or system of equations (less than or equal to 4 variables). The program will prase these input automatically and give proper results. The third one is reading from txt files. The input flow is same as the second approach. But these equations are already defined in txt files.

#### C. Applicable for both single equation and system of equations

Our program is suitable for solving nonlinear equation with one variable by aitken, newton, bisection and etc. What's more, solving system of equations by newton and modified newton method is also supported.

### 5. List of Tests

#### A. Test from existing test cases

We have four existing test cases (A, B, C, D), they are already defined in the project. User can follow instructions to load and test these test cases.

#### B. Test from keyboard input

Same as the examples. Please check previous keyboard input examples.

#### C. Test from txt files

There are 10 text files in the "txt_testfiles" folder. 

- test1, test2, test3, test4, test5 are test cases with 1 variable
- test6, test7, test8 are test cases with 2 variables
- test9 is a test case with 1 variable
- test10 is a test case with 1 variable

### 6. Project Structure

The project includes two important parts. The first part is the implementation of two basic classes: **NonLinearEquation** and **NonLinearSolver**. The second part is a family of test classes which includes the base test class ( **TestBase** ) and other dervied classes ( e.g. **Test-A** ,**Test-B** ). Also, the user defined test calss ( **RandomTest** ) is also derived from base class. The following graph shows the whole structure.

- Implementation
	- NonLinearEquation
	- NonLinearSolver
- Test
	- TestBase
	- Test-A
	- Test-B
	- ...
	- RandomTest

#### A. NonLinearEquation

NonLinearEquation is the class to serve as a container to store a nonlinear equation/nonliear systems. **NonLinearEquation has four members**.

- dim: the dimension of the equation
- funPtrArray: the pointer points to the **1d array** of function pointers.
- dfunPtrArray: the pointer points to the **2d array** of derivative function pointes.
- fpPtr: the pointer points to the fixed point function pointer (e.g. the g(x) in x=g(x), only exists in the case of 1 dimension).

NonLinearEquation has **four constructors and one deafault constructor**.

	//deafult constructor
	NonLinearEquation();
	//take all four arguments as inputs
    NonLinearEquation(functions_type* funArray,functions_type** dfunArray,functions_type fixedPoint, int dimension);
	//take only three arguments except fp (for higher dimension)
    NonLinearEquation(functions_type* funArray,functions_type** dfunArray,int dimension);
	//copy constructor
    NonLinearEquation(NonLinearEquation& copy);
    
NonLinearEquation has **Get member methods and Set member methods**. This provides a way to get and set members in NonLinearEquation.
	
	//Get methods
    int GetDimension();
    functions_type* GetFunArray();
    functions_type** GetDfunArray();
    functions_type GetFpFun();

    //Set methods
    void SetDimension(int dimension);
    void SetFunArray(functions_type* funarray);
    void SetDFunArray(functions_type** dfunarray);
    void SetFpFun(functions_type fp);

The **most import methods** in NonLinearEquation are **getting values of functions and derivate functions**. These methods provides a way to access the value of functions.

    //Get value of functions
    double* GetFunctionValue(double* input);
    double GetFunctionValue(double input);//overload for dimension 1
    double** GetDfunctionValue(double* input);
    double GetDfunctionValue(double input);//overload for dimesion 1
    double GetFpFunctionValue(double input);



#### B. NonLinearSolver
NonLinearSolver is a class to solve the nonlinear equations. There are several methods inside the solver. The class contains two private memebers.

	//contain the whole nonlinear system
    NonLinearEquation equations;
	//a map stores all the zeros and related methods
    std::map<std::string,std::list<double>> zeroPoint;

NonLinearSolver has three constructors and one default destructor. They are easy to understand.

    //Constructor
    NonLinearSolver();
    NonLinearSolver(NonLinearEquation input_equations);
    NonLinearSolver(NonLinearSolver& copy);
    //Destructor
    ~NonLinearSolver();

NonLinearSolver also has get and set member functions. They provides a way to access and set values in the class.

    //get member function
    const NonLinearEquation GetEquations();
    const std::map<std::string,std::list<double>> GetZeroPoint();
    //Set member function
    void SetEquations(NonLinearEquation input_equations);

NonLinearSolver has **6 numerical methods to solver 1d nonlinear equation** and **2 methods to solve nonlinear systems**. We also provides **2 methods to solve linear systems**. The methods to solve linear systems is used in solving nonlinear systems. 

Following useful links provide algorithms in these methods. These algorithms are standard algorithms. We will not provide any explanation of these algorithms.

- [Bisection, Chord, Fixed Point](https://mat.iitm.ac.in/home/sryedida/public_html/caimna/transcendental/iteration%20methods/fixed-point/iteration.html)
- [Aitken](https://en.wikipedia.org/wiki/Aitken%27s_delta-squared_process)
- [Newton Method](https://onlinelibrary.wiley.com/doi/pdf/10.1002/9781118673515.app8)
- [Newton Method For Nonlinear Systems](http://www.ohiouniversityfaculty.com/youngt/IntNumMeth/lecture13.pdf)


For 1d nonlinear equations, following 6 methods can be used.

    void Bisection(double a, double b);
    void Aitken(double initial_guess = 0.0, int max_iterations = 100);
    void Chord(double a, double b);
    void FixedPoint(double initial_guess = 0.0 , int max_iterations = 100);
    void Newton1D(double initial_guess=0.0, int max_iterations=100);
    void ModifiedNewton1D(double initial_guess = 0.0, double m=1.0, int max_iterations=100);

For nonlinear systems (dimension is less than 4). Following 2 methods can be used.

    void Newton(int max_iterations=100);
    void ModifiedNewton(double m=1.0, int max_iterations=100);

For linear systems. Following 2 methods are useful.

    double* LinearSolver_Jacobi(double** A, double* b, int max_iterations = 1000);
    double* LinearSolver_LU(double** A,double* b);


#### C. TestBase and its derived class

The TestBase class holds the nonliner equation and its solver. It do not contain any specific test case. But it is a template of other specific test cases. In the TestBase class, **RunTest()** runs the test. **ShowEquationsInfo()** shows the information of equations. **ChooseMethod** chooses methods in the test case.

Other derived class is derived from TestBase and contain **specific functions (they are already defined)**. Test-A, Test-B are examples of such derived class.

RandomTest is also a class derived from TestBase which is used for user input or reading from txt files. **The dimension of test case should be equal or less than 4**.


###7. TODOs and perspectives

#### A. Support higher dimension (more than 4)

Now, our tool only support nonlinear systems equal to (or less than) 4, which involves hard-coding. In the future, we may find a way to support higher dimension. 

#### B. Make algoritms more stable

There are two unstable parts in our program. The first is that our program lacks ability detecting inappropriate input. This may cause unexpected error. We may use exceptions to help us deal with this problem.

Another part is related to the implementation of algorithms. In our implementation, especially newton method for nonlinear systems (2 variables or more), we are using some algorithms to solve **linear systems**. We implement such algorithm by ourselves. As far, these implementation are not stable enough to consider general problems. We are considering using external libraries to improve the stability. Also, we implement matrix opeartions by ourselves, which may also encounter some problems. We have to deal with the allocated space carefully to avoid memory leak.

#### C. More friendly user interface

At present, our user interface is simple and naive. We expect to develope a more sophisticated GUI interface.

#### D. Support various ways of input

We only support three basic ways to input and they have to follow a certain standard. We expect to support more ways to input and make them more easy.

