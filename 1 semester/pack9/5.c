#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int if_sorted(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        if (arr[i]>arr[i+1]){
            return 0;
        }
    }
    return 1;
}
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
void shuffle(int* arr, int n){
    srand (time(NULL));
    for (int i = 0; i < n; i++){
        int swap_ind = rand() % n;
        swap(&arr[i], &arr[swap_ind]);
    }
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
int partition(int* arr, int first, int last) {
    int pivot = arr[last];
    int greater = (first - 1);
    for (int i = first; i < last; i++) { // проходимся по отрезку 
        if (arr[i] < pivot) { // если текущий меньше пивота
        greater++;           // то сдвигаем наибольший вправо и меняем с текущим 
        swap(&arr[greater], &arr[i]);
        }
    }
    swap(&arr[greater + 1], &arr[last]);
    return (greater + 1);
}
int partition_r(int* arr, int first, int last)
{
    srand(time(0));
    int random = first + rand() % (last - first);
    swap(&arr[random], &arr[last]);
    return partition(arr, first, last);
}
void quickSort(int* arr, int first, int last) {
  if (first < last) {
    int pi = partition_r(arr, first, last);
    quickSort(arr, first, pi);
    quickSort(arr, pi + 1, last);
  }
}
int main(){
    FILE * input = fopen("input.txt", "rb");
    FILE * output = fopen("output.txt", "wb");
    int n = 0;
    fread(&n, sizeof(int), 1, input);
    int arr[500002];
    fread(arr, sizeof(int), n, input);
    //shuffle(arr, n);
    //if (if_sorted(arr, n) == 0) 
    quickSort(arr, 0, n - 1);
    fwrite(arr, sizeof(int), n, output);
    fclose(input);
    fclose(output);
    return 0;   
}