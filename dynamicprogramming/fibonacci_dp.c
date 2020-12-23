#include <assert.h>

/**
 * Get nth fibonacci number.
 * @param nth the nth
 * @return nth fibonacci number.
 */
int fibonacci(int nth) {
    int fibs[nth + 1];
    fibs[0] = 0;
    fibs[1] = 1;
    for (int i = 2; i <= nth; ++i) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
    return fibs[nth];
}

void test() {
    assert(0 == fibonacci(0));
    assert(1 == fibonacci(1));
    assert(1 == fibonacci(2));
    assert(34 == fibonacci(9));
}

int main() {
    test();
    return 0;
}

