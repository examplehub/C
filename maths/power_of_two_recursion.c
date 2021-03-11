/**
 * https://en.wikipedia.org/wiki/Power_of_two
 */
#include <assert.h>
#include <stdbool.h>
/**
 * Test if a given number is power of two using recursion.
 * @param number the number to be tested.
 * @return true if given number is power of two, otherwise false.
 */
bool powerOfTwo(int number) {
    if (number == 2) {
        return true;
    } else if (number % 2 == 1) {
        return false;
    } else {
        return powerOfTwo(number / 2);
    }
}

void test() {
    assert(!powerOfTwo(1));
    assert(powerOfTwo(2));
    assert(!powerOfTwo(3));
    assert(powerOfTwo(8));
    assert(powerOfTwo(32));
    assert(powerOfTwo(1024));
}

int main() {
    test();
    return 0;
}