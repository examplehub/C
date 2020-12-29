#include <assert.h>

/**
 * Calculate the greatest common divisor of two numbers.
 * @param a the first number.
 * @param b the second number.
 * @return the greatest common divisor of given two numbers.
 */
int gcd(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    int t = 1;
    while (t != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

/**
 * Calculate the least common multiple of two numbers.
 * @param a the first number.
 * @param b the second number.
 * @return the least common multiple of given two numbers.
 */
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void test() {
    assert(lcm(15, 25) == 75);
    assert(lcm(15, 45) == 45);
}

int main() {
    test();
    return 0;
}