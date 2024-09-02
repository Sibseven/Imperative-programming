#include <stdio.h>
#include <stdlib.h>
int remKtr, tumblers_kol, bulbs, l;
int rec(int k, int* ans, int* ans_kols, char** tumblers, int now_in_ans){
    if(k == remKtr){
        for(int i = 0; i < bulbs; i++){
            int test  = ans[i];
            if(ans[i] != l){
                return 1;
            }
        }
        return 0;
    }
    int super_flag = 0;
    for(int i = 0; i < tumblers_kol; i++){
        int flag = 1;
        for(int j = 0; j < bulbs; j++){
            if(ans[j] == l && tumblers[k*tumblers_kol+i][j] == 'X'){
                flag = 0;
                break;
            }
            if(ans[j] + (remKtr - k) < l /*&& tumblers[k*tumblers_kol+i][j] == '.'*/){
                flag = 0;
                break;
            }
        }
        if(flag){
            for(int j = 0; j< bulbs; j++){
                if(tumblers[k*tumblers_kol+i][j] == 'X'){
                    ans[j] += 1;
                }
            }
            ans_kols[now_in_ans] = i+1;
            now_in_ans++;
            int check = rec(k+1, ans, ans_kols, tumblers, now_in_ans);
            // добавить откат и какой-нибудь супер флаг общий 
            if(check == 1){
                for(int j = 0; j< bulbs; j++){
                    if(tumblers[k*tumblers_kol+i][j] == 'X'){
                        ans[j] -= 1;
                    }
                }
                now_in_ans--;
            }
            else{
                super_flag = 1;
            }
        }
    }
    if(super_flag == 0){
        return 1;
    }
    return 0;
}
int main(){
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    scanf("%d %d %d %d\n", &remKtr, &tumblers_kol, &bulbs, &l);
    char **tumblers = (char **) malloc(sizeof(char*) * 101);
    for(int i = 0; i < tumblers_kol*remKtr; i++){
        tumblers[i] = (char *) malloc(sizeof(char)*(bulbs+10));
        // fgets(tumblers[i], 110, stdin);
        scanf("%s\n", tumblers[i]);
        if(tumblers[i][0] == ' '){
            i--;
        }
    }
    int ans[101] = {0};
    int ans_kols[101] = {0};
    int now_in_ans = 0;
    int check = rec(0, ans, ans_kols, tumblers, now_in_ans);
    if(check == 1){
        printf("NO\n");
        return 0;
    }
    printf("YES");
    for(int i = 0; i < remKtr; i++){
        printf("\n%d", ans_kols[i]);
    }
    for(int i = 0; i < tumblers_kol*remKtr; i++){
        free(tumblers[i]);
    }
    free(tumblers);
    return 0;
}