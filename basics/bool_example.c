#include <stdbool.h>
#include <assert.h>

void test() {
    bool flag = true;
    assert(flag);
    flag = !flag;
    assert(!flag);

    int sum = 0;
    for (int i = -3; i <= 2; i++) {
        sum += i;
    }
    bool isNegative = sum < 0;
    int number = isNegative ? -sum : sum;
    assert(number == 3);
}

int main() {
    test();
    return 0;
}

