#include <assert.h>

/**
 * Return the number of digits of a number.
 * @param number the number to checked.
 * @return the number of digits of a number.
 */
int countDigits(int number) {
    int count = 0;
    do {
        number /= 10;
        count++;
    } while (number != 0);
    return count;
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

