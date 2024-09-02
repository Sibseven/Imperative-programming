#include <stdio.h>

typedef struct Node_s {
    int value; // значение
    int index_prev; 
    int index_next;
} Node;

void main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, n, first, last, q, next_free;
    scanf("%d", &t);
    for (int test = 0; test < t; test++){
        scanf("%d %d %d %d", &n, &first, &last, &q);
        Node all_elems[1000000];
        all_elems[0].index_next = first+1;
        all_elems[0].index_prev = last+1;
        next_free = n + 1;
        for (int i = 1; i <= n; i++){
            scanf("%d %d %d", &all_elems[i].value, &all_elems[i].index_next, &all_elems[i].index_prev);
            all_elems[i].index_next++;
            all_elems[i].index_prev++;
        }
        all_elems[all_elems[0].index_next].index_prev = 0;
        all_elems[all_elems[0].index_prev].index_next = 0;
        for (int i = 0; i < q; i++){
            int operation, index_operation, new_value;
            scanf("%d %d", &operation, &index_operation);
            index_operation++;
            if (operation == 1){
                all_elems[next_free].index_next = all_elems[index_operation].index_next;
                all_elems[next_free].index_prev = index_operation;
                all_elems[all_elems[index_operation].index_next].index_prev = next_free;
                all_elems[index_operation].index_next = next_free;
                scanf("%d", &new_value);
                all_elems[next_free].value = new_value;
                printf("%d\n", next_free-1);
                next_free++;  
            }
            else if (operation == -1){
                all_elems[next_free].index_next = index_operation;
                all_elems[next_free].index_prev = all_elems[index_operation].index_prev;
                all_elems[all_elems[index_operation].index_prev].index_next = next_free;
                all_elems[index_operation].index_prev = next_free;
                scanf("%d", &new_value);
                all_elems[next_free].value = new_value;
                printf("%d\n", next_free - 1);
                next_free++;
            }
            else {
                printf("%d\n",all_elems[index_operation].value);
                all_elems[all_elems[index_operation].index_next].index_prev = all_elems[index_operation].index_prev;
                all_elems[all_elems[index_operation].index_prev].index_next = all_elems[index_operation].index_next;
            }
        }
        printf("%s\n", "===");
        for (int x = all_elems[0].index_next; x > 0; x = all_elems[x].index_next){
            printf("%d\n", all_elems[x].value);
        }
        printf("%s\n", "===");
    }
    fclose(stdin);
    fclose(stdout);
}