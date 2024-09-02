#include <stdio.h>

int TEST;

int check_check(int a, int b){
    printf("%d", TEST);
    return 1;
}

int main(){
    TEST = 34;
    int check = TEST;
    check_check(13, 13);
    return 0;
}