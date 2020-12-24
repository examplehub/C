#include <stdbool.h>
#include <assert.h>

void test() {
    bool flag = true;
    assert(flag);
    flag = !flag;
    assert(!flag);

    int number = -3;
    bool isNegative = number < 0;
    number = isNegative ? -number : number;
    assert(number == 3);
}

int main() {
    test();
    return 0;
}

