#include <stdio.h>
#include <ctype.h>
#include <string.h>

int len(char *s){
    int n = 0;
    while (*s != '\0' && *s !='\n')
    {
        n += 1;
        s += 1;
    }
    return n;
}
int calcLetters (char *iStr , int *oLowerCnt , int *oUpperCnt , int *oDigitsCnt ){
    *oLowerCnt = 0;
    *oUpperCnt = 0;
    *oDigitsCnt = 0;
    while (*iStr != '\0'){
        if (isdigit(*iStr) == 0){
            if (*iStr >= 'a' && *iStr <= 'z'){
                *oLowerCnt += 1;
            }
            else if (*iStr >= 'A' && *iStr <= 'Z'){
                *oUpperCnt += 1;
            }  
        }
        else{
            *oDigitsCnt += 1;
        }
        iStr += 1;
    }
}
int main(){

    int n = 1;
    int low_cnt = 0, up_cnt = 0, dig_cnt = 0;
    char s[500];
    while (fgets(s, 500, stdin) != NULL){
        calcLetters(s, &low_cnt, &up_cnt, &dig_cnt);
        printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", n, len(s), low_cnt+up_cnt, low_cnt, up_cnt, dig_cnt);
        n += 1;
    }
    return 0;
}
