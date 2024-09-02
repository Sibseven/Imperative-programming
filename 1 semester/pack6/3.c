#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count_symbol(char* start, char needed_symbol){
    int cnt = 0;
    while (*start != '\0'){
        if (*start == needed_symbol){
            cnt++;
        }
        start++;
    }
    printf("%d\n",cnt);
}

void main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    char** identifiers = calloc(n+1, __SIZEOF_POINTER__);
    int free_space = 0;
    int operation, lenght_string, index_operation;
    char symol_for_search;
    char value[100000];
    for (int i = 0; i < n; i++){
        scanf("%d", &operation);
        if (operation == 0){
            scanf("%d", &lenght_string);
            identifiers[free_space] = malloc(sizeof(char)*(lenght_string+1));
            scanf("%s", value);
            strcpy(identifiers[free_space], value);
            free_space++;
        }
        if (operation == 1){
            scanf("%d", &index_operation);
            free(identifiers[index_operation]);
            identifiers[index_operation] = '\0';
        }
        if (operation == 2){
            scanf("%d", &index_operation);
            printf("%s\n", identifiers[index_operation]);
        }
        if (operation == 3){
            scanf("%d", &index_operation);
            scanf("%c", &symol_for_search);
            while (symol_for_search == ' '){
                scanf("%c", &symol_for_search);
            }
            count_symbol(identifiers[index_operation],symol_for_search);
        }
    }
    for (int i = 0; i < n; i++)
    {
        free(identifiers[i]);
    }
    free(identifiers);
    fclose(stdin);
    fclose(stdout);
}