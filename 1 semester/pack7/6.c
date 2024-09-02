#include <stdio.h>

typedef struct Node_s {
    int value; // значение
    int index_prev; 
    int index_next;
} Node;

void main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    Node all_elems[100000];
    all_elems[0].index_next = 1;
    all_elems[0].index_prev = n;
    for (int i = 1; i <= n; i++){
        all_elems[i].value = i;
        all_elems[i].index_next = i + 1 ;
        all_elems[i].index_prev = i - 1;
    }
    all_elems[n].index_next = 0;
    int now_index = all_elems[0].index_next;
    while (all_elems[0].index_next != 0){
        for (int i = 1; i < k; i++){
            now_index = all_elems[now_index].index_next;
            if (now_index == 0){
                now_index = all_elems[0].index_next;
            }
        }
        printf("%d\n",all_elems[now_index].value);
        all_elems[all_elems[now_index].index_next].index_prev = all_elems[now_index].index_prev;
        all_elems[all_elems[now_index].index_prev].index_next = all_elems[now_index].index_next;
        now_index = all_elems[now_index].index_next;
        if (now_index == 0){
            now_index = all_elems[now_index].index_next;
        }
        }
    
    fclose(stdin);
    fclose(stdout);
}