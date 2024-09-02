void cblas_dgemm(int Order, int TransA, int TransB, int M, int N, int K,
		 const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc){
    for (int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            double temp = 0;
            for(int z = 0; z < K; z++){
                temp += A[i*K+z] * B[z*N + j];
            }
            temp *= alpha;
            C[i*N + j] *= beta;
            C[i*N + j] += temp;
        }
    }
}
