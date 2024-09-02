#include <stdio.h>
#include <stdlib.h>
int partition(int *a, int n, int pivot){
    int* new_arr = calloc(n, sizeof(int));
    int new_arr_now = 0;
    int pivot_kol = 0;
    int k;
    for (int i = 0 ; i < n; i++){ // Добавляем элементы меньше пивота и считаем количество пивотов
        if (a[i] == pivot){
            pivot_kol++;
        }
        if (a[i] < pivot){
            new_arr[new_arr_now] = a[i];
            new_arr_now++;
        }
    }
    k = new_arr_now + pivot_kol/2;
    for (int i = 0; i < pivot_kol; i++){ // Добавляем элементы которые равны пивоту 
        new_arr[new_arr_now] = pivot;
        new_arr_now++;
    }
    for (int i = 0; i < n; i++){ // Добавляем значения больше пивота
        if (a[i] > pivot){
            new_arr[new_arr_now] = a[i];
            new_arr_now++;
        }
    }
    for (int i = 0; i < n; i++){// Переносим значения в основной массив
        a[i] = new_arr[i];
    }
    free(new_arr);
    return k;
}

int main(){
    FILE * input = fopen("input.txt", "rb");
    FILE * output = fopen("output.txt", "wb");
    int n = 0;
    int pivot = 0;
    fread(&n, sizeof(int), 1, input);
    fread(&pivot, sizeof(int), 1, input);
    int arr[1000001] = {0};
    fread(&arr, sizeof(int), n, input);
    // for (int i = 0; i < n; i++){
    //     if (arr[i] <= pivot){
    //         fwrite(&arr[i], sizeof(int), 1, output);
    //     }
    // }
    int k = partition(arr, n, pivot);
    fwrite(&k, sizeof(int), 1, output);
    fwrite(arr, sizeof(int), n, output);
    return 0;
}