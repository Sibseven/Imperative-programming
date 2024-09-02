void dcopy(int n, const double *X, double *Y){
    for(int i = 0; i < n; i++){
        *Y = X[i];
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
void dscal(int n, double alpha , double *X){
    for(int i = 0; i < n; i++){
        *X = *X * alpha;
        X++;
    }
}
void daxpy(int n, double alpha , const double *X, double *Y){
    for(int i = 0; i < n; i++){
        *Y += X[i] * alpha; 
        Y++;
    }
}

double ddot(int n, const double *X, const double *Y){
    double res = 0;
    for(int i = 0; i < n; i++){
        res += X[i]*Y[i];
    }
    return res;
}