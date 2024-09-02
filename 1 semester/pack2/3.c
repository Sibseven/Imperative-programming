#include <stdio.h>

int main(){
    int n; 
    double pos_num, zero_num, neg_num;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int a;
        scanf("%d", &a);
        if (a > 0){
            pos_num +=1;
        }
        else if (a == 0){
            zero_num += 1;
        }
        else {
            neg_num += 1;
        }
    }
    pos_num = pos_num / n;
    zero_num = zero_num / n;
    neg_num = neg_num / n;
    printf("%0.5lf %0.5lf %0.5lf", neg_num, zero_num, pos_num);
}