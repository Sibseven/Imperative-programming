#include <stdio.h>
#include <time.h>
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition_new(int* arr, int first, int last) {
    int pivot = arr[(first+last)/2];
    int l = first;
    int r = last;

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
void shuffle(int arr[], int n){
    srand (time(0));
    for (int i = 0; i < n; i++){
        int swap_ind = rand() % n;
        swap(&arr[i], &arr[swap_ind]);
    }
}
void quickSort(int arr[], int first, int last) {
  if (first < last) {
    int pi = partition_new(arr, first, last);
    quickSort(arr, first, pi);
    quickSort(arr, pi + 1, last);
  }
}
int main(){
    FILE * input = fopen("input.txt", "rb");
    FILE * output = fopen("output.txt", "wb");
    int n = 0;
    fread(&n, sizeof(int), 1, input);
    int arr[500002] = {0};
    fread(arr, sizeof(int), n, input);
    shuffle(arr, n);
    quickSort(arr, 0, n - 1);
    fwrite(arr, sizeof(int), n, output);
    fclose(input);
    fclose(output);
    return 0;
}