#define MAX_N 100010
#include <stdio.h>
typedef struct{
    long long val;
    int id;
} amogus;

void LIS(int* arr, amogus* dp, int* prev, int n){
    for(int i = 0; i < n; i++){
        int l = 0, r = n-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if (dp[m].val < arr[i]){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        dp[r+1].val = arr[i];
        dp[r+1].id = i;
        prev[i] = dp[r].id;
    }
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int arr[MAX_N] = {0};
    int prev[MAX_N] = {0};
    amogus dp[MAX_N] = {0};
    dp[0].val = -2147483847;
    dp[0].id = -1;
    prev[1] = -1;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        dp[i+1].val = 2147483657;
    }
    LIS(arr, dp, prev, n);
    int max_index = 0;
    for(int i = n; i > 0; i--){
        if(dp[i].val != 2147483657){
            max_index = i;
            break;
        }
    }
    int path[MAX_N] = {0};
    int now_in_path = 1;
    path[0] = dp[max_index].id;
    int now = prev[dp[max_index].id];
    while (now != -1){
        path[now_in_path] = now;
        now = prev[now];
        now_in_path++;
    }
    printf("%d\n", max_index);
    for(int i = now_in_path - 1; i>=0; i--){
        printf("A[%d] = %d\n", path[i]+1, arr[path[i]]);
    }
    return 0;
}
