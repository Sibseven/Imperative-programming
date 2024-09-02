#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000006

typedef struct vector{
    char **string_arr;  //указатель на массив, выделенный на куче
    int next_free;      // номер следующего свободного элемента    
    int cnt;            //сколько элементов в массиве реально есть
    int cap;            //сколько выделено
} Vector;

int main(){
    FILE *input = freopen("input.txt", "r", stdin);
    FILE *output = freopen("output.txt", "w", stdout);
    int n = 0;
    scanf("%d", &n);
    Vector* arr_all = calloc(N, sizeof(Vector));
    for (int i = 0; i < N; i++){
        arr_all[i].cnt = 0;
    }
    for (int i = 0; i < n; i++){
        int number;
        char val[8];
        scanf("%d %s", &number, val);//ВВОД ЕСТЬ, ОСТАЛОСЬ ЛОГИКУ
        if (arr_all[number].cap == 0){
            arr_all[number].string_arr = calloc(1, sizeof(char *));  // память для массива строк 
            arr_all[number].string_arr[arr_all[number].next_free] = calloc(8, sizeof(char)); // память для первой строчки 
            strcpy(arr_all[number].string_arr[arr_all[number].next_free], val); 
            arr_all[number].cap = 1; 
            arr_all[number].cnt = 1;
            arr_all[number].next_free = 1;
        }
        else{
            if (arr_all[number].cap == arr_all[number].cnt){
                arr_all[number].string_arr = realloc(arr_all[number].string_arr, sizeof(char *)*arr_all[number].cap*2);
                arr_all[number].cap *= 2;
                arr_all[number].string_arr[arr_all[number].next_free] = calloc(8, sizeof(char));
                strcpy(arr_all[number].string_arr[arr_all[number].next_free], val);
                arr_all[number].cnt += 1;
                arr_all[number].next_free += 1;
            }
            else{
                arr_all[number].string_arr[arr_all[number].next_free] = calloc(8, sizeof(char));
                strcpy(arr_all[number].string_arr[arr_all[number].next_free], val);
                arr_all[number].cnt += 1;
                arr_all[number].next_free += 1;
            }
        }
    }
    for (int i = 0; i < N; i++){
        int count = arr_all[i].cnt;
        for(int j = 0; j < arr_all[i].cnt; j++){
            printf("%d %s\n", i, arr_all[i].string_arr[j]);
            free(arr_all[i].string_arr[j]);
        }
        free(arr_all[i].string_arr);
        
    }
    free(arr_all);
    fclose(input);
    fclose(output);
    return 0;
}