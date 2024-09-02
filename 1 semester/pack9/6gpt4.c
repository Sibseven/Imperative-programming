#include <stdlib.h>
#include <stdio.h>

#define BUCKET_COUNT 256

void countingSort(unsigned int arr[], int n, int digit){
    unsigned int output[n];
    int i, count[BUCKET_COUNT] = {0};

    for (i = 0; i < n; i++)
        count[((arr[i] >> (digit * 8)) & 0xff)]++;

    for(i = 1; i < BUCKET_COUNT; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--){
        output[count[((arr[i] >> (digit * 8)) & 0xff)] - 1] = arr[i];
        count[((arr[i] >> (digit * 8)) & 0xff)]--;
    }
    

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(unsigned int arr[], int n){
    for (int digit = 0; digit < sizeof(unsigned int); digit++)
        countingSort(arr, n, digit);
}

int main(){
    unsigned int arr[] = {170, 45, 75, 90, 2, 802, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
