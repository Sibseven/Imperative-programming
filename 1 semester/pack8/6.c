#include <stdio.h>



int main(){
    FILE * input = fopen("input.txt", "rb");
    FILE * output = fopen("output.txt", "wb");
    char now_byte;
    fread(&now_byte, sizeof(char), 1, input);
    while (now_byte != 0){
        if (now_byte >> 7 == 0){
            int value = now_byte
        }
    }
}