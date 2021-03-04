#include <assert.h>
#include <string.h>
#include <stdlib.h>

int length(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        count++;
    }
    return count;
}

void test() {
    const int SIZE = 100;
    char *str = (char *) malloc(sizeof(char) * SIZE);
    strcpy(str, "abc123");
    assert(strlen(str) == length(str));

    strcpy(str, "123456789");
    assert(strlen(str) == 9);

    strcpy(str, "");
    assert(strlen(str) == 0);
}

int main() {
    test();
    return 0;
}