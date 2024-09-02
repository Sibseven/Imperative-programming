#include "sol.h"
#include <stdlib.h>
// В sol.c нужно реализовать функции
//  init, getEdgesCount и getIncidentEdge
typedef struct Vector {
    Edge *arr;
    int cnt;            //сколько элементов в массиве реально есть
    int cap;            //на сколько элементов выделено место в блоке памяти arr (capacity)
} Vector;

Vector *mas;
Edge edge;

//=========================================5=====
//implement these functions in your solution:
//this function is called first to initialize graph
//you are expected to read graph here and fill internal data structures
int getVerticesCount (){
    return 5;
}

int froms[7];
int tos[7];
int weights[7];
int now = 0;
int readEdge(Edge *oEdge){
    if(now == 6){
        return 0;
    }
    oEdge->from = froms[now];
    oEdge->to = tos[now];
    oEdge->weight = weights[now];
    now++;
    return 1;
}

void init()
{
    int n = getVerticesCount();
    Vector *mas = calloc(n, sizeof(Vector));
    int start = 0, end = 0;
    while (readEdge(&edge) == 1)
    {
        start = edge.from;
        end = edge.to;
        
        if (mas[start].cnt == 0)
        {
            mas[start].cap = 2;
            mas[start].arr = calloc(mas[start].cap, sizeof(Edge));
        }
        if (mas[end].cnt == 0)
        {
            mas[end].cap = 2;
            mas[end].arr = calloc(mas[end].cap, sizeof(Edge));
        }

        if (mas[start].cap >= mas[start].cnt + 2) // если влезает
        {
            mas[start].arr[mas[start].cnt].from = start;    // mas[start].arr[mas[start].cnt++] = edge;
            mas[start].arr[mas[start].cnt].to = end;
            mas[start].arr[mas[start].cnt++].weight = edge.weight;
        } else // иначе добавляем память
        {
            mas[start].cap *= 2;
            mas[start].arr = realloc(mas[start].arr, mas[start].cap * sizeof(Edge));
            mas[start].arr[mas[start].cnt].from = start;    //
            mas[start].arr[mas[start].cnt].to = end;
            mas[start].arr[mas[start].cnt++].weight = edge.weight;  
        }

            /*int ildar = 0; // меняем местами вершинки
            ildar = edge.from;
            edge.from = edge.to;
            edge.to = ildar;*/
        if (mas[end].cap >= mas[end].cnt + 2) // если влезает
        {
            mas[end].arr[mas[end].cnt].from = end;    //
            mas[end].arr[mas[end].cnt].to = start;
            mas[end].arr[mas[end].cnt++].weight = edge.weight;  
        } else // иначе добавляем память
        {
            mas[end].cap *= 2;
            mas[end].arr = realloc(mas[end].arr, mas[end].cap * sizeof(Edge));
            mas[end].arr[mas[end].cnt].from = end;    //
            mas[end].arr[mas[end].cnt].to = start;
            mas[end].arr[mas[end].cnt++].weight = edge.weight; 
        }
    }
}

//returns number of edges indicent to vertex iVertex
int getEdgesCount(int iVertex)
{
    
    return mas[iVertex].cnt;
}
//returns iIndex-th edge incident to the vertex iVertex
//it must have .from == Vertex and .to denoting the other end
Edge getIncidentEdge(int iVertex, int iIndex)
{
    Edge curr;
    curr.from = iVertex;
    curr.to = mas[iVertex].arr[iIndex].to;
    curr.weight = mas[iVertex].arr[iIndex].weight;
    return curr;
}

int main(){
    froms[0] = 0;
    froms[1] = 3;
    froms[2] = 1;
    froms[3] = 2;
    froms[4] = 4;
    froms[5] = 4;
    tos[0] = 2;
    tos[1] = 4;
    tos[2] = 1;
    tos[3] = 0;
    tos[4] = 1;
    tos[5] = 1;
    weights[0] = 178;
    weights[1] = 207;
    weights[2] = 356;
    weights[3] = 101;
    weights[4] = 286;
    weights[5] = 213;
    init();
    printf("%d\n", getEdgesCount(0));
    printf("%d\n", getEdgesCount(1));
    printf("%d\n", getEdgesCount(2));
    printf("%d\n", getEdgesCount(3));
    printf("%d\n", getEdgesCount(4));
}