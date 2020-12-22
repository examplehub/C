#include <assert.h>
#include <stdbool.h>

/**
 * Test if a number is perfect number or not.
 * @param number the number to be tested.
 * @return true if given number is perfect number, otherwise false.
 */
bool isPerfectNumber(int number) {
    if (number <= 0) {
        return false; /* all negative is not perfect number */
    }
    int sum = 0;
    for (int i = 1; i < number; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum == number;
}

void test() {
    int perfectNumbers[] = {6, 28, 496, 8128};
    for (int i = 0, size = sizeof(perfectNumbers) / sizeof(perfectNumbers[0]); i < size; ++i) {
        assert(isPerfectNumber(perfectNumbers[i]));
    }
    int notPerfectNumbers[] = {0, 1, 2, 3, 4, 5, 7, 8, 8, 27};
    for (int i = 0, size = sizeof(notPerfectNumbers) / sizeof(notPerfectNumbers[0]); i < size; ++i) {
        assert(!isPerfectNumber(notPerfectNumbers[i]));
    }
}

int main() {
    test();
    return 0;
}