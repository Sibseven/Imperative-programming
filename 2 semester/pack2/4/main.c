#include <stdio.h>
#include <stdlib.h>
extern int Query(int l, long long sum);
extern void Init(const int *arr , int n);
long long *arr_mod;
int NN;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nums, questions;
    scanf("%d %d", &nums, &questions);
    NN = nums;
    int* arr;
    arr = malloc(nums*sizeof(int));
    arr_mod = malloc((nums+1) * sizeof(long long));
    for(int i = 0; i < nums; i++){
        scanf("%d", &arr[i]);
    }
    Init(arr, nums);
    for(int i = 0; i < questions; i++){
        int now_l;
        long long now_sum;
        scanf("%d %lld", &now_l, &now_sum);
        printf("%d\n", Query(now_l,now_sum));
    }
    free(arr);
    free(arr_mod);
    return 0;
}