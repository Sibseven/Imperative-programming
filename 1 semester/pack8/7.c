#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
    struct Node *prev , *next;
    double value;
} Node;

double *initList (){
    Node* head = calloc(1, sizeof(Node));
    head->value = 0;
    head->next = head;
    head->prev = head;
    return &(head->value);
} //создаёт пустой список и возвращает указатель на value в голове списка (вспом. узел)

void freeList(double *head){
    Node* p_head = (Node*)(head - (offsetof(struct Node, value)/8));
    Node* p_now = p_head->next;
    while (p_now != p_head){
        Node* temp = p_now;
        p_now = p_now->next;
        free(temp);
    }
    free(p_head);
    
} //полностью освобождает память списка и принимает указатель на value голове списка (вспом. узел)

double *getNext(double* curr){
    Node* p_curr = (Node*)(curr - (offsetof(struct Node, value)/8));
    return &(p_curr->next->value);
} //определяет следующий элемент после заданного (для вспом. узла возвращает первый элемент)

double *getPrev(double* curr){
    Node* p_curr = (Node*)(curr - (offsetof(struct Node, value)/8));
    return &(p_curr->prev->value);
} //определяет предыдущий элемент перед заданным для вспом. узла возвращает последний элемент)

double *addAfter(double* where , double newval ){
    Node* p_curr = (Node*)(where - (offsetof(struct Node, value)/8));
    Node* new_node = calloc(1, sizeof(Node));
    new_node->value = newval;
    new_node->prev = p_curr;
    new_node->next = p_curr->next;
    p_curr->next->prev = new_node;
    p_curr->next = new_node;
    return &(new_node->value);
} //создаёт и вставляет узел со значением newval сразу после узла where

double *addBefore(double* where , double newval ){
    Node* p_curr = (Node*)(where - (offsetof(struct Node, value)/8));
    Node* new_node = calloc(1, sizeof(Node));
    new_node->value = newval;
    new_node->prev = p_curr->prev;
    new_node->next = p_curr;
    p_curr->prev->next = new_node;
    p_curr->prev = new_node;
    return &(new_node->value);
} //создаёт и вставляет узел со значением newval сразу перед узлом where

void erase(double* what){
    Node* p_curr = (Node*)(what - (offsetof(struct Node, value)/8));
    printf("%0.3lf\n", *what);
    p_curr->prev->next = p_curr->next;
    p_curr->next->prev = p_curr->prev;
    free(p_curr);
} //удаляет и освобождает заданный узел


int main(){
    FILE *inputt = freopen("input.txt", "rb", stdin);
    FILE *output = freopen("output.txt", "w", stdout);
    int test = 0;
    scanf("%d", &test);
    
    // Node sample;
    // sample.next = calloc(1, sizeof(Node));
    // sample.next->value = 1.444;
    // sample.prev = calloc(1, sizeof(Node));
    // sample.prev->value = 1.546;
    // sample.value = 1.123;
    // Node* point = (Node*)(&sample.value - (offsetof(struct Node, value)/8));
    // printf("%p\n", &sample);
    // printf("%f", point->value);
    for (int te = 0; te < test; te++){
        int num_operations = 0;
        scanf("%d", &num_operations);
        double* head = initList();
        double* all_nodes[1000001] ={0};
        int next_free = 0;
        for (int i = 0; i < num_operations; i++){
            int now_operation = 0;
            scanf("%d", &now_operation);
            if (now_operation == 1){
                int index_operation = 0;
                double value_in = 0;
                scanf("%d", &index_operation);
                scanf("%lf", &value_in);
                if (index_operation == -1){
                    all_nodes[next_free] = addAfter(head, value_in);
                    next_free++;
                }
                else {
                    all_nodes[next_free] = addAfter(all_nodes[index_operation], value_in);
                    next_free++;
                }
            }
            else if (now_operation == -1){
                int index_operation = 0;
                double value_in = 0;
                scanf("%d", &index_operation);
                scanf("%lf", &value_in);
                if (index_operation == -1){
                    all_nodes[next_free] = addBefore(head, value_in);
                    next_free++;
                }
                else {
                    all_nodes[next_free] = addBefore(all_nodes[index_operation], value_in);
                    next_free++;
                }
            }
            else{
                int index_operation = 0;
                scanf("%d", &index_operation);
                if (index_operation == -1){
                    erase(getNext(head));
                }
                else {
                    erase(all_nodes[index_operation]);
                }
            }
        }
        printf("===\n");
        for (double* curr_print = getNext(head); curr_print != head; curr_print = getNext(curr_print)){
            printf("%0.3lf\n",*curr_print);
        }
        freeList(head);
        printf("===\n");
        
    }
    fclose(inputt);
    fclose(output);
}