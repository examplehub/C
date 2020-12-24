#include <assert.h>
#include <stdio.h>

void hanoi(int n, char A, char B, char C) {
    if (n != 0) {
        hanoi(n - 1, A, C, B);
        printf("move from %c to %c\n", A, B);
        hanoi(n - 1, C, B, A);
    }
}

void test() {
    /**
     * output:
     * move from A to B
     */
    hanoi(1, 'A', 'B', 'C');
    printf("---------------------\n");

    /**
     * move from A to C
     * move from A to B
     * move from C to B
     */
    hanoi(2, 'A', 'B', 'C');
    printf("---------------------\n");

    /**
     * move from A to B
     * move from A to C
     * move from B to C
     * move from A to B
     * move from C to A
     * move from C to B
     * move from A to B
     */
    hanoi(3, 'A', 'B', 'C');


}

int main() {
    test();
    return 0;
}
