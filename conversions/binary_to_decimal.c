#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

/**
 * Convert binary string to decimal number.
 * @param binary the binary string.
 * @return decimal number.
 */
int toBinary(char *binary) {
    int sum = 0;
    bool isNegative = binary[0] == '-';
    int k = isNegative ? (int) strlen(binary) - 1 : (int) strlen(binary);
    for (int i = isNegative ? 1 : 0; binary[i] != '\0'; ++i) {
        sum += (binary[i] - '0') * (int) pow(2, --k);
    }
    return isNegative ? -sum : sum;
}

void test() {
    assert(0 == toBinary("0"));
    assert(1 == toBinary("1"));
    assert(10 == toBinary("1010"));
    assert(-29 == toBinary("-11101"));
}

int main() {
    test();
    return 0;
}
