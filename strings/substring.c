#include <string.h>
#include <assert.h>

/**
 * substring
 * @param str the origin string.
 * @param sub the char array to store substring.
 * @param startIndex the start index.
 * @param len the count of characters of substring
 * @return the address of substring.
 */
char *substring(char str[], char sub[], int startIndex, int len) {
    if (startIndex < 0 || startIndex > strlen(str) - len) {
        return NULL;
    }
    int j = 0;
    for (int i = startIndex; i < startIndex + len; i++) {
        sub[j++] = str[i];
    }
    sub[j] = '\0';
    return sub;
}

void test() {
    char str[100] = "abc123456";
    char sub[100];
    substring(str, sub, 3, 6);
    assert(strcmp(sub, "123456") == 0);
}

int main() {
    test();
    return 0;
}
