#include <stdio.h>

void printTime( int h, int m, int s){
    printf("%02d:%02d:%02d\n", h, m, s);
}
int main(){
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        printTime(a, b, c);
    }
    return 0;
}