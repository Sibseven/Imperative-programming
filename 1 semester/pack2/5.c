#include <stdio.h>

int main(){
    char s;
    int n = 0;
    int flag = 1;
    scanf("%c",&s);
    if (s == '.'){
        flag = 0;
    
    }
    else {
        n += 1;
    }
    while (s != '\n'){
        scanf("%c", &s);
        if (flag == 0 && s != '.' && s != '\n'){
            n += 1;
            flag = 1;
        }
        else if (flag == 1 && s == '.'){
            flag = 0;
        }

    }
    printf("%d",n);
}