#include <stdio.h>

int main(){
    int l, r, k, n = 0;
    scanf("%d %d %d", &l, &r, &k);
    for (int i = l; i < r; i++){
        for (int step = 1; step <= (r - l); step++){
            if ((step * (k - 1)) + i <= r && ((step * k) + i > r)){
                n += 1;
            }
        }
    }
    printf("%d", n);
    return 0;
}