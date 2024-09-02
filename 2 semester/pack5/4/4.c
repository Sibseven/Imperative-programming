#include <stdio.h>
#include <stdlib.h>
int stack[100010];
int top = -1;
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

void topological_sort(int vert, Vector* graph, int* visited) {
    for(int i = 1; i < vert+1; i++) {
        if(!visited[i]) {
            dfs(graph, i, visited);
        }
    }
    
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int vert, edges;
    scanf("%d %d", &vert, &edges);
    Vector* graph_list = calloc(vert+10,sizeof(Vector));
    for(int i = 0; i < edges; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        add_vect(&graph_list[from], to);
    }
    int* visited = calloc(vert+5, sizeof(int));
    topological_sort(vert, graph_list, visited);
    if (top != vert - 1) {
      printf("NO");
      return 0;
    }

    int*sol = calloc(vert+5, sizeof(int));
    
    int now_sol = 1;
    for(int i = top; i >= 0; i--) {
        sol[stack[i]] = now_sol;
        now_sol++;
    }
    for(int i = 1; i<vert+1; i++){
        for(int j = 0; j < graph_list[i].next_free; j++){
            if(sol[i] >= sol[graph_list[i].Vert_arr[j]]){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES\n");
    for(int i = 1; i < vert+1; i++){
        printf("%d ", sol[i]);
    }
    free(visited);
    for(int i = 1; i< vert+1; i++){
        clear_vect(&graph_list[i]);
    }
    free(graph_list);
    free(sol);
}