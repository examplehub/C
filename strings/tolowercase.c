#include <assert.h>
#include <string.h>

/**
 * Convert a string to lower case.
 * @param str the string to be converted.
 */
char *toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    return str;
}

int main() {
    char str[100] = "ABC";
    assert(strcmp("abc", toLowerCase(str)) == 0);

    strcpy(str, "ABC123");
    assert(strcmp("abc123", toLowerCase(str)) == 0);

    strcpy(str, "");
    assert(strcmp("", toLowerCase(str)) == 0);
    return 0;
}
