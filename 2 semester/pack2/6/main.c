#include <stdio.h>
#include <stdlib.h>
extern double Function(double x);
// double Function(double x) {
//     if (x < 0.0 || x > 1.0) 
//         exit (666); //out of range
//     return x * x - x;
// }
double derivative(double x){
    double delta = 0.00000001;
    double check = x+delta;
    double verh, res;
    if (check > 1.0){
        verh = Function(x) - Function(x - delta);
        res = verh / delta;
        
    }
    else{
        verh = Function(check) - Function(x);
        res = verh / delta;
    }
    return res;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int number_of_dots;
    double dots[1010];
    scanf("%d", &number_of_dots);
    for (int i = 0; i < number_of_dots; i++){
        scanf("%lf", &dots[i]);
    }
    for (int i = 0; i < number_of_dots; i++){
        printf("%lf\n", derivative(dots[i]));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}