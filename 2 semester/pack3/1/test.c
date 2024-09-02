#include <stdio.h>
void dgemm(
int m, int n, int k,
double alpha , const double *A, const double *B,
double beta , double *C
){
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            double temp = 0;
            for(int z = 0; z < k; z++){
                double test1 = A[i*k+z];
                double test2 = B[z*n + j];
                temp += A[i*k+z] * B[z*n + j];
            }
            temp *= alpha;
            C[i*n + j] *= beta;
            C[i*n + j] += temp;
        }
    }
}
void daxpy(int n, double alpha , const double *X, double *Y){
    for(int i = 0; i < n; i++){
        *Y += X[i] * alpha;
        Y++;
    }
}
void dswap(int n, double *X, double *Y){
    for(int i = 0; i < n; i++){
        double temp = *X;
        *X = *Y;
        *Y = temp;
        X++;
        Y++;
    }
}
void dcopy(int n, const double *X, double *Y){
    for(int i = 0; i < n; i++){
        *Y = X[i];
        Y++;
    }
}
void dgemv(
int m, int n,
double alpha , const double *A, const double *X,
double beta , double *Y
){
    for(int i = 0; i < m; i++){
        double temp = 0;
        for(int j = 0; j < n; j++){
            temp += A[i*n+j]* X[j]*alpha;
        }
        Y[i] *= beta;
        Y[i] += temp;
    }
}

void dger(
int m, int n,
double alpha , const double *X, const double *Y,
double *A
){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            A[i*n+j] += alpha * X[i] * Y[j];
        }
    }
}
int main(){
    double A[7] = {1, 0, 0, 1, 1, 1};
    double B[7] = {1, 2 , 1 , 0, 1 , 2};
    double C[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    double X[3] = {1, 2};
    double Y[3] ={7, 9, 6};
    dgemm(3, 3, 2, 1, A, B, 1, C);
    for(int i = 0; i < 9; i++){
        if (i % 3 == 0){
            printf("\n");
        }
        printf("%lf ", C[i]);
    }
    dgemv(3, 2, 1, A, X, 1, Y);
    //printf("\n%lf %lf %lf", X[0], X[1], X[2]);
    printf("\n%lf %lf %lf", Y[0], Y[1], Y[2]);

}