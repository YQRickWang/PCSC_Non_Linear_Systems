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

The project includes two important parts. The first part is the implementation of two basic classes: **NonLinearEquation** and **NonLinearSolver**. The second part is a family of test classes which includes the base test class ( **TestBase** ) and other dervied classes ( e.g. **Test-A** ,**Test-B** ). Also, the user defined test calss ( **RandomTest** ) is also derived from base class. The following graph shows the whole structure;

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

The most import methods in NonLinearEquation are getting values of functions and derivate functions.




#### B. NonLinearSolver

#### C. 

