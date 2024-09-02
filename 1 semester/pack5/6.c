#include <stdio.h>
#define N 3500
typedef struct LongNum_s {
int len ;//сколько цифр в числе
int arr [N];//массив десятичных цифр числа
} LongNum ;

void zero(LongNum*long_num_1){
    for (int i = 0; i < N; i++){
        long_num_1->arr[i] = 0;
    }
}
LongNum multi(LongNum *long_num_1, LongNum *long_num_2){
    LongNum result;
    zero(&result);
    int n = long_num_1->len, m = long_num_2 -> len;
    result.len = n + m;
    for ( int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            result.arr[j + i] += (long_num_1->arr[i] * long_num_2->arr[j]);
        }
    }
    int buf = 0;
    for (int i = 0; i < result.len; i++){
        result.arr[i] = buf + result.arr[i];
        buf = result.arr[i]/10;
        result.arr[i] %= 10;
    }
    int a = result.arr[result.len-1];
    while (a == 0){
        result.len -= 1;
        a = result.arr[result.len-1];
    }
    return result;
}
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
    scanf("%d", &n);
    LongNum res, step, one;
    zero(&res);
    zero(&step);
    zero(&one);

    res.arr[0] = 1; res.len = 1;
    /*LongNum num1;
    LongNum num2;
    num1.arr[0] = 9; num1.arr[1] = 9; num1.len = 2;
    num2.arr[0] = 9; num2.arr[1] = 9; num2.len = 2;
    res = multi(&num1, &num2);*/
    step.arr[0] = 1; step.len = 1;
    one.arr[0] = 1; one.len = 1;
    for (int i = 0; i < n; i++){
        res = multi(&step, &res);
        step = add(&one, &step);
    }
    for (int i = res.len - 1; i >= 0; i--){
        printf("%d", res.arr[i]);
    }
}