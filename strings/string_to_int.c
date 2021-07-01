#include <assert.h>
#include <stdbool.h>

int stringToInt(const char *string) {
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
    //assert(123 == stringToInt("    123    "));//FIXME:去除空格
}

int main() {
    test();
    return 0;
}

