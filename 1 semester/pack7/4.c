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
    int prev_search = 0, now_search = 0;
    for (int i = 0; i < num_of_seraches; i++){
        int left = 0, right = number_of_elem-1, flag = 0;
        int now_scan;
        scanf("%d", &now_scan);
        now_search = now_scan + prev_search;
        while (left <= right){
            int mid = left + (right-left)/2;
            if (arr[mid] == now_search){
                if (arr[mid+1] == now_search){ //зоново запускаем бинпоиск чтобы найти макс индекс подходящего 
                    left = mid+1;
                    continue;
                }
                else{
                    printf("%d\n",mid);
                    prev_search = mid;
                    flag = 1;
                    break;
                }
            } 
            if (arr[mid] < now_search){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        if (flag != 1){ // не нашли
            printf("-1\n");
            prev_search = -1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}