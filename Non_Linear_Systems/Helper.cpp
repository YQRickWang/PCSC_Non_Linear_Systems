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



//double MatrixDeter(double** m, int n)
//{
//    int c, subi, i, j, subj;
//    double** subm = new double*[n];
//
//    for(int t=0;t<n;t++)
//    {
//        subm[t] = new double[n];
//    }
//
//    if(n==1)
//    {
//        return m[0][0];
//    }
//    else if(n==2)
//    {
//        return((m[0][0]*m[1][1])-(m[1][0]*m[0][1]));
//    }
//    else
//    {
//        for(c = 0; c<n;c++)
//        {
//            subi = 0;
//            for(i=1;i<n;i++)
//            {
//                subj = 0;
//                for(j=0;j<n;j++)
//                {
//                    if(j==c)
//                    {
//                        continue;
//                    }
//                    subm[subi][subj] =m[i][j];
//                    subj++;
//                }
//                subi++;
//            }
//        }
//        d = d+
//    }
//}