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