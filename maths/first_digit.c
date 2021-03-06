#include <assert.h>

/**
 * Return the first digit of a number.
 * @param number the number to be calculated.
 * @return the first digit of given number.
 */
int firstDigit(int number) {
    number = number < 0 ? -number : number;
    while (number >= 10) {
        number /= 10;
    }
    return number;
}

void test() {
    assert(0 == firstDigit(0));
    assert(8 == firstDigit(8));
    assert(8 == firstDigit(-8));
    assert(1 == firstDigit(123));
    assert(1 == firstDigit(-123));
}

int main() {
    test();
    return 0;
}

