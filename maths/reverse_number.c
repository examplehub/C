#include <assert.h>

int reverse(int number) {
    int reversed = 0;
    while (number != 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    return reversed;
}

void test() {
    assert(-123 % 10 == -3);
    assert(123 % -10 == 3);
    assert(-123 % -10 == -3);
    assert(21 == reverse(12));
    assert(-21 == reverse(-12));
    assert(123456 == reverse(654321));
    assert(-123456 == reverse(-654321));
    assert(0 == reverse(0));
}

int main() {
    test();
    return 0;
}