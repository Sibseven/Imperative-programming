#include <stdio.h>

void ShiftDown(int* arr, int n, int now)
{
    int largest = now;
    int left = 2*now + 1;

    int right = 2*now + 2;
    if (left < n && arr[left] > arr[largest])
 
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != now) {
        int temp = arr[now];
        arr[now] = arr[largest];
        arr[largest] = temp;
        ShiftDown(arr, n, largest);
    }
}
void heapSort(int* arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        ShiftDown(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        ShiftDown(arr, i, 0);
    }
}
int main(){
    FILE *input = fopen("input.bin", "rb");
    FILE *output = fopen("output.bin", "wb");
    int n;
    fread(&n, sizeof(int), 1, input);
    int arr[500000];
    fread(arr, sizeof(int), n, input);
    heapSort(arr, n);
    fwrite(arr, sizeof(int), n, output);
    fclose(input);
    fclose(output);
    return 0;
}