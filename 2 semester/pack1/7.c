#include <stdio.h>
#include <stdlib.h>

int main(){
    freopen("input.txt", "r", stdin);
    int variables;
    double* nums[210];
    for(int i = 0; i < 210; i++){
        nums[i] = malloc(sizeof(double)*210);
    }
    double ans[210];
    scanf("%d", &variables);
    for(int i = 0; i < variables; i++){
        for(int j = 0; j < variables+1; j++){
            scanf("%lf", &nums[i][j]);
        }
    }
    for(int i = 0; i < variables; i++){
        int j = i;
        while (nums[j][i] == 0){
            if (j == variables) break;
            j++;
        }
        if (j != i){
            double *temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        for (int subs_row = i+1; subs_row < variables; subs_row++){
            double coef = nums[subs_row][i] / nums[i][i];
            for (int sub_column = 0; sub_column < variables + 1; sub_column++){
                nums[subs_row][sub_column]-= nums[i][sub_column] * coef;
            }
        }
    }
    ans[variables - 1] = nums[variables - 1][variables ] / nums[variables - 1][variables - 1];
    for(int i = variables - 2; i >= 0; i--){
        double sum = 0;
        for(int j = i + 1; j < variables; j++)
        {
            sum += nums[i][j]*ans[j];
        }
        ans[i]=(nums[i][variables]-sum)/nums[i][i];
    }
    for (int i = 0; i < variables; i++){
        printf("%lf\n", ans[i]);
    }
    for (int i = 0; i < 210; i++){
        free(nums[i]);
    }
}