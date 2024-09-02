#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *inputt = fopen("input.txt", "rb");
    FILE *output = fopen("output.txt", "wb");
    signed int first = 0;
    signed int second = 0;
    fread(&first, sizeof(signed int), 1, inputt);
    fread(&second, sizeof(signed int), 1, inputt);
    signed long long int res = (signed long long int)first+ (signed long long int) second;
    if (res % 2 == -1){
        res = res /2;
        res--;
    }
    else {
        res =res / 2;
    }
    signed int res2 = (signed int) res;
    printf("%d\n", res2);
    fwrite(&res2, sizeof(signed int), 1, output);
    return 0;
}
