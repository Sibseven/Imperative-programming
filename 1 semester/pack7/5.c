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
        int left = 0, right = number_of_elem-1;
        int now_scan;
        scanf("%d", &now_scan);
        while (left <= right){
            int mid = (left + right)/2;
            if (arr[mid] == now_scan ){
                printf("%d %d\n", mid, 0);
                break;
            } 
            else if (arr[mid] < now_scan && (abs(arr[mid + 1] - now_scan) <= abs(arr[mid] - now_scan))){
                left = mid + 1;
            }
            else if (arr[mid] > now_scan && (abs(arr[mid - 1] - now_scan) <= abs(arr[mid] - now_scan))){
                right = mid - 1;
            }
            else{
                printf("%d %d\n", mid, arr[mid]);
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}