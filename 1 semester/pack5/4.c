// Решето Эратосфена
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, q;
    scanf("%d %d\n", &n, &q);
    int memory = (n+2)*sizeof(int);
    int *p = malloc(memory);
        
    for (int i = 0; i < (n + 2); i++)
    {
        *(p + i) = 1;
    }
    *p = 0; *(p+1) = 0;
    for (int d = 2; d * d <= n; d++){
        int cur = *(p + d);
        if (cur == 1){
            for (int i = d * d; i <= n; i += d){
                *(p + i) = 0;
            }
        }
    }
    int cur = 0;
    for (int i = 0; i < q; i++){
        scanf("%d", &cur);
        if (*(p + cur) == 1){
            printf("\n%d %s", cur, "prime");
        }
        else{
            printf("\n%d %s", cur, "not");
        }
    }
    free(p);
}