//
// Created by Rick Wang on 2019/12/2.
//

#ifndef NON_LINEAR_SYSTEMS_NONLINEAREQUATION_H
#define NON_LINEAR_SYSTEMS_NONLINEAREQUATION_H

#include "iostream"

/**
 * definition of a new type of pointer variable which points at a function and that function takes a array of double
 * precision values and return a double precision value
 */
typedef double (*functions_type)(double*);



/**
 * In this class, we try to build a way to access the expression of the functions we are going to study, and to get some
 * basic information of the nonlinear equation or the system of nonlinear equations, which we'll process later
 */
class NonLinearEquation{
private:
    /**
     * This variable stores the dimension (number of variables) of the equation or the system of equations( 1 for a nonlinear
     * equation and 2 or more for a system of nonlinear equations)
     */
    int dim;

    /**
     * This pointer points at the first element of the function pointer array f(x1, x2, ...) = 0 , of which the size of the array
     * is equal to the integer variable dim
     */
    functions_type* funPtrArray;

    /**
     * This pointer points at the first element of the derivative function pointer matrix, of which the size of the matrix is dim * dim
     */
    functions_type** dfunPtrArray;

    /**
     * This pointer points at the function pointer g(x) = x, developed for the fixed point and Aitken
     * method, only used for 1 dimension problem.
     */
    functions_type fpPtr;

public:

    /**
     * constructor with default setting
     */
    NonLinearEquation();

    /**
     * constructor to generate a instance of a nonlinear equation
     * @param funArray a pointer points to an array of function pointers
     * @param dfunArray a pointer points to an array of derivative function pointers
     * @param fixedPoint  a pointer points to function pointer, which points to the function developed for the fixed point
     * method
     * @param dimension the dimension (number of variables) of the equation or the system of equations, here, is usually 1
     */
    NonLinearEquation(functions_type* funArray,functions_type** dfunArray,functions_type fixedPoint, int dimension);

    /**
     *constructor to generate an instance of a system of nonlinear equations
     * @param funArray a pointer points to an array of function pointers
     * @param dfunArray a pointer points to an array of derivative function pointers
     * @param dimension the dimension (number of variables) of the equation or the system of equations
     */
    NonLinearEquation(functions_type* funArray,functions_type** dfunArray,int dimension);

    /**
     * constructor to copy an argument of a system of nonlinear equations
     * @param copy an argument of a system of nonlinear equations
     */
    NonLinearEquation(NonLinearEquation& copy);

    /**
     * destructor
     */
    ~NonLinearEquation();

    /**
     * It takes a variable of a vector which contains the value of the probable solution of the system of nonlinear equations
     * and return the corresponding value in that system
     * @param input a vector which contains the value of the probable solution of the system
     * @return the corresponding value in the system
     */
    double* GetFunctionValue(double* input);

    /**
     * It takes a double precision variable which contains the probable solution of the nonlinear equation and returns the
     * corresponding value in that equation
     * @param input a double precision variable which contains the probable solution
     * @return the corresponding value in that equation
     */
    double GetFunctionValue(double input);

    /**
     * It takes a variable of vector which contains the value of the probable solution of the system of nonlinear equations
     * and returns the corresponding value in the system of the derivative functions
     * @param input a vector which contains the value of the probable solution of the system
     * @return the corresponding value in the system of the derivative functions
     */
    double** GetDfunctionValue(double* input);

    /**
     * It takes a double precision variable which contains the probable solution of the nonlinear equation and returns the
     * corresponding value in the derivative equation
     * @param input a double precision variable which contains the probable solution
     * @return the corresponding value in the derivative function
     */
    double GetDfunctionValue(double input);

    /**
     * It takes a double precision variable which contains the probable solution of the nonlinear equation and returns the
     * corresponding value in the equation developed for the fixed point method
     * @param input a double precision variable which contains the probable solution
     * @return the corresponding value in the equation developed for the fixed point method
     */
    double GetFpFunctionValue(double input);

    /**
     *
     * @return the dimension of the system, specially 1 for a single equation
     */
    int GetDimension();

    /**
     *
     * @return the pointer which points to the nonlinear function pointer array
     */
    functions_type* GetFunArray();

    /**
     *
     * @return the pointer which points to the derivative function pointer array of the nonlinear system
     */
    functions_type** GetDfunArray();

    /**
     *
     * @return the pointer which points to the function pointer to the function developed for the fixed point method
     */
    functions_type GetFpFun();

    /**
     * the set the parameter of a class of NonLinearEquation
     * @param dimension the dimension of the system
     */
    void SetDimension(int dimension);

    /**
     * to set the pointer member "funPtrArray" defined earlier as the input pointer funcarray
     * @param funarray a input pointer pointing to the function pointer array
     */
    void SetFunArray(functions_type* funarray);

    /**
     * to set the pointer member "dfunPtrArray" defined earlier as the input pointer dfunarray
     * @param dfunarray a input pointer pointing to the derivative function pointer array
     */
    void SetDFunArray(functions_type** dfunarray);

    /**
     * to set the pointer member "fpPtr" defined earlier as the input pointer fp
     * @param fp a input pointer pointing to the function pointer to the function developed for the fixed point method
     */
    void SetFpFun(functions_type fp);

};


#endif //NON_LINEAR_SYSTEMS_NONLINEAREQUATION_H
