#include <stdio.h>
#include <string.h>

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
    LongNum res, num1, num2;
    zero(&res);
    zero(&num1); num1.len = 0;
    zero(&num2); num2.len = 0;
    char s1[N];
    char s2[N];
    fgets(s1, N, stdin);
    fgets(s2, N, stdin);
    int step = 0;
    for (int i = strlen(s1) - 2; i >= 0; i--){
        num1.arr[step] = s1[i] - '0';
        num1.len += 1;
        step ++;
    }
    step = 0;
    for (int i = strlen(s2) - 2; i >= 0; i--){
        num2.arr[step] = s2[i] - '0';
        num2.len += 1;
        step ++;
    }
    
    res = multi(&num1, &num2);
    
    for (int i = res.len - 1; i >= 0; i--){
        printf("%d", res.arr[i]);
    }
}