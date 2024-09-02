#include <stdio.h>

int main(){
    int n,m = 0;
    int nums[90000][2];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int val1, val2;
        scanf("%d %d", &val1, &val2);
        nums[i][0] = val1;
        nums[i][1] = val2;
    }
    int everywhere_d = 1, inj = 1, cinj = 1, biect = 1;
    for (int i = 0; i < m - 1; i++){
        int cur_x = nums[i][0], cur_y = nums[i][1];
        for (int j = i+1; j < m; j++){
            int comp_x = nums[j][0], comp_y = nums[j][1];
            if (comp_y == cur_y && cur_x != comp_x){
                inj = 0;
            }
            if (comp_x == cur_x && comp_y != cur_y){
                printf("%d", 0);
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        int flag_every = 0;
        for (int j = 0; j < m; j++){
            if (nums[j][0] == i) flag_every = 1;
        }
        if (flag_every == 0) everywhere_d = 0;
        if (everywhere_d == 0){
            break;
        }
    }
    for (int i = 1; i <= n; i++){
        int flag_cinj = 0;
        for (int j = 0; j < m; j++){
            if (nums[j][1] == i) flag_cinj = 1;
        }
        if (flag_cinj == 0) cinj = 0;
        if (cinj == 0){
            break;
        }
    }
    if (inj != 1 || cinj != 1) biect = 0;
    printf("%d ", 1);
    if (everywhere_d == 1) printf("%d ", 2);
    if (inj == 1) printf("%d ", 3);
    if (cinj == 1) printf("%d ", 4);
    if (biect == 1) printf("%d", 5);
    return 0;
}