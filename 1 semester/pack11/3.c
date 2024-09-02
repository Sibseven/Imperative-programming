#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define KOL 10000007


uint64_t a, b, c, M;
uint64_t func(uint64_t s){
    return (s*s*a + s*b + c) % M;
}

typedef struct hash_item{
    uint64_t key;
    uint64_t value;
    struct hash_item* next;
} hash_item;

int get_table(hash_item* table, uint64_t num_rand, uint64_t key){
    uint64_t index = key; //ищем в ячейке key, значение num_rand
    hash_item* now = &table[index];
    if (now->next == NULL && now->key == 0 && now->value == 0){
        return 0;
    }
    while (now != NULL){
        if (now->value == num_rand){
            return 1;
        }
        now = now->next;
    }
    return 0;
    
}

int add_and_check(hash_item* table, uint64_t num_rand, uint64_t* l, uint64_t* r, uint64_t* chet){
    uint64_t index = num_rand%KOL;
    if (get_table(table, num_rand, index) == 0){// если нету элемента то добавляем
        if (table[index].next == NULL){// добавляем первый
            table[index].value = num_rand;
            table[index].key = *chet; // записываем текущий счетчик
        }
        else{
            hash_item* now = &table[index];//добавляем в конец
            while (now->next != NULL){
                now = now->next;
            }
            hash_item* new_item = calloc(1, sizeof(hash_item)); // новый элемент в конце
            now->next = new_item;
            new_item->key = *chet;
            new_item->value = num_rand;
            new_item->next = NULL;
        }
        return 0;
    }
    else{
        hash_item* now = &table[index];// элемент есть
        while (now->value != num_rand){ // находим этот элемент
            now = now->next;
        }               //меняем границы по указателю
        *l = now->key; // левая граница - та итерация когда мы получили это число в первый раз
        *r = *chet; // правая граница - текущая итерация, т.е та на которой мы зациклились
        return 1;
    }
}

int main(){
    scanf("%llu", &M);
    scanf("%llu %llu %llu", &a, &b, &c);
    hash_item* my_table = calloc(KOL, sizeof(hash_item));
    for(int i = 0; i < KOL; i++){
        my_table[i].next = NULL;        //читаем все 
    }
    uint64_t now = 1,l = 0, r = 0, chet = 0;
    while (add_and_check(my_table, now, &l, &r, &chet) == 0){ // проверяем есть ли это число 
        now = func(now); // меняем state
        chet++; // обновляем глобальный счетчик
    }
    printf("%llu %llu", l, r);

    for (int i = 0; i < KOL; i++){
        hash_item* now = &my_table[i];
        hash_item* now2 = my_table[i].next;
        while (now2 != NULL){
            now = now2;
            now2 = now->next;
            free(now);
        }
    }
    free(my_table);
    return 0;
}