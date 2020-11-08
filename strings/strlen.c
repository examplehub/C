#include <string.h>
#include <assert.h>

/**
 * Calculate string length.
 * @param str the string to be calculated.
 * @return the number of characters in string.
 */
int stringLen(const char *str) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        length++;
    }
    return length;
}

void test() {
    char str[] = "hello world";
    assert(strlen(str) == stringLen(str));
}

int main() {
    test();
    return 0;
}

