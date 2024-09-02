#include "mymalloc.c"
#include <time.h>
#include <stdio.h>
int main(){
    clock_t begin = clock();
    body.x = sizeof(int);
    body.y = sizeof(long long);
    body.z = sizeof(char);
    int* adr[1000000] = {0};
    for(int i = 0; i <75000; i++){
        adr[i] =(int *) mymalloc(sizeof(int));
    }
    for(int i = 0; i <25000; i++){
        myfree(adr[i]);
    }
    for(int i = 0; i <25000; i++){
        adr[i] =(int *) mymalloc(sizeof(int));
    }
    for(int i = 75000; i <99000; i++){
        adr[i] =(int *) mymalloc(sizeof(int));
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    super_free();
    printf("\n%lf", time_spent);
    
}