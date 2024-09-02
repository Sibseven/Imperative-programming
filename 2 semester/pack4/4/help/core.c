#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "decls.h"

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

void print_1(State *state, char *idx) {
    int index = atoi(idx);
    if (state->regs[index] != NULL) {
        printf("%s\n", state->regs[index]);
    }
}

void printregs_0(State *state) {
    for (int i = 0; i < 256; i++) {
        if (state->regs[i] != NULL) {
            printf("%d = %s\n", i, state->regs[i]);
        }
    }
}

void store_2(State *state, char *idx, char *what) {
    int index = atoi(idx);
    if (state->regs[index] != NULL) {
        free(state->regs[index]);
    }
    state->regs[index] = strdup(what);
}

void copy_2(State *state, char *dst, char *src) {
    int destIndex = atoi(dst);
    int srcIndex = atoi(src);
    if (state->regs[srcIndex] != NULL) {
        if (state->regs[destIndex] != NULL) {
            free(state->regs[destIndex]);
        }
        state->regs[destIndex] = strdup(state->regs[srcIndex]);
    }
}

void clear_1(State *state, char *idx) {
    int index = atoi(idx);
    if (state->regs[index] != NULL) {
        free(state->regs[index]);
        state->regs[index] = NULL;
    }
}
