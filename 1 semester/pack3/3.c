#include <stdio.h>

int main(){
    int nums[10001] = {0};
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int cur = 0;
        scanf("%d", &cur);
        nums[cur] += 1;
    }
    for (int i = 1; i <= 10000; i++){
        if (nums[i] != 0){
            printf("%d: %d\n", i, nums[i]);
        }
    }
}