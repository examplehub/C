/** https://projecteuler.net/problem=1 */
#include <assert.h>

int solution1(int n) {
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

void test() {
    assert(0 == solution1(-100));
    assert(0 == solution1(3));
    assert(3 == solution1(4));
    assert(23 == solution1(10));
    assert(233168 == solution1(1000));
}

int main() {
    test();
    return 0;
}

