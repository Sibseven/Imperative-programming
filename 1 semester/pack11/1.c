#include <stdio.h>
#include <stdlib.h>

int knuth_hash_signed(int key) {
    unsigned int k = (unsigned int) key;
    const unsigned int A = 2654435768U;     //округлённое до целого phi * 2^32
    unsigned int x = (A * k);               //умножаем по модулю 2^32 (за счёт переполнения)
    return x%1000006;
} 
// const unsigned int multiplier = 2654435761u; 
//     return ((int)key & 0x7FFFFFFF) * multiplier % 2000006;
typedef struct hash_item{
    int key;
    int value;
    struct hash_item* next;
    
} hash_item;

void add_hash(hash_item* table, int key){
    int index = knuth_hash_signed(key);
    if (table[index].value == 1 && key != table[index].key){
        hash_item* new_item = calloc(1, sizeof(hash_item));
        hash_item* now = &table[index];
        while (now->next != NULL){
            now = now->next;
        }
        now->next = new_item;
        new_item->key = key;
        new_item->value = 1;
        new_item->next = NULL;
        
    }
    else{
        table[index].value = 1;
        table[index].key = key;
        table[index].next = NULL;
    }
}

int get_table(hash_item* table, int key){
    int index = knuth_hash_signed(key);
    int flag = 0;
    hash_item* now = &table[index];
    while (now != NULL){
        if (now->key == key && now->value == 1){
            flag = 1;
        }
        now = now->next;
    }
    return flag;
    
}
   
         
int main(){
    FILE* input = fopen("input.bin", "rb");
    FILE* output = fopen("output.bin", "wb");
    int n = 0;
    int arr[1000006] = {0};
    int k = 0;
    fread(&n, sizeof(int), 1, input);
    fread(&arr, sizeof(int), n, input);
    hash_item* my_table = calloc(sizeof(hash_item), 1000006);
    for(int i = 0; i < 100006; i++){
        my_table[i].next = NULL;
    }
    for (int i = 0; i < n; i++){
        if (get_table(my_table, arr[i]) == 0){
            add_hash(my_table, arr[i]);
            k++;
        }

    }
    fwrite(&k, sizeof(int), 1, output);
    for (int i = 0; i < n; i++){
        if (get_table(my_table, arr[i]) == 1){
            fwrite(&arr[i], sizeof(int), 1, output);
            hash_item* now = &my_table[knuth_hash_signed(arr[i])];
            while (now->key != arr[i]){
                now = now->next;
            }
            now->value = 0;
        }
    }
    for (int i = 0; i < 1000006; i++){
        hash_item* now = &my_table[i];
        hash_item* now2 = my_table[i].next;
        while (now2 != NULL){
            now = now2;
            now2 = now->next;
            free(now);
        }
    }
    free(my_table);
    fclose(input);
    fclose(output);
}