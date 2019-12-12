//
// Created by Rick Wang on 2019/11/22.
//

#ifndef NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H
#define NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H

#include "iostream"
#include "map"
#include "cmath"
#include "list"
#include "string"
#include "NonLinearSolver.h"
#include "NonLinearEquation.h"
#include "MatrixHelper.h"

typedef double (*functions_type)(double*);

/**
 * In this class, we construct different methods to solve an nonlinear equation, or a more sophisticated system of nonlinear
 * equations
 */
class NonLinearSolver {
private:

    /**
     * a member of type of class NonLinearEquation, contains the nonlinear equation(or equations) to solve and the derivative equations
     * associated
     */
    NonLinearEquation equations;

    /**
     * store the zero point of the nonlinear system, as well as the method applied
     */
    std::map<std::string,std::list<double>> zeroPoint;
public:

    /**
     * default constructor
     */
    NonLinearSolver();

    /**
     * constructor to construct the member of the class bassed on the input which is of the type of class NonLinearEquation
     * @param input_equations an input of the type of class NonLinearEquation
     */
    NonLinearSolver(NonLinearEquation input_equations);

    /**
     * constructor to copy an input of a NonLinearSolver
     * @param copy an input of the type of class NonLinearSolver
     */
    NonLinearSolver(NonLinearSolver& copy);

    /**
     * default destructor
     */
    ~NonLinearSolver();

    /**
     * to get the value of the member "equations"
     * @return the member "equations" of a class NonLinearSolver
     */
    const NonLinearEquation GetEquations();

    /**
     * to get the value of the member "zeroPoint"
     * @return the member "zeroPoint" of a class NonLinearSolver
     */
    const std::map<std::string,std::list<double>> GetZeroPoint();

    /**
     * to set the member "equations" based on an input of the type of class NonLinearEquation
     * @param input_equations
     */
    void SetEquations(NonLinearEquation input_equations);


    /**
     * The bisection method consists of repeatedly bisecting the interval defined by these a and b and then selecting
     * the sub_interval in which the function changes sign, and therefore must contain a root.
     * @param a the lower bound of the initial interval
     * @param b the upper bound of the initial interval
     */
    void Bisection(double a, double b);

    /**
     *The Aitken method is a series acceleration method, used for accelerating the rate of convergence of a sequence, in this
     * case, we apply it to the fixed point method
     * @param initial_guess the initial guess of the solution
     * @param max_iterations the limit of the number of iterations of the method
     */
    void Aitken(double initial_guess = 0.0, int max_iterations = 100);

    /**
     * In numerical analysis, the chord method is a root-finding algorithm that uses a succession of roots of secant lines
     * to better approximate a root of a function f.
     * @param a the lower bound of the initial interval
     * @param b the upper bound of the initial interval
     */
    void Chord(double a, double b);

    /**
     * Fixed point is a method of computing fixed points of iterated functions. More specifically, given a function f
     * defined on the real numbers with real values and given a point x0 in the domain of f, the fixed point iteration is
     * Xn+1 = f(Xn), for n = 0, 1, 2, ...... until convergence
     * @param initial_guess the initial guess of the solution
     * @param max_iterations the limit of the number of iterations of the method
     */
    void FixedPoint(double initial_guess = 0.0 , int max_iterations = 100);

    /**
     * Newton method is a root-finding algorithm which produces successively better approximations to the roots (or zeroes)
     * of a real-valued function Given the function f and the initial guess X0, the iteration goes like Xn+1 = Xn - f(Xn)/fp(Xn),
     * where fp is the derivative of the function f.
     * @param initial_guess the initial guess of the solution
     * @param max_iterations the limit of the number of iterations of the method
     */
    void Newton1D(double initial_guess=0.0, int max_iterations=100);

    /**
     * a modified version of the Newton method
     * @param initial_guess  the initial guess of the solution
     * @param m the weight
     * @param max_iterations the limit of the number of iterations of the method
     */
    void ModifiedNewton1D(double initial_guess = 0.0, double m=1.0, int max_iterations=100);

    /**
     * The Newton method for a system of nonlinear equations
     * @param initial_guess the initial guess of the solution
     * @param max_iterations the limit of the number of iterations of the method
     */
    void Newton(double* initial_guess, int max_iterations=100);

    /**
     * The modified version of Newton method for a system of nonlinear equations
     * @param initial_guess the initial guess of the solution
     * @param m the weight
     * @param max_iterations the limit of the number of iterations of the method
     */
    void ModifiedNewton(double* initial_guess, double m=1.0, int max_iterations=100);

    /**
     * To print the zero point and the method by which this particular zero point is found
     */
    void ZeroPointPrint();


    /**
     * Jacobi's iterative method for solving a linear system
     * @param A a matrix
     * @param b a vector
     * @param max_iterations the limit of the number of iterations of the method
     * @return the solution of the system Ax = b
     */
    double* LinearSolver_Jacobi(double** A, double* b, int max_iterations = 1000);

    /**
     * A direct LU decomposition method for solving a linear system
     * @param A a matrix
     * @param b a vector
     * @return the solution of the system Ax = b
     */
    double* LinearSolver_LU(double** A,double* b);

    /**
     * To add a zero point to the map ZeroPoint
     * @param method the name of the method applied to find the zero point
     * @param zeros the zero points (plural for the case of system of nonlinear equations)
     */
    void AddToZeroPoint(std::string method,double* zeros);

    /**
     * To add a zero point to the map ZeroPoint
     * @param method the name of the method applied to find the zero point
     * @param zeros the zero points (plural for the case of systems of nonlinear equations)
     */
    void AddToZeroPoint(std::string method,double zeros);

    /**
     * To clear the map ZeroPoint
     */
    void ClearZeroPoint();

};


#endif //NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H
