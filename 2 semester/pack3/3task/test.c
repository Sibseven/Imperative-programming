#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char test[50] = {"-    1.500"};
    double res = strtod(test, NULL);
    printf("%lf", res);
    if (isdigit(test[0])){
        printf("SUCC");
    }
    return 0;
}