#include <stdio.h>

typedef struct Node{
    char replace[65];
    int len;
} Node;
int pow_int( int a, int b){
    int res = 0;
    for (int i = 0; i < b; i++){
        res *= a;
    }
    return res;
}
int main(){
    FILE* input = fopen("input.txt", "rb");
    FILE* output = fopen("output.txt", "wb");
    signed int num_of_symbols = 0;
    fread(&num_of_symbols, sizeof(signed int), 1, input);
    Node arr[100001] = {0};
    for (int i = 0; i < num_of_symbols; i++){
        int num_of_bit;
        fread(&num_of_bit, sizeof(int), 1, input);
        arr[i].len = num_of_bit;
        for (int j = 0; j < num_of_bit; j++){
            fread(&arr[i].replace[j], sizeof(unsigned char), 1, input);
        }
    }
    int len_of = 0;
    int buff[8] = {0};
    int k = 0;
    fread(&len_of, sizeof(int), 1, input);
    for (int i = 0; i < len_of; i++){
        short int now_symbol;
        fread(&now_symbol, sizeof(short int), 1, input);
        for (int j = 0; j < arr[now_symbol].len; j++){
            buff[k] = arr[now_symbol].replace[j];
            k++;
            if (k == 8){
                unsigned char now_word = 0;
                for (int pos = 7; pos >= 0; pos--){
                    now_word <<= 1;
                    now_word += buff[pos];
                }
                fwrite(&now_word, sizeof(unsigned char), 1, output);
                k = 0;
            }
        }
    }
    if (k != 0){
        unsigned char last_word = 0;
        for (int pos = k - 1; pos >= 0; pos--){
            last_word <<= 1;
            last_word += buff[pos];
        }
        fwrite(&last_word, sizeof(unsigned char), 1, output);
    }
    
    fclose(input);
    fclose(output);
}