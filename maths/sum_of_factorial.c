#include <assert.h>

/**
 * Calculate 1! + 2! + 3! + ... n! using recursion.
 */
int sumOfFactorial(int i, int n){
    return i == n ? n : i + i * sumOfFactorial(i + 1, n);
}

void test(){
    assert(sumOfFactorial(1, 1) == 1);
    assert(sumOfFactorial(1, 2) == 3);
    assert(sumOfFactorial(1, 3) == 9);
    assert(sumOfFactorial(1, 4) == 33);
    assert(sumOfFactorial(1, 5) == 153);
}

int main(){
    test();
    return 0;
}