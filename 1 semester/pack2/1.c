#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int prime(int prime_ch){
    if (prime_ch == 1){
        return 0;
    }
    for (int i = 2; i*i <= prime_ch; i++){
        if (prime_ch % i == 0){
            return 0;
        }
    }
    return 1;

}
int main() {
	int n;
	scanf("%d", &n);
    for (int i = 2; i <= n; i++){
        if (prime(i) == 1){
            printf("%d \n",i);
        }
    }
    return 0;
}
