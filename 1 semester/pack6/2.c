#include <stdio.h>
#include <string.h>

typedef struct elem_list{
    char value[10];
    int next_index;    
} elem_list;

void add_elem(char *value, int insert_after, int free_space, elem_list* all_elems){
    all_elems[free_space].next_index = all_elems[insert_after].next_index;
    all_elems[insert_after].next_index = free_space;
    strcpy(all_elems[free_space].value, value);
    printf("%d\n", free_space);
}
void remove_elem(elem_list* all_elems, int index_delete){
    printf("%s\n", all_elems[all_elems[index_delete].next_index].value);
    all_elems[index_delete].next_index =  all_elems[all_elems[index_delete].next_index].next_index;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, n, q, f;
    scanf("%d", &t);
    for (int tests = 0; tests < t; tests++){// кол-во тестов
        scanf("%d %d %d", &n, &f, &q); // значения для текущего теста
        elem_list all_elems[500020]; 
        int next_free = n; // индекс следующего свободного элемента МАССИВА
        char value[10]; // локальные переменные 
        int index; // для индекса и значения
        for (int i = 0; i < n; i++){
            scanf("%s %d", value, &index); // считывание новых элементов
            strcpy(all_elems[i].value, value);
            all_elems[i].next_index = index;
        }
        int operation, index_operation;
        char new_value[10];
        for (int i = 0; i < q; i++){ // обработка команд
            scanf("%d", &operation); 
            if (operation == 0){ // добавление узла
                scanf("%d", &index_operation);
                scanf("%s", new_value);
                if (index_operation == -1){// добавление в начало
                    all_elems[next_free].next_index = f;
                    strcpy(all_elems[next_free].value, new_value);
                    f = next_free;
                    printf("%d\n", next_free);
                    next_free++; // смещение свободного индекса
                }
                else {
                    add_elem(new_value, index_operation, next_free, all_elems);
                    next_free++;
                }
            }
            else{
                scanf("%d", &index_operation);
                if (index_operation == -1){
                    printf("%s\n", all_elems[f].value);
                    f = all_elems[f].next_index;
                }
                else{
                    remove_elem(all_elems, index_operation);
                }
            }
        }
        printf("%s\n", "===");
        int end = f;
        for (int i = f; all_elems[i].next_index != -1; i = all_elems[i].next_index){
            printf("%s\n", all_elems[i].value);
            end = all_elems[i].next_index;
        }
        printf("%s\n", all_elems[end].value);
        printf("%s\n","===");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}