#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000010


typedef struct Tokens_s {
    int num; //количество слов в строке
    char **arr; //массив слов (каждый элемент –- строка, т.е. char*)
} Tokens;
//tokens: структура, в которую нужно положить результаты

int tokensSplit(Tokens *tokens , const char *str , const char *delims){
    if (tokens->arr == NULL){
        tokens->num = 0;
        int flag = 1;
        if (strchr(delims, (int)*str) != NULL){ flag = 0;}
        else {tokens->num += 1;}
        while (*str != '\n' && *str !='\0'){
            if (flag == 0 && strchr(delims, (int)*str) == NULL && *str != '\n'){
                tokens->num += 1;
                flag = 1;
            }
            else if (flag == 1 && strchr(delims, (int)*str) != NULL){
                flag = 0;
            }
            str++;
        }
        return 0;
    }
    char**start = tokens->arr;
    while (*str != '\n' && *str != '\0'){
        if (strchr(delims, (int)*str) == NULL){
            int n = 0;
            char* p_to_start = str;
            while (strchr(delims, (int)*str) == NULL && *str != '\0' && *str != '\n'){
                n += 1;
                str++;
            }
            str = p_to_start;
            *start = malloc(sizeof(char)*n+1);
            char*new_word = *start;
            while (strchr(delims, (int)*str) == NULL && *str != '\0' && *str != '\n'){
                *new_word = *str;
                str++; new_word++;
            }
            *new_word = '\0';
            start++;
        }
        str++;
    }
    return 0;
} //str: строка, в которой нужно искать слова //delims: все символы-разделители в виде строки

void tokensFree(Tokens *tokens){
    if (tokens->arr == NULL){
        return;
    }
    char **start = tokens->arr;
    for (int i; i < tokens->num;i++){
        free(*start);
        start++;
    }
    free(tokens->arr);
    return;
} //удаляет все ресурсы внутри tokens

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char* string = malloc(sizeof(char)*N);
    scanf("%s", string);
    Tokens token_main;
    token_main.arr = NULL;
    char delims[5] = ".,;:";
    tokensSplit(&token_main, string, delims);
    printf("%d\n",token_main.num);
    token_main.arr = malloc(token_main.num * sizeof(char*));
    char**start = token_main.arr;
    tokensSplit(&token_main, string, delims);
    for (int i = 0; i< token_main.num; i++){
        printf("%s\n", *start);
        start++;
    }
    tokensFree(&token_main);
    free(string);
    fclose(stdin);
    fclose(stdout);
}