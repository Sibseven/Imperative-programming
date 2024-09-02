#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare (const void *a, const void *b){
    int *a1 = (int*) a;
    int *b1 = (int *) b;
    if (*a1 == *b1) return 0;
    if (*a1 > *b1){
        return 1;
    }
    else return -1;
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
//Hoare 
int partition_new(int* arr, int first, int last) {
    int pivot = arr[last];//берем пивотом последний
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
// Lomato
int partition(int* arr, int first, int last) {
  int pivot = arr[last];
  int greater = (first - 1);
  for (int i = first; i < last; i++) { // проходимся по отрезку 
    if (arr[i] <= pivot) { // если текущий меньше пивота
      greater++;           // то сдвигаем наибольший вправо и меняем с текущим 
      swap(&arr[greater], &arr[i]);
    }
  }
  swap(&arr[greater + 1], &arr[last]);
  return (greater + 1);
}

int if_sorted(int* arr, int n){
    int flag = 1;
    for (int i = 0; i < n-1; i++){
        if (arr[i]>arr[i+1]){
            return 0;
        }
    }
    return 1;
}
int partition_r(int* arr, int first, int last)
{
    srand(time(NULL));
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
    int n = 0;
    scanf("%d", &n);    
    int arr[300002] = {0};
    for (int i = 0;  i < n; i++){
        scanf("%d", &arr[i]);
    }
    // if (if_sorted(arr, n) == 0){
    //     quickSort(arr, 0, n -1);
    // }
    //qsort (arr, n, sizeof(int), compare);
    quickSort(arr, 0, n-1);
    long long int sum = 0;
    for (int i = 0; i < n; i++){
        long long int now = (long long int)arr[i]*(n - i - 1);
        sum += now;
    }
    printf("%lld", sum);
    fclose(stdin);
    return 0;
}