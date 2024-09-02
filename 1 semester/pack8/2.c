#include <stdio.h>
#include <stdlib.h>
signed int swap_32_bit(signed int number){
    signed int byte1, byte2, byte3, byte4;
    byte1 = (number & 0xFF000000) >> 24;
    byte2 = (number & 0x00FF0000) >> 8;
    byte3 = (number & 0x0000FF00) << 8;
    byte4 = (number & 0x000000FF) << 24;
    signed int res = byte1 | byte2 | byte3 | byte4;
    return res;
}

int main(){
    FILE *inputt = fopen("input.txt", "rb");
    FILE *output = fopen("output.txt", "wb");
    signed int n = 0;
    fread(&n, sizeof(signed int), 1, inputt);
    signed int nums[10010];
    signed long long int res = 0;
    signed int res2  = 0;
    if (n > 10000 | n < 1){
        n = swap_32_bit(n);
        for (int i = 0; i < n; i++){
        signed int now = 0;
        fread(&now, sizeof(signed int), 1, inputt);
        now = swap_32_bit(now);
        res += (signed long long int) now;
        }
        res2 = (signed int) res;
        res2 = swap_32_bit(res2);
    }
    else{
        for (int i = 0; i < n; i++){
        signed int now = 0;
        fread(&now, sizeof(signed int), 1, inputt);
        res += (signed long long int) now;
        }
        res2 = (signed int) res;
    }
    
    printf("%d\n", res2);
    fwrite(&res2, sizeof(signed int), 1, output);
    return 0;
}
