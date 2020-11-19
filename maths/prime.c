#include <stdbool.h>
#include <assert.h>
#include <math.h>

bool isPrime(int number) {

    /* negative numbers and 0, 1 are not primes */
    if (number < 2) {
        return false;
    }

    /* both of 2 and 3 is primes */
    if (number == 2 || number == 3) {
        return true;
    }

    /* all even numbers which is larger than 2 are not primers */
    if (number % 2 == 0) {
        return false;
    }

    for (int i = 3, limit = (int) sqrt(number); i <= limit; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void test() {
    assert(!isPrime(-1));
    assert(!isPrime(0));
    assert(!isPrime(1));

    for (int i = 4; i <= 100; i += 2) {
        assert(!isPrime(i));
    }
    assert(isPrime(2));
    assert(isPrime(3));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(isPrime(97));
}

int main() {
    test();
    return 0;
}
