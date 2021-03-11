#include <assert.h>
#include <stdbool.h>

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

/**
 * Returns the value of the first argument raised to the power of the second argument.
 * @param a the base.
 * @param b the exponent.
 * @return the value {@code a}<sup>{@code b}</sup>.
 */
long pow(int a, int b) {
    long power = 1;
    for (int i = 1; i <= b; ++i) {
        power *= a;
    }
    return power;
}

/**
 * Test if a given number is NarcissisticNumber or not.
 * @param number the number to be tested
 * @return true if given number is NarcissisticNumber, otherwise false.
 */
bool isNarcissisticNumber(int number) {
    int power = countDigits(number);
    int numberCopy = number;
    long sum = 0;
    while (number != 0) {
        sum = sum + pow(number % 10, power);
        number /= 10;
    }
    return sum == numberCopy;
}

void test() {
    assert(!isNarcissisticNumber(10));
    assert(isNarcissisticNumber(2));
    assert(!isNarcissisticNumber(72));
    assert(isNarcissisticNumber(153));
}

int main() {
    test();
    return 0;
}

