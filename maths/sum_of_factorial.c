#include <assert.h>

/**
 * Calculate 1! + 2! + 3! + ... n! using recursion.
 */
int sumOfFactorial(int i, int n) {
    return i == n ? n : i + i * sumOfFactorial(i + 1, n);
}

int sumFactorial(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1 + 1 * 2; /* 1! + 2! */
    } else {
        return sumFactorial(n - 1) + (sumFactorial(n - 1) - sumFactorial(n - 2)) * n;
    }
}

void test() {
    assert(sumOfFactorial(1, 1) == 1);
    assert(sumOfFactorial(1, 2) == 3);
    assert(sumOfFactorial(1, 3) == 9);
    assert(sumOfFactorial(1, 4) == 33);
    assert(sumOfFactorial(1, 5) == 153);

    assert(sumFactorial(1) == 1);
    assert(sumFactorial(2) == 3);
    assert(sumFactorial(3) == 9);
    assert(sumFactorial(4) == 33);
    assert(sumFactorial(5) == 153);
}

int main() {
    test();
    return 0;
}