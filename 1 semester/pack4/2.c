#include <stdio.h>
#include <string.h>
void reverse (char *start , int len){
    char reversed[100];
    char *p = reversed;
    for (int i = len - 1; i >= 0; i--){
        *p = *(start+i);
        p+= 1;
    }
    *p = '\0';
    p = reversed;
    while (*p != '\0')
    {
        *start = *p;
        start ++;
        p ++;
    }
}
int main(){
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++){
        char s[100];
        char *p = s;
        scanf("%s", s);
        reverse(s, strlen(s));
        while (*p != '\0'){
            printf("%c", *p);
            *p ++;
        }
        printf("\n");
    }
}