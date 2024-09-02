#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define INPUT "input.txt"
#define OUTPUT "output.txt"



int main(){
    int N = 0;
    FILE * fp = fopen(INPUT, "rb");
    fread(&N, sizeof(int), 1, fp);
    
    short * arr[N];
    int k = 0;
    for(int i = 0; i < N; i++){
        int L;
        fread(&L, sizeof(int), 1, fp);
        arr[i] = (short*)malloc(sizeof(short) * L);
        for(int j = 0; j < L; j++){
            unsigned char b;
            fread(&b, sizeof(unsigned char), 1, fp);
            arr[i][j] = b;
        }
        k+=1;
    }
    
    
    int M;
    fread(&M, sizeof(int), 1, fp);
    FILE * f = fopen(OUTPUT, "wb");

    
    int l = 0;
    short massiv[8];
    int kkk = 0;
   
    for(int i = 0; i < M; i++){
        short b;
        fread(&b, sizeof(short), 1, fp);
        int len = _msize(arr[b])/sizeof(short);
        for(int j = 0; j < len; j++){
            massiv[l] = arr[b][j];
            l+=1;
            if(l == 8){
                unsigned char res = 0;
                for(int kkk = 7; kkk >= 0; kkk--){
                    res <<= 1;
                    res += massiv[kkk];
                }
                //printf("%d %x\n", res, res);
                fwrite(&res, sizeof(unsigned char), 1, f);
                l = 0;
            }
        }
    }
    if(l != 0){
        unsigned char res = 0;
        for(int kkk = l-1; kkk >= 0; kkk--){
            res <<= 1;
            res += massiv[kkk];
        }
        //printf("%d %x\n", res, res);
        fwrite(&res, sizeof(unsigned char), 1, f);
    }

    for(int i = 0; i < k; i++){
        free(arr[i]);
    }


    fclose(fp);
    fclose(f);
    

    return 0;
}
