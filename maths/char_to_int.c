#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Convert digit character to integer.
 * @param ch character to be converted.
 * @return integer number.
 */
int toInt(char ch) {
    return ch - '0';
}

void test() {
    for (char ch = '0', i = 0; ch <= '9'; ch++, i++) {
        assert(toInt(ch) == i);
    }
}

int main() {
    test();
    return 0;
}

