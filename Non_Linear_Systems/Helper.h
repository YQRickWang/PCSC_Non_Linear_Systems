//
// Created by Rick Wang on 2019/12/8.
//

#ifndef NON_LINEAR_SYSTEMS_HELPER_H
#define NON_LINEAR_SYSTEMS_HELPER_H


#include <cmath>

double GetError(double* x1, double* x2, int size);
double GetError(double x1, double x2);

double** MatrixAdd(double** m1, double** m2, int n, int m);
double* MatrixAdd(double* m1, double* m2, int n);

double** MatrixSub(double** m1, double** m2, int n, int m);
double* MatrixSub(double* m1, double* m2, int n);

double* MatrixMulti(double** m1, double* m2, int n);
double** MatrixMulti(double** m1, double a, int n);//multiply a constant

#endif //NON_LINEAR_SYSTEMS_HELPER_H
