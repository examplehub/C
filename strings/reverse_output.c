#include <string.h>
#include <stdio.h>

void reverse(char str[], int len) {
    if (len != 0) {
        printf("%c", str[len - 1]);
        reverse(str, len - 1);
    }
}

void reverseOneArg(char *p) {
    if (*p != '\0') {
        reverseOneArg(++p);
        printf("%c", *(--p));
    }
}

void test() {
    char str[] = "abc123";
    reverse(str, strlen(str)); /* 321cba */
    printf("\n");

    reverseOneArg(str); /* 321cba */
    printf("\n");
}

int main() {
    test();
    return 0;
}