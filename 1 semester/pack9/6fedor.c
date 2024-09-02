#include "stdio.h"
#include "malloc.h"
#include "stdint.h"


typedef struct key_val
{
    uint32_t key;
    uint32_t val;
} Key_val;

void radix(Key_val *arr, int n);

int main()
{
    FILE *out = fopen("output.txt", "wb");
    FILE *in = fopen("6.in", "rb");
    uint32_t n;
    fread(&n, 4, 1, in);
    Key_val *arr = malloc(n * sizeof(Key_val));
    fread(arr, 8, n, in);

    radix(arr, n);

    fwrite(arr, 8, n, out);

    free(arr);
    fclose(in);
    fclose(out);
    return 0;
}

Key_val *c_sort(Key_val *arr, int len, int round)
{
    int *counts = calloc(256, sizeof(int));

    uint32_t tail;
    for (int i = 0; i < len; i++)
    {
        tail = (arr[i].key >> (8 * (round - 1))) % 256;
        counts[tail]++;
    }
    uint32_t *indexes = calloc(256, sizeof(int));
    for (int i = 1; i < 256; i++)
    {
        indexes[i] = counts[i - 1] + indexes[i - 1];
    }
    Key_val *sorted = malloc(sizeof(Key_val) * len);
    for (int i = 0; i < len; i++)
    {
        tail = (arr[i].key >> (8 * (round - 1))) % 256;
        sorted[indexes[tail]] = arr[i];
        indexes[tail]++;
    }
    free(arr);
    free(indexes);
    free(counts);
    return sorted;
}

void radix(Key_val *arr, int n)
{
    for (int i = 0; i < 4; i++)
    {
        arr = c_sort(arr, n, i + 1);
    }
}
