#include <stdio.h>
int power(char a ,int x, int y){
    if (a == '0'){
        return 0;
    }
    if (y == 0){
        return 1;
    }
    int res = 1;
    for (int i = 0; i < y; i++){
            res = res * x;
        }
    return res;
}

int main(){
    printf("%d", power('1' ,2 , 3));
    printf("%d", 5 / 8);

}