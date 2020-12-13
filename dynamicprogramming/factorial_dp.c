#include <assert.h>

/**
 * Return the factorial of a number.
 * @param n the number.
 * @return the factorial of n.
 */
int factorial(int n) {
    int fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    return fact[n];
}

void test() {
    assert(1 == factorial(0));
    assert(1 == factorial(1));
    assert(2 == factorial(2));
    assert(6 == factorial(3));
    assert(24 == factorial(4));
    assert(120 == factorial(5));
}

int main() {
    test();
    return 0;
}
