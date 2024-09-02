#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc == 1){
        fprintf(stderr, "No parameters specified.");
        return 13;
    }
    if (argc == 4){
        long long a1 = atoll(argv[2]);
        long long a2 = atoll(argv[3]);
        if (strcmp(argv[1], "add") == 0){
            fprintf(stdout, "%lld", a1+a2);
            return 0;
        }
        else if(strcmp(argv[1], "sub") == 0){
            fprintf(stdout, "%lld", a1 - a2);
            return 0;
        }
        long long ans = a1 * a2;
        fprintf(stdout, "%lld", ans);
        return 0;
    }
    if (strcmp(argv[1], "-m") == 0){
        long long m = atoll(argv[2]);
        long long a1 = atoll(argv[4]);
        long long a2 = atoll(argv[5]);
        if (strcmp(argv[3], "add") == 0){
            long long ans = (a1+a2)%m;
            if (ans < 0) ans = (m+ans);
            fprintf(stdout, "%lld", ans);
            return 0;
        }
        else if(strcmp(argv[3], "sub") == 0){
            long long ans = (a1 - a2)%m;
            if (ans < 0) ans = (m+ans);
            fprintf(stdout, "%lld", ans);
            return 0;
        }
        long long ans = (a1 * a2)%m;
        if (ans < 0) ans = ans + m;
        fprintf(stdout, "%lld", ans);
        return 0;
    }
    long long m = atoll(argv[5]);
    long long a1 = atoll(argv[2]);
    long long a2 = atoll(argv[3]);
    if (strcmp(argv[1], "add") == 0){
        long long ans = (a1 + a2)%m;
        if (ans < 0) ans = (m+ans);
        fprintf(stdout, "%lld", ans);
        return 0;
    }
    else if(strcmp(argv[1], "sub") == 0){
        long long ans = (a1 - a2)%m;
        if (ans < 0) ans = (m+ans);
        fprintf(stdout, "%lld", ans);
        return 0;
    }
    long long ans = (a1 * a2)%m;
    if (ans < 0) ans = ans + m;
    fprintf(stdout, "%lld", ans);
    return 0;
}