#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int max,min,smin,smax;
    smin = 1;
    smax = 1;
    scanf("%d", &max);
    min = max;
    n-=1;
    for (int i = 2; i <= n + 1;i++ ){
        int a;
        scanf("%d", &a);
        if (a<min){
            min = a;
            smin = i;
        }
        if (a>max){
            max = a;
            smax = i;
        }
    }
    printf("%d %d %d %d", min,smin,max,smax);
}
