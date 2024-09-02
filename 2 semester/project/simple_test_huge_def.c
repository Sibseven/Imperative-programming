#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    clock_t begin = clock();
    int* adr[1000000] = {0};
    for(int i = 0; i <75000; i++){
        adr[i] =(int *) malloc(sizeof(int)* 1000);
    }
    for(int i = 0; i <25000; i++){
        free(adr[i]);
    }
    for(int i = 0; i <25000; i++){
        adr[i] =(int *) malloc(sizeof(int) * 1000);
    }
    for(int i = 75000; i <99000; i++){
        adr[i] =(int *) malloc(sizeof(int) * 1000);
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    for(int i = 0; i< 99000; i++){
        free(adr[i]);
    }
    printf("\n%lf", time_spent);
    
}