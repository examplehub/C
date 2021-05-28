#include <assert.h>

/**
 * Return the factorial of a given number using recursion.
 * @param number the number
 * @return the factorial of a given number.
 */
long factorial(int number) {
    return number == 0 || number == 1 ? 1 : number * factorial(number - 1);
}

void test() {
    int testNumbers[][2] = {{0, 1},
                            {1, 1},
                            {2, 2},
                            {3, 6},
                            {4, 24},
                            {5, 120}};
    for (int i = 0, len = sizeof(testNumbers) / sizeof(testNumbers[0]); i < len; ++i) {
        assert(factorial(testNumbers[i][0]) == testNumbers[i][1]);
    }
}

int main() {
    test();
    return 0;
}
