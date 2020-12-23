#include <assert.h>

/**
 * Returns the value of the first argument raised to the power of the second argument using recursion.
 * @param a the base.
 * @param b the exponent.
 * @return the value {@code a}<sup>{@code b}</sup>.
 */
long pow(int a, int b) {
    return b == 0 ? 1 : a * pow(a, b - 1);
}

void test() {
    assert(1 == pow(0, 0));
    assert(0 == pow(0, 10));
    assert(1 == pow(1, 0));
    assert(2 == pow(2, 1));
    assert(625 == pow(25, 2));
}

int main() {
    test();
    return 0;
}

