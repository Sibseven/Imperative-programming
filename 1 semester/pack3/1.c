#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    int nums[100];
    for (int i = 0; i<n; i++){
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < n; i++){
        int k = 0;
        for (int j = i+1; j < n; j++){
            if (nums[i] > nums[j]){
                k += 1;
            }
        }
        printf("%d ", k);
    }
    return 0;
}