#include <stdio.h>


int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int arr[100005] = {0};
    int subs[100005] = {0};
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++){
        subs[i] = arr[i+1] - arr[i]; 
    }
    for (int i = 0; i < n; i++){
        int kol = 1;
        int now_point = i - 1;
        int sum = subs[now_point];
        while (sum <= m &&  now_point >= 0){
            now_point--;
            sum += subs[now_point]; 
            kol++;
        }
        printf("\n%d", kol);
    }
}