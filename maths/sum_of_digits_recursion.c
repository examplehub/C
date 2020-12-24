#include <assert.h>

/**
 * Sum of digits of a number using recursion.
 * @param number the number to be calculated.
 * @return sum of digits of given number.
 */
int sumOfDigits(int number) {
    number = number < 0 ? -number : number;
    return number < 10 ? number : number % 10 + sumOfDigits(number / 10);
}

void test() {
    int testNumbers[][2] = {{-123,   6},
                            {-10,    1},
                            {0,      0},
                            {123,    6},
                            {100,    1},
                            {123456, 21}};
    int size = sizeof(testNumbers) / sizeof(testNumbers[0]);
    for (int i = 0; i < size; ++i) {
        assert(testNumbers[i][1] == sumOfDigits(testNumbers[i][0]));
    }
}

int main() {
    test();
    return 0;
}

