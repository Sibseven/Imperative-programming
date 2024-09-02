#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vert, edges;
typedef struct Edge
{
    int from;
    int to;
    int cap;
    int flow;
} Edge;

typedef struct Node {
    int vert;
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

void enQueue(struct Queue* q, int vert) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vert = vert;
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

int max_flow(int** Caps, int** Flows, int start, int finish, int* visited){
    int max_flow = 0;
    while (1){
        memset(visited, 0, sizeof(int)*119);
        visited[start] = 1;
        Queue* queue = createQueue();
        enQueue(queue, start);
        int fathers[120] = {0};
        while (queue->front != NULL){
            int u = queue->front->vert;
            deQueue(queue);
            for(int i = 1; i <= vert; i++){
                if (Caps[u][i] - Flows[u][i] > 0){
                    if (visited[i] == 0){
                        visited[i] = 1;
                        enQueue(queue, i);
                        fathers[i] = u;
                    }
                }
            }
        }
        if (visited[finish] == 0){
            break;
        }  
        int CP = 100000000;
        int x = finish;
        while (x != start){
            int y = fathers[x];
            if(CP > Caps[y][x] - Flows[y][x]){
                CP = Caps[y][x] - Flows[y][x];
            }
            x = y;
        }
        x = finish;
        while (x != start){
            int y = fathers[x];
            Flows[y][x] += CP;
            Flows[x][y] -= CP;
            x = y;
        }
        max_flow+= CP;
        clearQueue(queue);
    }
    return max_flow;
    
    
    
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int** Caps =(int **) malloc(sizeof(int*)*120);
    int** Flows =(int**) malloc(sizeof(int*)*120);
    int* visited =(int *) calloc(120,sizeof(int));
    scanf("%d %d", &vert, &edges);
    for(int i = 0; i <= vert; i++){
        Caps[i] = (int*) calloc(vert+2, sizeof(int));
        Flows[i] = (int*) calloc(vert+2, sizeof(int));
    }
    for(int i = 0; i < edges; i++){
        int from, to, cap;
        scanf("%d %d %d", &from, &to, &cap);
        Caps[from][to] = cap;
        Caps[to][from] = cap;
        // Flows[from][to] = cap;
        // Flows[to][from] = cap;
    }
    int res = max_flow(Caps, Flows, 1, vert, visited);
    // for(int i = 1; i <= vert; i++){
    //     for(int j = 1; j <= vert; j++){
    //         printf("%d ",Flows[i][j]);
    //     }
    // printf("\n");
    // }
    printf("%d", res);

    for(int i = 0; i <= vert; i++){
        free(Caps[i]);
        free(Flows[i]);
    }
    free(Caps); free(Flows); free(visited);
    fclose(stdin);
    fclose(stdout);
    return 0;
}