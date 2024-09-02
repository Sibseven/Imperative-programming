#include "sol.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct vector{
    Edge **edge_arr;  //указатель на массив, выделенный на куче
    int next_free;      // номер следующего свободного элемента    
    int cap;            //сколько выделено
} Vector;

void add_vect(Vector* vect, Edge* value){
    if(vect->cap == 0){
        vect->edge_arr = calloc(1, sizeof(Edge*));
        vect->cap = 1;
    }
    if(vect->next_free == vect->cap){
        vect->cap *= 2;
        vect->edge_arr = realloc(vect->edge_arr, sizeof(Edge*)*vect->cap);
    }
    vect->edge_arr[vect->next_free] = malloc(sizeof(Edge));
    vect->edge_arr[vect->next_free]->from = value->from;
    vect->edge_arr[vect->next_free]->to = value->to;
    vect->edge_arr[vect->next_free]->weight = value->weight;
    vect->next_free++;
}
void clear_vect(Vector* vect){
    for(int i = 0; i< vect->next_free; i++){
        free(vect->edge_arr[i]);
    }
    free(vect->edge_arr);
}

// int getVerticesCount (){
//     return 5;
// }

// int froms[7];
// int tos[7];
// int weights[7];
// int now = 0;
// int readEdge(Edge *oEdge){
//     if(now == 6){
//         return 0;
//     }
//     oEdge->from = froms[now];
//     oEdge->to = tos[now];
//     oEdge->weight = weights[now];
//     now++;
//     return 1;
// }
Vector* graph;

void init (){
    int n = getVerticesCount();
    graph = calloc(n,sizeof(Vector));
    Edge nowEdge = {0};
    int now = 0;
    for(int i = readEdge(&nowEdge); i != 0; i = readEdge(&nowEdge)){
        add_vect(&graph[nowEdge.from], &nowEdge);
        int temp = nowEdge.from;
        nowEdge.from = nowEdge.to;
        nowEdge.to = temp;
        add_vect(&graph[nowEdge.from], &nowEdge);
    }
}
int getEdgesCount(int iVertex ){
    return(graph[iVertex].next_free);
}

Edge getIncidentEdge(int iVertex , int iIndex ){
    return(*graph[iVertex].edge_arr[iIndex]);
}

// int main(){
//     froms[0] = 0;
//     froms[1] = 3;
//     froms[2] = 1;
//     froms[3] = 2;
//     froms[4] = 4;
//     froms[5] = 4;
//     tos[0] = 2;
//     tos[1] = 4;
//     tos[2] = 1;
//     tos[3] = 0;
//     tos[4] = 1;
//     tos[5] = 1;
//     weights[0] = 178;
//     weights[1] = 207;
//     weights[2] = 356;
//     weights[3] = 101;
//     weights[4] = 286;
//     weights[5] = 213;
//     init();
//     printf("%d\n", getEdgesCount(0));
//     printf("%d\n", getEdgesCount(1));
//     printf("%d\n", getEdgesCount(2));
//     printf("%d\n", getEdgesCount(3));
//     printf("%d\n", getEdgesCount(4));
// }