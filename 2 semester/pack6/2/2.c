#include <stdio.h>
#include <stdlib.h>
int min(int a, int b){
    if (a > b){
        return b;
    }
    return a;
}
int res[1010][1010];
void rec( int n){
    for(int sum = n; sum >= 0; sum--){
        for(int last = 0; last <= n; last++){
            if(sum == n){
                res[last][sum] = 1;
            }
            else{
                res[last][sum] = 0;
                int iter = min(last, n - sum);
                for(int x = 1; x <= iter; x++){
                    res[last][sum] += res[x][sum+x];
                    res[last][sum] %= 1000000007;
                }
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    rec(n);
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= n; j++){
    //         printf("%d ", res[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d", res[n][0]);
    for(int i = 0; i <= n; i++){
        free(res[i]);
    }
    free (res);
    return 0;
}
