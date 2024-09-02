#include "decls.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void echo_0(State *state) {
    printf("ECHO:\n");
}

void echo_1(State *state, char *arg0) {
    printf("ECHO: %s\n", arg0);
}

void echo_2(State *state, char *arg0, char *arg1) {
    printf("ECHO: %s|%s\n", arg0, arg1);
}

void echo_3(State *state, char *arg0, char *arg1, char *arg2) {
    printf("ECHO: %s|%s|%s\n", arg0, arg1, arg2);
}

void print_1(State *state , char *idx){
    if(state->regs[atoi(idx)] != NULL){
        printf("%s\n", state->regs[atoi(idx)]);
    }
}

void printregs_0(State *state){
    for(int i = 0; i<256; i++){
        if(state->regs[i] != NULL){
            printf("%d = %s\n", i, state->regs[i]);
        }
    }
}

void store_2(State *state , char *idx , char *what){
    int store_to = atoi(idx);
    if (state->regs[store_to] != NULL){
        free(state->regs[store_to]);
    }
    state->regs[store_to] = malloc(sizeof(char)*strlen(what)+2);
    strcpy(state->regs[store_to], what);
}

void copy_2(State *state , char *dst , char *src){
    int D = atoi(dst), S = atoi(src);
    if (state->regs[S] != NULL) {
        if (state->regs[D] != NULL) {
            free(state->regs[D]);
        }
        state->regs[D] = malloc(sizeof(char)*strlen(state->regs[S])+2);
        strcpy(state->regs[D], state->regs[S]);
    }
}

void clear_1(State *state, char *idx) {
    int clear = atoi(idx);
    if (state->regs[clear] != NULL) {
        free(state->regs[clear]);
        state->regs[clear] = NULL;
    }
}