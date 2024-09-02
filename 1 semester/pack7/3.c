#include <stdio.h>

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        double p,q;
        long long m;
        scanf("%lf/%lf xor %llx", &p, &q, &m);
        double value =  p/q;
        long long* pointer = (long long*) &value;
        long long* pointer_m = &m;
        long long xor =  (*pointer)^(*pointer_m);
        double ans = *((double*)&xor);
        printf("%0.15g\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
}