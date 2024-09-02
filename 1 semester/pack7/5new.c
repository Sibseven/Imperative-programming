#include <stdio.h>
#include <stdlib.h>

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int number_of_elem, num_of_seraches;
    scanf("%d", &number_of_elem);
    int arr[200020];
    for (int i = 0; i < number_of_elem; i++){scanf("%d", &arr[i]);}
    scanf("%d", &num_of_seraches);
    for (int i = 0; i < num_of_seraches; i++){
        int left = 0, right = number_of_elem-1, flag = 0;
        int now_scan;
        scanf("%d", &now_scan);
        while (right - left > 1){
            int mid = (left + right)/2;
            if (arr[mid] == now_scan){
                flag = 1;
                printf("%d %d\n", mid, 0);
                break;
            } 
            if (arr[mid] < now_scan){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        if (flag != 1){
            if (abs(arr[left] - now_scan) > abs(arr[right] - now_scan)){
                printf("%d %d\n", right, abs(arr[right] - now_scan));
                continue;
            }
            printf("%d %d\n", left, abs(arr[left] - now_scan));
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}