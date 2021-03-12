#include <assert.h>

/**
 * Return nth item of fibonacci.
 * @param n the nth.
 * @return the nth item of fibonacci.
 */
int fib(int n) {
    return n == 1 || n == 2 ? 1 : fib(n - 1) + fib(n - 2);
}

void test() {
    int fibonacci[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    for (int i = 0; i < 10; ++i) {
        assert(fib(i + 1) == fibonacci[i]);
    }
}

int main() {
    test();
    return 0;
}

