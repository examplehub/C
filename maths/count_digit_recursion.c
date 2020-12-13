#include <assert.h>

/**
 * Return the number of digits of a number using recursion.
 * @param number the number to checked.
 * @return the number of digits of a number.
 */
int countDigits(int number) {
    number = number < 0 ? -number : number;
    return number < 10 ? 1 : 1 + countDigits(number / 10);
}

void test() {
    assert(countDigits(-123) == 3);
    assert(countDigits(-1) == 1);
    assert(countDigits(0) == 1);
    assert(countDigits(123) == 3);
    assert(countDigits(123456) == 6);
}

int main() {
    test();
    return 0;
}

