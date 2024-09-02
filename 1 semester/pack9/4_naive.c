#include <stdio.h>
#include <stdlib.h>

void merge(int * arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int res_now = l;

    int* temp1 = calloc(n1, sizeof(int));
    int* temp2 = calloc(n2, sizeof(int));
    int start1 = 0, start2 = 0;

    for (int i = 0; i < n1; i++){
        temp1[i] = arr[i+l];
    }
    for (int i = 0; i < n2; i++){
        temp2[i] = arr[m + 1 + i];
    }
    
    while (start1 != n1 && start2 != n2){
        if (temp1[start1] < temp2[start2]){
            arr[res_now] = temp1[start1];
            res_now++;
            start1++;
        }
        else{
            arr[res_now] = temp2[start2];
            res_now++;
            start2++;
        }
    }
    while (start1 != n1){
        arr[res_now] = temp1[start1];
        res_now++;
        start1++;;
    }
    while (start2 != n2){
        arr[res_now] = temp2[start2];
        res_now++;
        start2++;
    }
    free(temp1);
    free(temp2);
}
void mergeSort(int *arr, int low, int high){
if (low < high){
    int middle = (low + high) / 2;
    mergeSort(arr, low, middle);
    mergeSort(arr, middle+1, high);
    merge(arr, low , middle, high);
    }
}
int main(){
    FILE * input = fopen("input.txt", "rb");
    FILE * output = fopen("output.txt", "wb");
    int n = 0;
    fread(&n, sizeof(int), 1, input);
    int arr[500002]  = {0};
    fread(arr, sizeof(int), n, input);
    mergeSort(arr, 0, n - 1);
    fwrite(arr, sizeof(int), n, output);
    fclose(input);
    fclose(output);
    return 0;
}