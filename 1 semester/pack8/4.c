#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *inputt = fopen("input.txt", "rb");
    FILE *output = freopen("output.txt", "w", stdout);
    signed int document_size = 0;
    fread(&document_size, sizeof(signed int), 1, inputt);
    printf("%c\n", '{');
    int t = 0;
    fread(&t, sizeof(char), 1,inputt);
    for (int i = 0; i < document_size; i++){
        if (t == '\0') break;
        char now_name;
        fread(&now_name, sizeof(char), 1, inputt);
        printf("    ");
        printf("%c", '"');
        while (now_name != '\0'){
            printf("%c", now_name);
            fread(&now_name, sizeof(char), 1, inputt);
        }
        printf("%c", '"');
        printf(": ");
        if (t == 1){
            double value = 0;
            fread(&value, sizeof(double), 1, inputt);
            fread(&t, sizeof(char), 1,inputt);
            if (t == '\0'){
                printf("%0.15g\n", value);
            }
            else {
                printf("%0.15g,\n", value);
            }
        }
        else if (t == 2){
            signed int size_str;
            fread(&size_str, sizeof(signed int), 1, inputt);
            char value;
            printf("%c", '"');
            for (int i = 0; i < size_str - 1; i++){
                fread(&value, sizeof(char),1, inputt);
                printf("%c", value);
            }
            fread(&value, sizeof(char), 1, inputt);
            printf("%c", '"');
            fread(&t, sizeof(char), 1,inputt);
            if (t == '\0'){
                printf("\n");
            }
            else {
                printf(",\n");
            }
        }
        else if (t == 8){
            char value;
            fread(&value, sizeof(char), 1, inputt);
            if (value == 1){
                fread(&t, sizeof(char), 1,inputt);
                if (t == '\0'){
                    printf("true\n");
                }
                else {
                    printf("true,\n");
                }
            }
            else{
                fread(&t, sizeof(char), 1,inputt);
                if (t == '\0'){
                    printf("false\n");
                }
                else {
                    printf("false,\n");
                }
            }
        }
        else if (t == 10){
            fread(&t, sizeof(char), 1,inputt);
            if (t == '\0'){
                printf("null\n");
            }
            else {
                printf("null,\n");
            }
        }
        else if (t == 16){
            signed int value = 0;
            fread(&value, sizeof(signed int), 1, inputt);
            fread(&t, sizeof(char), 1,inputt);
            if (t == '\0'){
                printf("%d\n", value);
            }
            else {
                printf("%d,\n", value);
            }
        }
        else if (t == 18){
            long long int value = 0;
            fread(&value, sizeof(long long int), 1, inputt);
            fread(&t, sizeof(char), 1,inputt);
            if (t == '\0'){
                printf("%lld\n", value);
            }
            else {
                printf("%lld,\n", value);
            }
        }
    }
    printf("%c", '}');
    return 0;
}