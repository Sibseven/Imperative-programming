#include <stdio.h>
#include <string.h>

int dfs(int start, int* used, int* matching, int (*graph)[120]){
    if(used[start]){
        return 0;
    }
    used[start] = 1;
    for(int i = 0; i < 120; i++){
        if(graph[start][i] == 1){
            if(matching[i] == -1  || dfs(matching[i], used, matching, graph)){
                matching[i] = start;
                return 1;
            }
        } 
        
    }
    return 0;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int stud, tasks, pairs;
    scanf("%d %d %d",  &stud, &tasks, &pairs);
    int used[120] = {0};
    int graph[120][120] = {0};
    for(int i = 0; i < pairs; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
    }
    int matching[120];
    for(int i = 0; i < 120; i++){
        matching[i] = -1;
    }
    for(int i = 1; i<= 120; i++){
        memset(used, 0, sizeof(used));
        dfs(i, used, matching, graph);
    }
    int cnt = 0;    
    for(int i = 1; i<120; i++){
        if(matching[i] != -1){
            cnt++;
            //printf("%d %d\n", i, matching[i]);
        }
    }
    printf("%d\n", cnt);
    for(int i = 1; i<120; i++){
    if(matching[i] != -1){
        //cnt++;
        printf("%d %d\n", matching[i], i);
        }
    }
}