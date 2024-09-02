#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 10000
int cnt = 0;
typedef struct vector{
    int *Vert_arr;  //указатель на массив, выделенный на куче
    int next_free;      // номер следующего свободного элемента    
    int cap;            //сколько выделено
} Vector;

void add_vect(Vector* vect, int value){
    if(vect->cap == 0){
        vect->Vert_arr = calloc(11, sizeof(int));
        vect->cap = 10;
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
Vector L[MAXN];

int mt[MAXN];
int visited[MAXN];

int dfs(int u){
    if(visited[u]){
        return 0;
    }
    visited[u] = 1;
    for(int i = 0; i < L[u].next_free; i++){
        int to = L[u].Vert_arr[i];
        if(mt[to] == -1 || dfs(mt[to]) == 1){ // mt[to] = -1 изначально, второе условие нашли увеличивающий путь 
            mt[to] = u;
            return 1;
        }
    }
    return 0;
}

void matching(){
    memset(mt, -1, sizeof(mt));
    for(int i = 1; i <= N; i++){
        memset(visited, 0, sizeof(visited));
        cnt+= dfs(i);
    }
}