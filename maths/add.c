#include <assert.h>
int add(int a, int b){
    return a + b;
}

int main(){
    assert(add(3, 2) == 5);
}

