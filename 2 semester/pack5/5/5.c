#include <stdio.h>
#include <stdlib.h>
int stack[200010];
int top = -1;
int is_found = 0;
int vert, edges;
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
void find_cycle(Vector* graph,int start, int now, int* visited){
    stack[++top] = now;
    visited[now] = 1;
    if(is_found){
        return;
    }
    for(int i = 0; i < graph[now].next_free; i++){
        if(visited[graph[now].Vert_arr[i]] == 1 && top >= 0){
            if(is_found){
                return;
            }
            is_found = 1;
            int cnt = 1;
            int now_in_stack = 0;
            for(int j = 0; j<=top; j++){
                if(stack[j] == graph[now].Vert_arr[i]){
                    now_in_stack = j;
                    break;
                }
            }
            cnt = top-now_in_stack+1;
            printf("%d\n", cnt);
            for(int j = now_in_stack; j <= top; j++){
                printf(" %d", stack[j]);
            }

            return;
        }
        if(visited[graph[now].Vert_arr[i]] == 0){
            find_cycle(graph, now, graph[now].Vert_arr[i], visited);
        }
    }
    visited[now] = 2;
    top--;
}



int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &vert, &edges);
    Vector* graph_list = calloc(vert+10,sizeof(Vector));
    for(int i = 0; i < edges; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        add_vect(&graph_list[from], to);
    }
    int *visited = calloc(vert+10, sizeof(int));
    for(int i = 1; i < vert+1; i++){
        top = -1;
        if(visited[i] == 0){
            find_cycle(graph_list, i, i, visited);
        }
        if (is_found){
            break;
        }
    }

    if(is_found == 0){
        printf("-1\n");
    }

    free(visited);
    for(int i = 1; i< vert+1; i++){
        clear_vect(&graph_list[i]);
    }
    free(graph_list);
    return 0;
}