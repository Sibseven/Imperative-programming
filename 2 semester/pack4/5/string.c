#include "decls.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void concat_2(State *state , char *idx0 , char *idx1){
    int index0 = atoi(idx0);
    int index1 = atoi(idx1);
    char* concat = calloc(strlen(state->regs[index0])+strlen(state->regs[index1])+5, sizeof(char));
    strcat(concat, state->regs[index0]);
    strcat(concat, state->regs[index1]);
    char *now_symbol = concat;
    free(state->regs[index0]);
    state->regs[index0] = calloc(strlen(concat)+5, sizeof(char));
    char *now_index0 = state->regs[index0];
    while (*now_symbol !='\0'){
        *now_index0 = *now_symbol;
        now_index0++;
        now_symbol++;
    }
    now_index0 = '\0';
    free(concat);
    
}

void tokenize_1(State *state , char *arg){
    int now_reg = 0;
    char * token = strtok(arg, "_");
    while( token != NULL ){
        now_reg++;
        if(state->regs[now_reg] == NULL){
            state->regs[now_reg] = calloc(strlen(token)+2, sizeof(char));
        }
        else{
            free(state->regs[now_reg]);
            state->regs[now_reg] = calloc(strlen(token)+2, sizeof(char));
        }
        strcpy(state->regs[now_reg], token);
        token = strtok(NULL, "_");
    }
    if(state->regs == NULL){
        state->regs[0] = calloc(100, sizeof(char));
    }
    else{
        free(state->regs[0]);
        state->regs[0] = calloc(100, sizeof(char));
    }
    sprintf(state->regs[0], "%d", now_reg);
}

// int main(){
//     State* ss = malloc(sizeof(State));
//     for(int i = 0; i<256; i++){
//         ss->regs[i] = calloc(256, sizeof(char));
//     }
//     strcpy(ss->regs[0], "123");
//     strcpy(ss->regs[1], "456");
//     concat_2(ss, "0", "1");
//     char prim[100];
//     strcpy(prim, "mama_mila__ramu_");
//     tokenize_1(ss, prim);
//     printf("%s", ss->regs[0]);
// }