#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 100010
int vert, edges;
int vert2heap[MAX_N];
typedef struct Edge
{
    int to;
    int weight;
    int number;
} Edge;

typedef struct vector{
    Edge *edge_arr;  //указатель на массив, выделенный на куче
    int next_free;      // номер следующего свободного элемента    
    int cap;            //сколько выделено
} Vector;

void add_vect(Vector* vect, int to, int weight, int number){
    if(vect->cap == 0){
        vect->edge_arr = calloc(11, sizeof(Edge));
        vect->cap = 10;
    }
    if(vect->next_free == vect->cap){
        vect->cap *= 2;
        vect->edge_arr = realloc(vect->edge_arr, sizeof(Edge)*vect->cap+2);
    }
    vect->edge_arr[vect->next_free].to = to;
    vect->edge_arr[vect->next_free].weight = weight;
    vect->edge_arr[vect->next_free].number = number;
    vect->next_free++;
}
void clear_vect(Vector* vect){
    if(vect->cap != 0){
        free(vect->edge_arr);
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp; 
}

int heapTop = 1;
int heap[MAX_N];

void siftUp(int now, long long* distances){
    int parent = now/2;
    while( distances[heap[parent]] > distances[heap[now]] && parent != 0){
        swap(&vert2heap[heap[now]], &vert2heap[heap[parent]]);
        swap(&heap[now], &heap[parent]);
        now = parent;
        parent /= 2;
    }
}
void siftDown(int now, long long* distances){
    int left = 2*now;
    int right = left + 1;
    while (left < heapTop){
        int choice = now;
        if ( left < heapTop && distances[heap[left]] < distances[heap[choice]]){
            choice = left;
        }
        if (right < heapTop && distances[heap[right]] < distances[heap[choice]]){
            choice = right;
        }
        if( choice == now){
            break;
        }
        swap(&vert2heap[heap[now]], &vert2heap[heap[choice]]);
        swap(&heap[now], &heap[choice]);
        now = choice;
        left = 2*now;
        right = 2*now +1;
    }
}

void heap_insert(int value, long long* distances){
    heap[heapTop] = value;
    vert2heap[value] = heapTop;
    siftUp(heapTop, distances);
    heapTop++;
}

int heap_extract(long long* distances){
    heapTop --;
    int val = heap[1];
    heap[1] = heap[heapTop];
    vert2heap[heap[1]] = 1;
    siftDown(1, distances);
    return val;
}
void Deiks(Vector *graph, int start, int* parents, long long* distances, int* flyes){
    memset(distances, 0x3f, sizeof(long long)*MAX_N);
    memset(flyes, 0x00, sizeof(int)*MAX_N);
    memset(parents, 0x00, sizeof(int)*MAX_N);
    distances[start] = 0;
    for(int i = 1; i <= vert; i++){
        heap_insert(i, distances);
    }
    while(heapTop != 1){
        int min_index = heap_extract(distances);
        for(int i = 0; i < graph[min_index].next_free; i++){
            int test = distances[graph[min_index].edge_arr[i].to];
            int from = distances[min_index];
            int weight = graph[min_index].edge_arr[i].weight;
            if (distances[graph[min_index].edge_arr[i].to] > distances[min_index] + graph[min_index].edge_arr[i].weight){
                distances[graph[min_index].edge_arr[i].to] = distances[min_index] + graph[min_index].edge_arr[i].weight;
                parents[graph[min_index].edge_arr[i].to] = min_index;
                flyes[graph[min_index].edge_arr[i].to] = graph[min_index].edge_arr[i].number;
                siftUp(vert2heap[graph[min_index].edge_arr[i].to], distances);
            }
        }
    }

}
int main(){
    int req_path;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d", &vert, &edges, &req_path);
    int friends[60] = {0};
    int to[60] = {0};
    for(int i = 0; i < req_path; i++){
        scanf("%d %d", &friends[i], &to[i]);
    }
    Vector* graph_list = calloc(vert+10,sizeof(Vector));
    for(int i = 0; i < edges; i++){
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        add_vect(&graph_list[from], to, weight, i+1);
    }
    int parents[MAX_N] = {0};
    long long distances[MAX_N] = {0};
    int flyes[MAX_N] = {0};
    for(int i = 0; i < req_path; i++){
        Deiks(graph_list, friends[i], parents, distances, flyes);
        if(distances[to[i]] == 0x3f3f3f3f3f3f3f3f){
            printf("DOOMED\n");
            continue;
        }
        int path[MAX_N] = {0};
        
        path[0] = flyes[to[i]];
        int now_in_path = 1;
        int src = parents[to[i]];
        while (src != friends[i]){
            path[now_in_path] = flyes[src];
            src = parents[src];
            now_in_path++;
        }

        printf("quarantine %lld %d", distances[to[i]], now_in_path);
        for(int j = now_in_path - 1; j>= 0; j--){
            printf(" %d", path[j]);
        }
        printf("\n");
    }
    for(int i = 1; i< vert+1; i++){
        clear_vect(&graph_list[i]);
    }
    free(graph_list);
    return 0;
}