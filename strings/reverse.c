#include <assert.h>
#include <string.h>

char *reverse(char *p) {
    for (int i = 0, j = strlen(p) - 1; i < j; ++i, --j) {
        char temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
    return p;
}

void test() {
    char str[] = "hello123";
    assert(strcmp("321olleh", reverse(str)) == 0);
}

int main() {
    test();
    return 0;
}

