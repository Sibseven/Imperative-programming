#include <stdio.h>
#include <string.h>

typedef struct elem_list{
    char value[8];
    int next_index;    
} elem_list;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, n, q, f;
    scanf("%d", &t);
    for (int tests = 0; tests < t; tests++){// кол-во тестов
        scanf("%d %d %d", &n, &f, &q); // значения для текущего теста
        elem_list all_elems[200020]; 
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
                scanf("%d %s", &index_operation, new_value);
                if (index_operation == -1){// добавление в начало
                    all_elems[next_free].next_index = f;
                    strcpy(all_elems[next_free].value, new_value);
                    f = next_free;
                    printf("%d\n", next_free);
                    next_free++; // смещение свободного индекса
                }
                else {
                    all_elems[next_free].next_index = all_elems[index_operation].next_index;
                    all_elems[index_operation].next_index = next_free;
                    strcpy(all_elems[next_free].value, new_value);
                    printf("%d\n", next_free);
                    next_free++;
                }
            }
            else{
                scanf("%d", &index_operation);
                if (index_operation == -1){//удаление узла
                    printf("%s\n", all_elems[f].value);
                    f = all_elems[f].next_index;
                }
                else{
                    printf("%s\n", all_elems[all_elems[index_operation].next_index].value);
                    all_elems[index_operation].next_index =  all_elems[all_elems[index_operation].next_index].next_index;
                }
            }
        }
        printf("%s\n", "===");
        for (int x = f; x >= 0; x = all_elems[x].next_index){
            printf("%s\n", all_elems[x].value);
        }     //next или first = -1, если следующего нет
        printf("%s\n","===");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}