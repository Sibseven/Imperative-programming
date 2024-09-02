#include <stdio.h>
#include <stdlib.h>


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    unsigned long long  all_masks[30050];
    for (int i = 0; i < n; i++){
        scanf("%llx", &all_masks[i]);
    }
    int counter = 0;
    for (int i = 0; i<n-1; i++){
        for (int j = i+1; j < n; j++){
            unsigned long long new = all_masks[i]&all_masks[j];
            if (new == 0){
                counter++;
            }
        }
    }
    printf("%d", counter);
    fclose(stdin);
    fclose(stdout);
    return 0;
}