#include <stdio.h>

long long fast_pow_mod(long long a, int k, int M){
    if (k == 0){
        return 1;
    }
    long long a_mod = a % M;
    if (k % 2 == 0){
        long long a_mod_mult = (a_mod * a_mod) % M;
        return fast_pow_mod(a_mod_mult, k/2, M);
    }
    else{
        return (a_mod * fast_pow_mod(a_mod, k-1, M))% M;
    }
}

int main(){
    int T, M;
    scanf("%d %d", &T, &M);
    long long now_ll;
    for (int i = 0; i < T; i++){
        scanf("%lld", &now_ll);
        if (now_ll == 0){
            printf("%d\n", -1);
            continue;
        }
        long long ans = fast_pow_mod(now_ll, M-2, M);
        printf("%lld\n", ans);
    }
    return 0;
}