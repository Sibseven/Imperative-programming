#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vert, edges;
typedef struct Edge
{
    int to;
    int weight;
} Edge;

typedef struct vector{
    Edge *edge_arr;  //указатель на массив, выделенный на куче
    int next_free;      // номер следующего свободного элемента    
    int cap;            //сколько выделено
} Vector;

void add_vect(Vector* vect, int to, int weight){
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
    vect->next_free++;
}
void clear_vect(Vector* vect){
    if(vect->cap != 0){
        free(vect->edge_arr);
    }
}
void Ford(Vector *graph, int start, int* parents, int* distances){
    memset(distances, 0x3f, sizeof(int)*5009);
    distances[start] = 0;
    for(int phase = 0; phase < vert - 1; phase++){
        for(int i = 1; i <= vert; i++){
            for(int j = 0; j< graph[i].next_free; j++){
                if(distances[graph[i].edge_arr[j].to] > distances[i] + graph[i].edge_arr[j].weight){
                    distances[graph[i].edge_arr[j].to] = distances[i] + graph[i].edge_arr[j].weight;
                    parents[graph[i].edge_arr[j].to] = i;
                }
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
    for(int i = 0; i < req_path; i++){
        scanf("%d", &friends[i]);
    }
    Vector* graph_list = calloc(vert+10,sizeof(Vector));
    for(int i = 0; i < edges; i++){
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        add_vect(&graph_list[from], to, weight);
    }
    int parents[5010] = {0};
    int distances[5010] = {0};
    Ford(graph_list, 1, parents, distances);
    for(int i = 0; i < req_path; i++){
        int path[5009] = {0};
        path[0] = friends[i];
        int now_in_path = 1;
        int now = parents[friends[i]];
        // for(int i = 0; i < 10; i++){
        //     printf("%d ", distances[i]);
        // }
        // printf("\n");
        while (now != 1){
            path[now_in_path] = now;
            now = parents[now];
            now_in_path++;
        }
        path[now_in_path] = 1;
        now_in_path++;
        printf("%d %d", distances[friends[i]], now_in_path);
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