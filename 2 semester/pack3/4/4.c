#include <stdio.h>
#include <math.h>
double proisv(double c0, double c1, double c2, double c3, double t, double l){
    double res = c1;
    res -= 2*c2*l;
    res+= 3*c3*l*l;
    res+= (2*c2 - 6*c3*l)*t;
    res += 3*c3*t*t;
    res*= res;
    return res;
}
double length_of_curve_simpson(double a, double b, double l, double* xs, double* ys, double* zs, double f_a, double f_b){
    double res = (b-a)/6;
    double f_2 = 0;
    f_2 += proisv(xs[0], xs[1], xs[2], xs[3], (a+b)/2, l);
    f_2 += proisv(ys[0], ys[1], ys[2], ys[3], (a+b)/2, l);
    f_2 += proisv(zs[0], zs[1], zs[2], zs[3], (a+b)/2, l);
    f_2 = sqrt(f_2);
    f_2 *= 4;
    res*= (f_a + f_2 + f_b);
    return res;

}
int main(){
    freopen("input.txt", "r", stdin);
    int spans;
    scanf("%d", &spans);
    double l_main = 0.0;
    for(int i = 0; i< spans; i++){
        double l, r, a_now, b_now;
        double xs[5] = {0};
        double ys[5] = {0};
        double zs[5] = {0};
        scanf("%lf %lf", &l, &r);
        scanf("%lf %lf %lf %lf", &xs[0], &xs[1], &xs[2], &xs[3]);
        scanf("%lf %lf %lf %lf", &ys[0], &ys[1], &ys[2], &ys[3]);
        scanf("%lf %lf %lf %lf", &zs[0], &zs[1], &zs[2], &zs[3]);
        double f_a = 0;
        f_a += proisv(xs[0], xs[1], xs[2], xs[3], l, l);
        f_a += proisv(ys[0], ys[1], ys[2], ys[3], l, l);
        f_a += proisv(zs[0], zs[1], zs[2], zs[3], l, l);
        f_a = sqrt(f_a);
        double f_b = 0;
        f_b += proisv(xs[0], xs[1], xs[2], xs[3], l+(r - l)/1000, l);
        f_b += proisv(ys[0], ys[1], ys[2], ys[3], l+(r - l)/1000, l);
        f_b += proisv(zs[0], zs[1], zs[2], zs[3], l+(r - l)/1000, l);
        f_b = sqrt(f_b);

        for (double l_r = l; l_r < r; l_r += (r - l)/1000){
            double left = l_r + (r - l)/1000;
            if (left > r){
                left = r;
            }
            f_b = 0;
            f_b += proisv(xs[0], xs[1], xs[2], xs[3], left, l);
            f_b += proisv(ys[0], ys[1], ys[2], ys[3], left, l);
            f_b += proisv(zs[0], zs[1], zs[2], zs[3], left, l);
            f_b = sqrt(f_b);
            l_main += length_of_curve_simpson(l_r, left, l, xs, ys, zs, f_a, f_b);
            f_a = f_b;
        }
    }
    printf("%0.20lf", l_main);
    return 0;
}