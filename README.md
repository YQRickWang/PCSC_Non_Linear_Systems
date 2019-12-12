# PCSC NonLinear Systems Solver

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

### 3. How to Use

### 4. Project Structure

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
