#include <stdio.h>

int main(){
    int n1 = 0, n2 = 0, n_res = 0;
    int nums_1[100001] = {0};
    int nums_2[100001] = {0};
    int nums_res[100001] = {0};
    scanf("%d", &n1);
    int cur = 0;
    for (int i = 0; i < n1; i++){
        cur = 0; 
        scanf("%d", &cur);
        nums_1[cur] += 1;
        
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++){
        cur = 0; 
        scanf("%d", &cur);
        nums_2[cur] += 1;
    }
    for (int i = 0; i < 100001; i++){
        if (nums_1[i] != 0 && nums_2[i] == 0){
            n_res += 1;
            nums_res[i] = 1;
        }
    }
    printf("%d\n", n_res);
    for (int i = 0; i < 100001; i++) {
        if (nums_res[i] != 0){
            printf("%d ", i);
        }
    }
}