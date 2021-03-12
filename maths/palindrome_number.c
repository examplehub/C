#include <stdbool.h>
#include <assert.h>

/**
 * Test if a given number is palindrome number or not.
 * @param number the number to be tested.
 * @return true if given number is palindrome, otherwise false.
 */
bool isPalindrome(int number) {
    int numberCopy = number;
    int reversedNumber = 0;
    while (number != 0) {
        reversedNumber = reversedNumber * 10 + number % 10;
        number /= 10;
    }
    return numberCopy == reversedNumber;
}

void test() {
    for (int i = 0; i < 10; ++i) {
        assert(isPalindrome(i));
    }
    assert(isPalindrome(11));
    assert(isPalindrome(113311));
    assert(isPalindrome(123321));
    assert(!isPalindrome(123));
}

int main() {
    test();
    return 0;
}