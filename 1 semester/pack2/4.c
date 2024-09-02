#include <stdio.h>
#include <math.h>
int max(int x, int y){
    if (x >= y){
        return x;
    }
    return y;
}
int main(){
    int a1, a2, b1, b2, c1, c2;
    scanf("%d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2);
    if ((b1 * b2 + c1 * c2) > a1 * a2){
        printf("NO");
        return 0;
    }
    if ( (b1 > a1 && b1 > a2) || (b2 > a1 && b2 > a2) || (c1 > a1 && c1 > a2) || (c2 > a1 && c2 > a2)){
        printf("NO");
        return 0;
    }
    if ((b1 + c1 <= a1 && max(b2,c2) <= a2) || (b1 + c1 <= a2 && max(b2, c2) <= a1)){
        printf("YES");
        return 0;
    }
    if ((b1 + c2 <= a1 && max(b2,c1) <= a2) || (b1 + c2 <= a2 && max(b2, c1) <= a1)){
        printf("YES");
        return 0;
    }  
    if ((b2 + c1 <= a1 && max(b1,c2) <= a2) || (b2 + c1 <= a2 && max(b1, c2) <= a1)){
        printf("YES");
        return 0;
    }
    if ((b2 + c2 <= a1 && max(b1,c1) <= a2) || (b2 + c2 <= a2 && max(b1, c1) <= a1)){
        printf("YES");
        return 0;
    }
    printf("NO");
    return 0;
}