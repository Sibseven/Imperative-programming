#include <stdio.h>

int gcd_int(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return gcd_int(b, a % b);
    }
}

int main(){
    int tests;
    scanf("%d", &tests);
    for(int i = 0; i < tests; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n",gcd_int(a, b));
    }
    return 0;
}