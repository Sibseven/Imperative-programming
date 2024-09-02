#include <stdio.h>
int power(char a ,int x, int y){
    if (a == '0'){
        return 0;
    }
    if (y == 0){  
        return 1;
    }
    int res = 1;
    for (int i = 0; i < y; i++){
            res = res * x;
        }
    return res;
}
int main(){
    int n, k;
    scanf("%d", &n);
    k = n / 8;
    int d = n % 8;
    for (int i = 0; i < k; i++){
        int sum = 0;
        for (int j = 0; j < 8; j++){
            char a = '0';
            scanf("%c", &a);
            if (a == '\n'){
                scanf("%c", &a);
            }
            int b = power(a, 2, j);
            sum += b;
        }
        printf("%d ", sum);
    }
    if (d == 0){
        return 0;
    }
    int sum = 0;
    for (int i = 0; i< d; i++){
        char a = '0';
        scanf("%c", &a);
        if (a == '\n'){
            scanf("%c", &a);
        }
        int b = power(a, 2, i);
        sum += b;
    }
    printf("%d", sum);
    return 0;
}