#include <assert.h>

int signFunction(int number) {
    return (number < 0) ? -1 : (number == 0) ? 0 : 1;
}

void test() {
    for (int i = 1; i <= 100; ++i) {
        assert(1 == signFunction(i));
        assert(-1 == signFunction(-i));
    }
    assert(0 == signFunction(0));
}

int main() {
    return 0;
}

