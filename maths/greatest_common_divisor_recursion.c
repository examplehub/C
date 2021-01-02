#include <assert.h>

/**
 * Calculate the greatest common divisor of two numbers using recursion.
 * @param a the first number.
 * @param b the second number.
 * @return the greatest common divisor of given two numbers.
 */
int gcd(int a, int b) {
    if (a == 0 || b == 0) {
        return a == 0 ? b : a;
    } else {
        return gcd(b, a % b);
    }
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
