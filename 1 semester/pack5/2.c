#include <stdio.h>


int main(){
    int q;
    int current_id = 0;
    scanf("%d", &q);
    double nums[1020][1020] = {0}; 
    nums[0][0] = 1;
    for(int i = 1; i < 1020; i++){ // заполняем края единицами 
        nums[i][0] = 1;
        nums[i][i] = 1;
    }
    for (int i = 2; i < 1020; i++){
        current_id = 1;
        while ( nums[i][current_id] != 1){
            nums[i][current_id] = nums[i-1][current_id-1] + nums[i-1][current_id]; // считаем собственно коэфициенты
            current_id ++;
        }
    }
    int n = 0, k = 0;
    for (int i = 0; i < q; i++){
        scanf("%d %d", &n, &k);
        printf("%0.10g\n", nums[n][k]);
    }
}