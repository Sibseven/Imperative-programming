#include <stdio.h>
#include "primes.h"
#include <assert.h>

int main(){
    assert(isPrime(12345) == 0);
    assert(isPrime(11) == 1);
    assert(isPrime(937) == 1);
    assert(isPrime(936) == 0);
    assert(isPrime(82) == 0);
    assert(isPrime(17) == 1);
    assert(isPrime(16) == 0);
    assert(isPrime(13) == 1);
    assert(isPrime(22) == 0);
    assert(isPrime(65) == 0);
    assert(isPrime(130) == 0);
    assert(isPrime(127241) == 1);
    assert(isPrime(127242) == 0);
    assert(isPrime(58567) == 1);
    assert(isPrime(0) == 0);
    assert(isPrime(10000000) == 0);


    assert(findNextPrime(120) == 127);
    assert(findNextPrime(120) == 127);
    assert(findNextPrime(128) == 131);
    assert(findNextPrime(930) == 937);
    assert(findNextPrime(82) == 83);
    assert(findNextPrime(83) == 83);
    assert(findNextPrime(12346) == 12347);
    assert(findNextPrime(13) == 13);
    assert(findNextPrime(12346) == 12347);
    assert(findNextPrime(130) == 131);
    assert(findNextPrime(58567) == 58567);
    assert(findNextPrime(58566) == 58567);
    assert(findNextPrime(58568) == 58573);
    assert(findNextPrime(10000000) == 10000019);


    assert (getPrimesCount(11, 79) == 17);
    assert (getPrimesCount(79, 179) == 19);
    assert (getPrimesCount(4, 179) == 38);
    assert (getPrimesCount(6, 179) == 37);
    assert (getPrimesCount(67, 294) == 44);
    assert (getPrimesCount(67, 292) == 43);
    assert (getPrimesCount(5682, 24630) == 1981);
    assert (getPrimesCount(4002, 5988) == 232);



    assert (getPrimesCount(128, 240) == 21);
    assert (getPrimesCount(2, 6) == 3);
    assert (getPrimesCount(1, 6) == 3);
    assert (getPrimesCount(0, 5) == 2);
    assert (getPrimesCount(1, 1000007) == 78499);
    assert (getPrimesCount(5, 5) == 0);
    assert (getPrimesCount(5, 6) == 1);
    assert (getPrimesCount(123, 234) == 21);
    assert (getPrimesCount(211, 463) == 43);
    assert (getPrimesCount(352, 790) == 68);

    assert (getPrimesCount(0, 10000000) == 664579);
    return 0;
}