#include <assert.h>

/**
 * Swap two variable using pointer.
 * @param pa the pointer of first number.
 * @param pb the pointer of second number.
 */
void swap(int *pa, int *pb) {
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

void test() {
    int a = 3;
    int b = 4;
    assert(a == 3 && b == 4);

    swap(&a, &b);

    assert(a == 4 && b == 3);
}

int main() {
    test();
    return 0;
}

