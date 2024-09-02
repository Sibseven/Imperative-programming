#define MOD 1000000007
#include <stdio.h>
#include <stdlib.h>


long long find_inv(long long a, int k, int M){
    if (a == 0){
        return 0;
    }
    if (k == 0){
        return 1;
    }
    long long a_mod = a % M;
    if (k % 2 == 0){
        long long a_mod_mult = (a_mod * a_mod) % M;
        return find_inv(a_mod_mult, k/2, M);
    }
    else{
        return (a_mod * find_inv(a_mod, k-1, M))% M;
    }
}

int main(){
    int tests; 
    scanf("%d", &tests);
    long long facts[1000006] = {0};
    facts[0] = 1;
    facts[1] = 1;
    for (int i = 2; i < 1000006; i++){
        facts[i] = (((facts[i - 1])%MOD) * i) % MOD;
        if (facts[i]<0) facts[i]+= MOD;
    }
    for (int i = 0; i < tests; i++){
        int n, k;
        scanf("%d %d", &n, &k);
        int test1 = facts[n];
        int test2 = facts[k];
        long long res = (facts[n]*find_inv(((facts[k]*facts[n-k])% MOD), MOD-2, MOD))%MOD;
        printf("%lld\n", res);
    }
    return 0;
}