#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

int stringToInt(const char *string) {
    if (string == NULL) {
        return 0;
    }
    bool isNegative = *string == '-';
    int number = 0;
    for (int i = isNegative ? 1 : 0; string[i] != '\0'; ++i) {
        number = number * 10 + string[i] - '0';
    }
    return isNegative ? -number : number;
}

void test() {
    assert(1 == stringToInt("1"));
    assert(123 == stringToInt("123"));
    assert(-123 == stringToInt("-123"));
    assert(123 == stringToInt("0123"));
    assert(0 == stringToInt(NULL));
    //assert(123 == stringToInt("    123    "));//FIXME:remove white-space
}

int main() {
    test();
    return 0;
}

