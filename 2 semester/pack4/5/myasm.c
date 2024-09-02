
#include "decls.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*FuncDllArg0)(State* state);
typedef void (*FuncDllArg1)(State* state, char* arg1);
typedef void (*FuncDllArg2)(State* state, char* arg1, char* arg2);
typedef void (*FuncDllArg3)(State* state, char* arg1, char* arg2, char* arg3);

int main(){
    State* global_state = malloc(sizeof(State));
    char *now_command = malloc(sizeof(char)*500);
    while (fgets(now_command, 500, stdin) != NULL){
        
        if (now_command == "\n\r" || now_command == "\r" || now_command == "\n" || now_command == "" || now_command == "\0"){
            break;
        }
        for(char *i = now_command; *i != '\0'; i++){
            if(*i == '\n' || *i == '\r'){
                *i = '\0';
            }
        }
        int args_kol = 0;
        char plugin_command[100] = {0};
        char plugin[100] = {0};
        char command[100] = {0};
        int only_command = 1;
        char arg1[100] = {0};
        char arg2[100] = {0};
        char arg3[100] = {0};
        char path[100] = {0};
        path[0] = '.';
        path[1] = '/';
        char* token = strtok(now_command, " ");
        if(token == NULL){
            break;
        }
        strcpy(plugin_command, token);
    
        token = strtok(NULL, " ");
        while (token != NULL){
            if (args_kol == 0){
                strcpy(arg1, token);
            }
            if (args_kol == 1){
                strcpy(arg2, token);
            }
            if (args_kol == 2){
                strcpy(arg3, token);
            }
            args_kol++;
            token = strtok(NULL, " ");
        }
        char* token_plugin_command = strtok(plugin_command, ":");
        strcpy(plugin, token_plugin_command);
        token_plugin_command = strtok(NULL, ":");
        if(token_plugin_command != NULL){
            strcpy(command, token_plugin_command);
            only_command = 0;
        }
        if(only_command == 1){
            strcpy(command, plugin);
            strcpy(plugin, "core");
        }
        strcat(plugin, ".so");
        strcat(path, plugin);
        void *now_dll = dlopen(path, RTLD_LAZY);
        char* no_so = strtok(plugin, ".");
        if(now_dll == NULL){
            printf("Missing plugin %s\n", no_so);
            continue;
        }
        if (args_kol == 0){
            strcat(command, "_0");
            FuncDllArg0 myfunc = (FuncDllArg0)dlsym(now_dll, command);
            if(myfunc == NULL){
                printf("Missing function %s in plugin %s\n", command, no_so);
                dlclose(now_dll);
                continue;
            }
            myfunc(global_state);

        }
        if (args_kol == 1){
            strcat(command, "_1");
            FuncDllArg1 myfunc = (FuncDllArg1)dlsym(now_dll, command);
            if(myfunc == NULL){
                printf("Missing function %s in plugin %s\n", command, no_so);
                dlclose(now_dll);
                continue;
            }
            myfunc(global_state, arg1);
        }
        if (args_kol == 2){
            strcat(command, "_2");
            FuncDllArg2 myfunc = (FuncDllArg2)dlsym(now_dll, command);
            if(myfunc == NULL){
                printf("Missing function %s in plugin %s\n", command, no_so);
                dlclose(now_dll);
                continue;
            }
            myfunc(global_state, arg1, arg2);
        }
        if (args_kol == 3){
            strcat(command, "_3");
            FuncDllArg3 myfunc = (FuncDllArg3)dlsym(now_dll, command);
            if(myfunc == NULL){
                printf("Missing function %s in plugin %s\n", command, no_so);
                dlclose(now_dll);
                continue;
            }
            myfunc(global_state, arg1, arg2, arg3);
        }
        dlclose(now_dll);
    }
    free(now_command);
    return 0;
    
}