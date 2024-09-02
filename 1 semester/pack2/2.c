#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int strcmp();
    char s[3];
    scanf("%3s",s);
    if (strcmp(s,"Mon") == 0){
        printf("%d",1);
    }
    if (strcmp(s,"Tue") == 0){
        printf("%d",2);
    }
    if (strcmp(s,"Wed") == 0){
        printf("%d",3);
    }
    if (strcmp(s,"Thu") == 0){
        printf("%d",4);
    }
    if (strcmp(s,"Fri") == 0){
        printf("%d",5);
    }
    if (strcmp(s,"Sat") == 0){
        printf("%d",6);
    }
    if (strcmp(s,"Sun") == 0){
        printf("%d",7);
    }
    return 0;
}