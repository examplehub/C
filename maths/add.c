#include <assert.h>
int add(int a, int b){
    return a + b;
}

void test() {
    assert(add(3, 2) == 5);
}
int main(){
    test();
    return 0;
}

