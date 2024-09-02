#include <stdlib.h>
#include "primes.h"
#define NNN 10000021
static int arr[NNN];
static int prefics[NNN];
static void sieve(){
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i*i < NNN; i++){
        if (arr[i] != 1){
            for(int j = i*i; j < NNN; j+=i){
                arr[j] = 1;
            }
        }
    }
    prefics[0] = 0;
    for(int i = 1; i < NNN; i++){
        prefics[i] = prefics[i-1];
        if (arr[i] == 0){
            prefics[i] += 1;
        }
    }
}

int isPrime(int x){
    if (arr[0] == 0){
        sieve();
    }
    if (arr[x] == 0){
        return 1;
    }
    return 0;
}

int findNextPrime(int x){
    if (arr[0] == 0){
        sieve();
    }
    for(int i = x; i < NNN; i++){
        if (arr[i] == 0){
            return i;
        }
    }
}

int getPrimesCount(int l, int r){
    if (arr[0] == 0){
        sieve();
    }
    if (l == 0){
        if (arr[r] == 0){
            return prefics[r] - 1;
        }
        return prefics[r];
    }
    if (arr[r] == 0){
        return prefics[r] - prefics[l - 1] - 1;
    }
    return prefics[r] - prefics[l - 1];
}