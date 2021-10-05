/**
 * https://en.wikipedia.org/wiki/Chinese_remainder_theorem
 */
#include <assert.h>

int getSoldiers(int limit) {
    for (int i = limit; i >= 0; --i) {
        if (i % 3 == 2 && i % 5 == 3 && i % 7 == 2) {
            return i;
        }
    }
    return -1; // unreachable code
}

void test() {
    assert(getSoldiers(100) == 23);
    assert(getSoldiers(1000) == 968);
    assert(getSoldiers(10000) == 9998);
}

int main() {
    test();
    return 0;
}
