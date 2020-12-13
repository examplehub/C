#include <assert.h>
#include <stdbool.h>

/**
 * Test if a given number is even number or not.
 * @param number the number to be checked.
 * @return true if given number is even number, otherwise false.
 */
bool isEven(int number) {
    return number % 2 == 0;
}

void test() {
    for (int i = -2; i <= 10; i += 2) {
        assert(isEven(i));
        assert(!isEven(i + 1));
    }
}

int main() {
    test();
    return 0;
}