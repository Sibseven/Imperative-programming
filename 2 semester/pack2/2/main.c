#include "modular.h"
#include <assert.h>

int main () {
    MOD = 13;
    //устанавливаем глобальный модуль
    int a = 45;
    a = pnorm (a);
    assert ( a == 6);
    int x = pmul ( padd (7 , psub (2 , 3)) , 5);
    assert ( x == 4);
    int y = pdiv (7 , x );
    assert ( pmul (x , y ) == 7);
    MOD = 2;
    //меняем модуль на другой
    assert ( pnorm (5) == 1);
    MOD = 37;
    a = -10;
    a = pnorm(a);
    assert(a == 27);
    a  = padd(10, 30);
    assert(a == 3);
    a = psub(10, 30);
    assert(a == 17);
    MOD = 1000007;
    long long x1 = 999999, y1 = 999999;
    assert(pmul(x1, y1) == ((x1 * y1) % MOD));
    MOD = 999999937;
    long long x2 = 123456, y2 = 123456;
    long long result_div = pdiv(x2, y2);
    assert(result_div == 1);
    return 0;
}