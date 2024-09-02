#include <stdio.h>
long long int func(long long int a, long long int c, long long int i){
    return a + c * i;
}

long long int main(){
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);
    long long int n;
    scanf("%lld", &n);
    long long int arr[100009] = {0};
    for (long long int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
    }
    long long int q = 0;
    scanf("%lld", &q);
    for (long long int i = 0; i < q; i++){
        long long int c_now = 0;
        scanf("%lld", &c_now);
        long long int l = 0, r = n - 1;
        while (r - l >= 3){
            long long int left_third = (l + (r - l) / 3);
            long long int right_third = (r - (r - l) / 3);
            if (func(arr[left_third], c_now, left_third) >= func(arr[right_third], c_now, right_third)){
                l = left_third;
            }
            else{
                r = right_third;
            }
        }
        long long int min = l;
        for (long long int i = l; i <= r; i++){
            if (func(arr[i], c_now, i) < func(arr[min], c_now, min)){
                min = i;
            }
        }
        printf("%lld\n", min);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}