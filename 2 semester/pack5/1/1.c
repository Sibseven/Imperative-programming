#pragma comment(linker , "/STACK:50000000")
#include <stdio.h>
#include <stdlib.h>
int n;
void dfs(char** labirint, int row, int column){
    labirint[row][column] = '+';
    if(row - 1 >= 0 && labirint[row-1][column] == ' '){
        dfs(labirint, row-1, column);
    }
    if(column - 1 >= 0 && labirint[row][column-1] == ' '){
        dfs(labirint, row, column - 1);
    }
    if(row+1 < n && labirint[row+1][column] == ' '){
        dfs(labirint, row+1, column);
    }
    if(column+1 < n && labirint[row][column+1] == ' '){
        dfs(labirint, row, column+1);
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    FILE * output = fopen("output.txt", "w");
    scanf("%d\n",&n);
    char** labirint = (char**) malloc(sizeof(char*)*(n+5));
    for(int i = 0; i < n; i++){
        labirint[i] =(char*) malloc(sizeof(char)*(n+5));
        fgets(labirint[i], n+10, stdin);
    }
    int k = 0;
    for(int i = 0; i<n; i++){
        if(labirint[0][i] == ' '){
            dfs(labirint, 0, i);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(labirint[i][j] == ' '){
                k++;
                dfs(labirint, i, j);
            }
        }
    }
    for(int i = 0; i<n; i++){
        free(labirint[i]);
    }
    free(labirint);
    printf("%d", k);
}