#include <string.h>
#include "integerset.h"
#include <stdlib.h>
#include <stdio.h>
struct IntegerSet{
    int* arr;
    int number;
};


int cmpfunc(const void *a, const void *b)
{
   const int *A = a, *B = b;
   return (*A > *B) - (*A < *B);
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
struct IntegerSet* CreateSet(int* arr, int n){
    IntegerSet* new = (IntegerSet*)calloc(sizeof(IntegerSet), 1);
    new->arr = calloc(sizeof(int), n+2);
    int* new_arr = calloc(sizeof(int), n+5);
    memcpy(new_arr, arr, n*sizeof(int));
    qsort(new_arr, n, sizeof(int), cmpfunc);
    for(int i = 0; i < n-1; i++){
        if (new_arr[i] == new_arr[i+1]){
            free(new_arr);
            return 0;
        }
    }
    memcpy(new->arr, new_arr, n*sizeof(int));
    free(new_arr);
    new->number = n;
    return new;
}
int IsInSet(struct IntegerSet* set, int num){
    if (set == 0){
        return 0;
    }
    if (binarySearch(set->arr, 0, set->number-1, num) != -1){
        return 1;
    }
    else{
        return 0;
    }
}