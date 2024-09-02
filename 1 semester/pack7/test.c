#include <stdio.h>
#include <stdlib.h>

int main(){
    char fff = 0b00000001;
    fff = fff << 4;
    if (fff != 0){
        printf("yes");
    }
    printf("%c", fff);
}