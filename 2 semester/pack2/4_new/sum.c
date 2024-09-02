extern long long *arr_mod;
void Init(const int *arr , int n){
    arr_mod[0] = 0;
    for(int i = 1; i <= n; i++){
        arr_mod[i] = arr_mod[i-1] + (long long) arr[i - 1];
    }
}

long long Sum(int l, int r){
    long long res = arr_mod[r] - arr_mod[l];
    return res;
}