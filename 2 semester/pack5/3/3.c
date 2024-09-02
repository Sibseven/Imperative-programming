#include <stdio.h>
#include <stdlib.h>
int rows, columns;
typedef struct Node {
    int row, column;
    struct Node *next;
} Node;

typedef struct Queue {
    struct Node *front, *rear;
} Queue;

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int row, int column) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->column = column;
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
void print_graph(int** graph){
    printf("\n");
    for(int i = 0; i<rows; i++){
        for (int j = 0; j < columns; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");  
    }
}
void bfs_line(int** graph, int start_row, int start_column){
    Queue* queue = createQueue();
    enQueue(queue, start_row, start_column);
    while (queue->front != NULL){
        int now_row = queue->front->row;
        int now_column = queue->front->column;
        deQueue(queue);
        if(now_column-1 >=0 && graph[now_row][now_column-1] == -1 ){
            enQueue(queue, now_row, now_column-1);
            graph[now_row][now_column-1] = graph[now_row][now_column]+1;
        }
        if(now_column+1 < columns && graph[now_row][now_column+1] == -1){
            enQueue(queue, now_row, now_column+1);
            graph[now_row][now_column+1] = graph[now_row][now_column]+1;
        }
        if(now_row-1 >=0 && graph[now_row-1][now_column] == -1 ){
            enQueue(queue, now_row-1, now_column);
            graph[now_row-1][now_column] = graph[now_row][now_column]+1;
        }
        if(now_row+1 < rows && graph[now_row+1][now_column] == -1){
            enQueue(queue, now_row+1, now_column);
            graph[now_row+1][now_column] = graph[now_row][now_column]+1;
        }
    }
    clearQueue(queue);
    free(queue);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d\n", &rows, &columns);
    int** labirint = (int**) malloc(sizeof(int*)*(rows+5));
    for(int i = 0; i < rows; i++){
        labirint[i] =(int*) malloc(sizeof(int)*(columns+5));
    }
    char now_input[130] = {0};
    int f_row, f_column, s_column, s_row;
    int flag = 0;
    for(int i = 0; i < rows; i++){
        fgets(now_input, 129, stdin);
        for(int j = 0; j<columns; j++){
            if(now_input[j] == '.'){
                labirint[i][j] = -1;
            }
            if(now_input[j] == 'X'){
                labirint[i][j] = -3;
            }
            if(now_input[j] == 'S'){
                flag += 1;
                labirint[i][j] = 0;
                s_row = i;
                s_column = j;
            }
            if(now_input[j] == 'F'){
                flag+= 1;
                labirint[i][j] = -1;
                f_row = i;
                f_column = j;
            }
        }
    }
    bfs_line(labirint, s_row, s_column);
    printf("%d", labirint[f_row][f_column]);
    for(int i = 0; i < rows; i++){
        free(labirint[i]);
    }
    free (labirint);
    return 0;
}