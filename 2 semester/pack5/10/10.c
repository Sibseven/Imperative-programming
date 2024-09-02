#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vert, edges;
int cnt = 0;
int time = 0;
int res1[100000] = {0};
typedef struct Edge
{
    int to;
    int number;
    int type;
} Edge;

typedef struct vector{
    Edge *edge_arr;  //указатель на массив, выделенный на куче
    int next_free;      // номер следующего свободного элемента    
    int cap;            //сколько выделено
} Vector;

int cmp(const void * a, const void * b) {
  int *ia = (int *)a;
  int *ib = (int *)b;
  if(*ia > *ib){
    return 1;
  }
  else if(*ia < *ib){
    return -1;
  }
  else{
    return 0;
  }
}
void add_vect(Vector* vect, int to, int number){
    if(vect->cap == 0){
        vect->edge_arr = calloc(11, sizeof(Edge));
        vect->cap = 10;
    }
    if(vect->next_free == vect->cap){
        vect->cap *= 2;
        vect->edge_arr = realloc(vect->edge_arr, sizeof(Edge)*vect->cap+2);
    }
    vect->edge_arr[vect->next_free].to = to;
    vect->edge_arr[vect->next_free].number = number;
    vect->next_free++;
}
void clear_vect(Vector* vect){
    if(vect->cap != 0){
        free(vect->edge_arr);
    }
}
void dfs(Vector* graph, int start,int parent, int *visited, int* level, int* up){
    visited[start] = 1;
    level[start] = time;
    up[start] = time;
    time++;
    for(int i = 0; i < graph[start].next_free; i++){
        if(parent == graph[start].edge_arr[i].to){
            continue;
        }
        if(visited[graph[start].edge_arr[i].to] == 1){
            graph[start].edge_arr[i].type = 0; // ребро обратное
            // for(int j = 0; j < graph[graph[start].edge_arr[i].to].next_free; j ++){ // помечаем обратным его близнеца
            //     if(graph[graph[start].edge_arr[i].to].edge_arr[j].to == start){
            //         graph[graph[start].edge_arr[i].to].edge_arr[j].type = 0;
            //     }
            // }
            if (up[start] > level[graph[start].edge_arr[i].to]){
                up[start] = level[graph[start].edge_arr[i].to];
            }
        }
        if(visited[graph[start].edge_arr[i].to] == 0){
            graph[start].edge_arr[i].type = 1; // ребро корневое 
            int krat = 0;
            for(int j = 0; j < graph[graph[start].edge_arr[i].to].next_free; j ++){ // помечаем корневым его близнеца
                if(krat > 1){
                    break;
                }
                if(graph[graph[start].edge_arr[i].to].edge_arr[j].to == start){
                    graph[graph[start].edge_arr[i].to].edge_arr[j].type = 1;
                    krat++;
                }
                
            }
            if(krat != 1){
                graph[start].edge_arr[i].type = 2;
            }
            dfs(graph, graph[start].edge_arr[i].to, start, visited, level, up);
            if (up[start] > up[graph[start].edge_arr[i].to]){
                up[start] = up[graph[start].edge_arr[i].to];
            }
            if(level[start] < up[graph[start].edge_arr[i].to] && graph[start].edge_arr[i].type == 1){

                res1[cnt] = graph[start].edge_arr[i].number;
                cnt++;
            }
        }
        
    }

}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &vert, &edges);
    int num = 1;
    Vector* graph_list = calloc(vert+10,sizeof(Vector));
    for(int i = 0; i < edges; i++){
        int from, to, maxx;
        scanf("%d %d", &from, &to);
        // if (graph_list[from].next_free > graph_list[to].next_free ){
        //     maxx = graph_list[to].next_free;
        // }
        // else {
        //     maxx = graph_list[from].next_free;
        // }
        // int flag = 0;
        // for(int j = 0; i < maxx; i++){
        //     if(graph_list[from].edge_arr[i].to == to || graph_list[to].edge_arr[i].to == from){
        //         flag = 1;
        //         break;
        //     }
        // }
        // if(flag){
        //     for(int j = )
        //     continue;
        // }
        add_vect(&graph_list[from], to, num);
        add_vect(&graph_list[to], from, num);
        num++;
    }
    int visited[100010] = {0};
    int level[100010] = {0};
    int up[100010] = {0};

    for(int i = 1; i <= vert; i++){
        if(visited[i] == 0){
            dfs(graph_list, i, 0, visited, level, up);
        }
        // memset(level, 0x00, sizeof(level));
        // memset(up, 0x00, sizeof(up));
        //time = 0;
    }
    qsort(res1, cnt, sizeof(int), cmp);
    printf("%d\n", cnt);
    for(int i = 0; i< cnt; i++){
        printf("%d ", res1[i]);
    }
    for(int i = 1; i< vert+1; i++){
        clear_vect(&graph_list[i]);
    }
    free(graph_list);
}