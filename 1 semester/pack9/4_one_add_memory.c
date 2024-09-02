#include <stdio.h>
#include <stdlib.h>

void merge(int * arr, int * temp, int l, int m, int r){
    int res_now = l;

    int start1 = l, start2 = m + 1;

    while (start1 <= m && start2 <= r){
        if (arr[start1] < arr[start2]){
            temp[res_now] = arr[start1];
            res_now++; //Собственно мердж
            start1++;
        }
        else{
            temp[res_now] = arr[start2];
            res_now++;
            start2++;
        }
    }
    while (start1 <= m){
        temp[res_now] = arr[start1];
        res_now++; //Собственно мердж
        start1++;
    }
    while (start2 <= r){
        temp[res_now] = arr[start2];
        res_now++;
        start2++;
    }
    for (int i = l; i <= r; i++){
        arr[i] = temp[i];
    }
}
void mergeSort(int *arr, int * temp, int low, int high){
if (low < high){
    int middle = (low + high) / 2;
    mergeSort(arr, temp, low, middle);
    mergeSort(arr, temp, middle+1, high);
    merge(arr, temp, low , middle, high);
    }
    return;
}
int main(){
    FILE * input = fopen("4.in", "rb");
    FILE * output = fopen("output.txt", "wb");
    int n = 0;
    fread(&n, sizeof(int), 1, input);
    int arr[500002]  = {0};
    int temp[500002] = {0};
    fread(arr, sizeof(int), n, input);
    mergeSort(arr, temp, 0, n - 1);
    fwrite(arr, sizeof(int), n, output);
    fclose(input);
    fclose(output);
    return 0;
}