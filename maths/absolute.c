#include <assert.h>
int absolute(int number) {
    return number < 0 ? -number : number;
}

void test() {
    assert(absolute(-2) == 2);
    assert(absolute(2) == 2);
    assert(absolute(0) == 0);
}

int main() {
    test();
    return 0;
}
