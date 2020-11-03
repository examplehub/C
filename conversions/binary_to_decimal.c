#include <stdbool.h>
#include <assert.h>
#include <string.h>

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
        --k;
        int power = 1;
        for (int j = 1; j <= k; j++) {
            power *= 2;
        }
        sum += (binary[i] - '0') * power;
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
