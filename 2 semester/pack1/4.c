#include <stdio.h>
#include <stdlib.h>

int main(){
    freopen("input.txt", "r", stdin);    
    freopen("output.txt", "w", stdout);
    int m, t;
    scanf("%d %d", &m, &t);
    int* nums[2012];
    for (int i = 0; i < 2012; i++){
        nums[i] = (int *)malloc(2012 * sizeof(int));
    }
    nums[0][0] = 1;
    for(int i = 1; i< 2012; i++){
        nums[i][0] = 1;
        nums[i][i] = 1;
    }
    for (int i = 2; i < 2012; i++){
        int current_id = 1;
        while (nums[i][current_id] != 1){
            nums[i][current_id] = (nums[i - 1][current_id - 1] + nums[i - 1][current_id]) % m;
            current_id ++;
        }
        
    }
    for (int i = 0; i < t; i++){
        int n, k;
        scanf("%d %d", &n, &k);
        if (k < 0 || k > n){
            printf("0\n");
            continue;
        }
        printf("%d\n", nums[n][k]);
    }
    for (int i = 0; i < 2012; i++){
        free(nums[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}