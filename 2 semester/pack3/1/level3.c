void dgemm(
int m, int n, int k,
double alpha , const double *A, const double *B,
double beta , double *C
){
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            double temp = 0;
            for(int z = 0; z < k; z++){
                temp += A[i*k+z] * B[z*n + j];
            }
            temp *= alpha;
            C[i*n + j] *= beta;
            C[i*n + j] += temp;
        }
    }
}