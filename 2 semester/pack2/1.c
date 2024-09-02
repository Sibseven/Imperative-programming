#include <stdio.h>
#include <stdlib.h>

long long extended_Euclidean_Algorithm(long long a, long long b, long long* x, long long* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = extended_Euclidean_Algorithm(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

long long mulmod(long long a, long long b, long long m) {
    long long result = 0;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result + a) % m;
        }
        a = (a * 2) % m;
        b = b / 2;
    }
    return result;
}

long long inv(long long a, long long mod) {
    long long x, y;
    int gcd = extended_Euclidean_Algorithm(a, mod, &x, &y);
    if (gcd == 1){
        return (x % mod + mod) % mod;
    }
    return -1;
}
int main(){
    freopen("input.txt", "r", stdin);
    int num_of_mods;
    scanf("%d", &num_of_mods);
    long long *mods;
    long long *remains;
    long long *mods_from_super;
    long long *inv_mods_from_super;
    mods = (long long *) malloc(num_of_mods*sizeof(long long));
    remains = (long long *) malloc(num_of_mods*sizeof(long long));
    mods_from_super =(long long *) malloc(num_of_mods*sizeof(long long));
    inv_mods_from_super = (long long *) malloc(num_of_mods*sizeof(long long));
    long long super_mod = 1;
    for(int i = 0; i < num_of_mods; i++){
        scanf("%lld", &mods[i]);
        super_mod *= mods[i];
    }
    for(int i = 0; i < num_of_mods; i++){
        scanf("%lld", &remains[i]);
    }
    for(int i = 0; i < num_of_mods; i++){
        mods_from_super[i] = super_mod/mods[i]; 
        inv_mods_from_super[i] = inv(mods_from_super[i], mods[i]);
    }
    long long ans = 0;
    for(int i = 0; i< num_of_mods; i++){
        long long tea = mulmod(remains[i], mods_from_super[i], super_mod);
        long long coffe = mulmod(tea, inv_mods_from_super[i], super_mod);
        ans += coffe;
        ans %= super_mod;
    }
    ans = ans % super_mod;
    printf("%lld", ans);
    free(mods);
    free(remains);
    free(inv_mods_from_super);
    free(mods_from_super);
    return 0;
}