#include <stdio.h>
#include <stdlib.h>

int comp_for_qsort(const void *a,const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
return *x - *y;
}
void main(){
    int n1 = 0, n2 = 0, n_res = 0;
    int nums_1[100001];
    int nums_2[100001];
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++){
        scanf("%d", &nums_1[i]);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++){scanf("%d", &nums_2[i]);}
    int a = 0, flag = 0, chet = 0;
    int nums_res[100001] = {0};
    qsort(nums_1, n1, sizeof(int), comp_for_qsort);
    qsort(nums_2, n2, sizeof(int), comp_for_qsort);
    for(int i = 0;i < n1;i++){
        for(int j = i+1; j < n1; j++){
            if(nums_1[i] == nums_1[j]){
                for(int k = j; k < n1; k++){
                    nums_1[k] = nums_1[k+1];
                }
                j--;
                n1--;
            }
        }
    }
    for(int i = 0;i < n2; i++){
        for(int j = i + 1; j < n2; j++){
            if(nums_2[i] == nums_2[j]){
                for(int k = j; k < n2; k++){
                    nums_2[k] = nums_2[k+1];
                }
                j--;
                n2--;
            }
        }
    }
    for (int i = 0; i < n1; i++){
        flag = 1;
        a = nums_1[i];
        for (int j = 0; j < n2; j++){ //проверка на наличие элемнта списка а в б
            if (a == nums_2[j]){
                flag = 0;
                break;
            }
        }
        if (flag){
            n_res += 1;
            nums_res[chet] = a;
            chet += 1;
        }
    }
    printf("%d\n", n_res);
    for (int i = 0; i < n_res; i++) printf("%d ", nums_res[i]);
}