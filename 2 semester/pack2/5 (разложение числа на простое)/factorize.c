typedef struct Factors {
    int k; //сколько различных простых в разложении
    int primes [32]; //различные простые в порядке возрастания
    int powers [32]; //в какие степени надо эти простые возводить
} Factors;

void Factorize(int X, Factors *res){
    res->k = 0;
    int i = 2;
    while (i*i <= X){
        if(X % i == 0){
            res->primes[res->k] = i;
            res->powers[res->k] +=1; 
            X /= i;
            if (X % i != 0){
                res->k++;
            }
        }
        else{
            i++;
        }
    }
    if (X != 1){
        res->primes[res->k] = X;
        res->powers[res->k] += 1;
        res->k++;
    }
    

}