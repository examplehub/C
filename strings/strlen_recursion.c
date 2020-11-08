#include <string.h>
#include <assert.h>

/**
 * Calculate string length using recursion.
 * @param str the string to be calculated.
 * @return the number of characters in string.
 */
int stringLen(const char *str) {
    return *str == '\0' ? 0 : 1 + stringLen(str + 1);
}

void test() {
    char str[] = "hello world";
    assert(strlen(str) == stringLen(str));
}

int main() {
    test();
    return 0;
}

