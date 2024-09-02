extern long long *arr_mod;
void Init(const int *arr , int n){
    arr_mod[0] = arr[0];
    for(int i = 1; i < n; i++){
        arr_mod[i] = arr_mod[i-1] + (long long) arr[i];
    }
}

long long Sum(int l, int r){
    if (l == 0 ){
        return arr_mod[r];
    }    
    long long res = arr_mod[r] - arr_mod[l-1];
    return res;
}
// 1 2 3 4 5 6 7 8 9