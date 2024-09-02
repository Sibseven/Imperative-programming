#include <stdio.h>


int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int arr[100005] = {0};
    int subs[100005] = {0};
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int now_index = 0;
    for (int i = 0; i < n; i++){
        while (m < arr[i] - arr[now_index]){
            now_index++;
        }
        printf("\n%d", i - now_index + 1);
    }
}