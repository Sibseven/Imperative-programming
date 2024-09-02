#include <stdio.h>
#include <stdlib.h>
#pragma pack(push, 1)

typedef struct Node{
    unsigned int key;
    unsigned int value;
} Node;

void CountSort(Node* arr, int n, int place_number){
    Node* sorted = calloc(n, sizeof(Node));
    int count[256] = {0};

    for(int i = 0; i < n; i++){
        count[arr[i].key >> (place_number * 8) & 0xff]++;
    }
    for(int i = 1; i < 256; i++){
        count[i] += count[i - 1];
    }
    for(int i = n - 1; i >= 0; i--){
        sorted[count[arr[i].key >> (place_number * 8) & 0xff] - 1] = arr[i];
        count[((arr[i].key >> (place_number * 8)) & 0xff)]--;
    }
    for (int i = 0; i < n; i++){
        arr[i] = sorted[i];
    }
    free(sorted);

}

void RadixSort(Node* arr, int n){
    for (int i = 0; i < 4; i ++){
        CountSort(arr, n, i);
    }
}


int main(){
    FILE * input = fopen("input.txt", "rb");
    FILE * output = fopen("output.txt", "wb");
    int n = 0;
    fread(&n, sizeof(int), 1, input);
    Node * arr = calloc(n, sizeof(Node));
    // 
    fread(arr, sizeof(Node), n, input);
    RadixSort(arr, n);
    fwrite(arr, sizeof(Node), n, output);
    fclose(input);
    fclose(output);
    free(arr);
    return 0;
}