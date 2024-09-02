#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vert, edges;


void print_graph(int** graph){
    printf("\n");
    for(int i = 1; i<=vert; i++){
        for (int j = 1; j <= vert; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");  
    }
}
void Floid_woyrshall(int **graph, int** next_vert){
    for(int inter = 1; inter <= vert; inter++){
        for(int from = 1; from <= vert; from++){
            for(int to = 1; to <= vert; to++){
                if(graph[from][to] > graph[from][inter] + graph[inter][to]){
                    graph[from][to] = graph[from][inter] + graph[inter][to];
                    next_vert[from][to] = next_vert[from][inter]; 
                }
            }
        }
    }
}
int main(){
    int req_path, req_time;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d %d", &vert, &edges, &req_path, &req_time);
    int **next_vert =(int**) malloc(sizeof(int*)*(vert+5));
    int **graph = (int**) malloc(sizeof(int*)*(vert+5));
    for(int i = 1; i < vert+1; i++){
        next_vert[i] =(int*)calloc((vert+5), sizeof(int));
        graph[i] =(int*)calloc((vert+5), sizeof(int));
        for(int j = 1; j <= vert; j++){
            graph[i][j] = 100000000;
        }
    }
    // print_graph(graph);
    // print_graph(next_vert);
    for(int i = 0; i < edges; i++){
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        if( graph[from][to] > weight){
            graph[from][to] = weight;
        }
        if( graph[to][from] > weight){
            graph[to][from] = weight;
        }
        
        next_vert[from][to] = to;//считываем граф, инициализируем массив след.вершин
        next_vert[to][from] = from;
    }
    Floid_woyrshall(graph, next_vert);
    for(int i = 0; i< req_path; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        printf("%d", graph[from][to]);
        int now_path[400] = {0};
        int now_in_path = 0;
        now_path[now_in_path] = from;
        now_in_path++;
        while (from != to){
            from = next_vert[from][to];
            now_path[now_in_path] = from;
            now_in_path++;
        }
        printf(" %d", now_in_path);
        for(int j = 0; j <now_in_path; j++){
            printf(" %d", now_path[j]);
        }
        printf("\n");
    }
    for(int i = 0; i < req_time; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        printf("%d\n", graph[from][to]);
    }
    for(int i = 1; i <= vert; i++){
        free(next_vert[i]);
        free(graph[i]);
    }
    free (next_vert);
    free(graph);
    return 0;
}