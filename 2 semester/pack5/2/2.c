#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    struct Node *front, *rear;
} Queue;


typedef struct vector{
    int *Vert_arr;  //указатель на массив, выделенный на куче
    int next_free;      // номер следующего свободного элемента    
    int cap;            //сколько выделено
} Vector;

void add_vect(Vector* vect, int value){
    if(vect->cap == 0){
        vect->Vert_arr = calloc(2, sizeof(int));
        vect->cap = 1;
    }
    if(vect->next_free == vect->cap){
        vect->cap *= 2;
        vect->Vert_arr = realloc(vect->Vert_arr, sizeof(int)*vect->cap+2);
    }
    vect->Vert_arr[vect->next_free] = value;
    vect->next_free++;
}
void clear_vect(Vector* vect){
    if(vect->cap != 0){
        free(vect->Vert_arr);
    }
    
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

void deQueue(struct Queue* q) {
    if (q->front == NULL) {
        return;
    }

    struct Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}
void clearQueue(struct Queue *queue) {
    while (queue->front != NULL) {
        struct Node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
}

void bfs_line(Vector* graph, int start, int* distances){
    Queue* queue = createQueue();
    enQueue(queue, start);
    while (queue->front != NULL){
        int now = queue->front->data;
        deQueue(queue);
        for(int i = 0; i<graph[now].next_free; i++){
            if(distances[graph[now].Vert_arr[i]] == -1){
                distances[graph[now].Vert_arr[i]] = distances[now] +1;
                enQueue(queue, graph[now].Vert_arr[i]);
            }
        }
    }
    clearQueue(queue);
    free(queue);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int vert, edges;
    scanf("%d %d", &vert, &edges);
    int *distances = calloc(vert+10,sizeof(int));
    for(int i = 0; i<vert+1; i++){
        distances[i] = -1;
    }
    distances[1] = 0;
    Vector* graph_list = calloc(vert+10,sizeof(Vector));
    for(int i = 0; i < edges; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        add_vect(&graph_list[from], to);
    }
    bfs_line(graph_list, 1, distances);
    for(int i = 1; i<vert+1; i++){
        printf("%d\n", distances[i]);
    }
    free(distances);
    for(int i = 0; i<vert+10; i++){
        clear_vect(&graph_list[i]);
    }
    free(graph_list);
    return 0;
}