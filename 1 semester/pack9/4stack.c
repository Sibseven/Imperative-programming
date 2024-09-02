#include <stdio.h>

void mergesort (int *a, int *b, int num)
{
    int rght, wid, rend;
    int i,j,m,t;

    for (int k=1; k < num; k *= 2 ) {       
        for (int left=0; left+k < num; left += k*2 ) {
            rght = left + k;        
            rend = rght + k;
            if (rend > num) rend = num; 
            m = left; i = left; j = rght; 
            while (i < rght && j < rend) { 
                if (a[i] <= a[j]) {         
                    b[m] = a[i]; i++;
                } else {
                    b[m] = a[j]; j++;
                }
                m++;
            }
            while (i < rght) { 
                b[m]=a[i]; 
                i++; m++;
            }
            while (j < rend) { 
                b[m]=a[j]; 
                j++; m++;
            }
            for (m=left; m < rend; m++) { 
                a[m] = b[m]; 
            }
        }
    }
}

int main(){
    FILE * input = fopen("4.in", "rb");
    FILE * output = fopen("output.txt", "wb");
    int n = 0;
    fread(&n, sizeof(int), 1, input);
    int a[502]  = {0};
    int b[502] = {0};
    fread(a, sizeof(int), n, input);
    mergesort(a, b, n);
    fwrite(a, sizeof(int), n, output);
    fclose(input);
    fclose(output);
    return 0;
}