#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    int nums[100000];
    for (int i = 0; i<n; i++){
        scanf("%d", &nums[i]);
    }
    for (int i = 1; i <= n; i++){
        int sum = 0;
        for (int j = i - 1; j < n; j+=i){
            sum += nums[j];
        }
        printf("%d\n", sum);
    }
}