#include <stdio.h>
#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize) {
    int* ans = (int*)malloc(sizeof(int));
    int ansSize = 1;
    *ans = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > *ans) {
            ans = (int*)realloc(ans, (ansSize + 1) * sizeof(int));
            ans[ansSize++] = nums[i];
        } else {
            int low = 0;
            int high = ansSize - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (ans[mid] < nums[i]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ans[low] = nums[i];
        }
    }

    int result = ansSize;
    free(ans);
    return result;
}

int main() {
    int nums[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Length of LIS is %d\n", lengthOfLIS(nums, numsSize));
    return 0;
}

