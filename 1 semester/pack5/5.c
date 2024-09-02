#include <stdio.h>

typedef struct LongNum_s {
int len ;//сколько цифр в числе
int arr [500];//массив десятичных цифр числа
} LongNum ;

LongNum add(LongNum *longnum_1, LongNum *longnum_2){
    LongNum res;
    int m, n;
    m = longnum_2->len;
    n = longnum_1->len;
    int temp = 0;
    for (int i = 0; i < m; i++){
        if (i <= n){
            res.arr[i] = (longnum_1->arr[i] + longnum_2->arr[i]+ temp)%10;
            temp = (longnum_1->arr[i] + longnum_2->arr[i] + temp)/10;
        }
        else{
            res.arr[i] = (longnum_2->arr[i] + temp)%10;
            temp = (longnum_2->arr[i] + temp)/10;
        }
    }
    res.len = m;
    if (temp){
        res.arr[m] = temp;
        res.len += 1;
    }
    return res;
}
int main(){
    int n;
    LongNum fibo_all[2200] = {0};
    fibo_all[0].arr[0] = 1;fibo_all[0].len = 1;
    fibo_all[1].arr[0] = 1;fibo_all[1].len = 1;
    for (int i = 2; i < 2001; i++){
        fibo_all[i] = add(&fibo_all[i - 2], &fibo_all[i - 1]);
    }
    scanf("%d", &n);
    for (int i = (fibo_all[n-1].len) - 1; i >= 0; i--){
        printf("%d", fibo_all[n-1].arr[i]);
    }
}