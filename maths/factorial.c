#include <assert.h>
#include <stdio.h>

/**
 * Return the factorial of a given number.
 * @param number the number
 * @return the factorial of a given number.
 */
long factorial(int number) {
    long factorial = 1;
    for (int i = 1; i <= number; ++i) {
        factorial *= i;
    }
    return factorial;
}

void test() {
    int testNumbers[][2] = {{0, 1},
                            {1, 1},
                            {2, 2},
                            {3, 6},
                            {4, 24},
                            {5, 120}};
    assert(sizeof(testNumbers) / sizeof(testNumbers[0]) == 6);
    for (int i = 0; i < sizeof(testNumbers) / sizeof(testNumbers[0]); ++i) {
        assert(factorial(testNumbers[i][0]) == testNumbers[i][1]);
    }
}

int main() {
    test();
    return 0;
}
