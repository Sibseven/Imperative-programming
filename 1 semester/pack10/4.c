#include <stdio.h>
#include <math.h>
#define KOL 1000000007

typedef struct Stack{
    int arr[100005];
    int top;
} Stack;

int pop(Stack* stack){
    int val = stack->arr[stack->top];
    stack->top--;
    return val;
}
void push(Stack* stack, int val){
    stack->arr[++stack->top] = val;
}
int power(int n, int k){
    int sum = 1;
    for (int i = 0; i < k; i++){
        sum *= n;
    }
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);
    Stack my_stack = {0};
    for (int i = 0; i < n; i++){
        char now;
        scanf("%c", &now);
        if (now == ' ' || now == '\n'){
            scanf("%c", &now);
        }
        if (now >= '0' && now <= '9'){
            int arr[11] = {0};
            int n_digits = 0;
            while (now != ' ' && now != '\n'){
                arr[n_digits++] = now - '0';
                scanf("%c", &now);
            }
            int sum = 0;
            for (int i = n_digits - 1; i >= 0; i--){
                sum += power (10, i) * arr[n_digits - i - 1];
            }
            push(&my_stack, sum);
        }
        else{
            int b = pop(&my_stack);
            int a = pop(&my_stack);
            if (now == '*'){
                long long res = (long long)a * (long long) b;
                res %= KOL; 
                push(&my_stack, (int) res);
            }
            else if (now == '-'){
                int res = (a - b);
                if (res < 0){
                    res += KOL;
                }
                push(&my_stack, (int) res);
            }
            else{
                int res = a + b;
                res %= KOL;
                push(&my_stack, res);
            }
        }
    }
    int ans = pop(&my_stack);
    printf("%d", ans);
    return 0;
}