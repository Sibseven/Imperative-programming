#include <stdio.h>
int main(){
    int hour, minutes, sec, k;
    scanf("%d %d %d %d", &hour, &minutes, &sec, &k);
    int global_sec = 0;
    global_sec += sec;
    global_sec += minutes*60;
    global_sec += hour*60*60;
    global_sec += k;
    global_sec = global_sec%86400;
    int f_hour, f_min, f_sec = 0;
    f_hour = global_sec/3600;
    global_sec = global_sec%3600;
    f_min = global_sec/60;
    global_sec = global_sec%60;
    f_sec = global_sec;
    printf("%d %d %d", f_hour, f_min, f_sec);
}