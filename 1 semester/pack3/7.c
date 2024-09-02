#include <stdio.h>

int main(){
    int n, max;
    int nums[100000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (nums[j] > nums [j+1]){
                int vr = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = vr;
            }

        }
    }
    for (int i = 0; i < n; i++){
        printf("%d ", nums[i]);
    }
}