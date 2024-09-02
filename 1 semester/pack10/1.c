#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int int_cmp(const void *a, const void *b){
    int a1 = *(int *)a;
    int b1 = *(int *)b; 
    if (a1 > b1){
        return 1;
    }
    else if (a1 < b1){
        return -1;
    }
    else{
        return 0;
    }
    
}


int delete_repeat(int *arr, int n){
    int res[100005] = {0};
    int k = 0;
    for (int i = 0; i < n - 1; i++){
        if (arr[i] == arr[i + 1]){
            continue;
        }
        else{
            res[k] = arr[i];
            k++;
        }
    }
    if (arr[n-1] != res[k - 1]){
        res[k] = arr[n - 1];
        k++;
    }
   
    memset(arr, 0, n*sizeof(int));
     for (int i = 0; i < k; i++){
        arr[i] = res[i]; 
    }
    return k;
}

int main(){
    int n1 = 0, n2 = 0;
    int s1[100005] = {0};
    int s2[100005] = {0};
    int res[100005] ={0};
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++){
        scanf("%d", &s1[i]);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++){
        scanf("%d", &s2[i]);
    }
    qsort(s1, n1, sizeof(int), int_cmp); // сортировки и удаления дубликатов
    int k1 = delete_repeat(s1, n1);      
    qsort(s2, n2, sizeof(int), int_cmp); 
    int k2 = delete_repeat(s2, n2);
    int res_now = 0, s1_now = 0, s2_now = 0; 
    
    while (s1_now < k1 && s2_now < k2){
        if (s1[s1_now] < s2[s2_now]){
            res[res_now] = s1[s1_now];
            s1_now++;
            res_now++;
        }
        else if(s1[s1_now] > s2[s2_now]){
            s2_now++; 
        }
        else{
            s1_now++;
            s2_now++;
        }   
    }
    while (s1_now < k1){
        res[res_now] = s1[s1_now];
        s1_now++;
        res_now++;
    }

    printf("%d\n", res_now);
    for (int i = 0; i < res_now; i++){
        printf("%d ", res[i]);
    }
    return 0;
}