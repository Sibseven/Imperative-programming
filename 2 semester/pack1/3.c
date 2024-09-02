#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");
    char input[120] = {0};
    char* params[120];
    for (int i = 0; i < 120; i++){
        params[i] = calloc(120, sizeof(char));
    }
    char* result;
    result = fgets(input, 110, input_file);
    char* now_symbol = input;
    int now_param = 0;
    char* now_symbol_in_param = params[now_param];
    while (*now_symbol != '\0' && *now_symbol !='\n')
    {
        if (*now_symbol == '"' ){ //обработка слова в кавычках 
            now_symbol++;
            while (*now_symbol != '"')
            {
                *now_symbol_in_param = *now_symbol; // считываем до след кавычки параметр
                now_symbol_in_param ++;
                now_symbol++;
            }
            now_param++;
            now_symbol_in_param = params[now_param]; // смещаем указатель, чтобы обработать новый парметр
            now_symbol++;
            continue;
        }
        if (*now_symbol != 32 && *now_symbol!= '\0' && *now_symbol !='\n'){ // считываем параметр без кавычек
            while (*now_symbol != 32 && *now_symbol != '\0' && *now_symbol !='\n')
            {
                *now_symbol_in_param = *now_symbol; // идем до след пробела или символа перевода строки
                now_symbol++;                       // или до конца строки
                now_symbol_in_param++;
            }
            now_param++;
            now_symbol_in_param = params[now_param]; // смещаем указатель для след параметра
            continue;
        }
        now_symbol++; //отрабатывает в случае пробела(не внутри слова), просто смещаемся 
    }
    for (int i = 0; i < now_param; i++){
        fprintf(output_file,"[%s]\n", params[i]);
    }
    for(int i = 0; i < 120; i++){
        free(params[i]);
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}