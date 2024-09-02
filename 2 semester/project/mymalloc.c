#include "mymalloc.h"
#include <stdlib.h>
#include "avl.c"
#include <stddef.h>
#define BLOCK_SIZE 25000


Smymalloc body;
Root* TreeFree;
int isInit = 0;

int BlockPointer_add(BlockPointer* to_add, void** value){
    if(to_add->cnt == BLOCK_SIZE){
        return 1;
    }
    if(to_add->empty_stack->top == 1 && to_add->cnt != BLOCK_SIZE-1){
        int now_stack = to_add->empty_stack->Stack_arr[0];
        char* iterator = (char *) to_add->address;
        iterator += to_add->elem_size*now_stack;
        *value = (void *)iterator;
        to_add->empty_stack->Stack_arr[0]++;
        to_add->cnt++;
        return 0;
    }
    to_add->empty_stack->top--;
    char* iterator = (char *) to_add->address;
    iterator += to_add->elem_size*to_add->empty_stack->top;
    *value =(void *) iterator;
    to_add->cnt++;
    return 0;

}
void BlockPointer_init(BlockPointer* block, size_t elem_size){
    block->cnt = 0;
    block->address = (void *) malloc(BLOCK_SIZE * elem_size);
    block->empty_stack = (Stack*) malloc(sizeof(Stack));
    block->empty_stack->Stack_arr = (int *) malloc(sizeof(int)*BLOCK_SIZE);
    block->empty_stack->top = 1;
    block->empty_stack->Stack_arr[0] = 0;
    block->elem_size = elem_size;
}
void init(){
    BlockPointer* z_block = malloc(sizeof(BlockPointer)); 
    body.z_mem.blocks[0] = z_block;
    BlockPointer_init(z_block, body.z);
    body.z_mem.next_free = 1;
    BlockPointer* y_block = malloc(sizeof(BlockPointer)); 
    body.y_mem.blocks[0] = y_block;
    BlockPointer_init(y_block, body.y);
    body.y_mem.next_free = 1;
    BlockPointer* x_block = malloc(sizeof(BlockPointer)); 
    body.x_mem.blocks[0] = x_block;
    BlockPointer_init(x_block, body.x);
    body.x_mem.next_free = 1;
    TreeFree = add(TreeFree, x_block->address, x_block, body.x);
    TreeFree = add(TreeFree, y_block->address, y_block, body.y);
    TreeFree = add(TreeFree, z_block->address, z_block, body.z);




}
void* VectorPointer_add(VP* vector, size_t ss){// Добавляет в блоки
    void* return_val;
    int now_cap = vector->next_free;
    for(int i = 0; i < now_cap; i++)
    {
        if(BlockPointer_add(vector->blocks[i], &return_val) == 0){ // пробуем добавить в каждый блок
            return return_val;
        }
    } 
    BlockPointer* new_block = malloc(sizeof(BlockPointer)); // все блоки заняты -> создаем новый
    vector->blocks[now_cap] = new_block;
    BlockPointer_init(new_block, ss);
    int check = BlockPointer_add(vector->blocks[now_cap], &return_val);
    vector->next_free++;
    TreeFree = add(TreeFree, new_block->address, new_block, ss);
    return return_val;
}
void* mymalloc(size_t field){
    if(isInit == 0){
        isInit = 1;
        init();
    }
    void* return_val = 0;
    if(field == body.x){
        return_val = VectorPointer_add(&body.x_mem, body.x);
    }
    else if (field == body.y){
        return_val = VectorPointer_add(&body.y_mem, body.y);
    }
    else if (field == body.z){
        return_val = VectorPointer_add(&body.z_mem, body.z);  
    }
    if(return_val == 0){
        return_val = malloc(field);
    }
    return return_val;
}
int BlockPointer_free_elem(BlockPointer* to_free, void* value, int index){// c помощью арифметики указателей и арифтемики находим индекс освобождаемого элемента
    to_free->empty_stack->Stack_arr[to_free->empty_stack->top] = index; //добавляем элемент в стэк пустых
    to_free->empty_stack->top++;
    to_free->cnt--;
    return 0;
}
void myfree(void* to_free){
    void* location_block = 0; 
    void* location_arr = 0;
    size_t found_size = 0;
    lower_bound(TreeFree, to_free, &location_block, &location_arr, &found_size); // находим блок в авл дереве
    if(found_size == 0){
        free(to_free);
        return;
    }
    int index = ((size_t) to_free - (size_t)location_arr)  / found_size;  // освобождаемое место не принадлежит ни одному из блоков -> было выделенно обычным malloc 
    if(index >= BLOCK_SIZE || index < 0){
        free(to_free);
        return;
    }
    BlockPointer_free_elem(location_block, to_free, index);
    
}
void BlockPointer_free_whole(BlockPointer* to_free){
    free(to_free->address);
    free(to_free->empty_stack->Stack_arr);
    free(to_free->empty_stack);
    free(to_free);
}
void VectorPointer_free(VP* vect){
    for(int i = 0; i < vect->next_free; i++){
        BlockPointer_free_whole(vect->blocks[i]);
    }
}
void super_free(){
    VectorPointer_free(&body.x_mem);
    VectorPointer_free(&body.y_mem);
    VectorPointer_free(&body.z_mem);
}
