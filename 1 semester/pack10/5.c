#include <stdio.h>
#include <math.h>



int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        double now;
        scanf("%lf", &now);
        double ans = 0;
        double now_tt = now;
        double znam = 1;
        double step = 1;
        for (int i = 0; i < 10; i++){
            ans += now_tt/znam;
            now_tt *= now;
            now_tt *= now;
            now_tt *= -1;
            step++;
            znam *= step;
            step++;
            znam *= step; 
        }
        printf("\n%0.15lf\n", ans);
    }
    
}