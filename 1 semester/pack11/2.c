#include <stdio.h>

typedef struct Node{
    int value;
    struct Node* next;
} Node;


typedef void (*callback) (void *ctx, int *value);

void if_chet(void *ctx, int *value){
    int* now = (int *)ctx;
    if (*value % 2 == 0){
        *now += *value;
    }
}

void arrayForeach(void *ctx, callback func, int *arr, int n){
    for(int i = 0; i < n; i++){
        func(ctx, &arr[i]);
    }
}
void listForeach(void *ctx, callback func, Node *arr){
    Node* now = arr;
    while (now != NULL){
        func(ctx, &(now->value));
        now = now->next;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[101] = {0};
    Node arr_node[101] = {0};
    for (int i = 0; i < n; i++){
        int now = 0;
        scanf("%d", &now);
        arr[i] = now;
        arr_node[i].value = now;
        arr_node[i].next = &arr_node[i+1];

    }
    arr_node[n - 1].next = NULL; 
    int kol_chet_arr = 0;
    int kol_chet_list = 0;
    arrayForeach( &kol_chet_arr, if_chet, arr, n);
    listForeach(&kol_chet_list, if_chet, arr_node);
    printf("%d %d",kol_chet_arr, kol_chet_list);
    return 0;
}