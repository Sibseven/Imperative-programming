#include<stdio.h>
#include <string.h>

int readTime(char* iStr, int *Hours, int *Minutes, int *Seconds){
    char *start = iStr;
    while (*iStr != '\0'){
        if ((*iStr < '0' || *iStr > '9') && *iStr != ':'){
            *Hours = -1;
            *Minutes = -1;
            *Seconds = -1;
            return 0;
        }
        iStr ++;
    }
    iStr = start;
    int check = 0;
    for (int i = 0; i < strlen(iStr); i++){
        if(iStr[i] != ':'){
            if (check == 0){
                *Hours *= 10;
                *Hours += iStr[i] - '0';
            }
            else if(check == 1){
                *Minutes *= 10;
                *Minutes += iStr[i] - '0';
            }
            else{
                *Seconds *= 10;
                *Seconds += iStr[i] - '0';
            }
        }
        else{
            check += 1;
        }
    }
    if (*Hours > 23 || *Minutes > 59 || *Seconds > 59)
    {
        *Hours = -1;
        *Minutes = -1;
        *Seconds = -1;
        return 0;
    }
    return 1;
    
}
int main(){
    char s[20];
    scanf("%s", s);
    int h = 0, m = 0, sec = 0;
    int res = readTime(s, &h, &m, &sec);
    printf("%d %d %d %d\n", res, h, m, sec);
    printf("%d %d %d\n", res, h, m);
    printf("%d %d\n", res, h);

}