#include <stdio.h>
#include <stdlib.h>
int m, n;
int solution[30] = {0};
int vertical[30] = {0};
int diagS[30] = {0};
int diagD[30] = {0};
int flag = 1;
void rec(int r, char** board){
    if (r == m){
        printf("YES\n");
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '?'){
                    printf(".");
                }   
                else{
                    printf("%c",board[i][j]);
                }
            }
            printf("\n");
        }
        flag = 0;
        exit(0);
    }
    for(int i = 0; i < n; i++){
        if( vertical[i] || diagS[r + i] || diagD[r - i + n] || board[r][i] == '.'){
            continue;
        }
        board[r][i] = 'X';
        solution[r] = i;
        vertical[i] = diagS[r+i] = diagD[r-i + n] = 1;
        rec(r+1, board);
        if(flag == 0){
            return;
        }
        board[r][i] = '?';
        vertical[i] = diagS[r+i] = diagD[r-i + n] = 0;
        solution[r] = i;
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d %d\n", &m, &n);
    char** board = (char **) malloc(sizeof(char*)*(12+1));
    for(int i = 0; i < m; i++){
        board[i] = (char *) malloc(sizeof(char)*(12+1));
        fgets(board[i], 14, stdin);
    }
    rec(0, board);
    if(flag == 1){
        printf("NO\n");
    }
    return 0;
    // printf("YES\n");
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         if(board[i][j] == '?'){
    //             printf(".");
    //         }
    //         else{
    //             printf("%c",board[i][j]);
    //         }
    //     }
    //     printf("\n");
    // }
    for(int i = 0; i < m; i++){
        free(board[i]);
    }
    free(board);
}