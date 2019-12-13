# PCSC NonLinear Systems Solver

**Author: Yuqi Wang, Haojun Zhu**

**Contact: yuqi.wang@epfl.ch, haojun.zhu@epfl.ch**

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

If you didn't clone the project yet. Please follow command below to download project. Note that use option "--depth=1" to avoid downloading large files.

	git clone --depth=1 https://github.com/YQRickWang/PCSC_Non_Linear_Systems.git
	cd PCSC_Non_Linear_Systems
	cd Non_Linear_Systems

If you already download the project, please follow following commands to generate makefile from cmakelist and build the project (including compling, linking).

	mkdir build
	cd build
	cmake ..
	make

Then, run the following command to run the executable file.

	./Non_Linear_Systems
	
### 3. How to Use And EXAMPLES

When the compling, linking and generating is done. The program is executive. In the executive program, user can choose three different ways to test. Each of them have input standard. **Please follow the standard.**

- 1. Test from existing test cases.
- 2. Test from keyborad input.
- 3. Test from reading txt files.
- 4. Test featuring the google unit test

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

![Test from existing test cases process](https://i.imgur.com/fKSJgBD.gif)

	//Test from keyboard input: Example 2
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
	


#### C. Test from reading txt files

Our tool can also test from existing txt files. The content in the file should following the standard. No extra lines are allowed in txt files. And all the files should be in the directory "txt_testfiles". The order of lines should follow in order of dimension, functions, derivative functions (derivative for all variables in function 1 then function 2 ...) and fixed point function (only for 1d). Following are two examples of test from txt files. 

Txt file Content:

	1
	5*x^2+exp(2*x)-x-10
	10*x+2*exp(2*x)-1
	5*x^2+exp(2*x)-10

Txt file Content:

	2
	x^2-y+exp(x)-1
	x-y+3
	2*x+exp(x)
	-1
	1
	-1

![From Files](https://i.imgur.com/qJEcqgs.gif)

### D. Test All

![Test_ALL](https://i.imgur.com/qO78yhg.gif)

### 4. List of Features

#### A. Interactive user experience

We provide a basic user interface to load existing test cases, read random equations from keyboard as well as read from txt files. This interactive interface helps user to switch between different approaches.

#### B. Multiple input approaches 

As mentioned in previous part, the tool provides three input ways. The first is to load pre-defined test cases which are already defined in the program. The second is to read equations from keyboard. User can type any appropriate equation or system of equations (less than or equal to 4 variables). The program will parsing these input automatically and give proper results. The third one is reading from txt files. The input flow is same as the second approach. But these equations are already defined in txt files.

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

- test1: f(x) = 5*x^2+exp(2*x)-x-10, the solution is  x1 = -1.31263 and x2 = 0.938533
- test2: f(x) = x^4-x-10, the solution is x1 = -1.6975 and x2 = 1.8556
- test3: f(x) = x-exp(-x), the solution is x = 0.567143
- test4: f(x) = exp(-x)*(x^2+5*x+2)+1, the solution is x1 = -4.55901 and x2 = -0.579159
- test5: f1(x, y) = (x - 1)^2 + y^2 -1, f2(x, y) = (x + 1)^2 + y^2 - 1, the solution is x = 0.0 and y = 0.0
- test6: f1(x, y, z) = x^2-y*z-1, f2(x, y, z) = y-2, f3(x, y, z) = x+z^2-4, there are two solutions, 
            sol1: x = 1.9631, y = 2, z = 1.4272; sol2: x = -2.4668, y = 2, z = 2.5430  

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

###7. TODOs and perspectives

#### A. Support higher dimension (more than 4)

Now, our tool only supports nonlinear systems equal to (or less than) 4, which involves hard-coding. In the future, we may find a way to support higher dimension. 

#### B. Make algoritms more stable

There are two unstable parts in our program. The first is that our program lacks ability detecting inappropriate input. This may cause unexpected error. We may use exceptions to help us deal with this problem.

Another part is related to the implementation of algorithms. In our implementation, especially newton method for nonlinear systems (2 variables or more), we are using some algorithms to solve **linear systems**. We implement such algorithm by ourselves. As far, these implementations are not stable enough to consider general problems. We are considering using external libraries to improve the stability. Also, we implement matrix operations by ourselves, which may also encounter some problems. We have to deal with the allocated space carefully to avoid memory leak.

#### C. More friendly user interface

At present, our user interface is simple and naive. We expect to develope a more sophisticated GUI interface.

#### D. Support various ways of input

We only support three basic ways to input and they have to follow a certain standard. We expect to support more ways to input and make them more easy.

