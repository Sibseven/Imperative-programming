#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_S{
    char value[8];
    struct Node_S *next_node;
} Node;
typedef struct Node_list_S{
    struct Node_S* first;
    struct Node_S* last;
} Node_list;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    Node_list **all_lists = malloc(sizeof(Node_list*)* 1000002);
    scanf("%d", &n);
    int index;
    char value[8];
    for (int i = 0; i < 1000001; i++){
        Node_list* new = malloc(sizeof(Node_list));
        all_lists[i] = new;
        all_lists[i]->first = NULL;
    }
    
    for(int i = 0; i < n; i++){
        scanf("%d %s", &index, value);
        if (all_lists[index]->first == NULL){
            Node *new_node = malloc(sizeof(Node));
            all_lists[index]->first = new_node;
            all_lists[index]->last = new_node;
            new_node->next_node = NULL;
            strcpy(new_node->value, value);
        }
        else{
            Node *new_node = malloc(sizeof(Node));
            all_lists[index]->last->next_node = new_node;
            new_node->next_node = NULL;
            all_lists[index]->last = new_node;
            strcpy(new_node->value, value);
        }
    }
    for (int i = 0; i < 1000001; i++){
        if (all_lists[i]->first == NULL){
            continue;
        }
        else{
            Node *cur = all_lists[i]->first;
            Node *cur2 = all_lists[i]->first;
            while (cur != NULL){
                printf("%d %s\n", i, cur->value);
                cur = cur->next_node;
                free(cur2);
                cur2 = cur;
            }   
        }
        free(all_lists[i]);
    }
    free(all_lists);
    fclose(stdin);
    fclose(stdout);
    return 0;
}