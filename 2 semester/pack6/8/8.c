#include <stdio.h>
#define MAX_W 100010
int max_weight, amof_items;
int max(int a, int b) { return (a > b) ? a : b; }
int rec(int k, int SumW, int* weights, int* prices, int (*F)[MAX_W], int (*memo)[MAX_W]){
    if(memo[k][SumW] != 0){
        return memo[k][SumW];
    }
    if(k == amof_items){
        return 0;
    }
    int Cskip = rec(k+1, SumW, weights, prices, F, memo);
    int Ctake = -1;
    if(SumW + weights[k] <= max_weight){
        Ctake = rec(k+1, SumW + weights[k], weights, prices, F, memo) + prices[k];
    }
    if(Cskip > Ctake){
        F[k][SumW] = 0;
        memo[k][SumW] = Cskip;
    }
    else {
        F[k][SumW] = 1;
        memo[k][SumW] = Ctake;
    }
    return memo[k][SumW];
    
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d %d", &amof_items, &max_weight);
    int weights[220] = {0};
    int prices[220] = {0};
    int memo[202][MAX_W] = {0};
    int F[202][MAX_W];
    for(int i = 0; i < amof_items; i++){
        scanf("%d %d", &weights[i], &prices[i]);
    }
    int res = rec(0, 0, weights, prices, F, memo);
    // for(int i = 0; i < 15; i++){
    //     for(int j = 0; j < 100; j++){
    //         printf("%d ", F[i][j]);
    //     }
    //     printf("\n");
    // }
    int resW = 0;
    int resKol = 0;
    int iterator = 0;
    int resItems[250] = {0};
    while (resW < max_weight && resKol < amof_items && iterator < amof_items){
        if(F[iterator][resW] == 1){
            resItems[resKol] = iterator+1;
            resW += weights[iterator];
            resKol++;
        }
        iterator++;
    }
    printf("%d %d %d\n", resKol, resW, res);
    for(int i = 0; i < resKol; i++){
        printf("%d ", resItems[i]);
    }
    


}