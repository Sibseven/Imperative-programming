#include <stdio.h>
#include <assert.h>




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
    if (gcd == 1){
        return (x % mod + mod) % mod;
    }
    return -1;
}
int MOD;

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
    long long test = (res % MOD);
    return(test + MOD) % MOD;
}
int pdiv(int a, int b){
    int b_1 = inv(b, MOD);
    return pmul(a, b_1);
}

int main(){
    MOD = 37;
    int testttt = MOD;
    int a = -10;
    a = pnorm(a);
    assert(a == 27);
    a  = padd(10, 30);
    assert(a == 3);
    a = psub(10, 30);
    assert(a == 17);
    MOD = 10^7+7;
    a = pmul(100, 100);
    printf("%d", a);
    assert(a == 10000);
    //assert(pdiv(10, 32567) == 9258920);
    return 0;
}