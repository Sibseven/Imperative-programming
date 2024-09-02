#include <stdio.h>
typedef struct Factors {
    int k; //сколько различных простых в разложении
    int primes [32]; //различные простые в порядке возрастания
    int powers [32]; //в какие степени надо эти простые возводить
} Factors;
extern void Factorize(int X, Factors *res);
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int req;
    scanf("%d", &req);
    for (int i = 0; i < req; i++){
        Factors now_fact = {0};
        now_fact.k = 0;
        int now_x = 0;
        scanf("%d", &now_x);
        if (now_x == 1){
            printf("1 = 1\n");
            continue;
        }
        Factorize(now_x, &now_fact);
        printf("%d = ", now_x);
        for(int i = 0; i < now_fact.k; i++){
            if(i == 0){
                printf("%d^%d", now_fact.primes[i], now_fact.powers[i]);
            }
            else {
                printf(" * %d^%d", now_fact.primes[i], now_fact.powers[i]);
            }
        }
        printf("\n");
    }
    return 0;
}