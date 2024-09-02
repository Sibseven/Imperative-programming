#include <stdlib.h> 
 
#define MAX_N 200 
#define MAX_W 50000 
 
int max(int a, int b) { 
    return a > b ? a : b; 
} 
 
int main() { 
    int N, W; 
    scanf("%d %d", &N, &W); 
 
    int weights[MAX_N], values[MAX_N]; 
    for (int i = 0; i < N; i++) { 
        scanf("%d %d", &weights[i], &values[i]); 
    } 
 
    int dp[MAX_N + 1][MAX_W + 1]; 
    for (int i = 0; i <= N; i++) { 
        for (int w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) { 
                dp[i][w] = 0; 
            } else if (weights[i - 1] <= w) { 
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]); 
            } else { 
                dp[i][w] = dp[i - 1][w]; 
            } 
        } 
    } 
 
    int resValue = dp[N][W]; 
    int resWeight = W; 
    int takenItems[MAX_N]; 
    int k = 0; 
    for (int i = N; i > 0 && resValue > 0; i--) { 
        if (resValue != dp[i - 1][resWeight]) { 
            takenItems[k++] = i; 
            resValue -= values[i - 1]; 
            resWeight -= weights[i - 1]; 
        } 
    } 
 
    printf("%d %d %d\n", k, W - resWeight, dp[N][W]); 
    for (int i = k - 1; i >= 0; i--) { 
        printf("%d ", takenItems[i]); 
    } 
    printf("\n"); 
 
    return 0; 
}