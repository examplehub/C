#include <assert.h>
#include <stdlib.h>
#include <string.h>

void str_copy(const char *src, char *dest) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; ++i) {
        dest[j++] = src[i];
    }
    dest[j] = '\0';
}

void test() {
    char src[] = "hello world";
    const int SIZE = 100;
    char *dest = (char *) malloc(sizeof(char) * SIZE);
    str_copy(src, dest);
    assert(strcmp(src, dest) == 0);
}

int main() {
    test();
    return 0;
}