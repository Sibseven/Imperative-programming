#include "modular.h"

int MOD;
int extended_Euclidean_Algorithm(int a, int b, int* x, int* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extended_Euclidean_Algorithm(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
int inv(int a, int mod) {
    int x, y;
    int gcd = extended_Euclidean_Algorithm(a, mod, &x, &y);
    return (x % mod + mod) % mod;
}

int pnorm(int a){
    int res = a%MOD;
    if (res < 0) res += MOD;
    return res;
}
int padd(int a, int b){
    int res = a+b; 
    return pnorm(res);
}
int psub(int a, int b){
    return (pnorm(a - b));
}
int pmul(int a, int b){
    long long res = (long long)a *(long long)b;
    return((res % MOD) + MOD) % MOD;
}
int pdiv(int a, int b){
    int b_inv = inv(b, MOD);
    long long result = (long long)a*(long long)b_inv;
    return (result % MOD + MOD) % MOD;
}