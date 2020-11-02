#include <assert.h>
int absolute(int number) {
    return number < 0 ? -number : number;
}

int main() {
    assert(absolute(-2) == 2);
}
