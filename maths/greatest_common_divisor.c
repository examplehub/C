#include <assert.h>
#include <stdlib.h>

/**
 * Calculate the greatest common divisor of two numbers.
 * @param a the first number.
 * @param b the second number.
 * @return the greatest common divisor of given two numbers.
 */
int gcd(int a, int b) {
    if (a == 0 || b == 0) {
        return abs(a - b);
    }
    int t = 1;
    while (t != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void test() {
    assert(gcd(10, 15) == 5);
    assert(gcd(10, 0) == 10);
    assert(gcd(0, 10) == 10);
    assert(gcd(15, 17) == 1);
}

int main() {
    test();
    return 0;
}
