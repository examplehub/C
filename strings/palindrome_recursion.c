#include <stdbool.h>
#include <string.h>
#include <assert.h>

/**
 * Test if a string is palindrome string or not using recursion.
 * @param str the string to be checked.
 * @return true if given string is palindrome, otherwise false.
 */
bool isPalindrome(const char *str, int low, int high) {

    return low >= high ?
           true : str[low] != str[high] ?
                  false : isPalindrome(str, low + 1, high - 1);
}

void test() {
    assert(isPalindrome("", 0, -1));
    assert(isPalindrome("1", 0, 0));
    assert(isPalindrome("a", 0, 0));
    assert(isPalindrome("aa", 0, 1));
    assert(isPalindrome("aba", 0, 2));
    assert(isPalindrome("abc11cba", 0, 7));
    assert(isPalindrome("amanaplanacanalpanama", 0, strlen("amanaplanacanalpanama") - 1));
    assert(!isPalindrome("abc", 0, 2));
}

int main() {
    test();
    return 0;
}

