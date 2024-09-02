#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, l_res, r_res, sum_res, sum_now = 0; 
    int neg_sum = -1;
    scanf("%d", &n);
    int nums[5000];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    sum_res = nums[0];
    for (int r = 0; r < n; ++r){
        sum_now += nums[r];
        if (sum_now > sum_res){
            sum_res = sum_now;
            l_res = neg_sum + 1;
            r_res = r;
        }
        if (sum_now < 0){
            sum_now = 0;
            neg_sum = r;
        }
    }
    printf("%d %d %d", l_res, r_res, sum_res);
}
