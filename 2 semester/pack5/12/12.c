#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vert, edges, check;
typedef struct Edge
{
    int to;
    long long weight;
} Edge;

typedef struct vector{
    Edge *edge_arr;  //указатель на массив, выделенный на куче
    int next_free;      // номер следующего свободного элемента    
    int cap;            //сколько выделено
} Vector;

void add_vect(Vector* vect, int to, long long weight){
    if(vect->cap == 0){
        vect->edge_arr = calloc(11, sizeof(Edge));
        vect->cap = 10;
    }
    if(vect->next_free == vect->cap){
        vect->cap *= 2;
        vect->edge_arr = realloc(vect->edge_arr, sizeof(Edge)*(vect->cap+2));
    }
    vect->edge_arr[vect->next_free].to = to;
    vect->edge_arr[vect->next_free].weight = weight;
    vect->next_free++;
}
void clear_vect(Vector* vect){
    if(vect->cap != 0){
        free(vect->edge_arr);
    }
}
void Ford(Vector *graph, int start, int* parents, long long* distances, int* negative){
    distances[start] = 0;
    for(int phase = 0; phase < vert - 1; phase++){
        for(int i = 1; i <= vert; i++){
            for(int j = 0; j< graph[i].next_free; j++){
                int to = distances[graph[i].edge_arr[j].to];
                int dist = distances[i];
                int weight = graph[i].edge_arr[j].weight;
                if(distances[graph[i].edge_arr[j].to] > distances[i] + graph[i].edge_arr[j].weight && distances[i] != 0x2e2e2e2e2e2e2e2e){
                    distances[graph[i].edge_arr[j].to] = distances[i] + graph[i].edge_arr[j].weight;
                    parents[graph[i].edge_arr[j].to] = i;
                }
            }
        }
    }
    for(int ph = 0; ph < vert - 1; ph++){
        for(int i = 1; i <= vert; i++){ // проход чтобы найти отрицательный цикл
            for(int j = 0; j< graph[i].next_free; j++){
                int to = distances[graph[i].edge_arr[j].to];
                int dist = distances[i];
                int weight = graph[i].edge_arr[j].weight;
                if(distances[graph[i].edge_arr[j].to] > distances[i] + graph[i].edge_arr[j].weight && distances[i] != 0x2e2e2e2e2e2e2e2e){
                    distances[graph[i].edge_arr[j].to] = distances[i] + graph[i].edge_arr[j].weight;
                    parents[graph[i].edge_arr[j].to] = i;
                    negative[graph[i].edge_arr[j].to] = 1;
                }
                if(negative[i] == 1){
                    negative[graph[i].edge_arr[j].to] = 1;
                }
            }
        }
    }
}
int main(){
    int req_path;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d\n", &vert, &edges, &req_path);
    Vector* graph_list = calloc(vert+10,sizeof(Vector));
    for(int i = 0; i < edges; i++){
        int from, to; 
        long long weight;
        scanf("%d %d %lld\n", &from, &to, &weight);
        add_vect(&graph_list[from], to, weight);
    }
    check = 0;
    int parents[5010] = {0};
    long long distances1[5010] = {0};
    int negative[5010] = {0};
    memset(distances1, 0x2e, sizeof(distances1));
    Ford(graph_list, req_path, parents, distances1, negative); // просто считаем пути  // находим негативные циклы 
    for(int i = 1; i <= vert; i++){
        if(distances1[i] == 0x2e2e2e2e2e2e2e2e){ // дистанция до вершины ни разу не поменялась, соответсвенно до нее не добраться
            printf("*\n");
            continue;
        }
        else if(negative[i] == 1){ // найден негативный цикл
            printf("-\n");
            continue;
        }
        else{
            printf("%lld\n", distances1[i]);
        }

    }
    for(int i = 1; i <= vert; i++){
        clear_vect(&graph_list[i]);
    }
    free(graph_list);
    return 0;
}