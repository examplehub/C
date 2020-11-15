#include <stdio.h>
#include <assert.h>
#include <math.h>

int absoluteMax(const int *array, int length){
    int max = array[0];
    for (int i = 1; i < length; i++) {
        if (fabs(array[i] * 1.0) > fabs(max * 1.0)) {
            max = array[i];
        }
    }
    return max;
}

void test(){
    int array[] = {1, -2, 5, -8, 7};
    assert(-8 == absoluteMax(array, sizeof(array) / sizeof(array[0])));
}
int main(){
    test();
    return 0;
}