//
// Created by Rick Wang on 2019/12/8.
//

#ifndef NON_LINEAR_SYSTEMS_MATRIXHELPER_H
#define NON_LINEAR_SYSTEMS_MATRIXHELPER_H


#include <cmath>

/**
 * @param x1 a vector
 * @param x2 a vector
 * @param size the size of the vector
 * @return the norm of the output of x1 -x2
 */
double GetError(double* x1, double* x2, int size);


/**
 * @param x1 a scalar
 * @param x2 a scalar
 * @return the absolute norm of the difference between x1 ans x2
 */
double GetError(double x1, double x2);


/**
 * @param m1 a vector
 * @param m2 a vector
 * @param n the size of the vector
 * @return the sum of these two vectors
 */
double* MatrixAdd(double* m1, double* m2, int n);


/**
 * @param m1 a matrix
 * @param m2 a matrix of the same size of m1
 * @param n the number of the lines
 * @param m the number of the columns
 * @return the sum of these two matrices
 */
double** MatrixAdd(double** m1, double** m2, int n, int m);


/**
 * @param m1 a vector
 * @param m2 a vector
 * @param n n the size of the vector
 * @return the difference between these two vectors
 */
double* MatrixSub(double* m1, double* m2, int n);


/**
 * @param m1 a matrix
 * @param m2 a matrix of the same size of m1
 * @param n the number of the lines
 * @param m the number of the columns
 * @return the difference between these two matrices
 */
double** MatrixSub(double** m1, double** m2, int n, int m);


/**
 * @param m1 a squared matrix
 * @param m2 a vector
 * @param n the number of lines(columns) of this matrix, also the size of the vector
 * @return the result of the multiplication of m1 and m2
 */
double* MatrixMulti(double** m1, double* m2, int n);


/**
 * @param m1 a squared matrix
 * @param a a scalar
 * @param n the number of lines(columns) of this matrix
 * @return the result of the multiplication of a and m1
 */
double** MatrixMulti(double** m1, double a, int n);


/**
 * @param P a matrix(supposed to be low triangular)
 * @param res a vector(the second member of the system Ax = b)
 * @param dim the number of lines(columns) of this matrix, also the size of the vector
 * @return the solution of the system P * x = res
 */
double* Forward(double** P, double* res, int dim);


/**
 * @param P a matrix(supposed to be upper triangular)
 * @param res a vector(the second member of the system Ax = b)
 * @param dim the number of lines(columns) of this matrix, also the size of the vector
 * @return the solution of the system P * x = res
 */
double* Backward(double** P, double* res, int dim);


/**
 * @param A a squared matrix
 * @param L a lower triangular matrix
 * @param U a upper triangular matrix
 * @param n  the number of lines(columns) of this matrix
 */
void LUDecomposition(double** A, double** L, double** U, int n);


#endif //NON_LINEAR_SYSTEMS_MATRIXHELPER_H
