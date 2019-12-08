//
// Created by Rick Wang on 2019/12/8.
//

#include "Helper.h"

double GetError(double* x1, double* x2, int size){
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
{
    double error = 0.0;
    error = fabs(x1 - x2);

    return error;
}

double* MatrixAdd(double* m1, double* m2, int n){
    double* A;
    A = new double [n];

    for(int i = 0; i < n; i++){
        A[i] = m1[i] + m2[i];
    }

    return A;
}

double** MatrixAdd(double** m1, double** m2, int n, int m){
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

double* MatrixSub(double* m1, double* m2, int n){
    double* A;
    A = new double [n];

    for(int i = 0; i < n; i++){
        A[i] = m1[i] - m2[i];
    }

    return A;
}

double** MatrixSub(double** m1, double** m2, int n, int m){
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

double** MatrixMulti(double** m1, int a, int n){
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

double* MatrixMulti(double** m1, double* m2, int n){
    double* A;
    A = new double [n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            double sum = 0.0;
            for (int k = 0; k < n; k++){
                sum = sum + m1[i][k] * m2[k];
            }
            A[i] = sum;
        }
    }

    return A;
}