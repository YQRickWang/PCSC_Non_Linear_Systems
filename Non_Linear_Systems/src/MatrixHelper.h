//
// Created by Rick Wang on 2019/12/8.
//

#ifndef NON_LINEAR_SYSTEMS_MATRIXHELPER_H
#define NON_LINEAR_SYSTEMS_MATRIXHELPER_H


#include <cmath>

double GetError(double* x1, double* x2, int size);
double GetError(double x1, double x2);
double GetError(double* x,int size);

double** MatrixAdd(double** m1, double** m2, int n, int m);
double* MatrixAdd(double* m1, double* m2, int n);

double** MatrixSub(double** m1, double** m2, int n, int m);
double* MatrixSub(double* m1, double* m2, int n);

double* MatrixMulti(double** m1, double* m2, int n);
double** MatrixMulti(double** m1, double a, int n);//multiply a constant

double* Forward(double** P, double* res, int dim);
double* Backward(double** P, double* res, int dim);

void LUDecomposition(double** A, double** L, double** U, int n);

double Deter(double** m, int n);

#endif //NON_LINEAR_SYSTEMS_MATRIXHELPER_H
