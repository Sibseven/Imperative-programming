#include <stdio.h>
#include <stdlib.h>
//merges sorted arrays a[0..ak-1] and b[0..bk-1] into
//one sorted array res[0..rk-1], returning rk from function
int merge(const int *a, int ak, const int *b, int bk, int *res){
    int a_now = 0;
    int b_now = 0;
    int res_now = 0;
    while (ak != a_now && bk != b_now){
        if (a[a_now] < b[b_now]){
            res[res_now] = a[a_now];
            res_now++;
            a_now++;
        }
        else{
            res[res_now] = b[b_now];
            res_now++;
            b_now++;
        }
    }
    while (ak != a_now){
        res[res_now] = a[a_now];
        res_now++;
        a_now++;
    }
    while (bk != b_now){
        res[res_now] = b[b_now];
        res_now++;
        b_now++;
    }
    return ak+bk;
}
int main(){
    FILE * input = fopen("input.txt", "rb");
    FILE * output = fopen("output.txt", "wb");
    int first_num  = 0;
    int second_num = 0;
    fread(&first_num, sizeof(int), 1, input);
    fread(&second_num, sizeof(int), 1, input);
    int* first_seq = calloc(first_num, sizeof(int));
    int* second_seq = calloc(second_num, sizeof(int));
    int* res = calloc(first_num+second_num, sizeof(int));
    fread(first_seq, sizeof(int), first_num, input);
    fread(second_seq, sizeof(int), second_num, input);
    int res_kol = merge(first_seq, first_num, second_seq, second_num, res);
    for (int i = 0; i < res_kol; i++){
        int now = res[i];
        fwrite(&now, sizeof(int), 1, output);
    }
    free(first_seq);
    free(second_seq);
    free(res);
    fclose(input);
    fclose(output);
    return 0;
}