//
// Created by Rick Wang on 2019/12/8.
//

#include "MatrixHelper.h"

double GetError(double* x1, double* x2, int size)
/**
 *
 * @param x1 a vector
 * @param x2 a vector
 * @param size the size of the vector
 * @return the norm of the output of x1 -x2
 */
{
    double sum = 0.0;
    double error = 0.0;

    for (int i = 0; i < size; i++){
        double j = x1[i] - x2[i];
        sum = sum + j * j;
    }
    error = sqrt(sum);

    return error;
}

double GetError(double x1, double x2)
/**
 *
 * @param x1 a scalar
 * @param x2 a scalar
 * @return the absolute norm of the difference between x1 ans x2
 */
{
    double error = 0.0;
    error = fabs(x1 - x2);

    return error;
}

double GetError(double* x,int size)
{
    double sum = 0.0;
    double error = 0.0;

    for (int i = 0; i < size; i++){
        double j = x[i];
        sum = sum + j * j;
    }
    error = sqrt(sum);

    return error;
}

double* MatrixAdd(double* m1, double* m2, int n)
/**
 *
 * @param m1 a vector
 * @param m2 a vector
 * @param n the size of the vector
 * @return the sum of these two vectors
 */
{
    double* A;
    A = new double [n];

    for(int i = 0; i < n; i++){
        A[i] = m1[i] + m2[i];
    }

    return A;
}

double** MatrixAdd(double** m1, double** m2, int n, int m)
/**
 *
 * @param m1 a matrix
 * @param m2 a matrix of the same size of m1
 * @param n the number of the lines
 * @param m the number of the columns
 * @return the sum of these two matrices
 */
{
    double** A;
    A = new double* [n];
    for (int i = 0; i < n; i++){
        A[i] = new double[m];
        for (int j = 0; j < m; j++){
            A[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return A;
}

double* MatrixSub(double* m1, double* m2, int n)
/**
 *
 * @param m1 a vector
 * @param m2 a vector
 * @param n n the size of the vector
 * @return the difference between these two vectors
 */
{
    double* A;
    A = new double [n];

    for(int i = 0; i < n; i++){
        A[i] = m1[i] - m2[i];
    }

    return A;
}

double** MatrixSub(double** m1, double** m2, int n, int m)
/**
 *
 * @param m1 a matrix
 * @param m2 a matrix of the same size of m1
 * @param n the number of the lines
 * @param m the number of the columns
 * @return the difference between these two matrices
 */
{
    double** A;
    A = new double* [n];
    for (int i = 0; i < n; i++){
        A[i] = new double[m];
        for (int j = 0; j < m; j++){
            A[i][j] = m1[i][j] - m2[i][j];
        }
    }

    return A;
}

double** MatrixMulti(double** m1, int a, int n)
/**
 *
 * @param m1 a squared matrix
 * @param a a scalar
 * @param n the number of lines(columns) of this matrix
 * @return the result of the multiplication of a and m1
 */
{
    double** A;
    A = new double* [n];
    for (int i = 0; i < n; i++){
        A[i] = new double [n];
        for(int j = 0; j < n; j++){
            A[i][j] = a * m1[i][j];
        }
    }

    return A;
}

double* MatrixMulti(double** m1, double* m2, int n)
/**
 *
 * @param m1 a squared matrix
 * @param m2 a vector
 * @param n the number of lines(columns) of this matrix, also the size of the vector
 * @return the result of the multiplication of m1 and m2
 */
{
    double* A;
    A = new double [n];
    for (int i = 0; i < n; i++){
        double sum = 0.0;
        for (int k = 0; k < n; k++){
            sum = sum + m1[i][k] * m2[k];
        }
        A[i] = sum;
    }

    return A;
}

//Helper Function for LU method
double* Forward(double** P, double* res, int dim)
/**
 *
 * @param P a matrix(supposed to be low triangular)
 * @param res a vector(the second member of the system Ax = b)
 * @param dim the number of lines(columns) of this matrix, also the size of the vector
 * @return the solution of the system P * x = res
 */
{
    double* ans;
    ans = new double[dim];
    ans[0] = res[0] / P[0][0];
    for(int i = 1; i < dim; i++){
        double sum = 0.0;
        for(int j = 0; j < i ; j++){
            sum = sum + P[i][j] * ans[j];
        }
        ans[i] = ((double)((1.0) / P[i][i])) * (res[i] - sum);
    }
    return ans;
}

double* Backward(double** P, double* res, int dim)
/**
 *
 * @param P a matrix(supposed to be upper triangular)
 * @param res a vector(the second member of the system Ax = b)
 * @param dim the number of lines(columns) of this matrix, also the size of the vector
 * @return the solution of the system P * x = res
 */
{
    double* ans;
    ans = new double[dim];
    ans[dim - 1] = (res[dim - 1] / P[dim - 1][dim - 1]);
    for(int i = dim - 2; i > -1; i--){
        double sum = 0.0;
        for(int j = i+1; j < dim ; j++){//j from i+1
            sum = sum + P[i][j] * ans[j];
        }
        ans[i] = ((double)((1.0) / P[i][i])) * (res[i] - sum);
    }
    return ans;
}

//need to add pivot technique
void LUDecomposition(double** A, double** L, double** U, int n)
/**
 *
 * @param A a squared matrix
 * @param L a lower triangular matrix
 * @param U a upper triangular matrix
 * @param n  the number of lines(columns) of this matrix
 * It performs the matrix decomposition of A = L * U
 */
{
    //allocate the space for A, L, U outside the function
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j<i)
                L[j][i] = 0;
            else{
                L[j][i] = A[j][i];
                for(int k=0;k<i;k++)
                {
                    L[j][i] = L[j][i] - L[j][k]*U[k][i];
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            if(j<i)
                U[i][j] = 0;
            else if(j==i)
                U[i][j] =1;
            else{
                U[i][j] = A[i][j]/L[i][i];
                for(int k=0;k<i;k++)
                {
                    U[i][j] = U[i][j] - ((L[i][k]*U[k][j])/L[i][i]);
                }
            }
        }
    }
}


