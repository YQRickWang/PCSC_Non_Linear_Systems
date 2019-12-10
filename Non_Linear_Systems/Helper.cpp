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
        double sum = 0.0;
        for (int k = 0; k < n; k++){
            sum = sum + m1[i][k] * m2[k];
        }
        A[i] = sum;
    }

    return A;
}

//Helper Function for LU method
double* Forward(double** P, double* res, int dim){
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

double* Backward(double** P, double* res, int dim){
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

double det(double** A, int n){
    if(n ==1)
        return A[0][0];
    double** B = new double* [n-1];
    for (int l = 0; l < n-1; l++){
        B[l] = new double[n-1];
    }
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <(n - 1); k++) {
                if (j < i){
                    B[k][j] = A[k+1][j];
                }
                else if (j > i){
                    B[k][j-1] = A[k+1][j];
                }
            }
        }
        sum = sum + pow(-1, i)*A[0][i] * det(B, (n - 1));
    }
    for (int l = 0; l < n-1; l++){
        delete[] B[l];
    }
    delete[] B;
}

bool unique(double** A, double* b, int dim){
    bool uni = true;
    if(fabs(det(A,dim))<1e-5){
        uni = false;
    }
    return uni;
}
