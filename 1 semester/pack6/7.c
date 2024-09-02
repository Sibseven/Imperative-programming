#include <stdio.h>


typedef struct Node_s {
    struct Node_s * prev , * next ;
    void * value ;
} Node ;
typedef Node List ; //List –- вспомогательный узел, являющийся головой списка

void initList ( List * list ); //инициализирует поля структуры *list значениями для пустого списка


//создаёт новый узел со значением ptr и вставляет его после узла node
//возвращает указатель на созданный узел
Node * addAfter ( Node * node , void * ptr );
//создаёт новый узел со значением ptr и вставляет его перед узлом node
//возвращает указатель на созданный узел
Node * addBefore ( Node * node , void * ptr );
//удаляет заданный узел, возвращая значение, которое в нём лежало
void * erase ( Node * node );

int main(){
    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++){
        int q;
        scanf("%d", &q);
        for (int i = 0; i < 0; i++){
            
        }
    }
}