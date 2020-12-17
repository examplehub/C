#include <stdbool.h>
#include <string.h>
#include <assert.h>

/**
 * Test if a string is palindrome string or not.
 * @param str the string to be checked.
 * @return true if given string is palindrome, otherwise false.
 */
bool isPalindrome(const char *str) {
    for (int i = 0, j = (int) (strlen(str) - 1); i < j; ++i, --j) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

void test() {
    assert(isPalindrome(""));
    assert(isPalindrome("1"));
    assert(isPalindrome("a"));
    assert(isPalindrome("aa"));
    assert(isPalindrome("aba"));
    assert(isPalindrome("abc11cba"));
    assert(isPalindrome("amanaplanacanalpanama"));
    assert(!isPalindrome("abc"));
}

int main() {
    test();
    return 0;
}

