int main(){
    MOD = 37;
    int a = -10;
    a = pnorm(a);
    assert(a == 27);
    a  = padd(10, 30);
    assert(a == 3);
    a = psub(10, 30);
    assert(a == 17);
    MOD = 10^7+7;
    assert(pmul(10000000, 10000000) == 49);
    assert(pdiv(10, 32567) == 9258920);
    return 0;
}