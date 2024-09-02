#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vert, edges;
int stack[100010];
int top = -1;
int cnt = 1;
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
void dfs(Vector* graph, int start, int *visited){
    visited[start] = 1;
    for(int i = 0; i < graph[start].next_free; i++){
        if(visited[graph[start].Vert_arr[i]] == 0){
            dfs(graph, graph[start].Vert_arr[i], visited);
        }   
    }
    stack[++top] = start;
}
void dfs2(Vector* graph, int start, int *visited, int* colors){
    visited[start] = 1;
    for(int i = 0; i < graph[start].next_free; i++){
        if(visited[graph[start].Vert_arr[i]] == 0){
            dfs2(graph, graph[start].Vert_arr[i], visited, colors);
        }   
    }
    colors[start] = cnt;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &vert, &edges);

    Vector* graph_list = calloc(vert+10,sizeof(Vector));
    Vector* graph_list_trans = calloc(vert+10,sizeof(Vector));
    for(int i = 0; i < edges; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        add_vect(&graph_list[from], to);
        add_vect(&graph_list_trans[to], from);
    }
    int visited[100001] = {0};
    for(int i = 1; i <= vert; i++){
        if(visited[i] == 0){
            dfs(graph_list, i, visited);
        }
    }
    memset(visited, 0x00, sizeof(visited));
    int colors[100001] = {0};
    for(int i = top; i >= 0; i--){
        if(visited[stack[i]] == 0){
            dfs2(graph_list_trans, stack[i], visited, colors);
            cnt++;
        }
    }
    printf("%d\n", cnt-1);
    for(int i = 1; i <= vert; i++){
        printf("%d ", colors[i]);
    }
    for(int i = 1; i< vert+1; i++){
        clear_vect(&graph_list[i]);
        clear_vect(&graph_list_trans[i]);
    }
    free(graph_list);
    free(graph_list_trans);
}