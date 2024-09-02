#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition_new(int* arr, int first, int last) {
    int pivot = arr[last];
    int l = first, r = last;

    while (l <= r){
        while (arr[l] < pivot){
            l++;
        }
        while (arr[r] > pivot){
            r--;
        }
        if (l >= r) break;
        swap(&arr[l], &arr[r]);
        l++;
        r--; 
    }
    return r;
}
int partition_r(int* arr, int first, int last)
{
    srand(time(0));
    int random = first + rand() % (last - first);
    swap(&arr[random], &arr[last]);
    return partition_new(arr, first, last);
}
void quickSort(int* arr, int first, int last) {
  if (first < last) {
    int pi = partition_r(arr, first, last);
    quickSort(arr, first, pi);
    quickSort(arr, pi + 1, last);
  }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 0;
    int nums[300009]= {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    quickSort(nums, 0, n - 1);
    int res[300009] = {0};
    int k = 0;
    for (int i = 0; i < n - 1; i++){
        if (nums[i] == nums[i + 1]){
            continue;
        }
        else{
            res[k] = nums[i];
            k++;
        }
    }
    if (nums[n-1] != res[k - 1]){
        res[k] = nums[n - 1];
        k++;
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++){
        printf("%d\n",res[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}