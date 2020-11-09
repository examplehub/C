#include <assert.h>
#include <string.h>

/**
 * Convert a string to upper case.
 * @param str the string to be converted.
 */
char *toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return str;
}

void test() {
    char str[100] = "abc";
    assert(strcmp("ABC", toUpperCase(str)) == 0);

    strcpy(str, "abc123");
    assert(strcmp("ABC123", toUpperCase(str)) == 0);

    strcpy(str, "");
    assert(strcmp("", toUpperCase(str)) == 0);
}

int main() {
    test();
    return 0;
}
